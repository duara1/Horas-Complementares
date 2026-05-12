#include <stdio.h>

int main(){
    char nome [100], curso [100];
    int ra, horas = 0;
    FILE *arqDados = fopen("dados.txt", "a+");
    FILE *arqIndex = fopen("index.txt", "a+");

    
    printf("=== Cadastrar novo aluno(a) ===");
    printf("\nNome: ");
    scanf("%99[^\n]s", nome);
    while(getchar() != '\n');
    printf("Curso: ");
    scanf("%99[^\n]s", curso);
    while(getchar() != '\n');
    printf("R.A: ");
    scanf("%d", &ra);
    while(getchar() != '\n');
    
    fseek(arqDados, 0, SEEK_END);
    long posicao = ftell(arqDados);

    fprintf(arqDados, "%d;%s;%s;%d\n", ra, nome, curso, horas);
    fprintf(arqIndex, "%d;%ld\n", ra, posicao);
    return 0;
}