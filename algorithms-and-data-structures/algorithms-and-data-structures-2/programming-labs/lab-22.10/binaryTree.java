import java.util.Scanner;
class Node{
	int value;
	int q;
	Node left;
	Node right;
	public Node(int x){
		value=x;
		q=0;
		left=null;
		right=null;
	}
}

class Bst{
	Node root;
	public Bst(){
		Node root;
		public Bst(int x){
			Node n=new Node(x);
			root=n;
		}
	}
	public Node insert(Node root,int x){
		if(root==null){
			return new Node(x);
		}	
		if(x<root.value){
			root.left=insert(root.lef,x);
		} else if(x>root.value){
			root.right=insert(root.right,x);
		} else {
			root.q++;
		}	
	}
	public boolean search(Node root, int target){
		if(root.value==target){
			return true;
		} else if(target<root.value){
			search(root.left,target);	
		} else if(target>root.value){
			search(root.right,target);
		} else {
			return false;
		}
		
		
	}
	//middle left right
	public void preOrder(Node root){
		if(root!=null){	
			System.out.printf("%d ",root.value); 
			preOrder(root.right); 
			preOrder(root.left);			
		}
	}
	
	//left right middle
	public void postOrder(Node root){
		if(root!=null){
			postOrder(root.left);
			postOrder(root.right);
			System.out.printf("%d ",root.value);
		}	
	}

	//left middle right
	public void inOrder(Node root){
		if(root!=null){
			inOrder(root.left);
			System.out.printf("%d ",root.value);
			inOrder(root.right);
		}
	}
}

public class BinaryTree{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		
	}
}
