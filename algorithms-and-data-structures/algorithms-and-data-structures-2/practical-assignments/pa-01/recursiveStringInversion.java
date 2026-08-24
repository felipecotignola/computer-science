	import java.util.Scanner;
	public class recursiveStringInversion{
		static String recursion(String str,int index){
			if(index==0){
				return  ""+str.charAt(index);
			}
			String string="";
			string=str.charAt(index)+recursion(str,index-1);
			return string;
		}
		public static void main(String[] args){
			Scanner sc=new Scanner(System.in);
			String string=sc.nextLine();
			System.out.printf("%s\n",recursion(string,(string.length())-1)); 	
		}
	}
