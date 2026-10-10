class Stack {
    int[] array;
    int top, capacity;

    public Stack(int n) {
        array = new int[n];
        top = -1;
        capacity = n;
    }

    void push(int x) {
        if (top >= capacity - 1) {
            return;
        }
        array[++top] = n;
    }

    int pop() {
        if (top < 0) {
            return -1;
        }
        int answ = array[top--];
        return answ;
    }

    boolean isVazia() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
}
