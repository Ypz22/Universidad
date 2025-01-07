import java.util.concurrent.Semaphore;
public class Filosofos {
    private static final int NUM_FILOSOFOS = 5;
    private static final Semaphore[] tenedores = new Semaphore[NUM_FILOSOFOS];
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
    static class Filosofo implements Runnable {
        private final int id;
        public Filosofo(int id) {
            this.id = id;
        }
        @Override
        public void run() {
            while (true) {
                try {
                    System.out.println("Filósofo " + id + " está pensando.");
                    Thread.sleep((int) (Math.random() * 2000));
                    System.out.println("Filósofo " + id + " quiere comer.");
                    // Adquirir los tenedores izquierdo y derecho
                    Semaphore tenedorIzquierdo = tenedores[id];
                    Semaphore tenedorDerecho = tenedores[(id + 1) % NUM_FILOSOFOS];
                    tenedorIzquierdo.acquire();
                    tenedorDerecho.acquire();
                    System.out.println("Filósofo " + id + " está comiendo.");
                    Thread.sleep((int) (Math.random() * 2000));
                    // Liberar los tenedores
                    tenedorIzquierdo.release();
                    tenedorDerecho.release();
                    System.out.println("Filósofo " + id + " ha terminado de comer.");
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}