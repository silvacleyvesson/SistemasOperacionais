#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>


void *busca(char *argv[]){ //procura os valores.

    FILE *arquivo;
    int i=atoi(argv[0]);
    int linha=1, igualdade;
    int aux=0;
    char c;
    int procurado =atoi(argv[2]);
    arquivo = fopen (argv[i],"r");
    printf("\n%s: ",argv[i]); //mostra nome arquivo
    while (!feof(arquivo)){
    fscanf (arquivo,"%d",&igualdade);
    c = fgetc(arquivo);
            if(procurado==igualdade) {
             printf(" %d",linha);
             aux = 1;
         }
     if(c=='\n')
        linha++;
    }
    fclose(arquivo);
    if(aux==0)
    printf(" not_found\n");
    linha=1;
    aux=0;
    }

int conta(char *argv[],int i){ //CONTA A QUANTIDADE DE DADOS POR ARQUIVO PARA DIVIDIR PELAS THREADS
    FILE *arquivo;
    i=atoi(argv[0]);
    int totalarq=0;
    int procurado =atoi(argv[2]);
    int igualdade;
    arquivo = fopen (argv[i],"r");
    while (!feof(arquivo)){
    fscanf (arquivo,"%d",&igualdade);
    totalarq++;
         }
    }


int main (int argc, char *argv[]) {


FILE * arquivo;
int procurado;
int Nthreads=atoi(argv[1]);
procurado=atoi(argv[2]);
int x=0;
 pthread_t thread_id[Nthreads];


    for (int i= 3; i < argc; i ++ ){
         sprintf(argv[0], "%i", i); //converte o i para primeira posicao do vetor
         x=conta(argv,i);//conta a quantidade de dados
         sprintf(argv[argc+1], "%i", x); //Conta a quantidade de dados de cada arquivo e passa para o argv+1
               for(int k=0; k<Nthreads; k++){
                  pthread_create(&thread_id[k],NULL,busca,argv); //CRIA AS THREADS. CADA THREAD LÊ e BUSCA em um ARQUIV
                  pthread_join(thread_id[k],NULL);
                  break;
               }

            }




    printf("\n");

return 0;

}
