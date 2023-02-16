#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// Itens usados para a Struct.
enum ESTILO {Romance, Poema, Novela, Ficcao, Terror, Suspence, Biografia, Conto, Drama};

typedef struct{
  char autor[100];
  char pais[50];
  char nome[100];
  enum ESTILO estilo;
  int data;
  double avaliacao;
} LIVROS;

LIVROS LIVRO[20];

// Funções para escrever o arquivo em binario.

bool escrever_data(FILE *, LIVROS *LIVRO, int total);

// Funções usadas.

int ler_arquivo(FILE *);

int colocar_struct(FILE *, LIVROS *LIVRO);

// Funções para ler o arquivo em binario.

LIVROS *ler_data(FILE *, int *total);

// Funções usadas.

void mostrar_livros(LIVROS *file_data, FILE *);

void pesquisar_autor(LIVROS *file_data, FILE *);

void pesquisar_categoria(LIVROS *file_data, FILE *);

void media_livros(LIVROS *file_data, FILE *);