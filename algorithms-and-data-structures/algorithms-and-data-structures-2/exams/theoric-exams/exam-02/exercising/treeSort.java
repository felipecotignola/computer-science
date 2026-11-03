void inOrder(Node root){
	if(root==null){
		return;
	}
	inOrder(root.left);
	System.out.println(root.val);
	inOrder(root.right);
}

void insertion(){
	//
}

void insert(int* array,int n,Node* root){
	for(int i=0;i<n;i++){
		root=insertion(root,array[i]);	
	}
	inOrder(root);
}
