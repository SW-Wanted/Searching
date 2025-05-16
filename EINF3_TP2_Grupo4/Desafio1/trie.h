#include <stdbool.h>
#include <stdbool.h> // para usar tipo booleano
#include <ctype.h>   // para usar funcoes de manipulacao de caracteres

#define ALFABETO_TAMANHO 52

// Estrutura para um no da trie R-Way
typedef struct No{
	struct NoTrie* filhos[ALFABETO_TAMANHO];
	bool fimDaPalavra; // indica se este no marca o final de uma palavra
}NoTrie;

// Prototipos das funcoes
NoTrie* criarNo(); // cria novos nos na trie
void inserir(NoTrie* raiz, char *Palavra ); // insere a palavra na trie
bool buscar(NoTrie* raiz, char *palavra); // busca a palavra na trie, retorna true se encontrada e false caso contrario
void imprimirPalavras(NoTrie* no, char prefixo[], int profundidade);
void imprimirEmOrdem(NoTrie* raiz);
bool removerPalavra(NoTrie* no, char *palavra, int profundidade);
bool temFilhos(NoTrie* no);
void remover(NoTrie* raiz, char *palavra);

