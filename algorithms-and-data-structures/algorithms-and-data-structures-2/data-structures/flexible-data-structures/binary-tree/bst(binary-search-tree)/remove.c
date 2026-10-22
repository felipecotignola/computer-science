//first implementation if target is a parent
Node* remove(Node* root, int target){
	if(root==NULL){
		return NULL;
	} else if(root->value<target){
		root->right=remove(root->right,target);	
	} else if(root->value>target){
		root->left=remove(root->left,target);
	} else {
		if(root->left==NULL && root->right==NULL){
			free(root);
			return NULL;
		} else if(root->left==NULL){
			Node* tmp=root->right;
			free(root);
			return tmp;
		} else if(root->right==NULL){
			Node* tmp=root->left;
			free(root);
			return tmp;
		} else {
			
		}	
	}	
}

//second implementation if target is a parent
Node* remove(Node* root,int target){
	if(root==NULL){
		return NULL;
	} else if(root->value<target){
		root->right=remove(root->right,target);
	} else if(root->value>target){
		root->left=remove(root->left,target);
	} else{
		if(root->left==NULL && root->right==NULL){
			free(root);
			return NULL;	
		} else if(root->left==NULL){
			Node* tmp=root->right;
			free (root);
			return tmp;
		} else if (root->right==NULL){
			Node* tmp=root->left;
			free(root);
			return tmp;
		} else {

		}

	}
	
}
