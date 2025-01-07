import java.util.concurrent.Semaphore;
public class ExclusionMutua {
    // Crear un semáforo binario
    private static final Semaphore semaforo = new Semaphore(1);
    public static void main(String[] args) {
        for (int i = 1; i <= 5; i++) {
            new Thread(new Escritor(i)).start();
        }
    }
    static class Escritor implements Runnable {
        private final int id;
        public Escritor(int id) {
            this.id = id;
        }
        @Override
        public void run() {
            try {
                System.out.println("Hilo " + id + " esperando para escribir...");
                semaforo.acquire(); // Entrar a la sección crítica
                System.out.println("Hilo " + id + " escribiendo en la sección crítica...");
                Thread.sleep(2000); // Simular escritura
                System.out.println("Hilo " + id + " ha terminado de escribir.");
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                semaforo.release(); // Salir de la sección crítica
            }
        }
    }
}