typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
	struct Node* upper;
	struct Node* lower;
}

Node* newNode(int x){
	Node* node=malloc(sizeof(Node));
	node->val=x;
	node->left=NULL;
	node->right=NULL;
	node->upper=NULL;
	node->lower=NULL;
	return node;
}

typedef struct Matrix{
	Node* start;
}

Matrix* newMatrix(int i,int j){
	Matrix* m=malloc(sizeof(Matrix));
	int x;
	scanf("%d",&x);
	Node* r=newNode(x);	
	Node* c=r;
	Node* y;
	m->start=r;
	//first row
	for(int k=1;k<j;k++){
		scanf("%d",&x);
		Node* new=newNode(x);
		c->right=new;
		new->left=c;
		c=new;
	}
	c=r;
	//double for
	for(int k=1;k<i;k++){
		scanf("%d",&x);
		Node* newRow=newNode(x);
		r=y=newRow;
		newRow->upper=c;
		c=c->right;	
		for(int l=1;l<j;l++){
			scanf("%d",&x);
			Node* new=newNode(x);
			y->right=new;
			new->left=y;
			y=new;
			new->upper=c;
			c=c->right;	
		}
		c=r;
	}
	return m;
}


