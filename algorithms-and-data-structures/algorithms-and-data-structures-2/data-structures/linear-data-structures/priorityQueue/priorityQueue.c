typedef struct{
  int q,n;
  int* array;
}Queue;
void set(Queue* queue,int n){
  (*queue).q=0;
  (*queue).n=x;
  (*queue).array=malloc(n*sizeof(int));
}
void enqueue(Queue* queue,int x){
  if((*queue).q==(*queue).n)return;
  int j=(*queue).q-1;
  while(j>=0 && (*queue).array[j]>x){
    (*queue).array[j+1]=(*queue).array[j];
    j--;
  }
  (queue).array[j+1]=x;
}
