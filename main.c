#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

void menu();

int main() {
  menu();

  return 0;
}

void menu(){
  int escolha;

  (*pClass) = (struct classroom){
    .pAluno = (struct aluno*)malloc(10 * sizeof(struct aluno)),
    .length = 0
  };

  a: printf("________Menu________\n\n");
  printf("1: inclusão de alunos\n");
  printf("2: exclusão de alunos\n");
  printf("3: pesquisa de alunos\n");
  printf("4: Relatório de notas\n");
  printf("5: Sair\n\n");

  printf("Escolha uma opção: (1-5)\n");
  scanf("%i", &escolha);
    
  switch(escolha){
    case 1:
      incluir(pClass);
      goto a;
    break;
    case 2:
      excluir(pClass);
      goto a;
    break;
    case 3:
      pesquisa(pClass);
      goto a;
    break;
    case 4:
      relatorio(pClass);
      goto a;
    break;
    case 5:
      sair(pClass);
    break;
    default:
      printf("Opção inexistente, escolha novamente");
      goto a;
    break;
  }
}