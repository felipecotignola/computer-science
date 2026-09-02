	class Queue{
		int[] array;
		int inicio,fim,capacidade,quantidade;
		public Queue(int n){
			array=new int[n+1];
			inicio=0;
			fim=-1;
			capacidade=n;
			quantidade=0;
		}
		void inserir(int n){
			if(quantidade==capacidade){
				return;
			}	
			array[(++fim%capacidade)]=n;
			quantidade++;
		}
		int remover(){
			if(quantidade==0){
				return -1;
			}
			quantidade--;
			return array[inicio++];	
		}
	}
