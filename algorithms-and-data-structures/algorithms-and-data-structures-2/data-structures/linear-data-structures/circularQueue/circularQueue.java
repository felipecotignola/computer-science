	class Queue{
		int[] array;
		int inicio,poscapacidade,quantidade;
		public Queue(int n){
			array=new int[n];
			capacidade=n;
			quantidade=0;
			inicio=0;
			pos=0;
		}
		void inserir(int n){
			if(quantidade==capacidade){
				return;
			}	
			array[pos]=n;
			pos=pos+1%capacidade;
		}
		int remover(){
			if(quantidade==0){
				return -1;
			}
			quantidade--;
			return array[inicio++];	
		}
	}
