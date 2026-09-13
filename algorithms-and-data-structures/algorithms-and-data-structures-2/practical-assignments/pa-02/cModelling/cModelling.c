#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int ano;
	int mes;
	int dia;
}Data;
void DataConstrutor(Data* struct,int ano,int mes,int dia){
	(*struct).ano=ano;
	(*struct).mes=mes;
	(*struct).dia=dia;
}
Data parseData(char* str){
	//splittar em um vetor de strings
	//fazer o parse de cada atributo
	//instanciar a struct
	//retornar a struct
}
int getAno(Data* struct){
	return (*struct).ano;
}
int getMes(Data* struct){
	return (*struct).mes;
}
int getDia(Data* struct){
	return (*struct).dia;
}
//formatar data

typedef struct{
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
	//bool turbo?????????
	Data dataRegistro;
}Veiculo;
Veiculo parseVeicullo(Veiculo* strct,char* str){
	//splitar a string em atributos
	//fazer o parse de cada atributos
	//instanciar a data etc paapapapap
	//retornar a struct veiculo
}
int getId(Veiculo* strct){
	return (*strct).id;
}
char* getMarca(Veiculo* strct){
	return (*strct).marca;
}
char* getModelo(Veiculo* strct){
	return (*strct).modelo;
}
int getAno(Veiculo* struct){
	return (*strct).ano;
}
char* getCategoria(Veiculo* strct){
	return (*strct).categoria;
}
char* getCombustivel(Veiculo* strct){
	return (*strct).combustivel;
}
int getCilindros(Veiculo* strct){
	return (*strct).cilindros;
}
double getCilindrada(Veiculo* strct){
	return (*strct).cilindrada;
}
char* getTransmissao(Veiculo* strct){
	return (*strct).transmissao;	
}
char* getTracao(Veiculo* strct){
	return (*strct).tracao;
}
double getConsumoCidade(Veiculo* strct){
	return (*strct).consumoCidade;
}
double getConsumoEstrada(Veiculo* strct){
	return (*strct).consumoEstrada;
}
int getTurbo(Veiculo* strct){
	return (*strct).turbo;
}
Data getDataRegistro(Veiculo* strct){
	return (*strct).dataRegistro;
}
void setConsumoCidade(Veiculo* strct,double n){
	(*strct).consumoCidade=n;	
}
void setConsumoEstrada(Veiculo* strct, double n){
	(*strct).consumoEstrada=n;
}
void setCo2(Veiculo* strct,double n){
	(*strct).co2=n;	
}
//format veiculos
int size(char* str){
	int count=0;
	while(*str!='\0'){
		count++;
		str++;
	}
	return count;
}
int readline(char* str,int tam,FILE* csv){
	if(fgets(str,tam,csv)==NULL){
		return 0;
	}
	if(str[size(str)-1]=='\n'){
		str[size(str)-1]='\0';
	}
	return 1;
}
Veiculo* leitorCsv(){
	FILE* csv=fopen("veiculos.csv","r");
	char linha[1024];
	readline(linha,1024,csv);
	int q=0;
	while(readline(linha,1024,csv)!=0){
		q++;
	}	
	rewind(csv);
	Veiculo* veiculos=malloc(q*sizeof(Veiculo));
	int i=0;
	readline(linha,1024,csv);
	while(readline(linha,1024,csv)!=0){
		parseVeiculo(&veiculos[i],linha);
		i++;
	}
	return veiculos;
}
