/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   pilha.h
 * Author: arthu
 *
 * Created on 24 de março de 2022, 21:56
 */

#ifndef PILHA_H
#define PILHA_H

#include "header.h"
typedef veiculo veiculoPilha;

#ifdef __cplusplus
extern "C" {
#endif
void insere_pilha(veiculoPilha * ptlista, veiculo *ant);
void imprimePilha(veiculoPilha *listaBusca);
veiculoPilha * remove_inicio(veiculoPilha * ptlista);


#ifdef __cplusplus
}
#endif

#endif /* PILHA_H */

