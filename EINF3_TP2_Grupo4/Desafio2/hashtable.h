#ifndef TABELAHASH_H
#define TABELAHASH_H

#include <stdbool.h>

// Estrutura para um no na cadeia
typedef struct No {
    int chave;
    struct No* proximo;
} No;

// Estrutura para a tabela hash
typedef struct HashTable {
    int tamanho;    // Numero de baldes
    No** tabela;    // Array de ponteiros para cadeias
} HashTable;

// Prototipos das funcoes
HashTable* criarHashTable(int tamanho);
void inserirChave(HashTable* th, int chave);
bool removerChave(HashTable* th, int chave);
bool buscarChave(HashTable* th, int chave);
void imprimirChaves(HashTable* th);
void liberarHashTable(HashTable* th);

#endif // TABELAHASH_H
