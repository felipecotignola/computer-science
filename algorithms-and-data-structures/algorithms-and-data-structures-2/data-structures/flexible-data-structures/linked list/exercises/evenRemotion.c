//with sentinel
void evenRemotion(List* l){
	Cell* nav=l->h->next;
	Cell* odd;
	Cell* tmp;
	while(nav!=NULL && nav->val%2==0){
		tmp=nav;
		nav=nav->next;
		tmp->next=NULL;
		free(tmp);	
	}	
	odd=nav;
	while(nav!=NULL){
		if(nav->val%2!=0){
			odd=nav;
			nav=nav->next;	
		} else {
			tmp=nav;
			nav=nav->next;
			tmp->next=NULL;
			free(tmp);
			even->next=nav;
		}
	}	
}

//withouth sentinel
void evenRemotion(List* l){
	Cell* nav=l->start;
	Cell* odd;
	Cell* tmp;
	while(nav!=NULL && nav->val%2==0){
		tmp=nav;
		nav=nav->next;
		tmp->next=NULL;
		free(tmp);
	}
	even=nav;
	while(nav!=null){
		if(nav->val%2!=0){
			odd=nav;
			nav=nav->next;
		} else {
			tmp=nav;
			nav=nav->next;
			tmp->next=NULL;
			free(tmp);
			even->next=nav;		
		}	
	}	
}
