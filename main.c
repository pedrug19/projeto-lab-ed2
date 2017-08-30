#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct hash_table {
	char nome[50];
	int idade;
	int numeroMatricula;
	char sexo;
	struct hash_table *prox;
} HashTable;

//APONTADOR PARA GUARDAR O FIM DA TABELA
HashTable* fim = NULL;

/*
*	PROTÓTIPOS
*/
HashTable* criaHash;
HashTable* insereHash(HashTable *h, int m);
HashTable* removeHash(HashTable *h, int valor);
void exibeHash(HashTable *h);

HashTable* criaHash(){
	/*FUNÇÃO PARA CRIAR A TABELA*/
	return NULL;
}

HashTable* insereHash(HashTable *h, int m){
	/*INSERE ELEMENTOS NO FIM DA TABELA*/
	HashTable *novo = (HashTable *) malloc(sizeof(HashTable));
	
	if(novo == NULL){
		printf("Memoria insuficiente\n");
		exit(1);
	}

	printf("Digite o nome: \n");
	scanf("%s", novo->nome);
	printf("Digite a idade: \n");
	scanf("%d", &novo->idade);
	printf("Digite o numero de matricula: \n");
	scanf("%d", &novo->numeroMatricula);
	printf("Digite o sexo (m ou f): \n");
	scanf("%c", novo->sexo);

	if(h == NULL){
		h = novo;
		fim = novo;
		novo->prox = NULL;
	} else {
		fim->prox = novo;
		novo->prox = NULL;
		fim = novo;
	}

	return h;
}

HashTable* removeHash(HashTable *h, int valor){
	int achou = 0;

	if(h == NULL){
		/*VERIFICANDO SE A TABELA ESTÁ VAZIA*/
		printf("Tabela vazia! \n");
	} else {
		/*CASO A TABELA TENHA PELO MENOS UM VALOR*/
		HashTable *aux = h;
		HashTable *aux2 = h;

		if(aux->prox == NULL){
		/*VERIFICANDO SE A LISTA POSSUI APENAS UM VALOR*/	
			if(aux->numeroMatricula == valor){
				h = NULL;
				fim = NULL;
				free(aux);
			} else {
				printf("Valor não encontrado!\n");
			}
		} else {
			/*CASO A LISTA POSSUA MAIS DE UM VALOR*/
			while(aux->prox != NULL){
				/*VERIFICANDO SE TEMOS O VALOR*/
				if(aux->numeroMatricula == valor){
					achou = 1;
					break;
				} else {
					aux = aux->prox;
				}
			}

			if(achou){
				//while(aux2)

			}
		}
	}
}

int main(){
	int m, n;
	int loop = 1;
	int opc = 0;
	HashTable *hash = criaHash();
	
	printf("Digite o valor de m: ");
	scanf("%d", &m);

	while(loop){
		printf("Digite o que deseja fazer: \n");
		printf("1 - Inserir registro\n");
		printf("2 - Remover registro\n", );
		printf("3 - Exibir tabela");
		printf("4 - Sair\n");
		scanf("%d", &opc);

		switch(opc){
			case 1:
				hash = insereHash(hash, m);
			break;
			case 2:

			break;
			case 3:

			break;
		}
	}
}