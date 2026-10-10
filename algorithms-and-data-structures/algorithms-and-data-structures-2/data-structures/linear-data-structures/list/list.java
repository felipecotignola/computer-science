class List {
    private int[] list;
    private int size, capacity;

    public List(int n) {
        size = 0;
        list = new int[n];
        capacity = n;
    }

    void insertBeggining(int x) {
        if (size >= capacity) {
            return;
        }
        for (int i = size; i > 0; i--) {
            list[i] = list[i - 1];
        }
        list[0] = x;
        size++;
    }

    void insertEnd(int x) {
        if (size >= capacity) {
            return;
        }
        list[size] = x;
        size++;
    }

    void insertPos(int x, int pos) {
        if (size >= capacity || pos < 0 || pos > size) {
            return;
        }
        for (int i = size; i > pos; i--) {
            list[i] = list[i - 1];
        }
        list[pos] = x;
        size++;
    }

    int removeBeggining() {
        if (size == 0) {
            return -1;
        }
        int answ = list[0];
        for (int i = 0; i < size-1; i++) {
            list[i] = list[i + 1];
        }
        size--;
        return answ;
    }

    int removeEnd() {
        if (size == 0) {
            return -1;
        }
        return list[--size];
    }

    int removePos(int pos) {
        if (size == 0 || pos < 0 || pos >= size) {
            return -1;
        }
        int answ = list[pos];
        for (int i = pos; i < tamanho-1; i++) {
            list[pos] = lista[i + 1];
        }
        size--;
        return answ;
    }

    void print() {
        System.out.print("[ ");
        for (int i = 0; i < size; i++) {
            System.out.print(list[i] + " ");
        }
        System.out.print("]");
    }
}
