import java.util.concurrent.PriorityBlockingQueue;
import java.util.concurrent.Semaphore;

public class FilosofosConPrioridad {
    private static final int NUM_FILOSOFOS = 5;
    private static final Semaphore[] tenedores = new Semaphore[NUM_FILOSOFOS];
    private static final PriorityBlockingQueue<Filosofo> colaPrioridad = new PriorityBlockingQueue<>();

    public static void main(String[] args) {
        // Inicializar semáforos para los tenedores
        for (int i = 0; i < NUM_FILOSOFOS; i++) {
            tenedores[i] = new Semaphore(1);
        }

        // Crear un hilo por filósofo
        for (int i = 0; i < NUM_FILOSOFOS; i++) {
            new Thread(new Filosofo(i)).start();
        }
    }

    static class Filosofo implements Runnable, Comparable<Filosofo> {
        private final int id;
        private long tiempoInicioEspera;

        public Filosofo(int id) {
            this.id = id;
            this.tiempoInicioEspera = System.currentTimeMillis();
        }

        @Override
        public void run() {
            while (true) {
                try {
                    // Pensar
                    System.out.println("Filósofo " + id + " está pensando.");
                    Thread.sleep((int) (Math.random() * 2000));

                    // Intentar comer
                    System.out.println("Filósofo " + id + " quiere comer.");
                    synchronized (colaPrioridad) {
                        this.tiempoInicioEspera = System.currentTimeMillis();
                        colaPrioridad.add(this);
                    }

                    // Esperar hasta que sea su turno en la cola
                    while (!esMiTurno()) {
                        Thread.sleep(100);
                    }

                    // Adquirir los tenedores izquierdo y derecho
                    Semaphore tenedorIzquierdo = tenedores[id];
                    Semaphore tenedorDerecho = tenedores[(id + 1) % NUM_FILOSOFOS];

                    tenedorIzquierdo.acquire();
                    tenedorDerecho.acquire();

                    // Comer
                    System.out.println("Filósofo " + id + " está comiendo.");
                    Thread.sleep((int) (Math.random() * 2000));

                    // Liberar los tenedores
                    tenedorIzquierdo.release();
                    tenedorDerecho.release();

                    System.out.println("Filósofo " + id + " ha terminado de comer.");

                    // Salir de la cola de prioridad
                    synchronized (colaPrioridad) {
                        colaPrioridad.remove(this);
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

        private boolean esMiTurno() {
            synchronized (colaPrioridad) {
                return colaPrioridad.peek() == this;
            }
        }

        @Override
        public int compareTo(Filosofo otroFilosofo) {
            // Comparar por tiempo de espera para asegurar que el filósofo que lleva más tiempo esperando
            // tenga prioridad
            return Long.compare(this.tiempoInicioEspera, otroFilosofo.tiempoInicioEspera);
        }
    }
}
