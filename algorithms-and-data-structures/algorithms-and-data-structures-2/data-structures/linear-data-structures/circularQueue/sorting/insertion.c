for(int i=(queue.beggining+1)%queue.capacity;i!=(queue.end)%queue.capacity;i=(i+1)%queue.capacity){
	int key=queue[i];
	int j=(i-1+queue.capacity)%queue.capacity;
	while(j!=(queue.beggining-1+queue.capacity)%queue.capacity && key<queue[j]){
		queue[(j+1)%queue.capacity]=queue[j];
		j=(j-1+queue.capacity)%queue.capacity;	
	}
	queue[(j+1)%queue.capacity]=key;
}
