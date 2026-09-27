import java.io.File;
import java.util.Locale;
import java.util.Scanner;

class Data {
    private int ano;
    private int mes;
    private int dia;

    public Data(int ano, int mes, int dia) {
        this.ano = ano;
        this.mes = mes;
        this.dia = dia;
    }
    
    public static Data parseData(String s) {
        String[] atributos = s.split("-");
        int ano = Integer.parseInt(atributos[0].trim());
        int mes = Integer.parseInt(atributos[1].trim());
        int dia = Integer.parseInt(atributos[2].trim());
        return new Data(ano, mes, dia);
    }
    
    public String format() {
        return String.format(Locale.US, "%02d/%02d/%04d", dia, mes, ano);
    }
    
    public int getAno() { return ano; }
    public int getMes() { return mes; }
    public int getDia() { return dia; }
}

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

    public static Veiculo parseVeiculo(String s) {
        String[] atributos = s.split(",");
        int id = Integer.parseInt(atributos[0].trim());
        String marca = atributos[1].trim();
        String modelo = atributos[2].trim();
        int ano = Integer.parseInt(atributos[3].trim());
        String categoria = atributos[4].trim();
        String combustivel = atributos[5].trim();
        int cilindros = Integer.parseInt(atributos[6].trim());
        double cilindrada = Double.parseDouble(atributos[7].trim());
        String transmissao = atributos[8].trim();
        String tracao = atributos[9].trim();
        double consumoCidade = Double.parseDouble(atributos[10].trim());
        double consumoEstrada = Double.parseDouble(atributos[11].trim());
        double co2 = Double.parseDouble(atributos[12].trim());
        boolean turbo = Boolean.parseBoolean(atributos[13].trim());
        Data dataRegistro = Data.parseData(atributos[14].trim());
        return new Veiculo(id, marca, modelo, ano, categoria, combustivel, cilindros, cilindrada, transmissao, tracao, consumoCidade, consumoEstrada, co2, turbo, dataRegistro);
    }
	
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

    public String format() {
        return String.format(Locale.US, "[%d ## %s ## %s ## %d ## %s ## %s ## %d ## %f ## %s ## %s ## %f ## %f ## %f ## %b ## %s]", id, marca, modelo, ano, categoria, combustivel, cilindros, cilindrada, transmissao, tracao, consumoCidade, consumoEstrada, co2, turbo, dataRegistro.format());
    }

    public void setConsumoCidade(double n) { consumoCidade = n; }
    public void setConsumoEstrada(double n) { consumoEstrada = n; }
    public void setCo2(double n) { co2 = n; }
}

class LeitorCsv {
    public static Veiculo[] leitura() {
        try {
            File csv = new File("veiculos.csv");
            Scanner sc = new Scanner(csv);
            sc.nextLine();
            int q = 0;
            while (sc.hasNextLine()) {
                sc.nextLine();
                q++;
            }
            sc.close();

            Veiculo[] veiculos = new Veiculo[q];
            sc = new Scanner(csv);
            sc.nextLine();
            int i = 0;
            while (sc.hasNextLine()) {
                String s = sc.nextLine();
                veiculos[i] = Veiculo.parseVeiculo(s);
                i++;
            }
            sc.close();
            return veiculos;
        } catch (Exception e) {
            return new Veiculo[0];
        }
    }
}

class List {
    int fim, quantidade, capacidade;
    Veiculo[] array;

    public List(int capacidade) {
        array = new Veiculo[capacidade];
        this.capacidade = capacidade;
        fim = 0;
        quantidade = 0;
    }

    void inserirInicio(Veiculo v) {
        if (quantidade < capacidade) {
            for (int i = fim; i > 0; i--) {
                array[i] = array[i - 1];
            }    
            array[0] = v;
            quantidade++;
            fim++;
        }
    }

    void inserirFim(Veiculo v) {
        if (quantidade < capacidade) {
            array[fim++] = v;
            quantidade++;
        }
    }

    void inserirPos(Veiculo v, int pos) {
        if (quantidade < capacidade && pos >= 0 && pos <= fim) {
            for (int i = fim; i > pos; i--) {
                array[i] = array[i - 1];
            }
            array[pos] = v;
            fim++;
            quantidade++;
        }
    }

    Veiculo removerInicio() {
        if (quantidade > 0) {
            Veiculo resp = array[0];
            for (int i = 0; i < fim - 1; i++) {
                array[i] = array[i + 1];
            }
            array[fim - 1] = null;
            fim--;
            quantidade--;
            return resp;
        }
        return null;
    }

    Veiculo removerFim() {
        if (quantidade > 0) {
            Veiculo resp = array[--fim];
            array[fim] = null;
            quantidade--;
            return resp;
        }
        return null;
    }

    Veiculo removerPos(int pos) {
        if (quantidade > 0 && pos >= 0 && pos < fim) {
            Veiculo resp = array[pos];
            for (int i = pos; i < fim - 1; i++) {
                array[i] = array[i + 1];
            }
            array[fim - 1] = null;
            quantidade--;
            fim--;
            return resp;
        }
        return null;
    }

    void print() {
        if (quantidade > 0) {
            for (int i = 0; i < fim; i++) {
                System.out.println(array[i].format());
            }
        }
    }
}

public class list {
    public static Veiculo getVeiculo(int id, Veiculo[] array) {
        for (int i = 0; i < array.length; i++) {
            if (array[i].getId() == id) {
                return array[i];
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Veiculo[] array = LeitorCsv.leitura();
        List l = new List(array.length + 100);
        Scanner sc = new Scanner(System.in);

        if (sc.hasNext()) {
            String comando = sc.next();
            while (!comando.equals("FIM")) {
                int id = Integer.parseInt(comando);
                Veiculo v = getVeiculo(id, array);
                if (v != null) {
                    l.inserirFim(v);
                }
                if (sc.hasNext()) {
                    comando = sc.next();
                } else {
                    break;
                }
            }
        }

        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                String comando = sc.next();
                Veiculo removido;
                if (comando.equals("II")) {
                    int id = sc.nextInt();
                    Veiculo v = getVeiculo(id, array);
                    l.inserirInicio(v);    
                } else if (comando.equals("IF")) {
                    int id = sc.nextInt();
                    Veiculo v = getVeiculo(id, array);
                    l.inserirFim(v);
                } else if (comando.equals("I*")) {
                    int pos = sc.nextInt();
                    int id = sc.nextInt();
                    Veiculo v = getVeiculo(id, array);
                    l.inserirPos(v, pos);
                } else if (comando.equals("RI")) {
                    removido = l.removerInicio();
                    if (removido != null) {
                        System.out.println("(R) " + removido.getMarca() + " " + removido.getModelo());    
                    }
                } else if (comando.equals("RF")) {
                    removido = l.removerFim();
                    if (removido != null) {
                        System.out.println("(R) " + removido.getMarca() + " " + removido.getModelo()); 
                    }
                } else if (comando.equals("R*")) {
                    int pos = sc.nextInt();
                    removido = l.removerPos(pos);
                    if (removido != null) {
                        System.out.println("(R) " + removido.getMarca() + " " + removido.getModelo()); 
                    }    
                }
            }
        }
        l.print();
        sc.close();
    }
}