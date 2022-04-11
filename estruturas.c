#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "pilha.h"

void imprimePilha(veiculoPilha *listaBusca) {
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-RESULTADO DE BUSCA EM PILHA-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

    while (listaBusca->prox != NULL) {
        printf("\n%s %s %s %s %s %s %s %s %s %s %s %s", listaBusca->prox->modelo, listaBusca->prox->marca, listaBusca->prox->tipo, listaBusca->prox->ano, listaBusca->prox->km, listaBusca->prox->potencia, listaBusca->prox->combustivel, listaBusca->prox->cambio, listaBusca->prox->direcao, listaBusca->prox->cor, listaBusca->prox->portas, listaBusca->prox->placa);
        listaBusca = listaBusca->prox;
    }
}

void insere_pilha(veiculoPilha * ptlista, veiculo *ant) {

    veiculoPilha* ptr;
    ptr = malloc(sizeof (veiculoPilha));
    strncpy(ptr->marca, ant->marca, 100);
    strncpy(ptr->modelo, ant->modelo, 100);
    strncpy(ptr->tipo, ant->tipo, 100);
    strncpy(ptr->ano, ant->ano, 100);
    strncpy(ptr->km, ant->km, 100);
    strncpy(ptr->potencia, ant->potencia, 100);
    strncpy(ptr->combustivel, ant->combustivel, 100);
    strncpy(ptr->cambio, ant->cambio, 100);
    strncpy(ptr->direcao, ant->direcao, 100);
    strncpy(ptr->cor, ant->cor, 100);
    strncpy(ptr->portas, ant->portas, 100);
    strncpy(ptr->placa, ant->placa, 100);

    ptr->prox = ptlista->prox;
    ptlista->prox = ptr;
    ptlista->tamanho++;

}

veiculoPilha * remove_inicio(veiculoPilha * ptlista) {
    veiculoPilha * ptr;

    if (ptlista->tamanho == 0)
        return NULL;

    ptr = ptlista->prox;
    ptlista->prox = ptr->prox;
    ptr->prox = NULL;
    ptlista->tamanho--;
    return ptr;
}