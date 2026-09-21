/*
	Resolução por ANA KILCIAUSKAS
	Lista de Exercícios por profa TIEMI SAKATA
	Engenharia de Computação - 2o Semestre

	Conteúdo: struct, struct aninhada, vetores de struct
    Os exercícios consistiam em desenvolver as funções a partir de seus
    protótipos utilizando as structs corretamente
 */

#include <stdio.h>
#include <string.h>

#define MAX 50

// DECLARAÇÕES DE STRUCT
/* =============================================================
   Definição e uso básico de struct
   ============================================================= */

struct Aluno {
    char nome[MAX];
    int idade;
    float nota;
};

/* =============================================================
   Struct aninhada
   ============================================================= */

struct Endereco {
    char rua[MAX];
    int numero;
};

struct Pessoa {
    char nome[MAX];
    struct Endereco end;
};

/* =============================================================
   Struct para dados agrupados
   ============================================================= */

struct Data {
    int dia;
    int mes;
    int ano;
};

// PROTÓTIPOS DE FUNÇÃO
void le_turma(struct Aluno turma[], int n);
void imprime_aluno(struct Aluno a);
void imprime_turma(struct Aluno turma[], int n);

float media_turma(struct Aluno turma[], int n);
int conta_aprovados(struct Aluno turma[], int n);

int busca_aluno_por_nome(struct Aluno turma[], int n, char nome[]);
void procura_aluno(struct Aluno turma[], int n);

void le_pessoas(struct Pessoa v[], int n);
void imprime_pessoa(struct Pessoa p);
void imprime_pessoas(struct Pessoa v[], int n);

void imprime_data(struct Data d);

// FUNÇÃO PRINCIPAL
int main(void) {	
    struct Aluno turma[3];
    struct Pessoa pessoas[2];
	struct Data hoje = {21, 9, 2026};

    le_turma(turma, 3);
    imprime_turma(turma, 3);

    printf("Media da turma: %.2f\n", media_turma(turma, 3));
    printf("Aprovados: %d\n\n", conta_aprovados(turma, 3));
    
    procura_aluno(turma, 3);
    
    le_pessoas(pessoas, 2);
    imprime_pessoas(pessoas, 2);

    imprime_data(hoje);

    return 0;
}

// FUNÇÕES AUXILIARES
/* =============================================================
   Vetor de estruturas
   ============================================================= */

void le_turma(struct Aluno turma[], int n) {
    int i;
    
    printf("===== CADASTRO ALUNOS =====\n");
    for (i = 0; i < n; i++){
    	printf("Aluno #%i\n", i+1);
    	
    	printf("Nome: ");
    	scanf("%s", turma[i].nome);
    	fflush(stdin);
    	
    	printf("Idade: ");
    	scanf("%d", &turma[i].idade);
    	fflush(stdin);
    	
    	printf("Nota: ");
    	scanf("%f", &turma[i].nota);
    	fflush(stdin);
    	
    	printf("\n");
	}
}

void imprime_aluno(struct Aluno a) {
    printf("Nome: %s\n", a.nome);
    printf("Idade: %i\n", a.idade);
    printf("Nota: %.2f\n", a.nota);
}

void imprime_turma(struct Aluno turma[], int n) {
    int i;

    printf("===== TURMA =====\n");
	for (i = 0; i < n; i++){
		imprime_aluno(turma[i]);
		printf("\n");
	}
}

/* =============================================================
   Cálculo usando vetor de struct
   ============================================================= */

float media_turma(struct Aluno turma[], int n) {
    int i;
    float media = 0.0;
    
    for (i = 0; i < n; i++){
    	media += turma[i].nota;
	}
	media = media/n;
	
    return media;
}

/* =============================================================
   Contagem condicional
   ============================================================= */

int conta_aprovados(struct Aluno turma[], int n) {
    /* TODO: retornar quantos alunos têm nota >= 6.0 */
    int i, aprov = 0;
    
    for (i = 0; i < n; i++){
    	if (turma[i].nota >= 6.0) aprov++;
	}
	
    return aprov;
}

/* =============================================================
   Busca em vetor de struct
   ============================================================= */

int busca_aluno_por_nome(struct Aluno turma[], int n, char nome[]) {
    int i;
    
    for (i = 0; i < n; i++){
    	if (!strcmp(nome, turma[i].nome)) return i;
	}
    
    return -1;
}

void procura_aluno(struct Aluno turma[], int n){
	char alunoProcura[MAX];
	int codeBusca;
	
	printf("=== PESQUISA ===\n");
    printf("Informe o nome do aluno: ");
    scanf("%s", alunoProcura);
    fflush(stdin);
    
    codeBusca = busca_aluno_por_nome(turma, n, alunoProcura);
    if (codeBusca != -1){
    	printf("Aluno encontrado!\nIndice: %i\n", codeBusca);
    	imprime_aluno(turma[codeBusca]);
	} else printf("Aluno não cadastrado!\n");
}

/* =============================================================
   Vetor de struct com struct aninhada
   ============================================================= */

void le_pessoas(struct Pessoa v[], int n) {
    int i;
    
    printf("===== CADASTRO PESSOAS =====\n");
    for (i = 0; i < n; i++){
    	printf("Pessoa #%i\n", i+1);
    	
    	printf("Nome: ");
    	scanf("%s", v[i].nome);
    	fflush(stdin);
    	
    	printf("Rua: ");
    	scanf("%s", v[i].end.rua);
    	fflush(stdin);
    	
    	printf("Numero: ");
    	scanf("%i", &v[i].end.numero);
    	fflush(stdin);
    	
    	printf("\n");
	}
}

void imprime_pessoa(struct Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Endereco: %s, %i\n", p.end.rua, p.end.numero);
}

void imprime_pessoas(struct Pessoa v[], int n) {
    int i;
    
    printf("===== PESSOAS =====\n");
    for (i = 0; i < n; i++){
    	imprime_pessoa(v[i]);
    	printf("\n");
	}
}

void imprime_data(struct Data d) {
    printf("Data: %d/%d/%d\n", d.dia, d.mes, d.ano);
}
