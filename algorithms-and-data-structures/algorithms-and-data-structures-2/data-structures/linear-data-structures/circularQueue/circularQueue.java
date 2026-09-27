class Queue {
    int[] array;
    int inicio, pos, capacidade, quantidade;

    public Queue(int n) {
        array = new int[n];
        capacidade = n;
        quantidade = 0;
        inicio = 0;
        pos = 0;
    }

    void inserir(int n) {
        if (quantidade == capacidade) {
            return;
        }
        array[pos] = n;
        pos = (pos + 1) % capacidade;
        quantidade++;
    }

    int remover() {
        if (quantidade == 0) {
            return -1;
        }
        int resp = array[inicio];
        inicio = (inicio + 1) % capacidade;
        quantidade--;
        return resp;
    }
}