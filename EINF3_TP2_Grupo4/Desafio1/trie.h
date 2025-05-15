
#include <stdbool.h>
#include <stdbool.h> //para usar o tipo boleano
#include <ctype.h>   //para usar funções de manipulação de caracteres

#define ALFABETO_TAMANHO 52

//Estrutura para um nó da trie R-Way
typedef struct No{
	struct NoTrie* filhos[ALFABETO_TAMANHO];
	bool fimDaPalavra; //indica se este nó marca o final de uma palavra.
}NoTrie;

//Protótipos das funções
NoTrie* criarNo(); //Função usada para criar novos nós na trie
void inserir(NoTrie* raiz, char *Palavra ); //Esta função insere a palavra na Trie
bool buscar(NoTrie* raiz, char *palavra); //busca a palavra na Trie, retorna true se a palavra for encontrada e false caso contrário.
void imprimirPalavras(NoTrie* no, char prefixo[], int profundidade);
void imprimirEmOrdem(NoTrie* raiz);
bool removerPalavra(NoTrie* no, char *palavra, int profundidade);
bool temFilhos(NoTrie* no);
void remover(NoTrie* raiz, char *palavra);

