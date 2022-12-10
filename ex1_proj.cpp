#include <stdio.h>
#include <stdlib.h>
#define TAM 5

struct Node {
  int dado;
  struct Node *proximo;
};

struct Stack {
  Node *topo;
  int max;
  int qtd;
};

// contar elementos
int Contar(struct Stack *&pilha) {
  int cont = 0;
  struct Node *aux = pilha->topo;
  while (aux != NULL) {
    cont++;
    aux = aux->proximo;
  }
  printf("\n\nExistem %d elementos na pilha", cont);
  return cont;
}

// verificar se esta vazia
void isEmpty(struct Stack *&pilha) {
  if (pilha->topo == NULL) {
    printf("\n\nPilha vazia");
  } else {
    printf("\n\nPilha nao esta vazia");
  }
}

// verificar se esta cheia
void isFull(struct Stack *&pilha) {
  int cont = 0;
  struct Node *aux = pilha->topo;
  while (aux != NULL) {
    cont++;
    aux = aux->proximo;
  }
  if (cont < pilha->max) {
    printf("\n\nPilha nao esta cheia");
  } else {
    printf("\n\nPilha cheia");
  }
}

// Adicionar elemento
void Push(struct Stack *&pilha, int num) {
  struct Node *novo;
  novo = (Node *)calloc(1, sizeof(struct Node));

  int cont = 0;
  struct Node *aux = pilha->topo;
  while (aux != NULL) {
    cont++;
    aux = aux->proximo;
  }

  if (novo == NULL) {
    printf("\n\nErro ao adicionar elemento");
  } else if (cont >= pilha->max) {
    printf("\n\nErro ao adicionar elemento, pilha cheia");
  } else {
    novo->dado = num;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
  }
}

// Consultar elemento
void Proucurar(struct Stack *&pilha, int i) {
  int flag = 0;
  struct Node *aux;
  aux = pilha->topo;
  while (aux != NULL) {
    if (aux->dado == i) {
      printf("\n\nElemento pertence a pilha");
      flag = 1;
    }
    aux = aux->proximo;
  }
  if (flag == 0)
    printf("\n\nElemento não pertence a pilha");
}

// Remover elemento
void Pop(struct Stack *&pilha) {
  int count = 0;
  struct Node *atual;
  if (pilha->topo == NULL) {
    printf("\n\nPilha vazia!");
  } else {
    atual = pilha->topo;
    pilha->topo = atual->proximo;
    free(atual);
    printf("\n\nElemento removido!");
  }
}

// Listar elementos
void Listar(struct Stack *&pilha) {
  if (pilha->topo == NULL) {
    printf("\n\nPilha vazia!");
  } else {
    struct Node *aux;
    aux = pilha->topo;
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
  struct Stack *pilha = (struct Stack *)calloc(1, sizeof(struct Stack));
  pilha->qtd = 0;
  pilha->max = 5;

  while (1) {
    printf("\n\n1 - Verificar se a pilha esta "
           "cheia\n2 - Verificar se a pilha esta vazia\n3 - Retornar "
           "quantidade de elementos\n4 - Consultar elemento\n5 - Exibir "
           "elementos da pilha\n6 - Empilhar\n7 - Desempilhar\n\n Escolha a "
           "opcao: ");
    scanf("%d", &opc);

    if (opc > 7 || opc < 1) {
      printf("\n\nOpcao invalida");
      continue;
    }
    if (opc == 1) {
      isFull(pilha);
    }
    if (opc == 2) {
      isEmpty(pilha);
    }
    if (opc == 3) {
      Contar(pilha);
    }
    if (opc == 4) {
      printf("\n\nValor que deseja proucurar: ");
      scanf("%d", &n);
      Proucurar(pilha, n);
    }
    if (opc == 5) {
      Listar(pilha);
    }
    if (opc == 6) {
      printf("\n\nValor que deseja adicionar: ");
      scanf("%d", &n);
      Push(pilha, n);
    }
    if (opc == 7) {
      Pop(pilha);
    }
  }
}