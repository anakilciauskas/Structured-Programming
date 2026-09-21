// ============== Treino de Ponteiros em C ==============
/* ========= Exercício proposto em sala de aula ========= */

// Detalhes
/* Uma empresa de monitoramento industrial armazena temperaturas coletadas por sensores instalados em uma linha de produção. Como a quantidade de leituras varia a cada coleta, os dados devem ser armazenados dinamicamente em memória.

Desenvolva um programa em linguagem C capaz de armazenar as leituras dos sensores e calcular estatísticas sobre os dados utilizando alocação dinâmica e chamada por referência. */

#include <stdio.h>
#include <stdlib.h>

// Protótipo de Função
void calcularEstatisticas(int *vetorF, int tamanho, int *maior, int *menor, float *media);

// Função Principal
int main(){
    int* vetor;
    int i, qtd, vMaior, vMenor;
    float vMedia;
    
    printf("Indique a quantidade de leituras: ");
    scanf("%d", &qtd);
    fflush(stdin);

    // reserva espaço dinamicamente do heap
    vetor = (int*) malloc(qtd * sizeof(int));

    // verifica se deu erro na alocação
    if (vetor == NULL) return 1;

    for (i = 0; i < qtd; i++) {
        printf("Digite o %io valor: ", i+1);
        // acesso ao primeiro endereço + i
        scanf("%d", (vetor+i));
    }

    calcularEstatisticas(vetor, qtd, &vMaior, &vMenor, &vMedia);

    printf("Maior: %d\n", vMaior);
    printf("Menor: %d\n", vMenor);
    printf("Media: %.2f", vMedia);

    free(vetor);
    vetor = NULL;
    return 0;
}

/* Função Obrigatória
A função deve:
    Receber um vetor de inteiros e seu tamanho.
    Determinar o maior valor armazenado.
    Determinar o menor valor armazenado.
    Calcular a média dos elementos.
    Retornar os resultados para a função main através dos ponteiros:
        maior
        menor
        media
*/
void calcularEstatisticas(int *vetorF, int tamanho, int *maior, int *menor, float *media){
    int i;
    *media = 0;
    *maior = *menor = *vetorF;

    for (i = 0; i < tamanho; i++) {
        if (*(vetorF+i) > *maior) *maior = *(vetorF+i);

        if (*(vetorF+i) < *menor) *menor = *(vetorF+i);

        *media += *(vetorF+i);
    }
    *media = *media/tamanho;
}
