class DoubleNode {
    int element;
    DoubleNode prev;
    DoubleNode next;

    public DoubleNode(int x) {
        this.element = x;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    private DoubleNode head;
    private DoubleNode tail;

    public DoublyLinkedList() {
        head = new DoubleNode(0);
        tail = head;
    }

    public void insertFirst(int x) {
        DoubleNode tmp = new DoubleNode(x);
        tmp.next = head.next;
        tmp.prev = head;

        if (head.next != null) {
            head.next.prev = tmp;
        } else {
            tail = tmp;
        }
        head.next = tmp;
    }

    public void insertLast(int x) {
        DoubleNode tmp = new DoubleNode(x);
        tmp.prev = tail;
        tail.next = tmp;
        tail = tmp;
    }

    public int removeFirst() {
        if (head == tail) {
            return -1;
        }
        DoubleNode tmp = head.next;
        int res = tmp.element;
        head.next = tmp.next;

        if (tmp.next != null) {
            tmp.next.prev = head;
        } else {
            tail = head;
        }

        return res;
    }

    public int removeLast() {
        if (head == tail) {
            return -1;
        }
        DoubleNode tmp = tail;
        int res = tmp.element;

        tail = tail.prev;
        tail.next = null;

        return res;
    }

    public void print() {
        DoubleNode tmp = head.next;
        while (tmp != null) {
            System.out.print(tmp.element + " ");
            tmp = tmp.next;
        }
        System.out.println();
    }
}