/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   bst.h
 * Author: arthu
 *
 * Created on 11 de abril de 2022, 12:25
 */

#ifndef BST_H
#define BST_H
typedef struct noArvore_{
    int tamanho;
    char modelo[100];
    char marca[100];
    char tipo[100];
    char ano[100];
    char km[100];
    char potencia[100];
    char combustivel[100];
    char cambio[100];
    char direcao[100];
    char cor[100];
    char portas[100];
    char placa[100];
    struct noArvore_ *esq;
    struct noArvore_ *dir;
} noArvore;

#ifdef __cplusplus
extern "C" {
#endif

noArvore *iniciaNo();
noArvore * busca(noArvore *raiz, char placa[100]);
noArvore *insere(noArvore *raiz, veiculo *no);
void imprimeArvore(noArvore *raiz);

#ifdef __cplusplus
}
#endif

#endif /* BST_H */

