import java.util.Scanner;
class Pilha{
	int [] array;
	int topo;
	int capacidade;
	public Pilha(int n){
		array=new int[n];
		topo=-1;
		capacidade=n;
	}
	void push(int n){
		array[++topo]=n;	
	}
	int pop(){
	    if(topo<=0){
		return array[topo--];
		}
		return -1;
	}
	void sum(){
	    if(topo>=1){
		int sum=array[topo]+array[topo-1];					  
		push(sum);
		}
	}
	void  mult(){
	    if(topo>=1){
		int mult=array[topo]*array[topo-1];
		push (mult);
		}
	}
	int getTop(){
	    if(topo>=0){
		return array[topo];
		}
		return -1;
	}
}
public class main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			int n=sc.nextInt();
			Pilha p=new Pilha(n);
			String op=sc.next();
			for(int i=0;i<n;i++){
				if(op.equals('p')){
					int x=sc.nextInt();
					p.push(x);
				}
				else if(op.equals('o')){
					System.out.println(p.pop());
				}
				else if(op.equals('a')){
					p.sum();
				}
				else{
					p.mult();
				}
				op=sc.next();
			}
			System.out.println(p.getTop());
		}
	}
}

