	import java.util.Scanner;
	public class is{
		static boolean isLetra(String s){
			int l=s.length();
			for(int i=0;i<l;i++){
				if(!(s.charAt(i)>='A' && s.charAt(i)=='Z' || s.charAt(i)>='a' &&s.charAt(i)<='z')){
					return false;
				}
			}
			return true;
		}
		static boolean isVogal(String s){
			if(isLetra(s)){
				int c=0,l=s.length();
				for(int i=0;i<l;i++){
					if(s.charAt(i)=='a' || s.charAt(i)=='e'|| s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u'||s.charAt(i)=='A'||s.charAt(i)=='E'||s.charAt(i)=='I'||s.charAt(i)=='O'||s.charAt(i)=='U'){
						c++;
					}
				}
				if(c==l){
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
		static boolean isConsoante(String s){
			if(isLetra(s)){
				int l=s.length();
				for(int i=0;i<l;i++){
                                	if(s.charAt(i)=='a' || s.charAt(i)=='e'|| s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u'||s.charAt(i)=='A'||s.charAt(i)=='E'||s.charAt(i)=='I'||s.charAt(i)=='O'||s.charAt(i)=='U'){
						return false;	
					}
				}
				return true;	
			}
			else{
				return false;	
			}
		}
		static boolean isInt(String s){
			 int l=s.length();
			 for(int i=0;i<l;i++){
				if(s.charAt(i)>'9'|| s.charAt(i)<'0'){											return false;
				}
			}
			return true;			
		}
		static boolean isReal(String s){
			int l=s.length(),dot=0,n=0;
			for(int i=0;i<l;i++){
				if(s.charAt(i)=='.'||s.charAt(i)==','){
					dot++;	
				}
				else if(s.charAt(i)<'0' || s.charAt(i)>'9'){
					return false;
				}
			}
			if(dot!=1){
				return false;
			}
			return true;
		}
		
		
			
		public static void main(String[] args){
			Scanner sc=new Scanner(System.in);
			String s=sc.nextLine();
			while(!(s.length()==3 && s.charAt(0)=='F' && s.charAt(1)=='I' && s.charAt(2)=='M')){
				if(isVogal(s)){
					System.out.print("SIM ");
				}
				else{
					System.out.print("NAO ");
				}
				if(isConsoante(s)){
					System.out.print("SIM ");
				}
				else{
					System.out.print("NAO ");
				}	
				if(isInt(s)){
					System.out.print("SIM ");	
				}	
				else{
					System.out.print("NAO ");
				}
				if(isReal(s)){
					System.out.print("SIM ");
				}
				else{
					System.out.print("NAO ");
				}
				System.out.println();
				s=sc.nextLine();
			}
		}
	}
