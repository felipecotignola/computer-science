    import java.io.IOException;
    import java.util.Scanner;
    public class Main {
        static int binarySearch(int[] array,int target){
            int left=0,right=array.length-1,mid=(left+right+1)/2;
            while(left<=right){
                if(array[mid]==target){
                    int resp=mid;
                    mid--;
                    while(mid>=left && array[mid]==target){
                        resp=mid;
                        mid--;
                    }
                    return resp;
                }
                else{
                    if(array[mid]>target){
                        right=mid-1;
                        mid=(left+right+1)/2;
                    }
                    else{
                        left=mid+1;
                        mid=(left+right+1)/2;
                    }
                }
            }
            return -1;
        }
        public static void main(String[] args) throws IOException {
            Scanner sc=new Scanner(System.in);
            int n=sc.nextInt(),q=sc.nextInt(),cas=1;
            while(n!=0 && q!=0){
                System.out.println("CASE# "+cas);
                int[] marbles=new int[n],queries=new int[q];
                for(int i=0;i<n;i++){
                    marbles[i]=sc.nextInt();
                }
                for(int i=0;i<q;i++){
                    queries[i]=sc.nextInt();
                }
                for(int i=1;i<n;i++){
                    int key=marbles[i];
                    int k=i-1;
                    while(k>=0 && marbles[k]>key){
                        marbles[k+1]=marbles[k];
                        k--;
                    }
                    marbles[k+1]=key;
                }
                for(int i=0;i<q;i++){
                    int pos=binarySearch(marbles,queries[i]);
                    if(pos==-1){
                        System.out.printf("%d not found\n",queries[i]);
                    }
                    else{
                        System.out.printf("%d found at %d\n",queries[i],pos+1);
                    }
                }
                cas++;
                n=sc.nextInt();
                q=sc.nextInt();            
            }
     
        }
     
    }
