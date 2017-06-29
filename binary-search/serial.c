#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
	/*
	 * Declaração e preenchimento do vetor no qual a busca será realizada.
	 * A busca binária só funciona para vetores ordenados.
	*/
	const int TAMANHO = 2093980;
	int vetor[TAMANHO];
	int i;
	for (i = 0; i < TAMANHO; i++) {
		vetor[i] = i;
	}

	/*
	 * Declaração das variáveis utilizadas na busca
	*/
	int inicio = 0;  //Marca o início do vetor. Esse ponto é modificado durante o algoritmo.
	int fim = TAMANHO - 1; //Marca o fim do vetor. Esse ponto é modificado durante o algoritmo.
	int meio = (fim + inicio) / 2; //Marca o ponto médio entre inicio e fim. Como o início e o fim são variáveis, este ponto também é.
	int alvo; //É o alvo da busca, ou seja, o elemento do vetor do qual queremos descobrir a posição.
	int posicao; //Armazenará a posição do elemento alvo. É a resposta que queremos encontrar.

	/*
	 * Pede ao usuário que informe o valor a ser buscado.
	 * Inicia o cronômetro assim que o usuário insere o valor.
	*/
	printf("Insira o valor a ser buscado: "); 
	scanf("%d", &alvo);
	printf("Buscando por %d...\n", alvo);
	clock_t fimCronometro, inicioCronometro = clock();

	while(inicio <= fim) {
		if(vetor[meio] < alvo) { //Se o elemento do meio do vetor for menor que o nosso alvo...
			inicio = meio + 1; //... dizemos que o início passa a ser a metade do vetor.
		} else {
			if(vetor[meio] > alvo) { //Se o elemento do meio do vetor for maior que o nosso alvo...
				fim = meio - 1; //... dizemos que o fim passa a ser a metade do vetor.
			} else { //Se o elemento do meio do vetor for igual ao nosso alvo...
				posicao = meio; //... encontramos o que queríamos.
				fimCronometro = clock();
				break;
			}
		}
		meio = (fim + inicio)/2;
	}
	if(inicio > fim) { //Se o laço rodou e ainda não encontramos o alvo...
		printf("O elemento %d não está contido no vetor.", alvo); //... significa que ele não está contido no vetor.
	} else { //Caso contrário, apenas imprimimosa posição encontrada
		printf("O elemento %d está na posição %d.\n", alvo, posicao);
	}

	printf("Tempo de execução: %f milissegundos.\n", ((double) (fimCronometro - inicioCronometro)/CLOCKS_PER_SEC)* 1000);
	return 0;
}