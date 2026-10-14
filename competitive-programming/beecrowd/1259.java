import java.io.IOException;
import java.util.Scanner;
public class Main {
 
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] even=new int[n];
        int[] odd=new int[n];
        int evenIndex=0,oddIndex=0;
        for(int l=0;l<n;l++){
            int number=sc.nextInt();
            if(number%2==0){
                even[evenIndex]=number;
                evenIndex++;
            }
            else{
                odd[oddIndex]=number;
                oddIndex++;
            }
        }
        for(int i=1;i<evenIndex;i++){
            int key=even[i];
            int k=i-1;
            while(k>=0 && even[k]>key){
                even[k+1]=even[k];
                k--;
            }
            even[k+1]=key;
        }
        for(int i=1;i<oddIndex;i++){
            int key=odd[i];
            int k=i-1;
            while(k>=0 && odd[k]<key){
                odd[k+1]=odd[k];
                k--;
            }
            odd[k+1]=key;
        }
        for(int i=0;i<evenIndex;i++){
            System.out.println(even[i]);
        }
        for(int i=0;i<oddIndex;i++){
            System.out.println(odd[i]);
        }
    }
 
}
