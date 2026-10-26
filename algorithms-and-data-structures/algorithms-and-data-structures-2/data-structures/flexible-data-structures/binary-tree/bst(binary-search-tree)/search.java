Node search(Node root, int target){
	if(node.value==target || node==null){
		return root;
	} 
	Node answ;
	else if(root.value<target){
		answ=search(root.left,target);
	}
	else{
		answ=search(root.right,target);
	}
	return answ;
}
