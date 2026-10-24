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
		root=null;
	}
	public Node insert(Node root,int x){
		if(root==null){
			return new Node(x);
		}	
		if(x<root.value){
			root.left=insert(root.left,x);
		} else if(x>root.value){
			root.right=insert(root.right,x);
		} else {
			root.q++;
		}	
		return root;
	}
	public boolean search(Node root,int target){
		if(root==null){
			return false;
		}
		System.out.printf("%d ",root.value); 
		boolean answ;
		if(target<root.value){
			answ=search(root.left,target);	
		} else if(target>root.value){
			answ=search(root.right,target);
		} else {
			return true;
		}	
		return answ;
	}
	public boolean isEmpty(Node root){
		if(root==null){
			return true;
		} else {
			return false;
		}
	}
	//middle left right
	public void preOrder(Node root){
		if(root!=null){	
			System.out.printf("%d ",root.value); 
			preOrder(root.left); 
			preOrder(root.right);			
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

public class binaryTree{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		Bst bst=new Bst();
		while(sc.hasNext()){
			String op=sc.next();
			switch (op){
				case"I":
					bst.root=bst.insert(bst.root,sc.nextInt());
					break;
				case"P":
					if(bst.search(bst.root,sc.nextInt())){
						System.out.println("S");
					} else {
						System.out.println("N");
					}
					break;
				case"PRE":
					if(bst.isEmpty(bst.root)){
						System.out.println("V");
					} else {
						bst.preOrder(bst.root);
						System.out.println();
					}
					break;
				case"POS":
					if(bst.isEmpty(bst.root)){
						System.out.println("V");
					} else {
						bst.postOrder(bst.root);
						System.out.println();
					}
					break;
				case"EM":
					if(bst.isEmpty(bst.root)){
						System.out.println("V");
					} else {
						bst.inOrder(bst.root);
						System.out.println();
					}
					break;
			}
		}	
	}
}
