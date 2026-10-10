class Queue {
    int[] array;
    int beggining, pos, capacity, quantity;

    public Queue(int n) {
        array = new int[n];
        capacity = n;
        quantity = 0;
        beggining = 0;
        pos = 0;
    }

    void enqueue(int x) {
        if (quantity == capacity) {
            return;
        }
        array[pos] = x;
        pos = (pos + 1) % capacity;
        quantity++;
    }

    int dequeue() {
        if (quantity == 0) {
            return -1;
        }
        int answ = array[beggining];
        beggining = (beggining + 1) % capacity;
        quantity--;
        return answ;
    }
}
