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
	Data data;
	sscanf(str,"%d-%d-%d",&data.ano,&data.mes,&data.dia);
	return data;
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
char* formatData(Data* data){
	char str[9];
	sprintf(str,"%02d-%02d-%04d",(*data).dia,(*data).mes,(*data).ano;
	return str;
}
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
	double co2;
	int turbo;
	Data dataRegistro;
}Veiculo;
Veiculo parseVeiculo(char* str){
	char* atributos[15];
	atributos[0]=strtok(str,',');
	int i=1;
	while(i<15){
		atributos[i]=strtok(NULL,',');
		i++;
	}
	Veiculo strct;
	strct.id=atoi(atributos[0]);
	strcpy(strct.marca,atributos[1]);
	strc(strct.modelo,atributos[2]);
	strct.ano=atoi(atributos[3]);
	strcpy(strct.categoria,atributos[4]);
	strcpy(strct.combustivel,atributos[5]);
	strct.cilindros=atoi(atributos[6]);
	strct.cilindrada=atod(atributos[7]);
	strcpy(strct.transmissao,atributos[8]);
	strcpy(strct.tracao,atributos[9]);	
	strct.consumoCidade=atod(atributos[10]);
	strct.consumoEstrada=atod(atributos[11]);
	strct.co2=atod(atributos[12]);
	strct.turbo=strcomp(atributos[13],"true")==0;
	strct.data=parseData(atributos[14]);
	return strct;	
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
char* formatVeiculo(Veiculo* veiculo){
	char str[1000];
	char turbo[6];
	if((*veiculo).turbo==1){
		strcpy(turbo,"true");
	}
	else{
		strcpy(turbo,"false");
	}
	sprintf(str,"[%d ## %s ## %s ## %d ## %s ## %s ## %d ## %lf ## %s ## %s ## %lf ## %lf ## %lf ## %s ## %s]",getId(veiculo),getMarca(veiculo),getModelo(veiculo),getCategoria(veiculo),getCombustivel(veiculo),getCilindros(veiculo),getCilindrada(veiculo),getConsumoCidade(veiculo),getConsumoEstrada(veiculo),turbo,formatData((*veiculo).&dataRegistro));
	return str;
}
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
		veiculos[i]=parseVeiculo(linha);
		i++;
	}
	return veiculos;
}
