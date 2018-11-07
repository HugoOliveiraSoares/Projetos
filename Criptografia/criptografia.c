#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//---Configuração da CHAVE------------------------
char CHAVE[] = "AbCd";
int TAM_CHAVE;
//------------------------------------------------

//---Vetor de entrada do texto a ser criptografada------------
char TEXTO[100000];
int TAM_TEXTO = 100000;
//------------------------------------------------------------

int TEXTO_CRIPT[100000];

bool Criptografar()
{
  int CHAVE_int;

  for (int i = 0; i < strlen(TEXTO); i++)
  {
    TEXTO_CRIPT[i] = TEXTO[i];
  }

  //printf("\n -- %d -- \n", TEXTO_CRIPT[1]);

  for(int aux = 0; aux < strlen(TEXTO) ; )
  {
    for (int i = 0; i < TAM_CHAVE; i++)
    {
      CHAVE_int = CHAVE[i];
      TEXTO_CRIPT[aux] *= CHAVE_int;
      aux++;
    }
  }

  //printf("\n -- %d -- \n", TEXTO_CRIPT[1]);

  return true;
}//------END Criptografar-------------------------------------------------------

bool Descriptografar()
{
  FILE *arq;

  int valor;
  int pos_chave;
  int pos_texto;

  arq = fopen("cript/arquivo_recebidos/criptografado.txt", "r");

  if (arq == NULL)
  {
    return false;
  }


  pos_chave = 0;
  pos_texto = 0;

  while ( !feof(arq) )
  {
    fscanf(arq,"%d", &valor);
    valor /= CHAVE[pos_chave];

    TEXTO[pos_texto] = (char)valor;
    pos_texto++;

    if (pos_chave == TAM_CHAVE-1 )
    {
      pos_chave = 0;
    }else
    {
      pos_chave++;
    }

  }
  fclose(arq);
  return true;
} //------END Descriptografar---------------------------------------------------

//-----------------------> MENUS <----------------------------------------------

void Recebe_texto(char tipo[])
{
  char aux[TAM_TEXTO];
  bool ok;
  FILE *arq;
  char palavra[100];

  if (strcmp(tipo,"msg") == 0 )
  {
    printf("\n\n Receber texto para criptografar\n\n");
    printf(" Digite o texto: ");
    gets(aux);

    if(strlen(aux) <= TAM_TEXTO)
    {
      strcpy(TEXTO, aux);
      printf(" Texto recebido com sucesso!\n");
      printf("\n Criptografando texto ...\n");
      ok = true;
    }else
    {
      printf("\n ERRO!\n   O tamanho do texto exece o limite de caracteres!\n");
      ok = false;
      printf("\nPressione Enter para continuar\n");
      getchar();
      setbuf(stdin, NULL);
    }
//------END msg------
  }else if(strcmp(tipo,"arquivo") == 0)
  {
    printf("\n\nInstruções para importar um arquivo de texto\n\n");
    printf("\n\n 1 - Renomeie o arquivo para 'original.txt'");
    printf("\n\n 2 - Copie o arquivo para a pasta que sera  aberta a seguir");
    printf("\n\n 3 - Feche o explorador e retorne a aplicação");

    printf("\n\n Pressione Enter para abrir a pasta \n");
    getchar();
    setbuf(stdin, NULL);

    system("nemo /home/hugo/Documentos/Projetos/Criptografia/cript/arquivo_orig");

    printf("\n Pressione Enter apos colar o arquivo na pasta \n");
    getchar();
    setbuf(stdin, NULL);
    printf("\n Importando ARQUIVO...\n\n");

    arq = fopen("cript/arquivo_orig/original.txt", "r");
    if (arq == NULL)
    {
      printf("\n ERRO ao importar o arquivo\n");
    }else
    {
      while (!feof(arq) )
      {
        fscanf(arq, "%s", palavra);
        strcat(aux, " ");
        strcat(aux, palavra);
      }
      fclose(arq);
      if(strlen(aux) <= TAM_TEXTO)
      {
        strcpy(TEXTO, aux);
        printf(" Texto recebido com sucesso!\n");
        printf(" Criptografando texto ...\n\n");
        ok = true;
      }else
      {
        printf("\n ERRO!\n   O tamanho do texto exece o limite de caracteres!\n");
        ok = false;
        printf("\nPressione Enter para continuar\n");
        getchar();
        setbuf(stdin, NULL);
      }
    } //------End fopen arquivo------

  }else //------End arquivo------
  {
    printf("ERRO ao receber texto\n");
  }//------END if msg ou arquivo------------

  if (ok) // Se o texto foi recebido
  {
    if ( Criptografar() )
    {
      printf("\n Texto criptografado com sucesso!");

      arq = fopen("cript/arquivo_gerado/criptografado.txt","wt");
      if (arq == NULL)
      {
        printf("\n ERRO ao criar o arquivo\n");
      }else
      {
        for (int i = 0; i < strlen(TEXTO); i++)
        {
          fprintf(arq, "%d ",TEXTO_CRIPT[i]);
        }
      }
      fclose(arq);

      printf("\n Pressione Enter para abrir a pasta do arquivo gerado\n");
      getchar();
      setbuf(stdin, NULL);
      system("nemo /home/hugo/Documentos/Projetos/Criptografia/cript/arquivo_gerado");
    }else
      printf("\n\n Não foi possivel criptografar o texto!\n\n");
    //-----END Criptografar-----

  }//------ END ok -------------------

  // printf("\nPressione Enter para continuar\n");
  // getchar();
  // setbuf(stdin, NULL);

}//------End Recebe_texto-------------------------------------------------------

void ReceberArquivo_cript()
{

  printf("\n\nInstruções para importar um arquivo criptografado:");
  printf("\n\n 1 - Renomeie o arquivo para 'criptografado.txt'");
  printf("\n\n 2 - Copie o arquivo para a pasta que sera  aberta a seguir");
  printf("\n\n 3 - Feche o explorador e retorne a aplicação");

  printf("\n\n Pressione Enter para abrir a pasta \n");
  getchar();
  setbuf(stdin, NULL);

  system("nemo /home/hugo/Documentos/Projetos/Criptografia/cript/arquivo_recebidos");
  printf("\n Pressione Enter apos colar o arquivo na pasta \n");
  getchar();
  setbuf(stdin, NULL);

  printf("\n Importando ARQUIVO...\n\n");

  if (Descriptografar() )
  {
    printf("\n Arquivo descriptografado com sucesso!\n");
    printf("Pressione Enter para continuar\n");
    getchar();
    setbuf(stdin, NULL);
    system("clear");
    printf("\n%s\n\n", TEXTO);
    printf("Pressione Enter para continuar\n");
    getchar();
    setbuf(stdin, NULL);
  }else
  {
    printf("\n Não foi possivel descriptografar o arquivo!\n");
    printf("Pressione Enter para continuar\n");
    getchar();
    setbuf(stdin, NULL);
  }//------ END Descriptografar ------------

}//------END ReceberArquivo_cript-----------------------------------------------

void Menu_Criptografar()
{
  system("clear");
  int opcao;
  printf("\n\t\t\t >>> Criptografia de dados <<<\n");
  printf("\nCriptografar texto ou arquivo");
  printf("\n\n 1 - Digitar texto");
  printf("\n\n 2 - Importar arquivo de texto (txt)");
  printf("\n\n 3 - Voltar ao menu principal");
  printf("\n\n Informe a opção desejada:\n");
  printf("  >>> ");
  scanf("%d", &opcao);
  setbuf(stdin, NULL);
  switch (opcao)
  {
    case 1:
      system("clear");
      Recebe_texto("msg");
      break;

    case 2:
      system("clear");
      Recebe_texto("arquivo");
      break;

    case 3:
      break;
  default:
    printf("\n Opcao invalida! Aperte Enter e tente novamente...\n");
    getchar();

  }//------END switch opcao------

}//------END Menu_Criptografar--------------------------------------------------

void menu()
{
  int opcao;
  while (1)
  {
    system("clear");
    printf("\n\t\t\t >>> Criptografia de dados <<<");
    printf("\n\n 1 - Criptografar arquivo");
    printf("\n\n 2 - Receber arquivo");
    printf("\n\n 3 - Sair");
    printf("\n\n Informe a opção desejada:\n");
    printf("  >>> ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    switch(opcao)
    {
      case 1:
        system("clear");
        Menu_Criptografar();
        break;

      case 2:
        system("clear");
        ReceberArquivo_cript();
        break;

      case 3:
          printf("\n Finalizando...\n\n");
          exit(0);
          break;
    default:
      printf("\n Opcao invalida! Aperte Enter e tente novamente...\n");
      getchar();

    }//------END switch opcao------

  }//END while(1)------------

}//------END menu---------------------------------------------------------------


int main()
{
  TAM_CHAVE = strlen(CHAVE);
  //TAM_TEXTO = strlen(TEXTO);
  menu();
  return 0;
}//------ END MAIN--------------------------------------------------------------
