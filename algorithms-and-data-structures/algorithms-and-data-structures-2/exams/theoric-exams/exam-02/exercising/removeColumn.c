void removeColumn(Matrix* m){
	if(m==NULL){
		return;
	}
	Cell* nav=m->start;
	while(nav->next!=NULL){
		nav=nav->next;	
	}
	Cell* tmp=nav;
	while(nav!=NULL){
		nav=nav->lower;
		tmp->left=NULL;
		tmp->right=NULL;
		tmp->upper=NULL;
		tmp->lower=NULL;
		free(tmp);
		tmp=nav;
	}	
}
