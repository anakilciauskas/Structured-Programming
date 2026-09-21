// ============== Revisão de Ponteiros em C ==============
/* Conteúdo baseado em anotações feitas em sala de aula */

#include <stdio.h>
#include <stdlib.h>

/* ========== Protótipos de Função ========== */
//introdução ponteiros
void basico();
void principio();

//vetores e ponteiros
void vetores();
void vetores_ex();
void vetores_for();

//funções, vetores e ponteiros
void troca_conteudo(int *x, int *y);
void zera_vetor(int *vinicial, int n);
void maior_valor(int n1, int n2, int *resultado);

//alocação dinâmica
void malloc_intro();
void malloc_ex();

/* ============ Função Principal ============ */
int main(){
    //basico();
    //principio();

    //vetores();
    //vetores_ex();
    //vetores_for();

    /*
    int a = 35, b = 40;
    printf("Antes: a = %i b = %i\n", a, b);
    //recebe os endereços das variáveis
    troca_conteudo(&a, &b);
    printf("Depois: a = %i b = %i\n", a, b);
    */
    
    /*
    int v[3] = {55, 32, 490};
    //recebe o endereço do primeiro elemento e o tamanho
    zera_vetor(v, 3);
    */

    /*
    int a = 20, b = 35, vmaior = 0;
    //recebe dois números e um endereço
    maior_valor(a, b, &vmaior);
    printf("a = %d, b = %d, maior = %d\n", a, b, vmaior);
    */

    //malloc_intro();
    //malloc_ex();

    return 0;
}

/* =========== Funções Auxiliares =========== */
void basico(){
    //maneiras de inicialização variáveis
    int valor = 0;
    int xvalor;
    xvalor = 0;

    //maneiras de inicialização ponteiros
    int *pvalor = &valor;
    int *pxvalor;
    pxvalor = &xvalor;

    //acesso ao conteudo do ponteiro
    printf("Endereco = %i\n", pvalor);

    //acesso ao conteudo da variavel do ponteiro
    printf("Conteudo valor = %i\n", *pvalor);

    //atribuição com ponteiro
    //vai p/onde o ponteiro aponta e muda o conteúdo
    printf("Valor original = %i\n", xvalor);
    *pxvalor = 15;
    printf("Valor alterado = %i\n", xvalor);
}

void principio(){
    int x = 72;

    //declaração e inicialização do ponteiro
    //px guarda o endereço de x
    int *px;
    px = &x;

    printf("Endereco de x = %i\n", px);
    //acesso do conteúdo via ponteiro
    printf("Conteudo indireto de x = %i\n", *px);

    //manipulação indireta via ponteiro
    //agora o conteúdo de x mudou
    *px = 15;
    printf("Endereco de x = %i\n", px);
    printf("Conteudo direto de x = %i\n", x);
    printf("Conteudo indireto de x = %i\n", *px);
}

void vetores(){
    //vetor é um ponteiro da primeira posição
    int vet[5] = {0, 1, 2, 3, 4};

    int *pvet;
    pvet = vet; //mesmo que pvet = &vet[0]

    //manipulação de vetor com ponteiro
    printf("[0] = %i\n", *pvet);
    printf("Endereco = %i\n", pvet);
    pvet = pvet+2;
    printf("[2] = %i\n", *pvet);
    printf("Endereco = %i\n", pvet);
    pvet++;
    printf("[3] = %i\n", *pvet);
    printf("Endereco = %i\n", pvet);
}

void vetores_ex(){
    int vetor[3] = {5, 10, 15};
    
    //mesmo que pvetor = &vetor[0]
    int *pvetor = vetor;

    printf("Andando no vetor e mostrando conteudo\n");
    printf("%i\n", *(pvetor++));
    printf("%i\n", *(pvetor++));
    printf("%i\n", *pvetor);

    pvetor = vetor;

    printf("Manipulando/incrementando conteudo\n");
    //incrementa o conteúdo do vetor
    printf("%i\n", (*pvetor)++);
    printf("%i\n", *pvetor);
    printf("[0] = %i\n", *vetor);
}

void vetores_for(){
    int vetfor[5];
    int *ini, *fim, *pfor;

    ini = vetfor; //mesmo que ini = &vet[0]
    fim = vetfor + 5; //mesmo que fim = &vet[5]

    printf("Guardando valores\n");
    for (pfor = ini; pfor < fim; pfor++){
        //guarda os valores no endereço de pfor
        scanf("%i", pfor); //já é endereço, não leva &
    }

    printf("Mostrando valores\n");
    for (pfor = ini; pfor < fim; pfor++){
        //mostra o conteúdo de pfor
        printf("%i\n", *pfor);
    }
}

void troca_conteudo(int *x, int *y){
    //função espera dois ponteiros, endereços

    int temp;

    temp = *x; //guarda o conteúdo original de x
    *x = *y; //recebe conteúdo original de y
    *y = temp; //recebe o conteúdo da temporária
}

void zera_vetor(int *vinicial, int n){
    for (int i = 0; i < n; i++){
        //mostra o conteúdo da posição vinicial+i
        printf("%i ", *(vinicial+i));
    }
    printf("\n");

    /*
    for (int i = 0; i < n; i++){
        //muda o conteúdo da posição vinicial+i
        *(vinicial+i) = 0;
        printf("%i ", *(vinicial+i));
    }
    printf("\n");
    */

    //utilizando ponteiro p/zerar o vetor
    int *p;
    for (p = vinicial; p < (vinicial + n); p++){
        *p = 0;
        printf("%i ", *p);
    }
}

void maior_valor(int n1, int n2, int *resultado){
    //altera o conteúdo dentro do endereço de resultado
    if (n1 > n2) *resultado = n1;
    else *resultado = n2;
}

void malloc_intro(){
    int *ptr, *ptrv;

    //retorna o endereço do primeiro elemento
    //indica o tipo e o tamanho do espaço a ser reservado
    ptr = (int*) malloc(sizeof(int));

    //pode ser usado como alternativa ao vetor
    //indica a quantidade de elementos no tamanho do vetor
    ptrv = (int*) malloc(10 * sizeof(int));
    //ptrv se torna o mesmo que vetor[0], para um vetor[10]

    //verificação se deu erro no malloc
    if (ptr == NULL) {
        printf("Nao foi possivel reservar o espaço solicitado no heap\n");
    }

    //precisa liberar o espaço reservado após seu uso!!
    free(ptr);
    free(ptrv);

    //depois de liberto, o ponteiro aponta p/região inválida
    ptr = NULL;
    ptrv = NULL;
}

void malloc_ex(){
    //cria o ponteiro
    float *pmalloc;

    //reserva espaço para float
    //atribui o endereço para o ponteiro
    pmalloc = (float*) malloc(sizeof(float));

    //verifica se deu erro ao reservar o endereço
    if (pmalloc == NULL) return;

    //armazena um novo conteúdo no endereço
    *pmalloc = 3.1415;

    printf("Endereco de pmalloc = %i\n", pmalloc);
    printf("Conteudo de pmalloc = %.4f\n", *pmalloc);

    //libera memória e reseta o ponteiro
    free(pmalloc);
    pmalloc = NULL;
}
