#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
	int sexo, idade, pais, idioma,escolaridade, renda;
	long int localizacao;
}pessoa;
//////
void printPessoa(pessoa p){
	printf("Sexo: %d\n",p.sexo);
	printf("Idade: %d\n",p.idade);
	printf("Pais: %d\n",p.pais);
	printf("Idioma: %d\n",p.idioma);
	printf("Localização: %li",p.sexo);
	printf("Renda: %d\n",p.renda);
}

pessoa randPessoa(){
	
	pessoa aux;
	int qualquer;
	aux.idade = rand()%128;
	aux.idioma = rand()%4095;
	qualquer = rand()%1000;
	aux.sexo = qualquer%2;
	aux.pais = rand()%255;
	aux.escolaridade = rand()%3;
	aux.localizacao = rand()%16000000;
	aux.renda = rand()%1023;
	return aux;
}
