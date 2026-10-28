import java.util.Scanner;
class Aluno{
	int nota,falta;
	String nome;
	public Aluno(int n,int f,String nome){
		nota=n;
		falta=f;
		this.nome=nome;
	}
}
public class main{
	public static int check(Aluno a,int nota,int falta,String nome){
		if(a.nota>nota){return -1;}
		if(a.nota<nota){return 1;}
		if(a.falta<falta){return -1;}
		if(a.falta>falta){return 1;}
		return (a.nome).compareTo(nome);
	}
	public static void quicksort(Aluno[] array,int esq,int dir,int k){
		int i=esq;
		int j=dir;	
		int pNota=array[(esq+dir)/2].nota;
		int pFalta=array[(esq+dir)/2].falta;
		String pNome=array[(esq+dir)/2].nome;
		while(i<=j){
			while(i<=j && check(array[i],pNota,pFalta,pNome)<0){
				i++;
			}
			while(i<=j && check(array[j],pNota,pFalta,pNome)>0){
				j--;
			}
			if(i<=j){
				Aluno tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
				i++;
				j--;
			}
		}
		if(esq<j){
			quicksort(array,esq,j,k);
		}	
		if(i<k && i<dir){
			quicksort(array,i,dir,k);
		}		
	}
	public static void print(Aluno[] array,int k){
		for(int i=0;i<k;i++){
			System.out.printf("%d %d %s\n",array[i].nota,array[i].falta,array[i].nome);
		}
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			int n=sc.nextInt();
			int k=sc.nextInt();
			int nota,falta;
			String nome;
			Aluno[] array=new Aluno[n];
			for(int i=0;i<n;i++){
				nota=sc.nextInt();
				falta=sc.nextInt();
				nome=sc.nextLine();
				array[i]=new Aluno(nota,falta,nome);
			}
			quicksort(array,0,n-1,k);
			print(array,k);
		}
	}
}
