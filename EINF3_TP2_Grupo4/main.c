#include <stdio.h>
#include "Trie_RWay.c"

int main(int argc, char *argv[]) {
	NoTrie* raiz = criarNo();
	char palavra[256];
	int opcao;
	
	do{
		printf("\n------------MENU------------\n");
		printf("1. Inserir palavra.\n");
		printf("2. Remover palavra.\n");
		printf("3. Buscar palavra.\n");
		printf("4. Imprimir palavras em ordem alfabética.\n");
		printf("5. Sair\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1: 
				printf("Digite a palavra a inserir: ");
				scanf("%s", palavra);
				inserir(raiz, palavra);
				printf("Palavra inserida com sucesso.\n");
				break;
			case 2: 
				printf("Digite a palavra a remover: ");
				scanf("%s", palavra);
				remover(raiz, palavra);
				printf("Palavra removida com sucesso.\n");
				break;
			case 3: 
				printf("Digite a palavra a buscar: ");
				scanf("%s", palavra);
				if(buscar(raiz, palavra)){
					printf("Palavra encontrada.\n");
				}
				else{
					printf("Palavra não encontrada.\n");
				}
			case 4: 
				printf("Palavras na TRIE em ordem alfabética: \n");
				imprimirEmOrdem(raiz);
				break;
			case 5:
				printf("Saindo...\n");
			default:
				printf("Opcao invalida.\n");
		}
	}
	while(opcao != 5);
	
	return 0;
}
