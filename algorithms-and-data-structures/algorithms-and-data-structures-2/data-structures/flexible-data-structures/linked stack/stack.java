class Node{
	int value;
	Node* next;
	public Node(int x){
		value=x;
		next=null;
	}
}
class Stack{
	Node* top;
	public Stack(int x){
		top=new Celula(x);
	}
	void push(int x){
		Node n=new Node(x);
		n.next=top;
		top=n;
	}
	int pop(){
		int answ=top.value;
		top=top->next;
		return answ;
	}
}
