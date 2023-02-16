#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"


int colocar_struct(FILE *fp, LIVROS *LIVRO){
  int read = 0, records = 0;

  do
  {
    read = fscanf(fp, "%99[^;]; %49[^;]; %99[^;]; %d; %d; %lf\n", LIVRO[records].autor, LIVRO[records].pais, LIVRO[records].nome, &LIVRO[records].estilo, &LIVRO[records].data, &LIVRO[records].avaliacao);
    records ++;
  } while(!feof(fp));

  puts("Itens colocado na struct!\n");

  return 0;
}

int ler_arquivo(FILE *fp){
  if (fp == NULL) {
    fprintf(stderr, "Arquivo nao encontrado. \n");
    return 1;
  } else {
    puts("Arquivo encontrado! \n");
  }
  return 0;
}

bool escrever_data(FILE *tfp, LIVROS *LIVRO, int total){

  if(tfp == NULL) return false;

  if(fwrite(&total, sizeof(int), 1, tfp) != 1)
    return false;
  
  if(fwrite(LIVRO, sizeof(LIVROS), total, tfp) != total)
    return false;

  if(fclose(tfp) == EOF) return false;
  return true;

}

void mostrar_livros(LIVROS *file_data, FILE *tfp){

    for(int i = 0; i < 20; i++){
        printf("Autor numero %d\n", i + 1);
        printf("Autor: %s\n", file_data[i].autor);
        printf("Nacionalidade: %s\n", file_data[i].pais);
        printf("Nome do livro: %s\n", file_data[i].nome);
        printf("Estilo do livro: %d\n", file_data[i].estilo);
        printf("Data de lancamento: %d\n", file_data[i].data);
        printf("Avaliacao: %.2lf\n", file_data[i].avaliacao);
        puts("\n");
    }

    for(int i = 0; i < 20; i++){
        fprintf(tfp, "Autor numero %d\n", i + 1);
        fprintf(tfp,"Autor: %s\n", file_data[i].autor);
        fprintf(tfp,"Nacionalidade: %s\n", file_data[i].pais);
        fprintf(tfp,"Nome do livro: %s\n", file_data[i].nome);
        fprintf(tfp,"Estilo do livro: %d\n", file_data[i].estilo);
        fprintf(tfp,"Data de lancamento: %d\n", file_data[i].data);
        fprintf(tfp,"Avaliacao: %.2lf\n", file_data[i].avaliacao);
        fprintf(tfp,"\n");
    }

}


void pesquisar_autor(LIVROS *file_data, FILE *tfp){
    char autores[100];
    int count = 0, value;

    puts("Digite o autor que deseja encontrar: ");
    gets(autores);

    for(int i = 0; i < 20; i++){
        if(strcmp(autores, file_data[i].autor) == 0){
            puts("Seu autor foi econtrado!");
            printf("Sua nacionalidade: %s\n", file_data[i].pais);
            fprintf(tfp,"Seu autor: %s\n", file_data[i].autor);
            fprintf(tfp,"Sua nacionalidade: %s\n", file_data[i].pais);
            count ++;
            break;
        }
    }
    if(count == 0){
        puts("Nao foi possivel encontrar esse autor!");
        fprintf(tfp,"Nao foi possivel encontrar esse autor!\n");
    }
    puts("\n");
}

void pesquisar_categoria(LIVROS *file_data, FILE *tfp){
    int cat = 0, count = 0;

    puts("Digite o estilo que deseja encontrar.");
    puts("Digite: 0 - Romance, 1 - Poema, 2 - Novela, 3 - Ficcao, 4 - Terror, 5 - Suspence, 6 - Biografia, 7 - Conto e 8 - Drama:");
    scanf("%d", &cat);

    for(int i = 0; i < 20; i++){
        if(cat == file_data[i].estilo){
            printf("Nome do livro: %s", file_data[i].nome);
            printf("\n");
            fprintf(tfp,"Nome do livro: %s", file_data[i].nome);
            fprintf(tfp,"\n");
            count ++;
        }
    }
    printf("Existe %d livro(s) do estilo %d", count, cat);
    fprintf(tfp,"Existe %d livro(s) do estilo %d", count, cat);
    fprintf(tfp,"\n");
    puts("\n");
}

void media_livros(LIVROS *file_data, FILE *tfp){
    int ano_i = 0, ano_f = 0, ano_final = 0, datas, count, divisor;
    puts("Digite o seu ano inicial: ");
    scanf("%d", &ano_i);
    puts("Digite o seu ano final: ");
    scanf("%d", &ano_f);

    if(ano_f < ano_i){
        puts("Ano final menor que o ano inicial!");
        return;
    }

    divisor = ano_f - ano_i;

    for(int i = 0; i < 20; i++){
        datas =  file_data[i].data;
        if(datas >= ano_i && datas <= ano_f){
            count ++;
        }
    }

    ano_final = divisor / count;

    printf("A media de livros foi de 1 livro a cada %d anos.", ano_final);
    fprintf(tfp,"A media de livros foi de 1 livro a cada %d anos.", ano_final);
    fprintf(tfp,"\n");
    puts("\n");
}

LIVROS *ler_data(FILE *fp, int *total){
    if(fp == NULL) return NULL;

    if(fread(total, sizeof(int),1, fp) != 1)
        return NULL;

    LIVROS *dados = malloc(sizeof(LIVROS) * *total);

    if(fread(dados, sizeof(LIVROS), *total, fp) != *total){
        free(dados);
        return NULL;
    }

    if(fclose(fp) == EOF){
        free(dados);
        return NULL;
    }

    return dados;
}