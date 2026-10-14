import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.nextLine();
        for(int i=0;i<n;i++){
            String[] vet=new String[50];
            int vetIndex=0;
            String string=sc.nextLine(),s="";
            for(int j=0;j<string.length();j++){
                if(string.charAt(j)==' '){
                    vet[vetIndex++]=s;
                    s="";
                }
                else{
                    s+=string.charAt(j);
                }
            }
            vet[vetIndex]=s;
            for(int j=1;j<=vetIndex;j++){
                String key=vet[j];
                int l=j-1;
                while(l>=0 && key.length()>vet[l].length()){
                    vet[l+1]=vet[l];
                    l--;
                }
                vet[l+1]=key;
            }
            for(int j=0;j<=vetIndex;j++){
                System.out.printf("%s ",vet[j]);
            }
            System.out.println();
        }
    }
 
}
