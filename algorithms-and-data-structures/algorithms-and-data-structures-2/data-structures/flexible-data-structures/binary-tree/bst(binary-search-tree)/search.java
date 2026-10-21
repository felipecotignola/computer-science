Node search(Node root, int target){
	if(node.value==target || node==null){
		return root;
	}	
	else if(root.value<target){
		search(root.left,target);
	}
	else{
		search(root.right,target);
	}
}
