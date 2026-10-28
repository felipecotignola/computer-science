//in order: left middle right 
//instead of implementing a flexible structure like a list/queue or stack and sort it. we could just implement a binary tree and print it in order, it will come out as sorted (without the cost of a sorting method)
//find the k'th smallest/biggest elemtn (travel until the k'th node)
void inOrder(Node* root){
	if(root!=null){
		inOrder(root.left);
		printf(root.value);
		inOrder(root.right);
	}
}


//pre order: middle left right
//every parent appears before its sons and the root is the first element
//really good for copying/cloning/reconstructing a bst
//printing an structure in a hierarquical order,since the parent always comes first
void preOrder(Node* root){
	if(root!=null){
		printf("%d",root.value);
		preOrder(root.left);
		preOrder(root.right);
		
	}	
}


//post order: left right middle
//visits all sons before parent, root always the last. with that in mid the post order travelling mehtod is excellent for freeing memory
void postOrder(Node* root){
	if(root!=null){
		Node left=postOrder(root.left);
		Node right=postOrder(root.right);
		free(root);	
	}
}


//descending
void descending(Node root){
	if(node!=null){
		descending(root.right);
		printf(root.value);
		descending(root.left);
	}
}

//ancestrals
void printAncestral(Node root,int target){
	if(root.element<target){
		printAncestraL(root.right,target);
	} else if(root.element>target){
		printAncestral(root.left,target);
	}
	System.out.prinln(root.element);
}

 
