class LinkedList <T> {
    private T arr[];

    LinkedList (T array[]) {
        arr = array.clone();
    }

    public void printList () {
        for (T t : arr) {
            System.out.println(t);
        }
    }
}

public class generics {
    public static void main(String[] args) {
        Integer[] arr = {1,2,3,4};
        LinkedList<Integer> li = new LinkedList<Integer>(arr);
        li.printList();
    }
}