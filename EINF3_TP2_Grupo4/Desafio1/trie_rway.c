#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "trie_rway.h"

struct noTrie{
	struct noTrie* filhos[ALFABETO_TAMANHO];
	bool fimDaPalavra;
};

// Funcao para criar um novo no na Trie
NoTrie* criarNo(){
	NoTrie* novoNo = (NoTrie*)malloc(sizeof(NoTrie));
	if (novoNo == NULL) {
		fprintf(stderr, "Erro ao alocar memoria para novo no da Trie.\n");
		exit(EXIT_FAILURE);
	}
	novoNo->fimDaPalavra = false;
	
	// Inicializa todos os ponteiros no array filhos do novo no como NULL. Inicialmente nenhum no tem filho
	int i;
	for(i=0;i<ALFABETO_TAMANHO;i++){
		novoNo->filhos[i] = NULL;
	}
	return novoNo;
}

// Funcao para calcular o indice da letra
int calcularIndice(char letra){
	letra = tolower(letra); // converte a letra recebida para minuscula
	return letra - 'a';
}

// Funcao para inserir uma palavra na TRIE
void inserir(NoTrie* raiz, char *palavra){
	NoTrie* atual = raiz;
	int comprimento = strlen(palavra);
	int i, indice;
	
	for(i=0;i<comprimento;i++){
		indice = calcularIndice(palavra[i]);
		if(atual->filhos[indice] == NULL){
			atual->filhos[indice] = criarNo();
		}
		atual = atual->filhos[indice];
	}
	atual->fimDaPalavra = true;
	
}

// Funcao para buscar uma palavra na TRIE
bool buscar(NoTrie* raiz, char *palavra){
	NoTrie *atual = raiz;
	int comprimento = strlen(palavra);
	int i, indice;
	
	for(i=0;i<comprimento;i++){
		indice = calcularIndice(palavra[i]);
		if(atual->filhos[indice] == NULL){
			return false;	
		}
		atual = atual->filhos[indice];
	}
	
	return(atual != NULL && atual->fimDaPalavra);
}

// Funcao auxiliar para imprimir palavras em ordem alfabetica
// prefixo acumula os caracteres do caminho percorrido na Trie
// profundidade indica a posicao onde o caractere deve ser adicionado no prefixo
void imprimirPalavras(NoTrie* no, char prefixo[], int profundidade){
	if(no == NULL){
		return;
	}
	
	if(no->fimDaPalavra){
		prefixo[profundidade] = '\0';
		printf("%s\n", prefixo);
	}
	int i;
	for(i=0;i < ALFABETO_TAMANHO; i++){
		 if(no->filhos[i] != NULL){
		 	prefixo[profundidade] = i + 'a';
		 	imprimirPalavras(no->filhos[i], prefixo, profundidade + 1);
		 }
	}	
}

// Funcao para imprimir todas as palavras na trie na ordem correta
void imprimirEmOrdem(NoTrie* raiz){
	char prefixo[256];
	imprimirPalavras(raiz, prefixo, 0);
}

// Funcao recursiva para remover uma palavra da TRIE
bool removerPalavra(NoTrie* no, char *palavra, int profundidade){
	if(no == NULL){
		return false;
	}
	if(profundidade == strlen(palavra)){
		if(no->fimDaPalavra){
			no->fimDaPalavra = false;
			return true;
		}
		return false; // palavra nao encontrada
	}
	int indice = calcularIndice(palavra[profundidade]);
	if(removerPalavra(no->filhos[indice], palavra, profundidade + 1)){
		// se o filho foi removido e nao tem mais filhos
		if(!no->fimDaPalavra && !temFilhos(no)){
			free(no);
			no = NULL;
		}
		return true;
	}
	return false;
}
// Funcao auxiliar para verificar se um no tem filhos
bool temFilhos(NoTrie* no){
	int i;
	for(i=0; i<ALFABETO_TAMANHO;i++){
		if(no->filhos[i] != NULL){
			return true;
		}
	}
	return false;
}

// Funcao para remover uma palavra da TRIE
void remover(NoTrie *raiz, char *palavra){
	removerPalavra(raiz, palavra, 0);
}
