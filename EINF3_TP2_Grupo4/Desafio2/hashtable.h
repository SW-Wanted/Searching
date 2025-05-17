#ifndef TABELAHASH_H
#define TABELAHASH_H

#include <stdbool.h>

typedef struct no No;
typedef struct hashTable HashTable;

HashTable* criarHashTable(int tamanho);
void inserirChave(HashTable* th, int chave);
bool removerChave(HashTable* th, int chave);
bool buscarChave(HashTable* th, int chave);
void imprimirChaves(HashTable* th);
void liberarHashTable(HashTable* th);

#endif
