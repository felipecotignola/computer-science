	import java.util.Scanner;
	public class caeser_cypher{
		public static String cypher(String string){
			String s="";
			//inicializo um objeto de String vazio
			for(int i=0;i<string.length();i++){
				char c=(char)(string.charAt(i)+3);
				//pego o caractere atual e somo 3 
				s+=c;
				//como string eh um objeto em Java quando eu faço s+= eu to criando uma nova String com o valor da antiga mais o caractere atual
			}
			return s;
		}
		public static void main(String[] args){
			Scanner sc=new Scanner(System.in);
			String string=sc.nextLine();
			while(string.charAt(0)!='F' && string.charAt(1)!='I' && string.charAt(2)!='M'){
				System.out.printf("%s\n",cypher(string));
				string=sc.nextLine();
			}		
		}
	}
