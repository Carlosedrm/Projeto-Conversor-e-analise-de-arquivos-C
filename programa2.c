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
  LIVROS *dados;

  dados = malloc(sizeof(LIVROS) * 20);

  // Função para ler o arquivo.
  FILE *fp = fopen(argv[1], "rb"); 

  // Função para escrever o arquivo.
  FILE *tfp = fopen(argv[2], "w"); 

  // Coloca os dados em uma struct.
  int total = 0;

  LIVROS *file_data;

  file_data = ler_data(fp, &total);

  if(file_data == NULL){
    puts("Erro em ler o arquivo");
    return 1;
  }
  puts("Encontramos o arquivo!");

  puts("Bem vindo a Biblioteca mini!");

  int escolha = 0;
  do{
    puts("O que deseja fazer ?");
    puts("Coloque: 1 - Ver todos os livros. 2 - Pesquisar por um autor em especifico. 3 - Pesquisar livros de uma certa categoria. 4 - Pesquisar a media de livros que sairam entre dois anos. 5 - Finalizar programa.\n");
    scanf("%d", &escolha);
    getchar();
    if(escolha > 0 && escolha < 6){
        switch (escolha)
        {
        case 1:
            puts("Mostrando todos os autores e seus livros!"); 
            mostrar_livros(file_data, tfp);
            break;
        case 2:
            pesquisar_autor(file_data, tfp);
            break;
        case 3:
            pesquisar_categoria(file_data, tfp);
            break;
        case 4:
            media_livros(file_data, tfp);
            break;
        case 5:
            puts("/n");
            break;
        default:
            puts("Algum erro aconteceu! Tente novamente.");
            break;
        }
    } else if(escolha == 5){
        break;
    }    
  }while(escolha != 5);
  puts("\nObrigado pela a visita na Biblioteca mini!");
  fclose(tfp);
  fclose(fp);
  return 0;
}

