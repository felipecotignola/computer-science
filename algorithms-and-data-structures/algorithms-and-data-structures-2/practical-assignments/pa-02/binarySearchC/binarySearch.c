#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	char str[11];
	sprintf(str,"%02d-%02d-%04d",(*data).dia,(*data).mes,(*data).ano);
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
	strcpy(strct.modelo,atributos[2]);
	strct.ano=atoi(atributos[3]);
	strcpy(strct.categoria,atributos[4]);
	strcpy(strct.combustivel,atributos[5]);
	strct.cilindros=atoi(atributos[6]);
	strct.cilindrada=atof(atributos[7]);
	strcpy(strct.transmissao,atributos[8]);
	strcpy(strct.tracao,atributos[9]);	
	strct.consumoCidade=atof(atributos[10]);
	strct.consumoEstrada=atof(atributos[11]);
	strct.co2=atof(atributos[12]);
	strct.turbo=strcmp(atributos[13],"true")==0;
	strct.dataRegistro=parseData(atributos[14]);
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
int getAno(Veiculo* strct){
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
Veiculo* leitorCsv(int* size){
	FILE* csv=fopen("veiculos.csv","r");
	char linha[1024];
	readline(linha,1024,csv);
	int q=0;
	while(readline(linha,1024,csv)!=0){
		q++;
	}	
	*size=q;
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
int check(Veiculo key,Veiculo v){
	if(strcmp(key.modelo,v.modelo)<0){
		return 1;	
	}
	else{
		return 0;
	}
}
void sort(Veiculo* array,int tam){
	for(int i=1;i<tam;i++){
		Veiculo key=array[i];
		int j=i-1;
		while(j>=0 && check(key,array[j])){
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=key;
	}
}
char* binarySearch(Veiculo* array,int tamanho,char* s){
	int esq=0,dir=tamanho-1,meio=(esq+dir+1)/2;
	char* resp="SIM";
	while(esq<=dir){
		if(strcmp(array[meio].modelo,s)==0){
			return resp;
		}
		else{
			if(strcmp(array[meio].modelo,s)<0){
				esq=meio+1;
				meio=(esq+dir+1)/2;	
			}
			else{
				dir=meio-1;
				meio=(esq+dir+1)/2;	
			}	
		}
	}
	resp="NAO";
	return resp;
}
void readline2(char* str,int tam){
	fgets(str,tam,stdin);
	str[size(str)-1]='\0';
}
int main(){
	int tamanho;
	Veiculo* array=leitorCsv(&tamanho);
	sort(array,tamanho);
	char s[256];
	readline2(s,256);
	while(!(s[0]=='F' && s[1]=='I' && s[2]=='M' && s[3]=='\0')){
		printf("%s\n",binarySearch(array,tamanho,s));
		readline2(s,256);
	}
}
