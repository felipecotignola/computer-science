import java.util.Scanner;
import java.io.File;

//classe data
class Data {
    private int ano;
    private int mes;
    private int dia;

    //construtor data
    public Data(int ano, int mes, int dia) {
        this.ano = ano;
        this.mes = mes;
        this.dia = dia;
    }
    
    //parse data
    public static Data parseData(String s) {
        String[] atributos = s.split("-");
        int ano = Integer.parseInt(atributos[0]);
        int mes = Integer.parseInt(atributos[1]);
        int dia = Integer.parseInt(atributos[2]);
        return new Data(ano, mes, dia);
    }
    
    //formatar data
    public String format() {
        return String.format("%02d/%02d/%04d", dia, mes, ano);
    }
    
    //metodos getter Data
    public int getAno() { return ano; }
    public int getMes() { return mes; }
    public int getDia() { return dia; }
}

//classe veiculo
class Veiculo {
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
   
    //construtor veiculo
    public Veiculo(int id, String marca, String modelo, int ano, String categoria, String combustivel, int cilindros, double cilindrada, String transmissao, String tracao, double consumoCidade, double consumoEstrada, double co2, boolean turbo, Data dataRegistro) {
        this.id = id;
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.categoria = categoria;
        this.combustivel = combustivel;
        this.cilindros = cilindros;
        this.cilindrada = cilindrada;
        this.transmissao = transmissao;
        this.tracao = tracao;
        this.consumoCidade = consumoCidade;
        this.consumoEstrada = consumoEstrada;
        this.co2 = co2;
        this.turbo = turbo;
        this.dataRegistro = dataRegistro;
    }

    //parse veiculo
    public static Veiculo parseVeiculo(String s) {
        String[] atributos = s.split(",");
        int id = Integer.parseInt(atributos[0]);
        String marca = atributos[1];
        String modelo = atributos[2];
        int ano = Integer.parseInt(atributos[3]);
        String categoria = atributos[4];
        String combustivel = atributos[5];
        int cilindros = Integer.parseInt(atributos[6]);
        double cilindrada = Double.parseDouble(atributos[7]);
        String transmissao = atributos[8];
        String tracao = atributos[9];
        double consumoCidade = Double.parseDouble(atributos[10]);
        double consumoEstrada = Double.parseDouble(atributos[11]);
        double co2 = Double.parseDouble(atributos[12]);
        boolean turbo = Boolean.parseBoolean(atributos[13]);
        Data dataRegistro = Data.parseData(atributos[14]);
        return new Veiculo(id, marca, modelo, ano, categoria, combustivel, cilindros, cilindrada, transmissao, tracao, consumoCidade, consumoEstrada, co2, turbo, dataRegistro);
    }
	
    //getter Veiculo
    public int getId() { return id; }
    public String getMarca() { return marca; }
    public String getModelo() { return modelo; }
    public int getAno() { return ano; }
    public String getCategoria() { return categoria; }
    public String getCombustivel() { return combustivel; }
    public int getCilindros() { return cilindros; }
    public double getCilindrada() { return cilindrada; }
    public String getTransmissao() { return transmissao; }
    public String getTracao() { return tracao; }
    public double getConsumoCidade() { return consumoCidade; }
    public double getConsumoEstrada() { return consumoEstrada; }
    public double getCo2() { return co2; }
    public boolean getTurbo() { return turbo; }
    public Data getDataRegistro() { return dataRegistro; }

    //formatar veiculo
    public String format() {
        return String.format("[%d ## %s ## %s ## %d ## %s ## %s ## %d ## %f ## %s ## %s ## %f ## %f ## %f ## %b ## %s]", id, marca, modelo, ano, categoria, combustivel, cilindros, cilindrada, transmissao, tracao, consumoCidade, consumoEstrada, co2, turbo, dataRegistro.format());
    }

    //setters veiculo
    public void setConsumoCidade(double n) { consumoCidade = n; }
    public void setConsumoEstrada(double n) { consumoEstrada = n; }
    public void setCo2(double n) { co2 = n; }
}

//classe leitorCsv
class LeitorCsv {
    public static Veiculo[] leitorCsv() { 
	File input=new File("/tmp/veiculos.csv");
	Scanner sc = new Scanner(input);
	sc.nextLine(); // Cabeçalho
	int q=0;
	//quantas linhas tem
        while (sc.hasNextLine()) {
            sc.nextLine();
            q++;
        }
        sc.close();

        Veiculo[] veiculos = new Veiculo[q];
        sc = new Scanner(input);
        sc.nextLine(); // Cabeçalho
        int i = 0;
        while (sc.hasNextLine()) {
            String s = sc.nextLine();
            veiculos[i] = Veiculo.parseVeiculo(s);
           i++;
        }
        sc.close();
        return veiculos;
    }
}
public class Main{
	public static void main(String[] args){
		Veiculo[] veiculos=LeitorCsv.leitorCsv();
	}
}
