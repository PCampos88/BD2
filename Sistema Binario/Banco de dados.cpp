#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pessoa.h"
//#include <windows.h>

void gerarBD(char *nome);
void contPaisSexo(char nome[]);
void contPaisSexoIdade(char nome[]);
void avgIdadePaisSexo(char nome[]);
void contPais15Sexo(char nome[]);
void contPais15Sexo1(char nome[]);
void contPais015Sexo(char nome[]);
void avgSalarioPaisSexo(char nome[]);

void contPaisIdioma(char nome[]);
void contPaisIdioma0100(char nome[]);
void contPaisEscolaridade(char nome[]);



int main(void){

	srand(time(NULL));
	//gerarBD("bd2.dat");
	//gerarBD("bd1.dat");
	//gerarBD("bd3.dat");
	//gerarBD("bd4.dat");
	
	//contPaisSexo("bd2.dat");
	//contPaisSexo("bd1.dat");
	//contPaisSexo("bd3.dat");
	// contPaisSexo("bd4.dat");
	
	//contPaisSexoIdade("bd1.dat");
	
	//avgIdadePaisSexo("bd1.dat");
	
	//contPais15Sexo("bd1.dat");
	
	//contPais15Sexo1("bd1.dat");
	
	//contPais015Sexo("bd1.dat");
	
	//avgSalarioPaisSexo("bd1.dat");

	//contPaisIdioma("bd2.dat");
	
	//contPaisIdioma0100("bd1.dat");
	
	//contPaisEscolaridade("bd1.dat");
	
}

void gerarBD(char *nome){
	FILE *BD;
	long int i = 0, result;
	pessoa aux;
	BD = fopen(nome, "wb");
		for(i=0;i<250000000;i++){
			aux = randPessoa();
			result = fwrite(&aux,sizeof(pessoa), 1, BD);
			if(i%100000000==0){
				printf(". ");
			}	
		}
	printf("\n ");	
	fclose(BD);
}
//=====================================================================================
//SELECT país, sexo, count(*) FROM pessoas GROUP BY país, sexo;
//===========================================================================================
void contPaisSexo(char nome[]){
	FILE *BD;
	int m[255],f[255];
	long int result,i;
	pessoa p2;
	for(i=0;i<255;i++){
		m[i]=0;
		f[i]=0;
	}
	BD = fopen(nome, "rb");
	for(i=0;i<250000000;i++){
		rewind(BD);
		//	printf(" .%li. ",i);
			fseek(BD,sizeof(pessoa)*i, SEEK_SET);
			result = fread(&p2,sizeof(pessoa), 1, BD);
			if(p2.sexo == 1){
				f[p2.pais]++;
			}else{
				m[p2.pais]++;
			}
			if(i%50000000==0||i%50000000==1){
			
			printf(" .%d . ",p2.pais);
		}
		
	}
	
	printf("\nSexo | Pais | Count\n");
	for(i=0;i<255;i++){
		if(f[i]!=0){
			printf("%d       %d     %d \n",1,i+1,f[i]);
		}
	}
	for(i=0;i<255;i++){
		if(m[i]!=0){
			printf("%d       %d     %d \n",0,i+1,m[i]);
		}
	}
	
	fclose(BD);
}
//===========================================================================================
//SELECT país, sexo, idade, count(*) FROM pessoas GROUP BY país, sexo, idade;
//============================================================================================
void contPaisSexoIdade(char nome[]){
	FILE *BD;
	int m[255][128],f[255][128];
	long int result,i,j;
	pessoa p2;
	for(i=0;i<255;i++){
		for(j=0;j<128;j++){
			m[i][j] = 0;
			f[i][j] = 0;
		}
	}
	BD = fopen(nome, "rb");
	for(i=0;i<250000000;i++){
		rewind(BD);
		//	printf(" .%li. ",i);
			fseek(BD,sizeof(pessoa)*i, SEEK_SET);
			result = fread(&p2,sizeof(pessoa), 1, BD);
			if(p2.sexo == 1){
				f[p2.pais][p2.idade]++;
			}else{
				m[p2.pais][p2.idade]++;
			}
			if(i%50000000==0||i%50000000==1){
			
			printf(" .%d . ",p2.pais);
		}
		
	}
	
	printf("\nSexo | Pais | Idade  |  Count\n");
	for(i=0;i<255;i++){
		for(j=0;j<128;j++){		
			if(f[i][j]!=0){
				printf("%d       %d     %d      %d\n",1,i, j,f[i][j]);
			}
		}
	}
	for(i=0;i<255;i++){
		for(j=0;j<128;j++){
		
		if(m[i][j]!=0){
			printf("%d       %d     %d      %d\n",1,i, j,f[i][j]);
		}
		}
	}
	
	fclose(BD);
}
//=================================================================================================
// SELECT país, sexo, avg(idade) FROM pessoas GROUP BY país, sexo;
//=================================================================================================
void avgIdadePaisSexo(char nome[]){
	FILE *BD;
	long int m[255],f[255], contM[255],contF[255];
	long int result,i;
	pessoa p2;
	for(i=0;i<255;i++){
		m[i]=0;
		f[i]=0;
		contM[i]=0;
		contF[i]=0;
	}
	BD = fopen(nome, "rb");
	for(i=0;i<250000000;i++){
		rewind(BD);
		//	printf(" .%li. ",i);
			fseek(BD,sizeof(pessoa)*i, SEEK_SET);
			result = fread(&p2,sizeof(pessoa), 1, BD);
			if(p2.sexo == 1){
				f[p2.pais]= f[p2.pais]+p2.idade;
				contF[p2.pais]++;
			}else{
				m[p2.pais]= m[p2.pais]+p2.idade;
				contM[p2.pais]++;
			}
			if(i%50000000==0||i%50000000==1){
			
			printf(" .%d . ",p2.idade);
		}
	}
	
	printf("\nSexo | Pais | avg(idade)\n");
	double media=1;
	for(i=0;i<255;i++){
		if(contF[p2.pais]!=0){
			media =f[i]/contF[i];
			printf("%d       %d     %lf \n",1,i+1,media);
		}
	}
	for(i=0;i<255;i++){
		if(contM[p2.pais]!=0){
			media = m[i]/contM[i];
			printf("%d       %d     %lf \n",0,i+1,media);
		}
	}
	
	fclose(BD);
}
//==============================================================================================
//SELECT país, sexo, count(*) FROM pessoas WHERE país = 15 GROUP BY país, sexo;
//==============================================================================================
void contPais15Sexo(char nome[]){
	FILE *BD;
	int m[255],f[255];
	long int result,i;
	pessoa p2;
	for(i=0;i<255;i++){
		m[i]=0;
		f[i]=0;
	}
	BD = fopen(nome, "rb");
	for(i=0;i<250000000;i++){
		rewind(BD);
		//	printf(" .%li. ",i);
			fseek(BD,sizeof(pessoa)*i, SEEK_SET);
			result = fread(&p2,sizeof(pessoa), 1, BD);
			if(p2.sexo == 1 && p2.pais==15){
				f[p2.pais]++;
			}else{
				if(p2.pais==15)
				m[p2.pais]++;
			}
			if(i%50000000==0||i%50000000==1){
			
			printf(" .%d . ",p2.pais);
		}
		
	}
	
	printf("\nSexo | Pais | Count\n");
	for(i=0;i<255;i++){
		if(f[i]!=0){
			printf("%d       %d     %d \n",1,i+1,f[i]);
		}
	}
	for(i=0;i<255;i++){
		if(m[i]!=0){
			printf("%d       %d     %d \n",0,i+1,m[i]);
		}
	}
	
	fclose(BD);
}
//==================================================================================
//SELECT país, sexo, count(*) FROM pessoas WHERE país = 15 AND sexo = 1;
//==================================================================================
void contPais15Sexo1(char nome[]){
	FILE *BD;
	int f[255];
	long int result,i;
	pessoa p2;
	for(i=0;i<255;i++){
		f[i]=0;
	}
	BD = fopen(nome, "rb");
	for(i=0;i<250000000;i++){
		rewind(BD);
		//	printf(" .%li. ",i);
			fseek(BD,sizeof(pessoa)*i, SEEK_SET);
			result = fread(&p2,sizeof(pessoa), 1, BD);
			if(p2.sexo == 1 && p2.pais==15){
				f[p2.pais]++;
			}
			if(i%50000000==0||i%50000000==1){
			printf(" .%d . ",p2.pais);
		}	
	}	
	printf("\nSexo | Pais | Count\n");
	for(i=0;i<255;i++){
		if(f[i]!=0){
			printf("%d       %d     %d \n",1,i+1,f[i]);
		}
	}
	fclose(BD);
}
//============================================================================================
//SELECT país, sexo, count(*) FROM pessoas WHERE país >=0 AND país <=15 GROUP BY país, sexo;
//=============================================================================================
void contPais015Sexo(char nome[]){
	FILE *BD;
	int m[255],f[255];
	long int result,i;
	pessoa p2;
	for(i=0;i<255;i++){
		m[i]=0;
		f[i]=0;
	}
	BD = fopen(nome, "rb");
	for(i=0;i<250000000;i++){
		rewind(BD);
		//	printf(" .%li. ",i);
			fseek(BD,sizeof(pessoa)*i, SEEK_SET);
			result = fread(&p2,sizeof(pessoa), 1, BD);
			if(p2.sexo == 1 && p2.pais<=15){
				f[p2.pais]++;
			}else{
				if(p2.pais<=15)
				m[p2.pais]++;
			}
			if(i%50000000==0||i%50000000==1){
			
			printf(" .%d . ",p2.pais);
		}	
	}
	printf("\nSexo | Pais | Count\n");
	for(i=0;i<255;i++){
		if(f[i]!=0){
			printf("%d       %d     %d \n",1,i+1,f[i]);
		}
	}
	for(i=0;i<255;i++){
		if(m[i]!=0){
			printf("%d       %d     %d \n",0,i+1,m[i]);
		}
	}
	fclose(BD);
}
//=============================================================================
//SELECT país, sexo, avg(salario) FROM pessoas GROUP BY país, sexo;
//=============================================================================

void avgSalarioPaisSexo(char nome[]){
	FILE *BD;
	long double m[255],f[255],contM[255],contF[255];
	long int result,i;
	pessoa p2;
	for(i=0;i<255;i++){
		m[i]=0;
		f[i]=0;
		contM[i]=0;
		contF[i]=0;
	}
	BD = fopen(nome, "rb");
	for(i=0;i<250000000;i++){
		rewind(BD);
		//	printf(" .%li. ",i);
			fseek(BD,sizeof(pessoa)*i, SEEK_SET);
			result = fread(&p2,sizeof(pessoa), 1, BD);
			if(p2.sexo == 1){
				f[p2.pais]= f[p2.pais]+p2.renda;
				contF[p2.pais]++;
			}else{
				m[p2.pais]= m[p2.pais]+p2.renda;
				contM[p2.pais]++;
			}
			if(i%50000000==0||i%50000000==1){
			
			printf(" .%d . ",p2.renda);
		}
	}
	
	printf("\nSexo | Pais | avg(idade)\n");
	long double media=1;
	for(i=0;i<255;i++){
		if(contF[p2.pais]!=0){
			media =f[i]/contF[i];
			printf("%d       %d     %Li \n",1,i+1,media);
		}
	}
	for(i=0;i<255;i++){
		if(contM[p2.pais]!=0){
			media = m[i]/contM[i];
			printf("%d       %d     %Li \n",0,i+1,media);
		}
	}
	
	fclose(BD);
}
//=====================================================================================
//SELECT país, idoma, count(*) FROM pessoas GROUP BY país, idoma;
//=====================================================================================
void contPaisIdioma(char nome[]){
	printf(" . ");
	FILE *BD;
	int m[255][4095];
	long int result,i,j;
	pessoa p2;
	for(i=0;i<255;i++){
		for(j=0;j<4095;j++){
			m[i][j]=0;
		}
	}
	printf(" . ");
	BD = fopen(nome, "rb");
	printf(" . ");
	for(i=0;i<2500;i++){
		rewind(BD);
		//	printf(" .%li. ",i);
			fseek(BD,sizeof(pessoa)*i, SEEK_SET);
			result = fread(&p2,sizeof(pessoa), 1, BD);
			m[p2.pais][p2.idioma]++;
			if(i%50000000==0||i%50000000==1){
			printf(" . ");
		}
		
	}
	
	printf("\nPais | Idioma | Count\n");
	for(i=0;i<255;i++){
		for(j=0;j<4095;j++){
			if(m[i][j]=!0){
				printf("%d       %d       %d",i,j,m[i][j]);
			}
		}
	}
	
	fclose(BD);
}

//=======================================================================
//SELECT país, idoma, count(*) FROM pessoas GROUP BY país, idoma WHERE idioma >= 0 AND idade <= 100;
//=======================================================================

void contPaisIdioma0100(char nome[]){
	FILE *BD;
	int m[255][4095];
	long int result,i,j;
	pessoa p2;
	for(i=0;i<255;i++){
		for(j=0;j<4095;j++){
			m[i][j]=0;
		}
	}
	BD = fopen(nome, "rb");
	for(i=0;i<2500;i++){
		rewind(BD);
			fseek(BD,sizeof(pessoa)*i, SEEK_SET);
			result = fread(&p2,sizeof(pessoa), 1, BD);
			if(p2.idioma>=0 && p2.idioma<=100){
				m[p2.pais][p2.idioma]++;
			}
			if(i%50000000==0||i%50000000==1){
			printf(" . ");
		}
		
	}
	
	printf("\nPais | Idioma | Count\n");
	for(i=0;i<255;i++){
		for(j=0;j<4095;j++){
			if(m[i][j]=!0){
				printf("%d       %d       %d",i,j,m[i][j]);
			}
		}
	}
	
	fclose(BD);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
//SELECT país, escolaridade, count(*) FROM pessoas GROUP BY país,idade escolaridade;
//===========================================================================================

void contPaisEscolaridade(char nome[]){
	FILE *BD;
	int m[4][255];
	long int result,i,j;
	pessoa p2;
	for(i=0;i<4;i++){
		for(j=0;j<255;j++){
			m[i][j]=0;
		}
	}
	BD = fopen(nome, "rb");
	for(i=0;i<2500;i++){
		rewind(BD);
			fseek(BD,sizeof(pessoa)*i, SEEK_SET);
			result = fread(&p2,sizeof(pessoa), 1, BD);
				m[p2.pais][p2.escolaridade]++;
			if(i%50000000==0||i%50000000==1){
			printf(" . ");
		}
		
	}
	
	printf("\nPais | escolaridade | Count\n");
	for(i=0;i<4;i++){
		for(j=0;j<255;j++){
			if(m[i][j]=!0){
				printf("%d       %d       %d",i,j,m[i][j]);
			}
		}
	}
	
	fclose(BD);
}
