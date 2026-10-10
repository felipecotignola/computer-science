class Queue {
    int q, n;
    int[] array;

    public Queue(int n) {
        q = 0;
        this.n = n;
        array = new int[n];
    }

    void enqueue(int x) {
        if (q == n) return;
        int j = q - 1;
        while (j >= 0 && array[j] > x) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = x;
        q++;
    }
}
