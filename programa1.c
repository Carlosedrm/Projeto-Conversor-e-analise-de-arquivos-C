#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"


// Main.
int main(int argc, char *argv[]) {

  // Verifica se a quantidade de argumentos e valida.
  if(argc != 3){
    fprintf(stderr, "Numero de argumentos invalidos. \n");
    return 0;
  }
  puts("Argumentos validos! O programa ira continuar!\n");

  // Alocação de memoria.
  LIVROS *LIVRO;

  LIVRO = malloc(sizeof(LIVROS) * 20);

  // Função para ler o arquivo.
  FILE *fp = fopen(argv[1], "r"); 

  ler_arquivo(fp);

  // Coloca os dados em uma struct.
  colocar_struct(fp, LIVRO);

  // Mostra o que tem na struct.
  for(int i = 0; i < 20; i++){
    printf("%s, %s, %s, %d, %d, %.2lf\n",
    LIVRO[i].autor,
    LIVRO[i].pais,
    LIVRO[i].nome,
    LIVRO[i].estilo,
    LIVRO[i].data,
    LIVRO[i].avaliacao);
  };

  puts("\nEscrevendo arquivo binario...");

  // Cria o arquivo de saida com o nome que o usuario queira.
  FILE *tfp = fopen(argv[2], "wb");

  // Função que escreve o arquivo em binario.
  if(escrever_data(tfp, LIVRO, 20)){
    puts("O arquivo foi escrito!");
  } else{
    puts("Erro em escrever arquivo!");
    return 1;
  }

  // Fim do programa.
  puts("Foi criado seu arquivo binario! Use ele como o arquivo de entrada no programa 2.");

  free(LIVRO);

  return 0;
}

/*int ler_arquivo(FILE *fp){
  if (fp == NULL) {
    fprintf(stderr, "Arquivo nao encontrado. \n");
    return 1;
  } else {
    puts("Arquivo encontrado! \n");
  }
  return 0;
}

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

bool escrever_data(FILE *tfp, LIVROS *LIVRO, int total){

  if(tfp == NULL) return false;

  if(fwrite(&total, sizeof(int), 1, tfp) != 1)
    return false;
  
  if(fwrite(LIVRO, sizeof(LIVROS), total, tfp) != total)
    return false;

  if(fclose(tfp) == EOF) return false;
  return true;

}*/

