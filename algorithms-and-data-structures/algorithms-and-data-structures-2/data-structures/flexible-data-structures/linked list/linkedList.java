class Node {
    int element;
    Node next;

    public Node(int x) {
        this.element = x;
        this.next = null;
    }
}

class SinglyLinkedList {
    private Node head;
    private Node tail;

    public SinglyLinkedList() {
        head = new Node(0);
        tail = head;
    }

    public void insertFirst(int x) {
        head.element = x;
        Node newHead = new Node(0);
        newHead.next = head;
        head = newHead;
    }

    public void insertLast(int x) {
        tail.next = new Node(x);
        tail = tail.next;
    }

    public int removeFirst() {
        if (head == tail) {
            return -1;
        }
        Node tmp = head.next;
        int res = tmp.element;
        head.next = tmp.next;
        if (tmp == tail) {
            tail = head;
        }
        return res;
    }

    public void print() {
        Node tmp = head.next;
        while (tmp != null) {
            System.out.print(tmp.element + " ");
            tmp = tmp.next;
        }
        System.out.println();
    }
}