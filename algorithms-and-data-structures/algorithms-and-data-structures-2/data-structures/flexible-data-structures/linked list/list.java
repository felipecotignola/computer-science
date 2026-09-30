class Node{
	int value;
	Node next;
	public Node(int x){
		value=x;
		next=null;
	}
}

class List{
	Node head;
	Node tail;
	int q;
	public List(){
		Node node=new Node(-1);
		head=node;
		tail=node;
		q=0;
	}	
	void insertStart(int x){
		Node node=new Node(-1);
		head.value=x;
		node.next=head;
		head=node;
		q++;
	}
	void insertEnd(int x){
		Node node=new Node(x);
		tail.next=node;
		tail=node;		
	}
	void insertPost(int x,int pos){
		if(pos>=0 && pos<=q){
			Node node=new Node(x);
			Node nav=head;
			int i=0;
			while(i<pos){
				nav=nav.next;
				i++;
			}
			node.next=nav.next;
			nav.next=node;
			if(node.next==null){
				tail=node;	
			}	
			q++;
		}
	}
	
	int removeStart(){
		int answ=head.next.value;
		head.next=head.next.next;
		q--;
		return answ;
	}
	int removeEnd(){
		Node* nav=head;
		while(nav.next!=t){

		}
	}
	int removePos(){

	}
}
