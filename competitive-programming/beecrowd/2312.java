import java.io.IOException;
import java.util.Scanner;

class Country{
    String nome;
    int gold,silver,bronze;
    public Country(String nome,int g,int s,int b){
        gold=g;
        silver=s;
        bronze=b;
        this.nome=nome;
    }
    
}
public class Main {
    static boolean check(Country chave,Country k){
        if(chave.gold!=k.gold){
            return k.gold<chave.gold;
        }
        else if(chave.silver!=k.silver){
            return k.silver<chave.silver;
        }
        else if(chave.bronze!=k.bronze){
            return k.bronze<chave.bronze;
        }
        else{
            return k.nome.compareTo(chave.nome)>0;
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.nextLine();
        Country[] array=new Country[n];
        for(int i=0;i<n;i++){
                String nome=sc.next();
                int gold=sc.nextInt(),silver=sc.nextInt(),bronze=sc.nextInt();
                sc.nextLine();
                array[i]=new Country(nome,gold,silver,bronze);
        }
        for(int j=1;j<n;j++){
            Country chave=array[j];
            int k=j-1;
            while(k>=0 && check(chave,array[k])){
                array[k+1]=array[k];
                k--;
            }
            array[k+1]=chave;
        }
        for(int i=0;i<n;i++){
            System.out.printf("%s %d %d %d\n",array[i].nome,array[i].gold,array[i].silver,array[i].bronze);
        }
        
        
    }
 
}
