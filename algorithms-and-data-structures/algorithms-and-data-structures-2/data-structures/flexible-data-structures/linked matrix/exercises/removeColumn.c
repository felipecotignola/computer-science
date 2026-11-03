//first collumn
void(Matrix* m){
	if(m==NULL){
		return;
	}
	Cell* nav=m->start;
	m=nav->next;
	while(nav!=NULL){
		Cell* tmp=nav;
		nav=nav->lower;
		tmp->left=NULL;
		tmp->right=NULL;
		tmp->upper=NULL;
		tmp->lower=NULL;
		free(tmp);
		
	}
}
//first colllumn: recursive
void remove(Cell* c){
	if(c==NULL){
		return;
	}
	Cell* tmp=c->lower;
	c->upper=NULL;
	c->lower=NULL;
	c->right=NULL;
	c->left=NULL;
	remove(tmp);
}
void removeFirstCollumn(Matrix* m){
	if(m==NULL){
		return;
	}	
	Cell* tmp=m->start;
	m=tmp->next;
	remove(tmp);
	return;
}
//any collumn

//any collumn recursive

//last collumn
void removeLastCollumn(Matrix* m){
	if(m==NULL){
		return;
	}
	Cell* nav=m->start;
	while(nav->next!=NULL){
		nav=nav->next;
	}
	while(nav!=NULL){
		Cell* tmp=nav;
		nav=nav->lower;
		tmp->right=NULL;
		tmp->left=NULL;
		tmp->upper=NULL;
		tmp->lower=NULL;
		free(tmp);
	}
}
//last collumn recursive

