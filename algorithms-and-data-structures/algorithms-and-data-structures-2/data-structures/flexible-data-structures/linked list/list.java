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
	void insertPos(int x,int pos){
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
		int answ=t.value;
		while(nav.next!=t){
			nav=nav.next;
		}
		nav.next=t;
		t.next=null;
		q--;
	}
	int removePos(int pos){
		if(pos>=0 && pos<q){
			Node* nav=h;
			int i=0;
			while(i<pos){
				nav=nav.next;
				i++;
			}
			Node* tmp=nav.next;
			int answ=tmp.value;
			nav.next=tmp.next;
			tmp.next=null;
			q--;
			if(nav.next==null){
				nav=t;
			}
		}
	}
}
