#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contSimples = 0, contEspecial = 0;

struct Node {
    int tipo;
    char nome[20];
    char pais[20];
    char uva[20];
    char safra[20];
    Node *proximo;
};

struct Queue {
    Node *inicio; 
    Node *fim;
};

// Adicionar Vinho
void EnqueueVinho(struct Queue *&filaVinho, char nome[20], char pais[20], char uva[20], char safra[20]) {
  struct Node *novo;
  novo = (Node *)calloc(1, sizeof(struct Node));
  if (novo == NULL) {
    printf("\n\nErro ao registrar Vinho");
  } else {
    memcpy(novo->nome, nome, sizeof novo->nome);
    memcpy(novo->pais, pais, sizeof novo->pais);
    memcpy(novo->uva, uva, sizeof novo->uva);
    memcpy(novo->safra, safra, sizeof novo->safra);
    
    novo->proximo = NULL;
    if(filaVinho->inicio==NULL){
      filaVinho->inicio = novo;
      filaVinho->fim = novo;
    }else{
      filaVinho->fim->proximo = novo;
      filaVinho->fim = novo;
    }
  }
}

// Remover Vinho (simples)
void DequeueOrdinario(struct Queue *&filaSimples) {
  int count = 0;
  struct Node *atual;
  if (filaSimples->inicio == NULL) {
    printf("\n\nNao ha vinhos deste tipo!");
  } else {
    atual = filaSimples->inicio;
    filaSimples->inicio = atual->proximo;
    printf("\n\nO Vinho:\nNome: %s\nPais: %s\nUva: %s\nSafra: %s\nFoi Retirado", atual->nome, atual->pais, atual->uva, atual->safra);
    free(atual);
  }
}
// Remover Vinho (especial)
void DequeueEspecial(struct Queue *&filaEspecial) {
  int count = 0;
  struct Node *atual;
  if (filaEspecial->inicio == NULL) {
    printf("\n\nNao ha vinhos deste tipo!");
  } else {
    atual = filaEspecial->inicio;
    filaEspecial->inicio = atual->proximo;
    printf("\n\nO Vinho:\nNome: %s\nPais: %s\nUva: %s\nSafra: %s\nFoi Retirado para uma ocasiao especial", atual->nome, atual->pais, atual->uva, atual->safra);
    free(atual);
  }
}

// 5 Aquisicoes mais antigas
void AquisicoesAntigas(struct Queue *&filaVinho) {
  int i = 0;
  if (filaVinho->inicio == NULL) {
    printf("\n\nNao ha vinhos deste tipo!");
  } else {
    struct Node *aux;
    aux = filaVinho->inicio;
    while ((aux != NULL) && ( i < 5)) {
      printf("\n\nNome: %s\nPais: %s\nUva: %s\nSafra: %s", aux->nome, aux->pais, aux->uva, aux->safra);
      aux = aux->proximo;
      i++;
    }
  }
}
// 5 Aquisicoes mais recentes vinhos simples
void AquisicoesRecentesSimples(struct Queue *&filaVinho) {
  int i = 0 ;
  if (filaVinho->inicio == NULL) {
    printf("\n\nNao ha vinhos deste tipo!");
  } else {
    struct Node *aux = filaVinho->inicio;
    
    if (contSimples<=5){
      while (aux != NULL) {
      printf("\n\nNome: %s\nPais: %s\nUva: %s\nSafra: %s", aux->nome, aux->pais, aux->uva, aux->safra);
      aux = aux->proximo;
      }
    }
    if (contSimples>5){
      while (i<contSimples){
        if(i>=(contSimples-5)){
          printf("\n\nNome: %s\nPais: %s\nUva: %s\nSafra: %s", aux->nome, aux->pais, aux->uva, aux->safra);
        }
        aux = aux->proximo;
        i++;
      }
    }
  }
}
// 5 Aquisicoes mais recentes vinhos simples
void AquisicoesRecentesEspeciais(struct Queue *&filaVinho) {
  int i = 0 ;
  if (filaVinho->inicio == NULL) {
    printf("\n\nNao ha vinhos deste tipo!");
  } else {
    struct Node *aux = filaVinho->inicio;
    
    if (contEspecial<=5){
      while (aux != NULL) {
      printf("\n\nNome: %s\nPais: %s\nUva: %s\nSafra: %s", aux->nome, aux->pais, aux->uva, aux->safra);
      aux = aux->proximo;
      }
    }
    if (contEspecial>5){
      while (i<contEspecial){
        if(i>=(contEspecial-5)){
          printf("\n\nNome: %s\nPais: %s\nUva: %s\nSafra: %s", aux->nome, aux->pais, aux->uva, aux->safra);
        }
        aux = aux->proximo;
        i++;
      }
    } 
  }  
}

int main() {
  int opc = 0, opc2 = 0;
  int n = 0;
  char nome[20], uva[20], pais[20], safra[20];
  
  struct Queue *filaSimples = (struct Queue *)calloc(1, sizeof(struct Queue));
  struct Queue *filaEspecial = (struct Queue *)calloc(1, sizeof(struct Queue));

  while (1) {
    printf("\n\n1 - Adicionar Vinho"
           "\n2 - Retirar Vinho comum\n3 - Retirar Vinho de ocasioes especiais\n4 - 5 aquisicoes mais antigas\n"
           "5 - 5 aquisocoes mais recentes\n\n Escolha a opcao: ");
    scanf("%d", &opc);

    if (opc > 5 || opc < 1) {
      printf("\n\nOpcao invalida");
      continue;
    }
    if (opc == 1) {
      printf("\n\n1 - Adicionar vinho comum\n2 - Adicioanar vinho para ocasiao especial\nEscolha: ");
      scanf("%d", &opc2);
      if(opc2 == 1){

        printf("\n\nDigite o nome do Vinho: ");
        scanf("%s", nome);
        printf("Digite o nome do Pais de origem: ");
        scanf("%s", pais);
        printf("Digite a uva: ");
        scanf("%s", uva);
        printf("Digite a safra: ");
        scanf("%s", safra);
  
        EnqueueVinho(filaSimples, nome, pais, uva, safra);
        contSimples++;
      }
      if(opc2 == 2){
        printf("\n\nDigite o nome do Vinho: ");
        scanf("%s", nome);
        printf("Digite o nome do Pais de origem: ");
        scanf("%s", pais);
        printf("Digite a uva: ");
        scanf("%s", uva);
        printf("Digite a safra: ");
        scanf("%s", safra);
        
        EnqueueVinho(filaEspecial, nome, pais, uva, safra);
        contEspecial++;
      }
    }
    if (opc == 2) {
      DequeueOrdinario(filaSimples);
      contSimples--;
    }
    if (opc == 3) {
      DequeueEspecial(filaEspecial);
      contEspecial--;
    }
    if (opc == 4) {
      printf("\n\n5 aquisicoes mais antigas para ocasioes comuns: ");
      AquisicoesAntigas(filaSimples);
      printf("\n\n5 aquisicoes mais antigas para ocasioes especiais: ");
      AquisicoesAntigas(filaEspecial);
    }
    if (opc == 5) {
      printf("\n\n5 aquisicoes mais recentes para ocasioes comuns: ");
      AquisicoesRecentesSimples(filaSimples);
      printf("\n\n5 aquisicoes mais recentes para ocasioes especiais: ");
      AquisicoesRecentesEspeciais(filaEspecial);
    }
  }
}

