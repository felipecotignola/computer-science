	class List{
		private int[] lista;
		private int tamanho,capacidade;
		public List(int n,int c){
			tam=0;
			lista=new int[n];
			capacidade=c;
		}
		void inserirInicio(int n){
			if(tamanho>=capacidade){
				return;	
			}
			for(int i=tamanho;i>0;i--){
				lista[i]=lista[i-1];
			}
			lista[0]=n;
			tamanho++;
		}
		void inserirFim(int n){
			if(tamanho>=capacidade){
				return;
			}
			lista[tamanho]=n;
			tamanho++;
		}
		void inserirPos(int n,int pos){
			if(tamanho>=capacidade ||pos<0 ||pos>tamanho){
				return;
			}
			for(int i=tamanho;i>pos;i--){
				lista[i]=lista[i-1];
			}
			lista[pos]=n;
			tam++;		
		}
		int removerInicio(){
			if(tamanho==0){
				return;
			}
			int resp=array[0];
			tamanho--;
			for(int i=0;i<tamanho;i++){
				lista[i]=lista[i+1];	
			}
			return resp;
		}	
		int removerFim(){
			if(tamanho==0){
				return;
			}
			return lista[--tamanho];	
		}
		int removerPos(int pos){
			if(tamanho==0 || pos<0|| pos>=tamanho){
				return;
			}
			int resp=lista[pos];
			tamanho--;
			for(int i=pos;i<tamanho;i++){
				lista[i]=lista[i+1];
			}
			return resp;
		}
		void print(){
			System.out.print("[ ");
			for(int i=0;i<tamanho;i++){
				System.out.print(lista[i]+" ");
			}
			System.out.print(" ]");
		}	
	}
