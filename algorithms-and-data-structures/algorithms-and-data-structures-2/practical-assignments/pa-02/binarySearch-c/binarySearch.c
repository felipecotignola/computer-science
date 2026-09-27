#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct Data
typedef struct {
    int ano;
    int mes;
    int dia;
} Data;

//strcpy
void strcopy(char* dest, char* origem) {
    while (*origem != '\0') {
        *dest = *origem;
        dest++;
        origem++;
    }
    *dest = '\0';
}

//construtor Data
void DataConstrutor(Data* data, int ano, int mes, int dia) {
    data->ano = ano;
    data->mes = mes;
    data->dia = dia;
}

//parse Data
Data parseData(char* str) {
    Data data;
    sscanf(str, "%d-%d-%d", &data.ano, &data.mes, &data.dia);
    return data;
}

//getters Data
int getAnoData(Data* data) { return data->ano; }
int getMesData(Data* data) { return data->mes; }
int getDiaData(Data* data) { return data->dia;}

//formatar Data
void formatData(Data* data, char* str) {
    sprintf(str, "%02d-%02d-%04d", data->dia, data->mes, data->ano);
}

//struct Veiculo
typedef struct {
    int id;
    char marca[256];
    char modelo[256];
    int ano;
    char categoria[256];
    char combustivel[256];
    int cilindros;
    double cilindrada;
    char transmissao[256];
    char tracao[256];
    double consumoCidade;
    double consumoEstrada;
    double co2;
    int turbo;
    Data dataRegistro;
} Veiculo;

//parse Veiculo
Veiculo parseVeiculo(char* str) {
    char* atributos[15];
    atributos[0] = strtok(str, ",");
    int i = 1;
    while (i < 15) {
        atributos[i] = strtok(NULL, ",");
        i++;
    }
    Veiculo strct;
    strct.id = atoi(atributos[0]);
    strcopy(strct.marca, atributos[1]);
    strcopy(strct.modelo, atributos[2]);
    strct.ano = atoi(atributos[3]);
    strcopy(strct.categoria, atributos[4]);
    strcopy(strct.combustivel, atributos[5]);
    strct.cilindros = atoi(atributos[6]);
    strct.cilindrada = atof(atributos[7]);
    strcopy(strct.transmissao, atributos[8]);
    strcopy(strct.tracao, atributos[9]);
    strct.consumoCidade = atof(atributos[10]);
    strct.consumoEstrada = atof(atributos[11]);
    strct.co2 = atof(atributos[12]);
    strct.turbo = (strcmp(atributos[13], "true") == 0);
    strct.dataRegistro = parseData(atributos[14]);
    return strct;
}

//getters Veiculo
int getId(Veiculo* strct) { return strct->id; }
char* getMarca(Veiculo* strct) { return strct->marca; }
char* getModelo(Veiculo* strct) { return strct->modelo; }
int getAnoVeiculo(Veiculo* strct){ return strct->ano; }
char* getCategoria(Veiculo* strct) { return strct->categoria; }
char* getCombustivel(Veiculo* strct) { return strct->combustivel; }
int getCilindros(Veiculo* strct) { return strct->cilindros; }
double getCilindrada(Veiculo* strct) { return strct->cilindrada; }
char* getTransmissao(Veiculo* strct) { return strct->transmissao; }
char* getTracao(Veiculo* strct) { return strct->tracao; }
double getConsumoCidade(Veiculo* strct) { return strct->consumoCidade; }
double getConsumoEstrada(Veiculo* strct) { return strct->consumoEstrada; }
double getCo2(Veiculo* strct) { return strct->co2; } 
int getTurbo(Veiculo* strct) { return strct->turbo; }
Data getDataRegistro(Veiculo* strct) { return strct->dataRegistro; }

//setters Veiculo
void setConsumoCidade(Veiculo* strct, double n) { strct->consumoCidade = n; }
void setConsumoEstrada(Veiculo* strct, double n) { strct->consumoEstrada = n; }
void setCo2(Veiculo* strct, double n) { strct->co2 = n; }

//format Veiculo
void formatVeiculo(Veiculo* veiculo, char* str) {
    char* turbo;
    if (veiculo->turbo == 1) {
        strcopy(turbo, "true");
    } else {
        strcopy(turbo, "false");
    }
    char* dataStr;
    formatData(&(veiculo->dataRegistro), dataStr);
    sprintf(str, "[%d ## %s ## %s ## %d ## %s ## %s ## %d ## %lf ## %s ## %s ## %lf ## %lf ## %lf ## %s ## %s]", getId(veiculo), getMarca(veiculo), getModelo(veiculo), getAnoVeiculo(veiculo), getCategoria(veiculo), getCombustivel(veiculo), getCilindros(veiculo), getCilindrada(veiculo), getTransmissao(veiculo), getTracao(veiculo), getConsumoCidade(veiculo), getConsumoEstrada(veiculo), getCo2(veiculo), turbo, dataStr);
}

//get size
int size(char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

//ler linha
int readline(char* str, int tam, FILE* csv) {
    if (fgets(str, tam, csv) == NULL) {
        return 0;
    }
    int len=size(str);
    if(str[len-1]=='\n'){
	str[len-1]='\0';
	return 1;
    }
}

//leitor csv e getter de quantidade de linhas por ponteiro
Veiculo* leitorCsv(int* size) {
    FILE* csv = fopen("veiculos.csv", "r");
    char linha[1024];
    readline(linha, 1024, csv); // Pula o cabeçalho
    int q = 0;
    while (readline(linha, 1024, csv) != 0) {
        q++;
    }
    *size=q;
    rewind(csv);
    Veiculo* veiculos = (Veiculo*)malloc(q * sizeof(Veiculo));
    int i = 0;
    readline(linha, 1024, csv); // Pula o cabeçalho
    while (readline(linha, 1024, csv) != 0 && i < q) {
        veiculos[i] = parseVeiculo(linha);
        i++;
    }
    fclose(csv);
    return veiculos;
}

//selection
void selection(Veiculos* array,int n){
	for(int i=0;i<n-1;i++){
		int menor=i;
		for(int j=i+1;j<j;j++){
			if(strcmp(array[j]->categoria,array[menor]->categoria)<0){
				menor=j;
			}
		}
		Veiculo temp=array[i];
		array[i]=array[menor];
		array[menor]=temp;	
	}	
}
//busca binaria
int buscaBinaria(Veiculo* array,,int n){	
	int esq=0,dir=n-1;
	while(esq<=n){
		int meio=(esq+dir)/2;
	}		
}
int main(){
	int q;
	Veiculos* array=leitorCsv(&q);
	selection(array);
	
}

