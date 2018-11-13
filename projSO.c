#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <string.h>


int main (int argc, char *argv[]) {


FILE * arquivo;
int i,procurado,num, encontrou, qntdDados, linha;
i=0; 	     			// contador de arquivos
num=0;       			// valor ds numeros lidos = 0
encontrou=0; 			// contador de numeros procurados encontrados
qntdDados=0; 			// numero que guarda o valor do tamanho do vetor do tipo auxiliar criado
procurado=atoi(argv[2]); 	// variavel que passa o valor a ser procurado a partir da chamada do programa no terminal
linha=1;     			// variavel para armazenar da qual a variavel foi lida

char c; 			// variavel para analisar o caracter lido
int temp;			// variavel temporaria para contagem dos dados totais (arquivos)
int Ntreads=atoi(argv[1]);	// Numero de threads



//----------------tipo que vai armazenar os dados----------------//

typedef struct dados   // tipo criado para guardar os dados
{
	char nomearq[100]; // nome do arquivo do dado
	int linha;     // numero da linha onde o dado se encontra
	int numero;    // valor
	int achado;    // se encontrado - default 0
} dados;

//----------------contador que varre os arquivos, pegando um "valor total"----------------//
for ( i = 3; i <= argc-1; i ++ ){
    arquivo = fopen (argv[i],"r");

    while (!feof(arquivo)){
	fscanf (arquivo,"%d\n",&temp);
	qntdDados++;
    }
    fclose(arquivo);
}


dados dado[qntdDados]; // vetor que irá armazenar os dados

//----------------zerando dados----------------//
for (i = 0; i<qntdDados; i++){
    dado[i].achado=0;
    dado[i].linha=0;
}

// contador que varre os arquivos, atribuindo os dados ao vetor de dados da variavel do tipo criado
for ( i = 3; i <= argc-1; i ++ ){
    arquivo = fopen (argv[i],"r");
    strcpy(dado[i-3].nomearq, argv[i]);	//declarar dado como pointer

    do{
	fscanf (arquivo,"%d",&num);
	c=fgetc(arquivo);
	dado[i-3].linha=linha;
	if (c=='\n'){
		linha++;
	}
	dado[i-3].numero= num;
	if(!feof(arquivo))
  	if (procurado==num) {
  		dado[i-3].achado= 1;
		printf("%s: %d, linha %d\n",dado[i-3].nomearq, dado[i-3].numero, dado[i-3].linha);
		encontrou=1;
	}
	qntdDados++;
    }while (!feof(arquivo));
	if(encontrou==0)
		printf("%s: not_found\n",dado[i-3].nomearq);
    fclose(arquivo);
    linha=1;
}

//threads

//programa funcionando, testes 1 e 2

return 0;

}
