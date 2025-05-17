#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

// Estrutura para um no na cadeia
struct no {
    int chave;
    struct no* proximo;
};

// Estrutura para a tabela hash
struct hashTable {
    int tamanho;    // Numero de baldes
    No** tabela;    // Array de ponteiros para cadeias
};
// Cria uma nova tabela hash
HashTable* criarHashTable(int tamanho) {
    HashTable* th = (HashTable*)malloc(sizeof(HashTable));
    th->tamanho = tamanho;
    th->tabela = (No**)malloc(tamanho * sizeof(No*));
    int i;
    for (i = 0; i < tamanho; i++) {
        th->tabela[i] = NULL;
    }
    return th;
}

// Funcao hash
int funcaoHash(int chave, int tamanho) {
    return chave % tamanho;
}

// Insere uma chave na tabela hash
void inserirChave(HashTable* th, int chave) {
    int indice = funcaoHash(chave, th->tamanho);
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->proximo = th->tabela[indice];
    th->tabela[indice] = novoNo;
}

// Remove uma chave da tabela hash
bool removerChave(HashTable* th, int chave) {
    int indice = funcaoHash(chave, th->tamanho);
    No* atual = th->tabela[indice];
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->chave == chave) {
            if (anterior == NULL) {
                th->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

// Busca uma chave na tabela hash
bool buscarChave(HashTable* th, int chave) {
    int indice = funcaoHash(chave, th->tamanho);
    No* atual = th->tabela[indice];

    while (atual != NULL) {
        if (atual->chave == chave) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

// Imprime todas as chaves na tabela hash
void imprimirChaves(HashTable* th) {
    int i;
    for (i = 0; i < th->tamanho; i++) {
        No* atual = th->tabela[i];
        printf("Balde %d: ", i);
        while (atual != NULL) {
            printf("%d -> ", atual->chave);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

// Libera a tabela hash
void liberarHashTable(HashTable* th) {
    int i;
    for (i = 0; i < th->tamanho; i++) {
        No* atual = th->tabela[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(th->tabela);
    free(th);
}
