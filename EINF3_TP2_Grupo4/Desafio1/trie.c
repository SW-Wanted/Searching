#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // para usar o tolower() e o toupper()
#include "Trie_RWay.h"

//Função para criar um novo nó na Trie
NoTrie* criarNo(){
	NoTrie* novoNo = (NoTrie*)malloc(sizeof(NoTrie));
	novoNo->fimDaPalavra = false;
	
	//Inicializando todos os ponteiros no array filhos do novo nó como NULL. Inicialmente nenhum nó tem filho
	int i;
	for(i=0;i<ALFABETO_TAMANHO;i++){
		novoNo->filhos[i] = NULL;
	}
	return novoNo;
}

//Função para calcular o índice da letra
int calcularIndice(char letra){
	letra = tolower(letra); //converte a letra recebida para minúscula
	return letra - 'a';
}

//Função para inserir uma palavra na TRIE
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

//Função para buscar uma palavra na TRIE
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

//Função auxiliar para imprimir palavras em ordem alfabética
//prefixo acumula os caracteres do caminho percorrido na Trie.
//profundidade indica a posição onde o caractere deve ser adicionado no prefixo.
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

//Função para imprimir todas as palavras na trie na ordem correcta
void imprimirEmOrdem(NoTrie* raiz){
	char prefixo[256];
	imprimirPalavras(raiz, prefixo, 0);
}

//Função recursiva para remover uma palavra da TRIE
bool removerPalavra(NoTrie* no, char *palavra, int profundidade){
	if(no == NULL){
		return false;
	}
	if(profundidade == strlen(palavra)){
		if(no->fimDaPalavra){
			no->fimDaPalavra = false;
			return true;
		}
		return false; //palavra não encontrada
	}
	int indice = calcularIndice(palavra[profundidade]);
	if(removerPalavra(no->filhos[indice], palavra, profundidade + 1)){
		//se o filho foi removido e não tem mais filhor
		if(!no->fimDaPalavra && !temFilhos(no)){
			free(no);
			no = NULL;
		}
		return true;
	}
	return false;
}
//funcão auxiliar para verificar se um nó tem filhos
bool temFilhos(NoTrie* no){
	int i;
	for(i=0; i<ALFABETO_TAMANHO;i++){
		if(no->filhos[i] != NULL){
			return true;
		}
	}
	return false;
}

//Função para remover uma palavra da TRIE
void remover(NoTrie *raiz, char *palavra){
	removerPalavra(raiz, palavra, 0);
}

