Node search(Node root, int target){
	if(node.value==target || node==null){
		return root;
	}
	Node n;	
	else if(root.value<target){
		n=search(root.left,target);
	}
	else{
		n=search(root.right,target);
	}
	return n;
}
