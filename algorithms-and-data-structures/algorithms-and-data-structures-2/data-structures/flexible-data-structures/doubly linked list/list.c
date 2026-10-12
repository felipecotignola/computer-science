typedef struct Node{
	int value;
	struct Node* next;
	struct Node* ant;
}Node;

Node* newNode(int x){
	Node* n=malloc(sizeof(Node));
	n->value=x;
	n->next=NULL;
	n->ant=NULL;
	return n;
}

typedef struct List{
	Node* h;
	Node* t;
	int q;
}List;

List* newList(){
	Node* n=newNode(-1);
	List* l=malloc(sizeof(List));
	l->h=n;
	l->t=n;
	l->q=0;
	return l;	
}

void insertStart(List* l,int x){
	Node* n=newNode(-1);
	l->h->value=x;
	n->next=l->h;
	l->h->ant=n;
	l->h=n;
	l->q++;
}

void insertEnd(List* l,int x){
	Node* n=newNode(x);
	l->t->next=n;
	n->ant=l->t;
	l->t=n;
	q++;
}

 void insertPos(List* l,int x,int pos){
	if(pos>=0 &&pos<=l->q){
		Node* n=newNode(x);
		Node* nav=l->h;
		int i=0;
		while(i<pos){
			nav=nav->next;
			i++;
		}
		n->next=nav->next;
		nav->next=n;
		n->ant=nav;
		l->q++;
		if(n->next==NULL){
			l->t=n;
		}
	}	
}

int removeStart(List* l){
	if(list->q!=0){
		Node* tmp=l->h->next;
		int answ=tmp->value;
		l->h->next=tmp->next;
		tmp->next->ant=l->h;
		l->q--;
		tmp->next=NULL;
		tmp->ant=NULL;
		free(tmp);
		return answ;	
	}
}

int removeEnd(List* l){
	if(list->q>0){
		Node* tmp=l->t;
		int answ=tmp->value;
		tmp->ant->next=NULL;
		tmp->ant=NULL;
		l->q--;
		free(tmp);
	}
}

int removePost(List* l,int pos){
	if(l->q>0 && pos>=0 && pos<l->q){
		Node* nav=l->h;
		int i=0;
		while(i<pos){
			nav=nav->next;
			i++;
		}
		Node* tmp=nav->next;
		int answ=tmp->value;
		nav->next=tmp->next;	
		if(nav->next!=NULL){
			nav->next->ant=nav;
		}	
		tmp->next=NULL;
		tmp->ant=NULL;
		free(tmp);
		l->q--;
	}
}

void print(List* l){
	for(Node* i=l->h->next;i!=NULL;i=i->next){
		printf("%d ",i->value);
	}
}
