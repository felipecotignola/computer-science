#include <stdio.h>
<<<<<<< HEAD:beecrowd/1110.c
#include<stdlib.h>
=======
#include <stdlib.h>

>>>>>>> 475ba04c38a929ca7334ce411acb7eca7d5b6b14:beecrowd/data-structures-and-libraries/1110.c
typedef struct{
    int* remainingCards;
    int* discardedCards;
    int top,bottom,quantity,capacity,discartedIndex;
}Deck;
<<<<<<< HEAD:beecrowd/1110.c
=======

>>>>>>> 475ba04c38a929ca7334ce411acb7eca7d5b6b14:beecrowd/data-structures-and-libraries/1110.c
void fill(Deck* deck){
    for(int i=1;i<=(*deck).capacity;i++){
        (*deck).remainingCards[++(*deck).bottom]=i;
    }
}
<<<<<<< HEAD:beecrowd/1110.c
=======

>>>>>>> 475ba04c38a929ca7334ce411acb7eca7d5b6b14:beecrowd/data-structures-and-libraries/1110.c
void set(Deck* deck,int n){
    (*deck).remainingCards=malloc(n*sizeof(int));
    (*deck).discardedCards=malloc((n-1)*sizeof(int));
    (*deck).top=0;
    (*deck).bottom=-1;
    (*deck).quantity=n;
    (*deck).capacity=n;
    (*deck).discartedIndex=0;
    fill(deck);
}
<<<<<<< HEAD:beecrowd/1110.c
=======

>>>>>>> 475ba04c38a929ca7334ce411acb7eca7d5b6b14:beecrowd/data-structures-and-libraries/1110.c
int remov(Deck* deck){
    int resp=(*deck).remainingCards[(*deck).top];
    (*deck).top=((*deck).top+1)%(*deck).capacity;
    (*deck).quantity--;
    (*deck).bottom=((*deck).bottom+1)%(*deck).capacity;
    (*deck).remainingCards[(*deck).bottom]=(*deck).remainingCards[(*deck).top];
    (*deck).top=((*deck).top+1)%(*deck).capacity;
    return resp;
}
<<<<<<< HEAD:beecrowd/1110.c
=======

>>>>>>> 475ba04c38a929ca7334ce411acb7eca7d5b6b14:beecrowd/data-structures-and-libraries/1110.c
void loop(Deck* deck){
    while((*deck).quantity>=2){
        (*deck).discardedCards[(*deck).discartedIndex]=remov(deck);
        (*deck).discartedIndex++;
    }
}
<<<<<<< HEAD:beecrowd/1110.c
=======

>>>>>>> 475ba04c38a929ca7334ce411acb7eca7d5b6b14:beecrowd/data-structures-and-libraries/1110.c
void print(Deck* deck){
    printf("Discarded cards: ");
    for(int i=0;i<(*deck).discartedIndex;i++){
        if(i!=(*deck).discartedIndex-1){
            printf("%d, ",(*deck).discardedCards[i]);
        }
        else{
            printf("%d\n",(*deck).discardedCards[i]);
        }
    }
    printf("Remaining card: %d\n",(*deck).remainingCards[(*deck).top]);
}
<<<<<<< HEAD:beecrowd/1110.c
int main() {
    int n;
    scanf("%d",&n);
=======

int main() {
    int n;
    scanf("%d",&n);

>>>>>>> 475ba04c38a929ca7334ce411acb7eca7d5b6b14:beecrowd/data-structures-and-libraries/1110.c
    while(n!=0){
        Deck deck;
        set(&deck,n);
        loop(&deck);
        print(&deck);
        scanf("%d",&n);
    }
<<<<<<< HEAD:beecrowd/1110.c
=======

>>>>>>> 475ba04c38a929ca7334ce411acb7eca7d5b6b14:beecrowd/data-structures-and-libraries/1110.c
    return 0;
}
