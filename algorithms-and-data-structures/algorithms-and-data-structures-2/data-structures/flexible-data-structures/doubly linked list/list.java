class Node{
	int value;
	Node next;
	Node ant;
	public Node(int x){
		value=x;
		next=null;
		ant=null;
	}
}

class List{
	Node h;
	Node t;
	int q;
	public List(){
		Node n=new Node(-1);
		h=n;
		t=n;
		q=0;
	}
	
	void insertStart(int x){
		Node n=new Node(-1);
		h.value=x;
		h.ant=n;
		n.next=h;
		h=n;
		q++;	
	}
	void insertEnd(int x){
		Node n=new Node(x);
		t.next=n;
		n.ant=t;
		t=n;
		q++;
	}
	void insertPos(int x,int pos){
		if(pos>=0 && pos<=q){
			Node nav=h;
			int i=0;
			while(i<pos){
				nav=nav.next;
				i++;
			}
			Node n=new Node(x);
			n.next=nav.next;
			n.ant=nav;
			nav.next=n;
			if(n.next==null){
				t=n;
			}
			q++;
		}
	}

	int removeStart(){
		if(q>0){
			int answ=h.next.value;
			h.next=h.next.next;
			q--;
			
			return answ;
		}
	}
	int removeEnd(){

	}
	int removePos(){

	}
	void print(){
		for(Node i=h->next;i!=null;i=i->next){
			printf("%d ",i.value);
		}
	}
}
