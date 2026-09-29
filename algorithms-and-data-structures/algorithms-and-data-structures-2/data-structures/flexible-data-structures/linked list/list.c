typedef struct Node{
	int value;
	struct Node* next;
}Node;

Node* newNode(int x){
	Node* node=malloc(sizeof(Node));
	node->value=x;
	node->next=NULL;
	return node;
}

typedef struct{
	Node* head;
	Node* tail;
	int q;
}List;

List* newList(){
	Node* n=newNode(-1);
	List* l=malloc(sizeof(List));
	l->head=n;
	l->tail=n;
	l->q=0;
}

void insertStart(List* l,int x){
	Node* node=newNode(-1);
	node->next=l->head;
	head->value=x;
	l->head=node;
	l->q++;
}
void insertEnd(List* l,int x){
	Node* node=newNode(x);
	l->tail->next=node;
	l->tail=node;
	l->q++;
}
void insertPos(List* l,int x,int pos){
	if(pos>=0 && pos<=l->q){
		Node* node=newNode(x);
		Node* temp=l->head;
		int i=0;
		while(i<pos){
			temp=temp->nex;
			i++;
		}
		node->next=temp->next;
		temp->next=node;
		if(node->next==NULL){
			l->tail=node;
		}
	}
}

int removeStart(List* l){
	Node* temp=l->head->next;
	int answ=temp->value;
	l->head->next=temp->next
	temp->next=NULL
	free(temp);
	l->q--;
	return answ;
}
int removeEnd(List* l){
	Node* temp=l->tail;
	int answ=temp->value;
	Node* nav=l->head;
	while(nav->next!=l->tail){
		nav=nav->next;
	}	
	nav->next=NULL;
	l->tail=nav;
	free(temp);
	l->q--;
	return answ;
}
int removePos(List* l,int pos){
	if(pos>=0 && pos<l->q){
		Node* nav=l->head;
		int i=0;
		while(i<pos){
			nav=nav->next;
			i++;
		}
		Node* temp=nav->next;
		int answ=temp->value;
		nav->next=temp->next;
		temp->next=NULL;
		free(temp);
		l->q--;
		if(nav->next==NULL){
			l->tail=nav;
		}
		return answ;
	}	
}

