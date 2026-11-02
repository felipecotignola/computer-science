void inOrder(Node root){
	if(root==null){
		return;
	}
	inOrder(root.left);
	System.out.println(root.val);
	inOrder(root.right);
}
