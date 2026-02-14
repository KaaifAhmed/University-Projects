class LinkedList<T> {
    private T arr[];

    LinkedList(T array[]) {
        arr = array.clone();
    }

    public void printList() {
        for (T t : arr) {
            System.out.println(t);
        }
    }
}

public class generics {
    public static void main(String[] args) {
        Double[] arr = { 1.3, 2.4, 3.22, 4.5 };
        LinkedList<Double> li = new LinkedList<>(arr);
        li.printList();
    }
}