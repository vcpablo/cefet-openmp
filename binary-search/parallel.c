#include <stdio.h>
#include <math.h>
#include <time.h>
#include <omp.h>

void buscaBinaria(int inicio, int fim, int alvo, int * vetor, int tamanho, clock_t * fimCronometro) {
	int i, encontrado = 0; //encontrado é uma flag para dizer para as outras threads quando o alvo foi encontrado.
	int posicao = (fim - inicio)/2; //Começa chutando que a posição do alvo é o meio do vetor
	int limiteInferior = inicio - 1; //Apenas para facilitar o uso dos valores.
	int limiteSuperior = fim + 1; //Apenas para facilitar o uso dos valores.

	for (i = 0; i < tamanho; i ++) { //Repete no máximo o tamanho do vetor. Evita um laço de repetição infinito.
		if(vetor[posicao] == alvo) { //Se econtrou o elemento.
			*fimCronometro = clock();			
			printf("O elemento %d está na posição %d.\n", alvo, posicao);
			encontrado = 1; //Avisa para as outras threads que o elemento foi encontrado.
			return;
		}

		if (vetor[posicao] < alvo) { //Se o elemento é menor que o alvo...
			limiteInferior = posicao; //... ajusta o limite inferior...
			posicao += (limiteSuperior - limiteInferior)/2; //... e chuta novamente que a posição do alvo é o meio do vetor
		} else { //Se o elemento é maior que o alvo...
			limiteSuperior = posicao; //... ajusta o limite superior...
			posicao -= (limiteSuperior - limiteInferior)/2; //... e chuta novamente que a posição do alvo é o meio do vetor
		}

		if (encontrado == 1) { //Se a flag foi setada para 1, para o algoritmo (alguma thread já encontrou o alvo.)
			return;
		}
	}
}

void main() {
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

	int alvo; //É o alvo da busca, ou seja, o elemento do vetor do qual queremos descobrir a posição.

	/*
	 * Pede ao usuário que informe o valor a ser buscado.
	 * Inicia o cronômetro assim que o usuário insere o valor.
	*/
	printf("Insira o valor a ser buscado: "); 
	scanf("%d", &alvo);
	printf("Buscando por %d...\n", alvo);
	clock_t fimCronometro, inicioCronometro = clock();

	int quantidadeDeNucleos = omp_get_num_procs(); //Obtém a quantidade de núcleos.
	int tamanhoBloco = TAMANHO / quantidadeDeNucleos; //"Divide" o vetor em blocos de tamanhos iguais.

	#pragma parallel for
	for(i = 0; i < quantidadeDeNucleos; i++) { //Para cada núcleo, manda executar a busca binária em cada bloco.
		buscaBinaria(i * tamanhoBloco, i * tamanhoBloco + tamanhoBloco - 1, alvo, vetor, TAMANHO, &fimCronometro);
	}

	//Quando termina, exibe o tempo utilizado.
	printf("Tempo de execução: %f milissegundos.\n", ((double) (fimCronometro - inicioCronometro)/CLOCKS_PER_SEC)* 1000);

}
