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
Veiculo parseVeicullo(char* str){
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
Veiculo* leitorCsv(){
	
}
