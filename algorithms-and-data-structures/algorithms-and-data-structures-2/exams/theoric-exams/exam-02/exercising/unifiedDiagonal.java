void insert(Cell l,doubleCell dl){
	Cell nav=l;
	if(dl==null){
		dl=new doubleCell(nav->val);
		nav=nav.next;
	}
	doubleCell tmp=dl;
	while(nav!=null){
		doubleCell c=new doubleCell(nav.val);
		nav=nav.next;
		tmp.next=c;
		c.ant=tmp;
		tmp=tmp.next;
	}
}
doubleCell unifiedDiagonal(){
	doubleCell lista=null;
	Cell nav=start;
	while(nav.lower!=null && nav.right!=null){
		insert(nav.list,list);
		nav=nav.right.lower;	
	}
	return list;
}
