#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
   char str[200];
}TPalavra;


 char palavraSorteada[30];//guarda a palavra sorteada
 int contador_erros=0;
 char palavraDigitada[30];
 char letra;



FILE* aberturaArquivo(char nome[],char modo[]);
FILE* fecharArquivo(FILE *arq);
//void gravar();//criar uma funcao gravar do tipo FILE;
void sorteioDepalavras();
int menu();
void nivelDificuldade();
int Jogar();
void exibir_boneco();
void imprimePalavraDig();
void limpaPavraDig();
void substituir();
void imprimeLetrasDig();
void taxadesucesso();

int main(){
 FILE *temp;

 temp=aberturaArquivo("palavras.txt","r");
 sorteioDepalavras();
 menu();

 temp=fecharArquivo(temp);
return 0;
}

FILE* aberturaArquivo(char nome[],char modo[])
{
   FILE *arq;
   arq =fopen(nome,modo);
   if(arq == NULL){
    printf("nao foi possivel abrir o arquivo");
   }
   return arq;
}
FILE* fecharArquivo(FILE *arq){
     if(arq == NULL){
        printf("erro ao fecha arquivo");
     }
     fclose(arq);
     return arq;
}

void sorteioDepalavras(){
     char result;
     int tam=0;
     int conf=0;
     FILE *arq;
     int x;

     arq=aberturaArquivo("palavras.txt","rb+");
     rewind(arq);
     fflush(stdin);
     result=getc(arq);

          while(result!=EOF){
            if(result == '\n'){
                tam++;
            }
            fflush(stdin);
            result=getc(arq);
          }
        TPalavra palavra[tam];
        rewind(arq);

         while((!feof(arq))&&(conf<tam)){
            fflush(stdin);
            fscanf(arq,"%s",palavra[conf].str);
            conf++;
         }
         srand((unsigned)time(NULL));


            x=(rand()%tam);
            strcpy(palavraSorteada,palavra[x].str);


         arq=fecharArquivo(arq);
}
bool verificaLetraDig(char letra,char vetorletrasdig[26]){
     int cont;
          for(cont=0;cont<strlen(vetorletrasdig);cont++){
             if(letra==vetorletrasdig[cont]){
                return true;
             }
          }
          return false;

}
void imprimePalavraDig(){
      int i;
      printf("\n %d letras\n\n",strlen(palavraSorteada));
   for(i=0;i<strlen(palavraSorteada);i++){
            printf("%c ",palavraDigitada[i]);
          }
}
void imprimeLetrasDig(char letras[],int tam){
    int i;

    printf("\n\nLetras digitadas:");
        for(i=0;i<tam;i++){
            printf(" %c,",letras[i]);
        }
        printf("\n\n");
}

void exibir_boneco(){
         switch(contador_erros){

            case 0:
            printf(" ______ \n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
            break;

            case 1:
            printf(" ______ \n");
            printf("|    O  \n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
            break;

            case 2:
            printf(" ______ \n");
            printf("|    O  \n");
            printf("|    |  \n");
            printf("|       \n");
            printf("|       \n");
            break;

            case 3:
            printf(" ______ \n");
            printf("|    O  \n");
            printf("|   /|  \n");
            printf("|       \n");
            printf("|       \n");
            break;

            case 4:
            printf(" ______ \n");
            printf("|    O  \n");
            printf("|   /|\\\n");
            printf("|       \n");
            printf("|       \n");
            break;

            case 5:
            printf(" ______ \n");
            printf("|    O  \n");
            printf("|   /|\\\n");
            printf("|   /   \n");
            printf("|       \n");
            break;

            case 6:
            printf(" ______ \n");
            printf("|    O  \n");
            printf("|   /|\\\n");
            printf("|   / \\\n");
            printf("|       \n");
            break;

            case 7:
            printf(" ______ \n");
            printf("|     | \n");
            printf("|    O| \n");
            printf("|   /|\\\n");
            printf("|   / \\\n");
            printf("|       \n");
            break;
         }
}
int menu(){
    int op=0;

    while(op<=3){
        system("cls");
      printf("\n\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
      printf("\n\tบ                                                                   บ");
      printf("\n\tบ                           JOGO DA FORCA                           บ");
      printf("\n\tบ                                                                   บ");
      printf("\n\tบ___________________________________________________________________บ");
      printf("\n\tบ                                                                   บ");
      printf("\n\tบ                                                                   บ");
      printf("\n\tบ                      [1] - INICIAR JOGO                           บ");
      printf("\n\tบ                      [2] - JOGO SALVO                             บ");
      printf("\n\tบ                      [3] - SAIR                                   บ");
      printf("\n\tบ                                                                   บ");
      printf("\n\tศ___________________________________________________________________ผ\n");
      printf("Escolha um das opcoes;");

      fflush(stdin);
      scanf("%d",&op);
    if(op == 1){
     Jogar();
    }else if(op == 2){

    }else if(op == 3){
        return 0;
    }
    }

  return 0;
}

void limpaPalavraDig(){
    int i;
      //limpando o vetor palavraDigitada
     for(i=0;i<strlen(palavraSorteada);i++){
        palavraDigitada[i]='_';
     }
}
void substituir(){
       int i;

          for(i=0;i<strlen(palavraSorteada);i++){
             if(palavraSorteada[i]==letra){
                palavraDigitada[i]=letra;
             }
          }
}

void taxadesucesso(){

}
int Jogar(){

    char letrasDigitada[26];
    int contLetraDig=0;
    float taxaSucesso=100;

         sorteioDepalavras();
         limpaPalavraDig();

     while(contador_erros != 8){
            system("cls");
       printf("\n\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
      printf("\n\tบ                                                                   บ");
      printf("\n\tบ                           JOGO DA FORCA                           บ");
      printf("\n\tบ   [1]-NOVO;  [2]-SAIR;                     -DIFICULDADE: NORMAL   บ");
      printf("\n\tบ___________________________________________________________________บ\n\n\n");

          exibir_boneco(contador_erros);
          imprimePalavraDig();
          imprimeLetrasDig(letrasDigitada,contLetraDig);


          printf("Tentativas restantes %d",8-contador_erros);
          printf("\n\nTaxa de Sucesso %.1f palpites/palavras\n",taxaSucesso);
          printf("\n\n");
          printf("Digite uma letra:");
          fflush(stdin);
          letra=getchar();
                     //verificar comandos
                     if(letra=='1'){
                        Jogar();
                     }else if(letra=='2'){
                        break;
                     }else{
             if(verificaLetraDig(letra,letrasDigitada)){
                printf("letra ja foi digitada tente novamente\n\n");
                system("pause");
             }else{
                letrasDigitada[contLetraDig]=letra;
                 contLetraDig++;
                 if(verificaLetraDig(letra,palavraSorteada)){
                      substituir(letra);
                 }else{
                     printf("\nletra incorreta!\n");
                     system("pause");
                     contador_erros++;
                     taxaSucesso=taxaSucesso/contador_erros;
                 }
             }

           if(strcmp(palavraSorteada,palavraDigitada)==0){
                    system("cls");
                    printf("\n\n");
                    printf("\t\tParabens voce acertou a palavra");
                    printf("\n\n");
                    printf("\t\t Inicie um novo jogo para continuar:\n\n");
                    system("pause");
                    return main();
           }
              }
     }
          if(contador_erros==8){
                system("cls");
                    printf("\n\n");
                    printf("\t\t A palavra correta e %s",palavraSorteada);
                    printf("\n\n");
                    printf("\t\t Inicie um novo jogo para continuar:\n\n");
                    system("pause");
          }

     return main();
}
