for(int i=queue.beggining;i!=queue.end;i=(i+1)%queue.capacity){
	int smallest=i;
	for(int j=(i+1)%queue.capacity;j!=queue.end;j=(j+1)%queue.capacity){
		if(queue[j]<queue[smallest]){
			smallest=j;
		}
	}
	int tmp=queue[i];
	queue[i]=queue[smallest];
	queue[smallest]=tmp;
}
