class Cell{
	String w;
	Cell next;
	public Cell (String word){
		w=word;
		next=null;
	}
	public void insertOrdered(Node root,String word){
		Cell tmp=root.first;
		if(tmp.word.compareTo(word)>0){
			Cell c=new Cell(word);
			c->next=tmp;
			root.first=c;
			return;
		}	
		while(tmp.next!=null && tmp.next.compareTo(word)<0){
			tmp=tmp.next;
		}
		Cell c=new Cell(word);
		c.next=tmp.next;
		tmp.next=c;
		if(c.next==null){
			root.last=c;	
		}
	}
	public void removeWord(Node root,String word){
		Cell tmp=root.first;
		if(tmp.word.compareTo(word)==0){
			root.first=tmp.next;
			return;
		}
		while(tmp.next!=null && tmp.next.word.compareTo(word)<0){
			tmp=tmp.next;

		}
		if(tmp.next.word.compareTo(word)==0){
			tmp.next=tmp.next.next;	
			if(tmp.next==null){
				root.last=tmp;
			}
		} else {
			return null;
		}
	}
}
class Node{
	char letter;
	Cell first,last;
	Node right,left;
	public Node (String word){
		letter=word.charAt(0);
		first=new Cell(word);
		last=first;
		left=null;
		right=null;
	}
	public void insertion(Node root,String word){
		if(root==null){
			return new Node(word);
		} else if(root.letter<word.charAt(0)){
			root.right=insertion(root.right,word);
		} else if(root.letter>word.charAt(0)){
			root.left=insertion(root.left,word);
		} else {
			root.first.insertOrdered(word);
		}
		return root;
	}
	public void remotion(Node root,String word)[
		if(root==null){
			return null;
		} else if(){

		} else if(){
			root.first.removeWord(root,word);
		}
	}
	public void insert(String word){
		root=insertion(root,word);
	}
	public void remove(String word){
		root=remotion(root,word);
	}
}
