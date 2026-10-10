class Queue {
    int[] array;
    int beggining, end, capacity, quantity;

    public Queue(int n) {
        array = new int[n];
        capacity = n;
        quantity = 0;
        beggining = 0;
        end = 0;
    }

    void enqueue(int x) {
        if (quantity == capacity) {
            return;
        }
        array[end] = x;
        end = (end + 1) % capacity;
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
