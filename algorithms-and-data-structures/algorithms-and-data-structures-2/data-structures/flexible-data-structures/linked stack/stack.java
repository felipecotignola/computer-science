class Node {
    int element;
    Node next;

    public Node(int x) {
        element = x;
        next = null;
    }
}

class Stack {
    Node top;

    public Stack() {
        top = null;
    }

    void push(int x) {
        Node n = new Node(x);
        n.next = top;
        top = n;
    }

    int pop() {
        if (top != null) {
            int res = top.element;
            top = top.next;
            return res;
        }
        return -1;
    }

    void print() {
        Node tmp = top;
        while (tmp != null) {
            System.out.print(tmp.element + " ");
            tmp = tmp.next;
        }
        System.out.println();
    }
}