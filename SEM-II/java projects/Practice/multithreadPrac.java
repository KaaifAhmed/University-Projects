class numCounter implements Runnable{
    int count = 0;
    numCounter (int x) {
        count = x;
    } 
    @Override
    public void run () {
        for (int i = 0; i < 10; i++) {
            System.out.println("i = "+i + " of thread: "+count);
        }
    }
}

public class multithreadPrac {
    public static void main (String[] args) {
        Runnable lol = new numCounter(1);
        Runnable lol2 = new numCounter(2);
        Thread t1 = new Thread(lol);
        Thread t2 = new Thread(lol2);

        Thread lambdaThread = new Thread(()->{System.out.println("Heya");});

        t1.start();
        t2.start();

        lambdaThread.start();
    }
}
