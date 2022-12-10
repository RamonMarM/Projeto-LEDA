#include <stdio.h>
#include <stdlib.h>
#define TAM 5;

struct Node {
    int dado;
    Node *proximo;
};

struct Queue {
    Node *inicio; 
    Node *fim;
    int max;
    int qtd;
};

// contar elementos
int Contar(struct Queue *&fila) {
  int cont = 0;
  struct Node *aux = fila->inicio;
  while (aux != NULL) {
    cont++;
    aux = aux->proximo;
  }
  printf("\n\nExistem %d elementos na fila", cont);
  return cont;
}

// verificar se esta vazia
void isEmpty(struct Queue *&fila) {
  if (fila->inicio == NULL) {
    printf("\n\nFila vazia");
  } else {
    printf("\n\nFila nao esta vazia");
  }
}

// verificar se esta cheia
void isFull(struct Queue *&fila) {
  int cont = 0;
  struct Node *aux = fila->inicio;
  while (aux != NULL) {
    cont++;
    aux = aux->proximo;
  }
  if (cont < fila->max) {
    printf("\n\nFila nao esta cheia");
  } else {
    printf("\n\nFila cheia");
  }
}

// Adicionar elemento
void Enqueue(struct Queue *&fila, int num) {
  struct Node *novo;
  novo = (Node *)calloc(1, sizeof(struct Node));

  int cont = 0;
  struct Node *aux = fila->inicio;
  while (aux != NULL) {
    cont++;
    aux = aux->proximo;
  }

  if (novo == NULL) {
    printf("\n\nErro ao adicionar elemento");
  } else if (cont >= fila->max) {
    printf("\n\nErro ao adicionar elemento, fila cheia");
  } else {
    novo->dado = num;
    novo->proximo = NULL;
    if(fila->inicio==NULL){
      fila->inicio = novo;
      fila->fim = novo;
    }else{
      fila->fim->proximo = novo;
      fila->fim = novo;
    }
      
  }
}

// Consultar elemento
void Proucurar(struct Queue *&fila, int i) {
  int flag = 0;
  struct Node *aux;
  aux = fila->inicio;
  while (aux != NULL) {
    if (aux->dado == i) {
      printf("\n\nElemento pertence a fila");
      flag = 1;
    }
    aux = aux->proximo;
  }
  if (flag == 0)
    printf("\n\nElemento não pertence a fila");
}

// Remover elemento
void Dequeue(struct Queue *&fila) {
  int count = 0;
  struct Node *atual;
  if (fila->inicio == NULL) {
    printf("\n\nFila vazia!");
  } else {
    atual = fila->inicio;
    fila->inicio = atual->proximo;
    free(atual);
    printf("\n\nElemento removido!");
  }
}

// Listar elementos
void Listar(struct Queue *&fila) {
  if (fila->inicio == NULL) {
    printf("\n\nFila vazia!");
  } else {
    struct Node *aux;
    aux = fila->inicio;
    printf("\n\nElementos: ");
    while (aux != NULL) {
      printf("%d ", aux->dado);
      aux = aux->proximo;
    }
  }
}

int main() {
  int opc = 0;
  int n = 0;
  struct Queue *fila = (struct Queue *)calloc(1, sizeof(struct Queue));
  fila->qtd = 0;
  fila->max = 5;

  while (1) {
    printf("\n\n1 - Verificar se a fila esta "
           "cheia\n2 - Verificar se a fila esta vazia\n3 - Retornar "
           "quantidade de elementos\n4 - Consultar elemento\n5 - Exibir "
           "elementos da fila\n6 - Enfileirar\n7 - Desenfileirar\n\n Escolha a "
           "opcao: ");
    scanf("%d", &opc);

    if (opc > 7 || opc < 1) {
      printf("\n\nOpcao invalida");
      continue;
    }
    if (opc == 1) {
      isFull(fila);
    }
    if (opc == 2) {
      isEmpty(fila);
    }
    if (opc == 3) {
      Contar(fila);
    }
    if (opc == 4) {
      printf("\n\nValor que deseja proucurar: ");
      scanf("%d", &n);
      Proucurar(fila, n);
    }
    if (opc == 5) {
      Listar(fila);
    }
    if (opc == 6) {
      printf("\n\nValor que deseja adicionar: ");
      scanf("%d", &n);
      Enqueue(fila, n);
    }
    if (opc == 7) {
      Dequeue(fila);
    }
  }
}