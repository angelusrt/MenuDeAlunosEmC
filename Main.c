#include <stdio.h>
#include "Functions.h"
#include <stdlib.h>

void menu();

int main() {
  menu();

  return 0;
}

void menu(){
  int escolha;

  printf("________Menu________\n\n");
  printf("1: inclusão de alunos\n");
  printf("2: exclusão de alunos\n");
  printf("3: pesquisa de alunos\n");
  printf("4: Relatório de notas\n");
  printf("5: Sair\n\n");

  printf("Escolha uma opção: (1-5)\n");
  scanf("%i", &escolha);
    
  switch(escolha){
    case 1:
      incluir();
    break;
    case 2:
      excluir();
    break;
    case 3:
      printf("Você solicitou a pesquisa");
    break;
    case 4:
      printf("Você solicitou o relatório");
    break;
    case 5:
      sair();
    default:
      printf("Opção inexistente, escolha novamente");
      menu();
    break;
  }
}