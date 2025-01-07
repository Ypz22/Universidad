import java.util.concurrent.Semaphore;
public class SemaforoContable {
    private static final Semaphore semaforo = new Semaphore(2); // Dos recursos disponibles
    public static void main(String[] args) {
        for (int i = 1; i <= 10; i++) {
            new Thread(new Cliente(i)).start();
        }
    }
    static class Cliente implements Runnable {
        private final int id;
        public Cliente(int id) {
            this.id = id;
        }
        @Override
        public void run() {
            try {
                System.out.println("Cliente " + id + " esperando para usar una impresora...");
                semaforo.acquire(); // Acceder al recurso
                System.out.println("Cliente " + id + " está usando una impresora.");
                Thread.sleep(3000); // Simular tiempo de uso del recurso
                System.out.println("Cliente " + id + " ha terminado de usar la impresora.");
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                semaforo.release(); // Liberar el recurso
            }
        }
    }
}