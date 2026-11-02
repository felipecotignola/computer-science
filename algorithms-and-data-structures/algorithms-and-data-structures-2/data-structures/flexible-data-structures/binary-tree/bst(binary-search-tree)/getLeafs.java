int getLeafs(Node root){
	if(root==null){
		return 0;	
	} else if (root.left==null && root.right==null){
		return 1;
	} 
	int left=getLeafs(root.left);
	int right=getLeafs(root.right);
	return left+right;
}
