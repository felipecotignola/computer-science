class Data{
	private int dia,mes,ano;
	public Data(int ano,int mes, int dia){
		this.ano=ano;
		this.mes=mes;
		this.dia=dia;
	}
	public static Data parseData(String s){
		String[] atributos=s.Split('-');
		int ano=Integer.parseInt(atributos[0]);
		int mes=Integer.parseInt(atributos[1]);
		int dia=Integer.parseInt(atributos[2]);
		Data data=new Data(ano,mes,dia);		
		return data;
	}
	int getAno(){
		return ano;
	}
	int getMes(){
		return mes;
	}
	int getDia(){
		return dia;
	}	
}
class Veiculo{
	private int id;
	private String marca;
	private String modelo;
	private int ano;
	private String categoria;
	private String combustivel;
	private int cilindros;
	private float cilindrada;
	private String transmissao;
	private String tracao;
	private float consumoCidade;
	private float consumoEstrada;
	private float co2;
	private boolean turbo;
	private Data data;
	public Veiculo(int id,String marca,String modelo, int ano,String categoria,String combustivel,int cilindros,float cilindrada,String transmissao,String tracao,float consumoCidade,float consumoEstrada,float co2,boolean turbo,Data data){
		this.id=id;
		this.marca=marca;
		this.modelo=modelo;
		this.ano=ano;
		this.categoria=categoria;
		this.combustivel=combustivel;
		this.cilindro=cilindro;
		this.cilindrada=cilindrada;
		this.transmissao=transmissao;
		this.tracao=tracao;
		this.consumoCidade=consumoCidade;
		this.consumoEstrada=consumoEstrada;
		this.co2=co2;
		this.turbo=turbo;
		this.data=data;	
	}
	public static void parseVeiculo(String s){
		String[] atributos= String.split(',');
		int id=Integer.parseInt(atributos[0]);
		String marca=atributos[1];
		String modelo=atributos[2];
		int ano=Integer.parseInt(atributos[3]);
		String categoria=atributos[4];
		String combustivel=atributos[5];
		int cilindro=Integer.parseInt(atributos[6]);
		float cilindradas=Float.parseFloat(atributos[7]);
		String transmissao=atributos[8];
		String tracao=atributos[9];
		float consumoCidade=Float.parseFloat(atributos[10]);
		float consumoEstrada=Float.parseFloat(atributos[11]);
		float co2=Float.parseFloat(atributos[12]);
		boolean turbo=Boolean.parseBoolean(atributos[13]);	
		Data data=Data parseData(atributos[14]);
			
	}	
}
