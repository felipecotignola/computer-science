Node insert(Node root,int x){
	if(root==null){
		return new Node(x);
	}
	if(x>root.value){
		root.dir=insert(root.dir,x);
	}
	else if(x<root.value){
		root.left=insert(root.left,x);
	}
	else{
		root->q++;
	}
	return root;
}
