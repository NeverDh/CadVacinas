#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>



typedef struct
  { 
    
    int codigo;
    int lote;
    char nome[60] ;
    char cpf[30];
    char vacina[20];
    char data[10];
    
    
    
  }Vacina;

void clearBuffer (void){
  char c;
  while ((c = getchar ()) != '\n' && c != EOF);
  }

void menu()
{
    printf("\n----------------------- MENU --------------------------\n");
    printf ("1 - Cadastrar paciente\n");
    printf ("2 - Listar Aplicações\n");
    printf ("3 - Consultar por CPF\n");
    printf ("4 - Sair\n");
    printf ("\n");
}


void registrarVacina(Vacina *read, int j, Vacina ler[99])
{



int i = 0;
char cpf[30];
printf("\n Por favor, desconsidere os pontos e traços!\n Digite o cpf: ");
scanf(" %s", read->cpf);fflush(stdin);

for(i = 0; i < j; i++){
    int s = strcmp(ler[i].cpf, read->cpf);
    printf("%s", ler[i].cpf);
        if(s == 0 && j != 0){
            printf("\n CPF JÁ CONSTA NA NOSSA BASE DE DADOS!\n");
            printf("\n Digite outro cpf: ");
            scanf(" %s", read->cpf);fflush(stdin);
            break;
        }
    }

printf("\n Digite o lote: ");
scanf("%d", &read->lote);fflush(stdin);
printf("\n Digite o nome: ");
scanf("%s", read->nome);fflush(stdin);

printf("\n Digite o vacina: ");
scanf("%s", read->vacina);fflush(stdin);
printf("\n Digite o data: ");
scanf("%s", read->data);fflush(stdin);
}

void lerVacina(Vacina read[99], int j)
{
    int i = 0;

    while (i < j) {
printf("\n-------------------- Codigo %d --------------------------\n",i+1);

printf("\n lote: %d",read[i].lote);
printf("\n Nome: %s",read[i].nome);
printf("\n CPF: %s",read[i].cpf);
printf("\n Vacina: %s",read[i].vacina);
printf("\n Data: %s",read[i].data);


printf("\n-------------------------------------------------------------------\n");
i++;
}
}

void verificarCPF(Vacina read[99])
{
    char outroCpf[99];
    printf("\n Por favor, desconsidere os pontos e traços!\n Digite o cpf: ");
    scanf("%s", outroCpf);fflush(stdin);

    int i = 0;

    for(i = 0; i <= 99; i++){
        int s = strcmp(read[i].cpf, outroCpf);
        if(s == 0){

            printf("\n CPF LOCALIZADO!\n");
            printf("\n lote: %d",read[i].lote);
            printf("\n Nome: %s",read[i].nome);
            printf("\n CPF: %s",read[i].cpf);
            printf("\n Vacina: %s",read[i].vacina);
            printf("\n Data: %s",read[i].data);
            break;
        }else if(i == 99){
            printf("\n CPF não consta na nossa base de dados!\n");
        }
    }
    
}


int nPacientes;
int opc, i, lote;
int codigo;
int lote;
char nome[60] ;
char cpf[30];
char vacina[20];
char data[10];

int main(void) {
setlocale(LC_ALL,"");
Vacina vacina[99];
int i=0,opcao;

do {
    menu();

    scanf("%d",&opcao);

    if (opcao == 4) break;
    switch(opcao)
    {
    case 1:
        registrarVacina(&vacina[i], i, vacina);
        i++;
        break;
    case 2:
        lerVacina(vacina, i);
        break;
    case 3:
        verificarCPF(vacina);
        break;
    case 4:
        return 0;
        break;
    }
} while (opcao != 4);
  return 0;
}




