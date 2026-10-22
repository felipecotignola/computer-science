void quicksort(Node* left, Node* right,int gap){
	Node* i=left;
	Node* j=right;
	int pivot=right->value;
	int pI=0;
	int pJ=gap;
	while(pI<=pJ){
		while(pI<=pJ && i->value<pivot){
			i=i->next;
			pI++;
		}
		while(pJ>=pI && j->value>pivot){
			j=j->prev;
			pJ--;
		}
		if(pI<=pJ){
			int tmp=i->value;
			i->value=j->value;
			j->value=tmp;
			i=i->next;
			pI++;
			j=j->prev;
			pJ--;
		}
	}
	if(0<pJ){
		quicksort(left,j,pJ);
	}
	if(pI<gap){
		quicksort(i,right,gap-pI);
	}
}
