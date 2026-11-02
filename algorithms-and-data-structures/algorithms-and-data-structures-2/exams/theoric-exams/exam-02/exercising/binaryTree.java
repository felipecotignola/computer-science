private boolean isMirror(Node a,Node b){
	if(a==null && b==null){
		return true;
	} else if(a==null || b==null){
		return false;
	} else if(a.val!=b.val){
		return false;
	}
	return is(a.left,b.right) && is(a.right,b.left);
	
}
