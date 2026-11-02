typedef struct Cell{
	int val;
	struct Cell* left;
	struct Cell* right;
	struct Cell* upper;
	struct Cell* lower;	
} Cell;

Cell* newCell(int x){
	Cell* c=malloc(sizeof(Cell));
	c->val=x;
	c->left=NULL;
	c->right=NULL;
	c->upper=NULL;
	c->lower=NULL;
	return c;
}

typedef struct Matrix{
	Cell* start;
} Matrix;

Matrix* newMatrix(int i,int j){
	int x;
	scanf("%d",&x);
	Cell* cell=newCell(x);
	Matrix* m=malloc(sizeof(Matrix));
	m->start=cell;
	Cell* r=cell;
	Cell* c=r;
	Cell* y=c;
	for(int l=1;l<j;l++){
		scanf("%d",&x);
		Cell* cell=newCell(x);
		cell->left=c;
		c->right=cell;
		c=cell;
	}
	c=r;
	for(int l=1;l<i;l++){
		scanf("%d",&x);
		Cell* newRow=newCell(x);
		r=newRow;
		y=newRow;
		newRow->upper=c;
		c->lower=newRow;
		c=c->right;
		for(int k=1;k<j;k++){
			scanf("%d",&x);
			cell=newCell(x);
			cell->left=y;
			y->right=cell;
			y=cell;
			cell->upper=c;
			c->lower=cell;
			c=c->right;	
		}
		c=r;
	}
	return m;
}
