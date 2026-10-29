import java.util.Scanner;
class Hack{
	int id;
	String nome;
	public Hack(int id,String nome){
		this.id=id;
		this.nome=nome;
	}	
}
class Node{
	Hack h;
	Node left;
	Node right;
	public Node(Hack h){
		this.h=h;
		left=null;
		right=null;
	}
}
class Bst{
	Node root;
	public Bst(){
		root=null;
	}
	Node insertion(Node root,Hack h,int id){
		if( root==null){
			return new Node(h);
		}
		if(root.h.id<id){
			root.right=insertion(root.right,h,id);
		} else {
			root.left=insertion(root.left,h,id);
		}
		return root;
	}

	int getFolhas(Node root){
		if(root==null){return 0;}
		if(root.left==null && root.right==null){
			return 1;
		}
		int left=getFolhas(root.left);
		int right=getFolhas(root.right);
		return left+right;
		
	}
	void postOrder(Node root){
		if(root==null){
			return;
		}
		postOrder(root.left);
		postOrder(root.right);
		System.out.println(root.h.nome);
	}

	
}

public class main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			int n=sc.nextInt();
			Bst bst=new Bst();
			for(int i=0;i<n;i++){
				int id=sc.nextInt();
				String nome=sc.nextLine();
				Hack h= new Hack(id,nome);
				bst.root=bst.insertion(bst.root,h,id);
			}
			int folhas=bst.getFolhas(bst.root);
			System.out.println(bst.getFolhas(bst.root));	
			bst.postOrder(bst.root);
		}
	}
}
