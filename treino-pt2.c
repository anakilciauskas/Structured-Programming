// ============== Treino de Ponteiros em C ==============
/* ======= Exercício elaborado por IA para treino ======= */

// Detalhes
/* Uma empresa de saneamento realiza a leitura diária do consumo de água (em litros) de uma residência por meio de um hidrômetro inteligente. Como a quantidade de dias monitorados pode variar de residência para residência, os dados devem ser armazenados dinamicamente em memória.

Desenvolva um programa em linguagem C capaz de armazenar as leituras diárias de consumo e calcular estatísticas sobre os dados utilizando alocação dinâmica e chamada por referência. */

#include <stdio.h>
#include <stdlib.h>

// Protótipo de Função
void calcularConsumo(int *vetorC, int tamanho, int *soma, int *amplitude, float *media);

// Função Principal
int main(){
    int *vetor;
    int i, qtd, vSoma, vAmplitude;
    float vMedia;

    printf("Indique a quantidade de dias monitorados: ");
    scanf("%d", &qtd);
    fflush(stdin);

    vetor = (int*) malloc(qtd * sizeof(int));
    if (vetor == NULL) return 1;

    for (i = 0; i < qtd; i++) {
        printf("Consumo %do dia (litros): ", i+1);
        scanf("%d", (vetor+i));
        fflush(stdin);
    }

    calcularConsumo(vetor, qtd, &vSoma, &vAmplitude, &vMedia);

    printf("Consumo total: %d litros\n", vSoma);
    printf("Amplitude consumo: %d litros\n", vAmplitude);
    printf("Media diaria: %.2f litros", vMedia);

    free(vetor);
    vetor = NULL;
    return 0;
}

/* Função Obrigatória
A função deve:
    Receber um vetor de inteiros e seu tamanho.
    Calcular a soma total do consumo no período.
    Calcular a amplitude (diferença entre o maior e o menor valor de consumo).
    Calcular a média de consumo diário.
    Retornar os resultados para a função main através dos ponteiros:
        soma
        amplitude
        media
*/
void calcularConsumo(int *vetorC, int tamanho, int *soma, int *amplitude, float *media){
    int i;
    int menor = *vetorC;
    int maior = *vetorC;
    *soma = *amplitude = 0;
    *media = 0.0;

    for (i = 0; i < tamanho; i++) {
        *soma += *(vetorC+i);

        if (*(vetorC+i) > maior) maior = *(vetorC+i);
        if (*(vetorC+i) < menor) menor = *(vetorC+i);
    }

    *amplitude = (maior - menor);
    *media = *soma/tamanho;
}