#include <stdio.h>
#include <stdlib.h>

//sizeof(aluno) == 60
typedef struct aluno{
  char nome[50];
  int nota1;
  int nota2;
} aluno;

typedef struct class{
  aluno aluno[1];
} class;

class *turma; 

//Não tá rolando
// turma = (class *)malloc(sizeof(class));

// tAluno a1 ; 
// tAluno *ptrAluno ;
// ptrAluno = malloc(sizeof());
// tAluno ptr_a =(tAluno)malloc(sizeof(tAluno));

void incluir(){
  char nome[50];
  int nota1, nota2;

  printf("\nA seguir será solicitado o nome do aluno assim como suas notas\n");
  printf("Digite o nome do aluno (max: 50 characteres)\n");
  
  //Espaço não funcionando
  scanf("%s", nome);

  printf("Digite sua primeira nota\n");
  scanf("%i", &nota1);
  
  printf("Digite sua segunda nota\n");
  scanf("%i", &nota2);

  printf("Incluindo novo aluno...\n");
  // printf("%c", turma->aluno[0].nome[0]); //Quebrou
  // printf("%p", turma); //Quebrou
  // printf("%li", sizeof(*turma)); //Quebrou

  if(turma->aluno[(int)sizeof(*turma)/60 - 1].nome[0] != 0){
    class *newTurma = (class *)malloc(sizeof(*turma) + sizeof(class));
    
    for (int i = 0; i < sizeof(*turma); i++)
    {
      for (int j = 0; j < 50; j++)
        newTurma->aluno[i].nome[j] = turma->aluno[i].nome[j];
      
      newTurma->aluno[i].nota1 = turma->aluno[i].nota1;
      newTurma->aluno[i].nota2 = turma->aluno[i].nota2;
    }
    free(turma);

    turma = newTurma;
  }
  // printf("a");
  int newPos = (((int)sizeof(*turma))/60) - 1; //Erro aqui

  for (int j = 0; j < 50; j++)
    turma->aluno[newPos].nome[j] = nome[j];
  
  turma->aluno[newPos].nota1 = nota1;
  turma->aluno[newPos].nota2 = nota2;
  
  printf(
    "O aluno: %s, com a nota %d e a nota %d foi adicionado\n", 
    nome, nota1, nota2
  );

  printf("Sua nova estrutura ficou assim:\n");

  for (int i = 0; i < sizeof(*turma); i++)
  {
    printf(
      "Nome: %s Nota1: %d Nota2: %d", 
      turma->aluno[i].nome,
      turma->aluno[i].nota1,
      turma->aluno[i].nota2
    );
  }
}

void excluir(){
  printf("excluindo..");
}

void sair(){
  printf("Você solicitou sair");
}