,class Data{
	private int dia,mes,ano;
	public Data(int dia,int mes,int ano){
		this.dia=dia;
		this.mes=mes;
		this.ano=ano;
	}
	public int getDia(){
		return dia;
	}
	public int getMes(){
		return mes;
	}
	public int getAno(){
		return ano;
	}
}
class Veiculo{
	private int id,ano,cilindros;
	private float cilindradas,consumoCidade,consumoEstrada,co2;
	private String marca,modelo,categoria,combustivel,transmissao,tracao;
	private	boolean turbo;
	private Data data;
	public Veiculo(int id,int ano,int cilindros,float cilindradas,float consumoCidade,float consumoEstrada,float co2,String marca,String modelo,String categoria,String combustivel,String transmissao,String tracao,boolean turbo,int dia,int mes,int ano2){
		this.id=id;
		this.ano=ano;
		this.cilindros=cilindros;
		this.cilindradas=cilindradas;
		this.consumoCidade=consumoCidade;
		this.consumoEstrada=consumoEstrada;
		this.co2=co2;
		this.marca=marca;
		this.modelo=modelo;
		this.categoria=categoria;
		this.combustivel=combustivel;
		this.transmissao=transmissao;
		this.tracao=tracao;
		this.turbo=turbo;
		this.data=new Data(dia,mes,ano2);	
	}
	public	int getId(){
		return id;
	}
	public int getAno(){
		return ano;
	}
	public int getCilindros(){
		return cilindros;
	}
	public float getCilindradas(){
		return cilindradas;
	}
	public float getConsumoCidade(){
		return consumoCidade;
	}
	public float getConsumoEstrada(){
		return consumoEstrada;
	}
	public float getCo2(){
		return co2;
	}
	public String getMarca(){
		return marca;
	}
	public String getModelo(){
		return modelo;
	}
	public String getCategoria(){
		return categoria;
	}
	public String getCombustivel(){
		return combustivel;
	}
	public String getTransmissao(){
		return transmissao;
	}
	public String getTracao(){
		return tracao;
	}
	public boolean getTurbo(){
		return turbo;
	}
	public Data getData(){
		return data;
	}
	
	
}
