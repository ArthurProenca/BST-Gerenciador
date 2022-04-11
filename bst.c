#include "header.h"
#include "bst.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

noArvore *iniciaNo() {
    noArvore *ptr = malloc(sizeof (noArvore));
    strncpy(ptr->modelo, "", 100);
    strncpy(ptr->marca, "", 100);
    strncpy(ptr->tipo, "", 100);
    strncpy(ptr->ano, "", 100);
    strncpy(ptr->km, "", 100);
    strncpy(ptr->potencia, "", 100);
    strncpy(ptr->combustivel, "", 100);
    strncpy(ptr->cambio, "", 100);
    strncpy(ptr->direcao, "", 100);
    strncpy(ptr->cor, "", 100);
    strncpy(ptr->portas, "", 100);
    strncpy(ptr->placa, "AB", 100);
    return ptr;
}

noArvore * busca(noArvore *raiz, char placa[100]) {
    if (raiz == NULL || strcmp(placa, raiz->placa)) {
        return raiz;
    }
    if (strcmp(placa, raiz->placa) > 0) {
        return busca(raiz->esq, placa);
    } else {
        return busca(raiz->dir, placa);
    }
}

noArvore *instancia(noArvore *no, veiculo *veiculo) {

    strncpy(no->modelo, veiculo->modelo, 100);
    strncpy(no->marca, veiculo->marca, 100);
    strncpy(no->tipo, veiculo->tipo, 100);
    strncpy(no->ano, veiculo->ano, 100);
    strncpy(no->km, veiculo->km, 100);
    strncpy(no->potencia, veiculo->potencia, 100);
    strncpy(no->combustivel, veiculo->combustivel, 100);
    strncpy(no->cambio, veiculo->cambio, 100);
    strncpy(no->direcao, veiculo->direcao, 100);
    strncpy(no->cor, veiculo->cor, 100);
    strncpy(no->portas, veiculo->portas, 100);
    strncpy(no->placa, veiculo->placa, 100);
    //no->esq = NULL;
    //no->dir = NULL;

    return no;

}

noArvore *insere(noArvore *raiz, veiculo *no) {
    if (raiz == NULL) {
        return instancia(raiz, no);
    }

    if (busca(raiz, no->placa) != NULL) {
        //free(no);
        return instancia(raiz, no);
    }

    if (strcmp(no->placa, raiz->placa) > 0) {
        raiz->esq = insere(raiz->esq, no);
        
    } else {
        raiz->dir = insere(raiz->dir, no);

    }
    printf("[%s]", raiz->placa);
    return raiz;
}

void imprimeArvore(noArvore * raiz) {
    if (raiz == NULL) {
        printf("Árvore vazia.\n");
        return;
    }

    if (raiz->esq != NULL) {
        imprimeArvore(raiz->esq);
    }
    printf("%s ", raiz->placa);
    if (raiz->dir != NULL) {
        imprimeArvore(raiz->dir);
    }


}

