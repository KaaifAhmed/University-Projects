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
        // 3 Ways to do using Runnable

        // 1. Create a full class and create object, then pass to Thread
        Runnable lol = new numCounter(1);
        Thread t1 = new Thread(lol);
        t1.start();

        // 2. Create Runnable using lambda, then pass to Thread
        Runnable lol2 = ()->System.out.println("hola!");        
        Thread t2 = new Thread(lol2);
        t2.start();

        // 3. Create Thread object, and give the interface as parameter using lambda
        Thread lambdaThread = new Thread(()->{System.out.println("Heya");});
        lambdaThread.start();
    }
}
