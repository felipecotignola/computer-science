import java.util.Scanner;
class Runner{
	String name;
	int h,m,s;
	public Runner(String name,int h,int m,int s){
		this.name=name;
		this.h=h;
		this.m=m;
		this.s=s;
	}
	public static boolean condition(Runner r, Runner key){
		if(r.h>key.h){
			return true;	
		}
		else if (r.h==key.h){
			if(r.m>key.m){
				return true;
			}		
			else if(r.m==key.m){
				if(r.s>key.s){
					return true;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		} 
		else{
			return false;
		}
	}
	
	public static void sort(Runner[] array, int k){
		for(int i=1;i<array.length;i++){
			Runner key=array[i];
			int j;
			if(i<k){
				j=i-1;	
			} else{
				j=k-1;
			}
			
			while(j>=0 && condition(array[j],key)){
				array[j+1]=array[j];
				j--;
			} 
			array[j+1]=key;
		}
	}
	
	public void print(){
		System.out.printf("%s %d %d %d\n",name,h,m,s);
	}
	
}
public class main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			int n=sc.nextInt();
			Runner[] array=new Runner[n];
			int k=sc.nextInt();
			String name;
			int h,m,s;
			for(int i=0;i<n;i++){
				name=sc.next();
				h=sc.nextInt();
				m=sc.nextInt();
				s=sc.nextInt();
				array[i]=new Runner(name,h,m,s);
			}
			Runner.sort(array,k);
			for(int i=0;i<k;i++){
				array[i].print();
			}		
		}
	}
}
