/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   header.h
 * Author: arthu
 *
 * Created on 15 de março de 2022, 14:57
 */

#ifndef HEADER_H
#define HEADER_H


typedef struct veiculo_ {
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
    struct veiculo_ *prox;

} veiculo;


#ifdef __cplusplus
extern "C" {
#endif
    void menu();
    void ptlista_init();
    veiculo *remove_veiculo(char placa[100]);
    void commit_bd();
    int insere_enc(char placa[100]);
    void grava_banco();
    void busca_lista(char placa[100], veiculo **ant, veiculo **pont, int opt);
    void encerra_lista();
    veiculo *inicia_lista();
    void imprime();
    void encerra_lista();

#endif /* HEADER_H */


