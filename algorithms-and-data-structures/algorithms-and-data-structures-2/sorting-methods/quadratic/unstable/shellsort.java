 for (int gap = tamanho / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < tamanho; i++)
        {
            int temp = vetor[i];
            int j = i;
            while (j >= gap && vetor[j - gap] > temp)
            {
                vetor[j] = vetor[j - gap];
                j -= gap;
            }
            vetor[j] = temp;
        }
    }
/*
a insertion sort like used when array is majorly unsorted
insertion sort still better when slightly unsorted

best case: n*log n
medium case: deppends on gap value // n¹·²⁵
worst case: also  deppends on gap value
*/
