	import java.util.Scanner;
	import java.util.Random;
	
	public class randomSort{
		static String randomSort(String string,Random gerador){
			//O caractere a representa o caractere que sera substituido e o b representa o que ira substituir o a
			char a=((char)+('a'+(Math.abs(gerador.nextInt())) %26)),b=((char)+('a'+(Math.abs(gerador.nextInt()))%26));
			//como em java em String eh imutavel eu  crio uma vazia e vou concatenando ela	
			String str="";
			int tam=string.length();
			for(int i=0;i<tam;i++){
				//se o caractere o A aparecer eu vou adicionar o caractere B na string
				if(string.charAt(i)==a){
					str+=b;
				}
				else{
					//se o caractere atual n for o A eu adiciono o caractere atual original da String
					str+=string.charAt(i);	
				}
			}
			return str;	
		}
		public static void main(String[] args){
			Scanner sc=new Scanner(System.in);
			Random gerador=new Random();
			gerador.setSeed(4);
			String string=sc.nextLine();
			while(!(string.length()==3 && string.charAt(0)=='F' && string.charAt(1)=='I' && string.charAt(2)=='M')){
				System.out.printf("%s\n",randomSort(string,gerador));
				string=sc.nextLine();
			}
		}
	}
