	import java.util.Scanner;
	public class passwordValidation{	
		public static boolean validation(String string){
			//verifico se tem o tamanho minimo;
			if(string.length()>=8){
				int upperCase=0,lowerCase=0,number=0,specialChar=0;
				//contadores de requisitos
				for(int i=0;i<string.length();i++){
					if(string.charAt(i)>=65 && string.charAt(i)<=90){
						upperCase++;
					}
					else if(string.charAt(i)>=97 && string.charAt(i)<=122){
						lowerCase++;
					}
					else if(string.charAt(i)>=48 && string.charAt(i)<=57){
						number++;
					}
					else{
						specialChar++;
					}
				}
				//se atender aos pre requisitos retorna true pq eu ja sei q tem o tamanho minimo entao todas as necessidades foram cumpridas
				if(upperCase!=0 && lowerCase!=0 && number!=0 && specialChar!=0){
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
		public static void main(String[] args){
			Scanner sc=new Scanner(System.in);
			String s=sc.next();
			if(validation(s)){
				System.out.println("SIM");
			}
			else{
				System.out.println("NAO");	
			}	
		}
	}
