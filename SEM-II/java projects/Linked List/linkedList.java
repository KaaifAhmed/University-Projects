import java.util.Scanner;

public class linkedList {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node.startingIndex = 1;
        Node[] linked_list = { new Node(65, 3), new Node(15, 2), new Node(45, 0), new Node(72, -1) };

        // Main program loop
        String message = "";
        while (!message.equalsIgnoreCase("quit")) {
            System.out.println("ACTIONS:\n\t1. Create a new linked list.");
            System.out.println("\t2. Add an element to the list.");
            System.out.println("\t3. Print all the elements of the list.");
            System.out.print("\nPlease choose an action from above (1-3): ");

            message = scanner.nextLine();

            if (message.trim().equalsIgnoreCase("1")) {
                linked_list = new Node[0];
                Node.startingIndex = -1;
            } else if (message.trim().equalsIgnoreCase("2")) {
                System.out.print("Enter the element: ");
                float num = scanner.nextFloat();
                linked_list = addElement(num, linked_list);
            } else if (message.trim().equalsIgnoreCase("3")) {
                printLinkedList(linked_list);
            }
        }

        scanner.close();

    }

    public static void printLinkedList(Node[] ll) {
        int i = Node.startingIndex;
        System.out.println("\nLinked List:");
        while (i != -1) {
            System.out.println(ll[i].data);
            i = ll[i].nextIndex;
        }
        System.out.println("\n");
    }

    // To add elements to the linked list
    public static Node[] addElement(float new_num, Node[] linked_list) {
        int i = Node.startingIndex;
        int j = Node.startingIndex;

        if (linked_list.length == 0) {
            linked_list = addListElement(linked_list, new Node(new_num, -1));
            Node.startingIndex = 0;
        } else if (new_num < linked_list[i].data) {
            Node.startingIndex = linked_list.length;
            linked_list = addListElement(linked_list, new Node(new_num, i));
        } else {

            while (i != -1 && linked_list[i].data <= new_num) {
                j = i;
                i = linked_list[i].nextIndex;
            }

            linked_list[j].nextIndex = linked_list.length;
            linked_list = addListElement(linked_list, new Node(new_num, i));

        }

        return linked_list;
    }

    public static Node[] addListElement(Node[] ll, Node element) {
        Node[] newll = new Node[ll.length + 1];

        for (int i = 0; i < ll.length; i++) {
            newll[i] = ll[i];
        }

        newll[newll.length - 1] = element;

        return newll;
    }

}

class Node {
    static int startingIndex;
    float data;
    int nextIndex;

    Node(float d, int ni) {
        data = d;
        nextIndex = ni;
    }
}