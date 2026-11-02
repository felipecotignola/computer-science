Node reverseInterscale(Node h1,Node h2){
	Node h3=new Node(-1);
	Node tmp1=h1;
	while(tmp1.next!=null){
		tmp1=tmp1.next;
	}
	Node tmp2=h2;
	while(tmp2.next!=null){
		tmp2=tmp2.next;
	}
	Node tmp3=h3;
	while(tmp1!=h1 && tmp2!=h2){
		tmp3.next=tmp1;
		tmp3=tmp3.next;
		tmp1=tmp1.previous;
		tmp3.next=tmp2;
		tmp3=tmp3.next;
		tmp2=tmp2.previous;	
	}
	while(tmp1!=h1){
		tmp3.next=tmp1;
		tmp3=tmp3.next;
		tmp1=tmp1.previous;
	}
	while(tmp2!=h2){
		tmp3.next=tmp2;
		tmp3=tmp3.next;
		tmp2=tmp2.previous;
	}
	return h3;
}
