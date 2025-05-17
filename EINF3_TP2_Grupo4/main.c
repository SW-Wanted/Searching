#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Desafio1/trie_rway.h"
#include "Desafio2/hashtable.h"

#define MAX_WORD 100

void menuTrie() {
    NoTrie* raiz = criarNo();
    int op;
    char palavra[MAX_WORD];

    do {
        printf("\n====== MENU TRIE R-WAY ======\n");
        printf("1. Inserir palavra\n");
        printf("2. Remover palavra\n");
        printf("3. Imprimir em ordem alfabetica\n");
        printf("4. Pesquisar palavra\n");
        printf("5. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        getchar(); // Limpa o buffer

        switch (op) {
            case 1:
                printf("Digite a palavra para inserir: ");
                fgets(palavra, MAX_WORD, stdin);
                palavra[strcspn(palavra, "\n")] = 0;
                inserir(raiz, palavra);
                printf("Palavra %s inserida\n", palavra);
                break;
            case 2:
                printf("Digite a palavra para remover: ");
                fgets(palavra, MAX_WORD, stdin);
                palavra[strcspn(palavra, "\n")] = 0;
                remover(raiz, palavra);
                printf("Palavra %s removida se existia\n", palavra);
                break;
            case 3:
                printf("Palavras na Trie em ordem alfabetica\n");
                imprimirEmOrdem(raiz);
                break;
            case 4:
                printf("Digite a palavra para pesquisar: ");
                fgets(palavra, MAX_WORD, stdin);
                palavra[strcspn(palavra, "\n")] = 0;
                if (buscar(raiz, palavra))
                    printf("Palavra %s encontrada\n", palavra);
                else
                    printf("Palavra %s nao encontrada\n", palavra);
                break;
            case 5:
                printf("Voltando ao menu principal\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (op != 5);

    // Liberacao de memoria da Trie pode ser implementada se desejar
}

void menuHashTable() {
    int size, op, key;
    printf("\nDigite o tamanho da Hash Table: ");
    scanf("%d", &size);
    HashTable* ht = criarHashTable(size);

    do {
        printf("\n====== MENU HASH TABLE ======\n");
        printf("1. Inserir chave\n");
        printf("2. Remover chave\n");
        printf("3. Imprimir chaves\n");
        printf("4. Pesquisar chave\n");
        printf("5. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite a chave para inserir: ");
                scanf("%d", &key);
                inserirChave(ht, key);
                printf("Chave %d inserida\n", key);
                break;
            case 2:
                printf("Digite a chave para remover: ");
                scanf("%d", &key);
                if (removerChave(ht, key))
                    printf("Chave %d removida\n", key);
                else
                    printf("Chave %d nao encontrada\n", key);
                break;
            case 3:
                printf("Chaves na Hash Table\n");
                imprimirChaves(ht);
                break;
            case 4:
                printf("Digite a chave para pesquisar: ");
                scanf("%d", &key);
                if (buscarChave(ht, key))
                    printf("Chave %d encontrada\n", key);
                else
                    printf("Chave %d nao encontrada\n", key);
                break;
            case 5:
                printf("Voltando ao menu principal\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (op != 5);

    liberarHashTable(ht);
}

int main() {
    int op;
    do {
        printf("\n==============================\n");
        printf("   Segunda Prova Parcial Menu   \n");
        printf("==============================\n");
        printf("1. Testar Trie R-Way\n");
        printf("2. Testar Hash Table\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                menuTrie();
                break;
            case 2:
                menuHashTable();
                break;
            case 3:
                printf("Obrigado por usar o programa\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (op != 3);

    return 0;
}
