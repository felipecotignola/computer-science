import java.util.Scanner;
class Node{
	String nome;
	Node next;
	Node ant;
	public Node(String nome){
		this.nome=nome;
		next=null;	
		ant=null;
	}
}
class Queue{
	Node head;
	Node tail;
	int q;
	public Queue(){	
		Node node=new node("-1");
		head=node;
		tail=node;
		q=0;	
	}	
	void enqueue(String s){
		Node node=new Node(s);
		node.next=tail.next;
		tail.next=node;
		node.ant=tail;
		tail=u;
		q++;		
	}
	void dequeue(int k){
		Node* tmp=head; 
		int i=head.next; 
		while(i<k){
			tmp=tmp->next;	
			i++;
		}
		t.next=h.next;
		t.ant=h;
		h.next=t;
		tmp.ant.next=null;
		tmp.ant=null;
		tmp.next=null;
		tmp=u;
		while(tmp.next!=null){
			tmp=tmp.next;
		}
		u=tmp;
		q--;
	}
	void print(){
		Node* tmp=head.next;
		while(tmp!=null){
			System.out.print("%s ",tmp.nome;
			tmp=tmp.next;
		}
		System.out.println();
	}	
	int getQ(){
		return q;
	}
}

public class main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);	
		while(sc.hasNext()){
			int k=sc.nextInt();	
			Scanner reader=new Scanner(System.in);
			Queue queue=new Queue();
			while(reader.hasNext()){
				String nome=sc.next();
				queue.enqueue(nome);
			}
			queue.print();
			while(queue.getQ()>=k){
				queue.dequeue(k);
				queue.print();
			}
		}		
	}
}
