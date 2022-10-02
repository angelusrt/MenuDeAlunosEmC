#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sizeof(aluno) == 60
struct aluno{
  char nome[50];
  float nota1;
  float nota2;
};

struct classroom{
  struct aluno *pAluno;
  int length;
};

struct classroom class, *pClass = &class;

void incluir(struct classroom *sala){
  struct aluno *newAluno = sala->pAluno + sala->length;
  char nome[50];
  float nota1, nota2;

  printf("\nA seguir será solicitado o nome do aluno assim como suas notas\n");
  printf("Digite o nome do aluno (max: 50 characteres)\n");
  
  //Espaço não funcionando
  scanf("%s", nome);

  printf("Digite sua primeira nota\n");
  scanf("%f", &nota1);
  
  printf("Digite sua segunda nota\n");
  scanf("%f", &nota2);

  printf("Incluindo novo aluno...\n");
  if(sala != NULL){
    if(sala->length == sizeof(*(sala->pAluno))/60){
      sala->pAluno = (struct aluno*)realloc(sala->pAluno, 10);
    }

    *newAluno = (struct aluno){
      .nota1 = nota1,
      .nota2 = nota2
    };
    
    strncpy(newAluno->nome, nome, 50);

    sala->length++;
  }

  printf(
    "O aluno: %s, com a nota %.2f e a nota %.2f foi adicionado\n\n", 
    newAluno->nome, newAluno->nota1, newAluno->nota2
  );
}

void excluir(struct classroom *sala){
  int index = -1;
  a: printf(
    "Selecione qual casa você deseja excluir: (Total: %d)\n", sala->length - 1
  );
  scanf("%i", &index);

  if(sala != NULL){
    if(index <= sala->length - 1 && index >= 0){
      printf("excluindo..\n");
      printf("Velho aluno na estrutura: %s\n", (sala->pAluno + index)->nome);

      for (int i = index; i < sala->length - 1; i++)
        *(sala->pAluno + index) = (struct aluno)*(sala->pAluno + index + 1);
      
      sala->length--;
      
      printf("Novo aluno na estrutura: %s\n\n", (sala->pAluno + index)->nome);
    }else{
      printf("Número selecionado inválido, digite novamente\n\n");
      goto a;
    }
  }
}

void pesquisa(struct classroom *sala){
  struct aluno *pAluno = NULL;
  char nome[50];

  printf(
    "Digite o nome do aluno a qual se quer ver as suas informações: (Sem espaços)\n"
  );
  scanf("%s", nome);

  if(sala != NULL)
    for (int i = 0; i < sala->length; i++)
      if(strncmp((sala->pAluno + i)->nome, nome, 50) == 0){
        pAluno = sala->pAluno + i;
        break;
      }
  
  if(pAluno != NULL)
    printf(
      "O aluno procurado, %s, possui notas %.2f e %.2f\n\n", 
      pAluno->nome, 
      pAluno->nota1,
      pAluno->nota2
    );
  else 
    printf("O aluno pesquisado não existe\n\n");
}

void relatorio(struct classroom *sala){
  if(sala != NULL){
    printf("Nome | Nota 1 | Nota 2 | Média | Situação\n");

    for (int i = 0; i < sala->length; i++){ 
      struct aluno *pAluno = sala->pAluno + i;
      float media = (pAluno->nota1 + pAluno->nota2)/2.0f;

      printf(
        "%s | %.2f | %.2f | %.2f | %s\n",
        pAluno->nome,
        pAluno->nota1,
        pAluno->nota2,
        media,
        media >= 6.0f ? "Aprovado" : 
        media >= 4.0f ? "Em recuperação" : 
        "Reprovado" 
      );
    }

    printf("\n");
  }
}

void sair(struct classroom *sala){
  free(sala->pAluno);
  
  printf("Você solicitou sair\n");
}