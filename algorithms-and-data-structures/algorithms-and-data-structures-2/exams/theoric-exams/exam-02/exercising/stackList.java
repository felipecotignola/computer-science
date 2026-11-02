ListNode biggestStack(){
	ListNode tmp=start;
	int max=0;
	ListNode answ=start;
	while(tmp!=null){
		int size=0;
		StackNode stack=tmp.top;
		while(stack!=null){
			size++;
			stack=stack.next;
		}
		if(size>max){
			max=size;	
			answ=tmp;
		}
		tmp=tmp.next;
	}
	return answ;
}
