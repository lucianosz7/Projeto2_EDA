/*********************************************************************************************
* EDA 2017/2 - ESTRUTURAS DE DADOS E ALGORITMOS (Prof. Fernando W. Cruz)
* Projeto  - Arvores e funcoes de hash
* Verifica corretude de palavras de um arquivo-texto segundo um dicionario carregado em RAM.
 *********************************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <stdbool.h>
#include<stdlib.h>


struct NO{
  int info;
  int altura;
  struct NO *esq;
  struct NO *dir;
};
typedef struct NO* ArvAVL;

int insere_ArvAvl(ArvAVL *raiz,int valor);



int altura_No(struct NO* No){
  if(No==NULL){
    return -1;
  }
  else
    return No->altura;
}
int fatorBalanceamento_No(struct NO* No){
  return labs(altura_No(No->esq)-altura_No(No->dir));
}
int maior(int x,int y){
  if(x>y){
    return x;
  }
  else
    return y;
}
void RotacaoLeft(ArvAVL *raiz){
  struct NO *no;
  no = (*raiz)->esq;
  (*raiz)->esq = no->dir;
  no->dir = *raiz;
  (*raiz)->altura = maior(altura_No((*raiz)->esq),altura_No((*raiz)->dir))+1;
  no->altura = maior(altura_No(no->esq),(*raiz)->altura)+1;
  *raiz=no;
}
void RotacaoRight(ArvAVL *raiz){
  struct NO *no;
  no= (*raiz)->dir;
  (*raiz)->dir = no->esq;
  no->esq = (*raiz);
  (*raiz)->altura = maior(altura_No((*raiz)->esq),altura_No((*raiz)->dir))+1;
  no->altura=maior(altura_No(no->dir),(*raiz)->altura)+1;
  (*raiz) = no;
}
void RotacaoLR(ArvAVL *raiz){
  RotacaoRight(&(*raiz)->esq);
  RotacaoLeft(raiz);
}

int insere_ArvAvl(ArvAVL *raiz,int valor){
  int AuxRaiz;
  if(*raiz == NULL){
    struct NO *novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo==NULL)
      return 0;
    novo->info = valor;
    novo->altura = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;
    return 1;
  }
  struct NO *atual = *raiz;
  if(valor < atual->info){
    if((AuxRaiz=insere_ArvAvl(&(atual->esq),valor))==1){
      if(fatorBalanceamento_No(atual) >= 2){
        if(valor < (*raiz)->esq->info){
          RotacaoLeft(raiz);
        }else{
          RotacaoLR(raiz);
        }
      }
    }
  }else{
    if(valor>atual->info){
      if((AuxRaiz=insere_ArvAvl(&(atual->dir),valor))==1){
        if(fatorBalanceamento_No(atual) >=2){
          if((*raiz)->dir->info < valor){
            RotacaoRight(raiz);
          }else{
            RotacaoLR(raiz);
          }
        }
      }
    }else{
      printf("valor duplicado\n");
      return 0;
    }
  }
  atual->altura = maior(altura_No(atual->esq),altura_No(atual->dir))+1;
  return AuxRaiz;
}
int main(){
  ArvAVL *raiz;
  int x ;
  //InicializaAVL(raiz);
  x = insere_ArvAvl(raiz,4);

  return 0;
}
