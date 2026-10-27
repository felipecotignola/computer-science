//if root height ==1
void getHeight(Node* root){
	if(root==null){
		return 0;
	}
	int left=getHeight(root.left);
	int right=getHeight(root.right);
	return (left>dir? left:dir)+1;	
}

//if root height==0
void getHeight(Node* root){
	if(root==null){
		return -1;
	}
	int left=getHeight(root.left);
	int right=getHeight(root.right);
	return (left>dir? left:dir)+1;
}

//the height is always either n or lg(n)
//a bst cost equals its height
//cost of getting height: o(n)
