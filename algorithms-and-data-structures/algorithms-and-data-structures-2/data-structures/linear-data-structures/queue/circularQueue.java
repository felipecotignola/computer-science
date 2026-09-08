	class Queue{
		int[] array;
		int capacidade,quantidade;
		public Queue(int n){
			array=new int[n];
			capacidade=n;
			quantidade=0;
		}
		void inserir(int n){
			if(quantidade==capacidade){
				return;
			}	
			array[quantidade]=n;
			quantidade=quantidade+1%capacidade;
		}
		int remover(){
			if(quantidade==0){
				return -1;
			}
			quantidade--;
			return array[inicio++];	
		}
	}
