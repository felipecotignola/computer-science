//in order(ascending order): left middle right 
//an use for this method is: instead of implementing a flexible structure like a list/queue or stack and sort it. we could just implement a binary tree and print it in order, it will come out as sorted (without the cost of a sorting method)
//find the k'th smallest/biggest elemtn (travel until the k'th node)
void inOrder(Node* root){
	if(root!=null){
		inOrder(root.left);
		printf(root.value);
		inOrder(root.right);
	}
}


//descending right middle left
void descending(Node* root){
	if(root!=null){	
		descending(root.right);
		printf(root.value);
		descending(root.left);
	}
}


//pre order: middle left right
//every parent appears before its sons and the root is the first element
//really good for copying/cloning/reconstructing a bst
//saving the bst in a file,since you can reconstruct it exactly from the start
//printing an structure in a hierarquical order,since the parent always comes first
void preOrder(Node* root){
	if(root!=null){
		printf(root.value);
		preOrder(root.left);
		preOrder(root.right);
	}	
}


//post order: left right middle
//visits all sons before parent, root always the last. with that in mid the post order travelling mehtod is excellent for freeing memory
void postOrder(Node* root){
	if(root!=null){
		
	}
} 
