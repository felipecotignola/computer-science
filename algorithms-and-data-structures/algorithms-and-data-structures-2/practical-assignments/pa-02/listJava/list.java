import java.util.Scanner;
class Data{
	private int ano;
	private int mes;
	private int dia;
	public Data(int ano,int mes,int dia){
		this.ano=ano;
		this.mes=mes;
		this.dia=dia;
	}	
	public static Data parseData(String s){
		String[] atributos=s.split('-');
		int ano=Integer.parseInt(atributos[0]);
		int mes=Integer.parseInt(atributos[1]);
		int dia=Integer.parseInt(atributos[2]);
		Data dataRegistro=new Data(ano,mes,dia);
		return dataRegistro;
	}
	public String format(){
		return String.format("%02d/%02d/%04d",dia,mes,ano);
	}
	public int getAno(){
		return ano;
	}
	public int getMes(){
		return mes;
	}
	public int getDia(){
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
	private double cilindrada;
	private String transmissao;
	private String tracao;
	private double consumoCidade;
	private double consumoEstrada;
	private double co2;
	private boolean turbo;
	private Data dataRegistro;
	public Veiculo(int id,String marca,String modelo,int ano,String categoria,String combustivel,int cilindros,double cilindrada,String transmissao,String tracao,double consumoCidade,double co2,boolean turbo,Data dataRegistro){
		this.id=id;
		this.marca=marca;
		this.modelo=modelo;
		this.ano=ano;
		this.categoria=categoria;
		this.combustivel=combustivel;
		this.cilindros=cilindros;
		this.cilindrada=cilindrada;
		this.transmissao=transmissao;
		this.tracao=tracao;
		this.consumoCidade=consumoCidade;
		this.consumoEstrada=consumoEstrada;
		this.co2=co2;
		this.turbo=turbo;
		this.dataRegistro=dataRegistro;
	}
	public Veiculo parseVeiculo(String s){
		String[] atributos=s.split(',');
		int id=Integer.parseInt(atributos[0]);
		String marca=atributos[1];
		String modelo=atributos[2];
		int ano=Integer.parseInt(atributos[3]);
		String categoria=atributos[4];
		String combustivel=atributos[5];
		int cilindros=Integer.parseInt(atributos[6]);
		double cilindrada=Double.parseDouble(atributos[7]);
		String transmissao=atributos[8];
		String tracao=atributos[9];
		double consumoCidade=Double.parseDouble(atributos[10]);
		double consumoEstrada=Double.parseDouble(atributos[11]);
		double co2=Double.parseDouble(atributos[12]);
		boolean turbo=Boolean.parseBoolean(atributos[13]);
		Data dataRegistro=parseData(atributos[14]);
		return new Veiculo(id,marca,modelo,ano,categoria,combustivel,cilindros,cilindrada,transmissao,tracao,consumoCidade,consumoEstrada,co2,turbo,dataRegistro);	
		
	} 
	public int getId(){
		return id;
	}
	public String getMarca(){
		return marca;
	}
	public String getModelo(){
		return modelo;
	}
	public int getAno(){
		return ano;
	}
	public String getCategoria(){
		return categoria;
	}
	public String getCombustivel(){
		return combustivel;
	}
	public int getCilindros(){
		return cilindros;
	}
	public double getCilindrada(){
		return cilindrada;
	}
	public String getTransmissao(){
		return transmissao;
	}
	public String getTracao(){
		return tracao;
	}
	public double getConsumoCidade(){
		return consumoCidade;
	}
	public double getConsumoEstrada(){
		return consumoEstrada;
	}
	public double getCo2(){
		return co2;
	}
	public boolean getTurbo(){
		return turbo;
	}
	public Data getDataRegistro(){
		return dataRegistro;
	}
	public String format(){
		return String.format("[%d ## %s  ## %s ## %d ## %s ## [%s] ## %d ## %f ## %s ## %s ## %s ## %f ## %f ## %f ## %b ## %s]",id,marca,modelo,ano,categoria,combustivel,cilindros,cilindrada,transmissao,tracao,consumoCidade,consumoEstrada,co2,turbo,dataRegistro.format());  
	}
	public void setConsumoCidade(double n){
		consumoCidade=n;
	}
	public void setConsumoEstrada(double n){
		consumoEstrada=n;
	}
	public void setCo2(double n){
		co2=n;
	}
	public static Veiculo search(Veiculo[] array,int id){
		for(int i=0;i<array.length;i++){
			if(array[i].getId()==id){
				return array[i];
			}
		}
	}
}
class LeitorCsv{
	public static Veiculo[] leitura(){
		int q=0;
		Scanner sc=new Scanner(new File(veiculos.csv))
		sc.nextLine();
		while(sc.hasNextLine()){
			sc.nextLine();
			q++;
		}
		sc.close;
		Veiculos[] veiculos=new Veiculos[q];
		sc=new Scanner(new File(veiculos.csv);
		int i=0;
		while(sc.hasNextLine()){
			String s=sc.nextLine();
			veiculos[i]=parseVeiculos(s);
			i++;
		}
		sc.close();
		return veiculos;
	}
}
class List{
	private Veiculo[] array;
	private int fim,capacidade;
	public list(Veiculo[] array){
		this.array=array;
		fim=0;
		capacidade=array.length;
	}
	void inserirInicio(Veiculo v){
		if(fim>=capacidade){
			return;
		}
		for(int i=fim;i>0;i--){
			Array[i+1]=array[i];
		}
		array[0]=v;
		fim++;
	}
	void inserirFim(Veiculo v){
		if(fim>=capacidade){
			return;
		}
		array[fim++]=v;
	}
	void inserirPos(Veiculo v,int pos){
		if(fim>=capacidade){
			return;
		}
		for(int i=fim;i>pos;i--){
			array[i]=array[i-1];
		}
		array[pos]=v;
		fim++;
	}
	int removerInicio(){
		if(fim<=0){
			return;
		}
		Veiculo resp=array[0];
		for(int i=0;i<fim-1;i++){
			array[i]=array[i+1];
		}
		fim--;
		return resp;
	}
	int removerFim(){
		if(fim<=0){
			return;
		}
		return array[--fim];
	}
	int removerPos(int pos){
		if(fim<=0){
			return;
		}
		int resp=array[pos];
		for(int i=pos;i<fim;i++){
			array[i]=array[i+1];
		}
		fim--;
		return resp;
	}
	void print(){
		for(int i=0;i<fim;i++){
			printf("%s\n",array[i].formatVeiculo());
		}
	}	
}
public class list{
	public static void main(String[] args){
		Veiculo[] array=leitorCsv();
		List lista=new List(array);
		for(int i=0;i<array.length;i++){
			lista.inserirFim(array[i]);
		}	
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++){
			String operacao=sc.next();
			switch(operacao){
				case "II":
					int id=sc.nextInt();
					Veiculo v=search(array,id);
					lista.inserirInicio(v);
					break;
				case "I*":
					int pos=sc.nextInt(),id=sc.nextInt();
					Veiculo v=search(array,id);
					lista.inserirPos(v,pos);
					break;
				case"IF":
					int id=sc.nextInt();
					Veiculo v=search(array,id);
					lista.inserirFim(v);
					break;
				case "RI":
					Veiculo v=lista.removerInicio();
					System.out.printf("%s\n",v.format());
					break;
				case "R*":
					int pos=sc.nextInt();
					Veiculo v=lista.removerPos(pos);
					System.out.printf("%s\n",v.format());
					break;
				case "RF":
					Veiculo v=lista.removerFim();
					System.out.printf("%s\n",v.format());	
			}	
		}
	}
}
