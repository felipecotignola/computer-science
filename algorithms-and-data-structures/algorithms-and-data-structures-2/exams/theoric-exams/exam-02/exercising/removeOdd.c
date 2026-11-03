void removeOdd(List* l){
	Cell* even=l->head->next
	while(even!=NULL && even->val%2!=0){
		Cell* tmp=even;
		even=even->next;
		tmp->next=NULL;
		free(tmp);
	}
	l->head=even;
	Cell* nav=even->next;
	while(nav!=NULL){
		if(nav->val%2==0){
			even=nav;
			nav=nav->next;
		} else {
			Cell* tmp=nav;
			nav=nav->next;
			even->next=nav;
			tmp->next=NULL;
			free(tmp);
		}
	}
}
void travel(Matrix* m){
	for(Cell* i=m->start,i!=NULL;i=i->lower){
		for(Cell* j=i;j!=NULL;j=j->right){
			removeOdd(j->list);
		}
	}
}
