public class searchLL {

    public static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    public static boolean searchList(Node list1, Node list2) {

        if (list1 == null)
            return true;

        Node current = list2;

        while (current != null) {

            Node p1 = list1;
            Node p2 = current;

            while (p1 != null && p2 != null && p1.data == p2.data) {
                p1 = p1.next;
                p2 = p2.next;
            }

            if (p1 == null) {
                return true;
            }

            current = current.next;
        }

        return false;
    }

    public static void main(String[] args) {

        Node list1 = new Node(10);
        list1.next = new Node(20);

        Node list2 = new Node(5);
        list2.next = new Node(10);
        list2.next.next = new Node(20);

        if (searchList(list1, list2)) {
            System.out.println("Yes");
        }
        else {
            System.out.println("No");
        }
    }
}
