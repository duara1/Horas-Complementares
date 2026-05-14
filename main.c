#include <stdio.h>

int main(){
    char nome[100], curso[100];
    int ra = 0, horas = 0;

    FILE *arqDados = fopen("dados.txt", "a+");
    FILE *arqIndex = fopen("index.txt", "a+");

    if(!arqDados || !arqIndex){
        printf("Erro ao abrir arquivo");
        return 0;
    } 


    int id;
    long posi;
    int maiorRA = 0;

    fseek(arqIndex, 0, SEEK_SET);

    while (fscanf(arqIndex, "%d;%ld", &id, &posi) == 2) {
        if (id > maiorRA) {
            maiorRA = id;
        }
    }

    ra = maiorRA + 1; // novo RA 

    //Cadastro
    printf("=== Cadastrar novo aluno(a) ===");
    printf("\nNome: ");
    scanf("%99[^\n]", nome);
    while(getchar() != '\n');

    printf("Curso: ");
    scanf("%99[^\n]", curso);
    while(getchar() != '\n');

    fseek(arqDados, 0, SEEK_END);
    long posicao = ftell(arqDados);

    fprintf(arqDados, "%04d;%s;%s;%d\n", ra, nome, curso, horas);
    fprintf(arqIndex, "%04d;%ld\n", ra, posicao);

    //Leitura
    fseek(arqIndex, 0, SEEK_SET);

    printf("\n--- INDEX ---\n");
    while (fscanf(arqIndex, "%d;%ld", &id, &posi) == 2)
    {
        printf("%04d %ld\n", id, posi);
    }

    fclose(arqDados);
    fclose(arqIndex);

    return 0;
}