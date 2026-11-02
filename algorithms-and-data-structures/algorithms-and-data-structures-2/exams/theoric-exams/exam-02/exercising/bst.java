class Node{
	public int val,q;
	public Node left,right;
	public Node(int x){
		val=x;
		q=1;
		left=null;
		right=null;
	}	
}

public class Bst{
	public Node root;
	public Node insertion(Node root,int x){
		if(root==null){
			return new Node(x);
		} else if (root.val<x){
			root.right=insertion(root.right,x);
		} else if (root.val>x){
			root.left=insertion(root.left,x);
		} else {
			root.q++;
		}
		return root;
	}
	public void insert(int x){
		root=insertion(root,x);
	}
}
