#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char name[256];
    double weight;
}Gift;

void strcopy(char* destino, char* origem){
    while(*origem != '\0'){
        *destino = *origem;
        origem++;
        destino++;
    }
    *destino = '\0';
}

void construtor(Gift* Struct, char* str, double weight){
    strcopy((*Struct).name, str);
    (*Struct).weight = weight;
}

int tam(char* str){
    int count = 0;
    while(*str != '\0'){
        count++;
        str++;
    }
    return count;
}

void readline(char* str, int size){
    fgets(str, size, stdin);

    if(str[tam(str)-1] == '\n'){
        str[tam(str)-1] = '\0';
    }
}

int strComp(char* str, char* str2){
    while(*str != '\0' && *str2 != '\0'){
        if(*str != *str2){
            return 0;
        }
        str++;
        str2++;
    }

    return *str == '\0' && *str2 == '\0';
}

double totalWeight(int n, Gift* vet, int t, char* str){
    double sum = 0;

    for(int i = 0; i < t; i++){
        if(strComp(vet[i].name, str)){
            return sum = n * vet[i].weight;
        }
    }

    return -1;
}

int main(){
    int y;

    scanf("%d", &y);

    for(int i = 0; i < y; i++){
        int t;

        scanf("%d", &t);

        Gift* gifts = malloc(t * sizeof(Gift));

        double weight;
        char str[256];

        for(int j = 0; j < t; j++){
            getchar();

            readline(str, 256);

            scanf("%lf", &weight);

            construtor(&gifts[j], str, weight);
        }

        double m;

        scanf("%lf", &m);
        getchar();

        char p[256];
        readline(p, 256);

        int j;
        double total = 0;

        scanf("%d", &j);
        getchar();

        while(j != 0){
            double sum = totalWeight(j, gifts, t, p);

            if(sum != -1){
                total += sum;
            }
            else{
                printf("NAO LISTADO: %s\n", p);
            }

            readline(p, 256);

            scanf("%d", &j);
            getchar();
        }

        if(fabs(fmod(total, m)) < 0.0001){
            printf("Peso total: %.2f kg\n", total);

            int trenos = (int)(total / m);

            printf("Numero de trenos: %d\n", trenos);
            printf("\n");
        }
        else{
            printf("Peso total: %.2f kg\n", total);

            int trenos = 1 + ((int)(total / m));

            printf("Numero de trenos: %d\n", trenos);
            printf("\n");
        }

        free(gifts);
    }

    return 0;
}
