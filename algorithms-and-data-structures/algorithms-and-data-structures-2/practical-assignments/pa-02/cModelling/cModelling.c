typedef struct{
	int dia,mes,ano;
}Data;
void setData(Veiculo* veiculo,Data* data,int dia,int mes,int ano){
	(*data).dia=dia;
	(*data).mes=mes;
	(*data).ano=ano;
}
void strCopy(char* destino,char* origem){
	while(*origem!='\0'){
		*destino=*origem;
		destino++; origem++;
	}
	*destino='\0';
}
typedef struct{
	int id,ano,cilindros,turbo;
	float cilindrada,consumoCidade,consumoEstrada,co2;
	char marca[256],modelo[256],categoria[256],combustivel[256],transmissao[256],tracao[256];
	Data data;	
}Veiculo;
void setVeiculo(Veiculo* veiculo,int id,int ano,int cilindros,int turbo,float cilindrada,float consumoCidade,float consumoEstrada,float co2,char* marca,char* modelo,char* categoria,char*combustivel,char* transmissao,char* tracao,int dia,int mes,int ano2){
	(*veiculo).id=id;
	(*veiculo).ano=ano;
	(*veiculo).cilindros=cilindros;
	(*veiculo).turbo=turbo;
	(*veiculo).cilindrada=cilindrada;
	(*veiculo).consumoCidade=consumoCidade;
	(*veiculo).consumoEstrada=consumoEstrada;
	(*veiculo).co2=co2;
	strCopy((*veiculo).marca,marca);
	strCopy((*veiculo).modelo,modelo);
	strCopy((*veiculo).categoria,categoria);
	strCopy((*veiculo).combustivel,combustivel);
	strCopy((*veiculo).transmissao,transmissao);
	strCopy((*veiculo).tracao,tracao);	
	setData(veiculo,&(*veiculo).data,dia,mes,ano2);
}
int getAno(Veiculo* veiculo){
	return (*veiculo).ano;
}
int getId(Veiculo* veiculo){
	return(*veiculo).id;
}
int getCilindros(Veiculo* veiculo){
	return (*veiculo).cilindros;
}
int getTurbo(Veiculo* veiculo){
	return (*veiculo).turbo;
}
float getCilindrada(Veiculo* veiculo){
	return (*veiculo).cilindrada;
}
float getConsumoCidade(Veiculo* veiculo){
	return (*veiculo).consumoCidade;
}
float getConsumoEstrada(Veiculo* veiculo){
	return (*veiculo).consumoEstrada;
}
float getCo2(Veiculo* veiculo){
	return (*veiculo).co2;
}
char* getMarca(Veiculo* veiculo){
	return (*veiculo).marca;
}
char* getModelo(Veiculo* veiculo){
	return (*veiculo).modelo;
}
char* getCategoria(Veiculo* veiculo){
	return (*veiculo).categoria;
}
char* getCombustivel(Veiculo* veiculo){
	return (*veiculo).combustivel;
}
char* getTransmissaO(Veiculo* veiculo){
	return (*veiculo).transmissao;
}
char* getTracao(Veiculo* veiculo){
	return (*veiculo).tracao;
}
Data getData(Veiculo* veiculo){
	return (*veiculo).data;
}
