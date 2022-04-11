/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "header.h"
#include "bst.h"
#include "pilha.h"
veiculo *ptlista;
noArvore *arLista;

void ptlista_init() {
    setlocale(LC_ALL, "Portuguese");
    ptlista = inicia_lista();
    arLista = iniciaNo();
}

void imprime() {
    veiculo *ptr = ptlista->prox;
    int cont = 0, opt = -1;
    while (ptr != NULL) {
        printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("\n%i %s %s %s %s %s %s %s %s %s %s %s %s", cont, ptr->modelo, ptr->marca, ptr->tipo, ptr->ano, ptr->km, ptr->potencia, ptr->combustivel, ptr->cambio, ptr->direcao, ptr->cor, ptr->portas, ptr->placa);

        cont++;
        ptr = ptr->prox;
    }
    while (opt != 1) {
        printf("\n> Deseja voltar para o menu? \n1 - Sim\n0 - Nao\n> ");
        scanf("%d", &opt);
    }
}

veiculo *inicia_lista() {

    veiculo *ptr = malloc(sizeof (veiculo));
    ptr->tamanho++;
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
    strncpy(ptr->placa, "", 100);
    ptr->prox = NULL;

    return ptr;
}

/**
 * Desaloca o espaco previamente
 * alocado para a lista encadeada.
 */
void encerra_lista() {
    veiculo *ant = ptlista->prox;
    veiculo *pont = ant->prox;

    while (pont != NULL) {
        free(ant);
        ant = pont;
        pont = pont->prox;
    }
    free(ant);
    free(ptlista);
}

void busca_lista(char placa[100], veiculo **ant, veiculo **pont, int opt) {
    *ant = ptlista;
    *pont = NULL;

    veiculo *ptr = ptlista->prox;

    if (opt == 1) {
        while (ptr != NULL) {
            if (strcmp(placa, ptr->placa) > 0) {
                *ant = ptr;
                ptr = ptr->prox;
            } else {
                if (strcmp(placa, ptr->placa) == 0) {
                    *pont = ptr;
                }
                ptr = NULL;
            }
        }
    }
}

void grava_banco() {
    FILE *bd;
    int i = 0;
    veiculo *ant, *pont;
    char modelo[100], marca[100], tipo[100], ano[100], km[100], potencia[100], combustivel[100], cambio[100], direcao[100], cor[100], portas[100], placa[100];
    char linha[100];
    bd = fopen("banco.txt", "r");
    if (!bd) {
        printf("Falha na abertura de arquivo.");
        return;
    }
    fgets(linha, 100, bd);
    fgets(linha, 100, bd);

    // Criar para cada linha, uma instância de veiculo
    while (!feof(bd)) {
        fscanf(bd, "%s %s %s %s %s %s %s %s %s %s %s %s", modelo, marca, tipo, ano, km, potencia, combustivel, cambio, direcao, cor, portas, placa);

        busca_lista(placa, &ant, &pont, 1);

        if (pont == NULL) {
            veiculo *ptr = malloc(sizeof (veiculo));
            strncpy(ptr->modelo, modelo, 100);
            strncpy(ptr->marca, marca, 100);
            strncpy(ptr->tipo, tipo, 100);
            strncpy(ptr->ano, ano, 100);
            strncpy(ptr->km, km, 100);
            strncpy(ptr->potencia, potencia, 100);
            strncpy(ptr->combustivel, combustivel, 100);
            strncpy(ptr->cambio, cambio, 100);
            strncpy(ptr->direcao, direcao, 100);
            strncpy(ptr->cor, cor, 100);
            strncpy(ptr->portas, portas, 100);
            strncpy(ptr->placa, placa, 100);
            ptr->prox = ant->prox;
            ant->prox = ptr;
        }
    }
    fclose(bd);
}

int insere_enc(char placa[100]) {
    char modelo[100], marca[100], tipo[100], ano[100], km[100], potencia[100], combustivel[100], cambio[100], direcao[100], cor[100], portas[100];

    int retorno = -1;
    // ant,em busca_enc, recebe a lista INTEIRA!
    veiculo *ant;
    // pont é indexado na memória em busca_enc.
    veiculo *pont;

    busca_lista(placa, &ant, &pont, 1);

    if (pont == NULL) {
        printf("Digite os dados do novo veiculo: \n(obs: valores separados por ' ' espaços)\n>");
        scanf("%s %s %s %s %s %s %s %s %s %s %s", modelo, marca, tipo, ano, km, potencia, combustivel, cambio, direcao, cor, portas);

        // Cada nó gerou um malloc.
        veiculo *ptr = malloc(sizeof (veiculo));
        ptr->tamanho++;
        strncpy(ptr->modelo, modelo, 100);
        strncpy(ptr->marca, marca, 100);
        strncpy(ptr->tipo, tipo, 100);
        strncpy(ptr->ano, ano, 100);
        strncpy(ptr->km, km, 100);
        strncpy(ptr->potencia, potencia, 100);
        strncpy(ptr->combustivel, combustivel, 100);
        strncpy(ptr->cambio, cambio, 100);
        strncpy(ptr->direcao, direcao, 100);
        strncpy(ptr->cor, cor, 100);
        strncpy(ptr->portas, portas, 100);
        strncpy(ptr->placa, placa, 100);
        ptr->prox = ant->prox;
        ant->prox = ptr;

        retorno = 0;
    }

    return retorno;
}

void commit_bd() {
    FILE *bd;
    veiculo *ant, *pont;

    bd = fopen("banco.txt", "w");
    if (!bd) {
        printf("Falha na abertura de arquivo.");
        return;
    }
    fprintf(bd, "# modelo marca tipo ano km potência_do_motor combustível câmbio direção cor portas placa");
    fprintf(bd, "\n\n");
    veiculo *ptr = ptlista->prox;
    while (ptr != NULL) {

        fprintf(bd, "%s %s %s %s %s %s %s %s %s %s %s %s\n", ptr->modelo, ptr->marca, ptr->tipo, ptr->ano, ptr->km, ptr->potencia, ptr->combustivel, ptr->cambio, ptr->direcao, ptr->cor, ptr->portas, ptr->placa);
        ptr = ptr->prox;
    }
    fclose(bd);
}

veiculo *remove_veiculo(char placa[100]) {
    veiculo *ant, *pont;
    busca_lista(placa, &ant, &pont, 1);

    if (pont != NULL) {
        ant->prox = pont->prox;
        return pont;
    }

    return NULL;
}

veiculoPilha *separador(char busca[100]) {
    veiculo *ptr = ptlista->prox;
    veiculoPilha *listaBusca = inicia_lista();
    veiculoPilha *aux;
    int controlador = 0;

    while (ptr != NULL) {
        if (strcmp(busca, ptr->modelo) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->marca) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->tipo) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->ano) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->km) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->potencia) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->combustivel) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->cambio) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->direcao) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->cor) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->portas) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (strcmp(busca, ptr->placa) == 0) {
            aux = ptr;
            controlador = 1;
        }
        if (controlador == 1) {
            insere_pilha(listaBusca, aux);
        }
        controlador = 0;
        ptr = ptr->prox;
    }
    imprimePilha(listaBusca);
}

void insereBST() {
    veiculo *ptr = ptlista->prox;

    noArvore *noArvore = iniciaNo();

    while (ptr != NULL) {

        if (strncmp(noArvore->placa, ptr->placa, 100) > 0) {
            arLista->dir = insere(noArvore, ptr);
        } else {
            arLista->esq = insere(noArvore, ptr);
        }
        ptr = ptr->prox;
    }

}

void menu() {
    int opt = -1, bsc = 0, ctn = -1;
    char placa[100];

    ptlista_init();
    grava_banco();
    veiculo *ant, *pont;

    while (opt != (-777)) {
        printf("\nOla! Seja bem vindo(a) ao sistema de gerenciamento de busca.\n");
        printf("\n1 - Incluir novo veiculo \n2 - Excluir um veiculo\n3 - Busca\n4 - Arvores\n5 - Relatorio das Arvores\n6 - Relatorio\n0 - Sair\nOpcao: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("Digite a placa do novo veiculo: ");
                scanf("%s", placa);
                if (insere_enc(placa) == 0) {
                    printf("\nVeiculo inserido com sucesso");
                } else {
                    printf("\nVeiculo ja consta na base de dados");
                }
                break;
            case 2:
                printf("Digite a placa do novo veiculo: ");
                scanf("%s", placa);
                if (remove_veiculo(placa) == NULL) {
                    printf("\nVeiculo nao existe.");
                } else {
                    printf("\nVeiculo removido com sucesso.");
                }
                break;
            case 3:
                printf("\n1 - Encadeada\n2 - Pilha\nOpcao: ");
                scanf("%d", &bsc);
                if (bsc == 1) {
                    while (ctn != 0) {
                        printf("Digite um item veiculo: ");
                        scanf("%s", placa);
                        /*
                        printf("\nRealizar nova busca?\n1 - Sim\n0 - Nao\n> ");
                        scanf("%d", &ctn);
                        system("clear || cls");*/
                    }
                } else if (bsc == 2) {
                    while (ctn != 0) {
                        printf("Digite um item veiculo: ");
                        scanf("%s", placa);
                        separador(placa);
                        printf("\nRealizar nova busca?\n1 - Sim\n0 - Nao\n> ");
                        scanf("%d", &ctn);
                        system("clear || cls");
                    }
                } else {
                    printf("Opcao invalida");
                }
                break;
            case 4:
                printf("\n1 - Arvore binaria de busca\n2 - Arvore AVL\nOpcao: ");
                scanf("%d", &bsc);

                if (bsc == 1)
                    insereBST();
                if (bsc == 2)
                break;
            case 5:
                //Relatório de árvores
                printf("\n1 - BST\n2 - AVL\nOpcao: ");
                scanf("%d", &bsc);
                if (bsc == 1)
                    imprimeArvore(arLista);
                if (bsc == 2)
                    imprimeArvore(arLista);
                printf("\nRealizar nova busca?\n1 - Sim\n0 - Nao\n> ");
                scanf("%d", &ctn);
                system("clear || cls");
                break;
            case 6:
                //Relatório lista principal
                imprime();
                break;
            case 0:
                opt = (-777);
                break;
            default:
                printf("Opcao invalida.");
                break;
        }
        system("cls || clear");
    }
}
