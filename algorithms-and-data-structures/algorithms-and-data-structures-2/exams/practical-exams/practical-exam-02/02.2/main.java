import java.util.Scanner;
class Comp{
	int id;
	String nome;
	public Comp(int x,String s){
		id=x;
		nome=s;
	}
}

class Node{
	Comp c;
	Node left;
	Node right;
	public Node(int id,String nome){
		c=new Comp(id,nome);
		left=null;
		right=null;
	}
}

class Bst{
	Node root;
	public Bst(){
		root=null;
	}
	public Node insertion(Node root,int id,String nome){
		if(root==null){
			return new Node(id,nome);		
		}
		if(root.c.id<id){
			root.right=insertion(root.right,id,nome);
		} else {
			root.left=insertion(root.left,id,nome);
		}
		return root;
	}
	public Node getNode(Node root,int id){
		if(root.c.id==id || root==null){
			return root;
		}
		Node answ;
		if(root.c.id<id){
			answ=getNode(root.right,id);
		} else { answ= getNode(root.left,id);}
		return answ;
	}
	public int getHeight(Node root,Node target){
		if(root==target){
			return 0;
		}
		int left=getHeight(root.left);
		int right=getHeight(root.right);
		if(left>=right){return left+1;}
		else{ return right+1;}
	}

	void printAncestral(Node root,int target){
		if(root.c.id==target){
			return;
		} else if(root.c.id<target){
			printAncestral(root.right,target);
		} else if (root.c.id>target){
			printAncestral(root.left,target);
		}
		System.out.println(root.c.nome);
	}	
}

public class main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
		
		}
	}
}
