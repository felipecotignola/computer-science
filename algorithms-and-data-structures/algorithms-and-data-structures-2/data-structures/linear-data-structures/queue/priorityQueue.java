class Queue{
  int q,int n;
  int[] array;
  public Queue(int x){
    q=0;
    n=x;
    array=new int[x];
  }
  void enqueue(int x){
    if(q==n)return;
    int j=q-1;
    while(j>=0 && array[j]>x){
      array[j+1]=array[j];
      j--;
    }
    array[j+1]=x;
  }
}
