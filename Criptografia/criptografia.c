#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>

//---Configuração da CHAVE------------------------
char CHAVE[] = "AbCd";
int TAM_CHAVE;
//------------------------------------------------

//---Vetor de entrada do texto a ser criptografada------------
char TEXTO[100000];
int TAM_TEXTO = 100000;
//------------------------------------------------------------

int TEXTO_CRIPT[100000];

void pause(char msg[])
{
  printf("%s\n", msg);
  getchar();
  setbuf(stdin, NULL);
}

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

void Recebe_texto()
{
  char aux[TAM_TEXTO];
  bool ok;
  FILE *arq;

  printf("\n\n Receber texto para criptografar\n\n");
  printf(" Digite o texto: ");
  gets(aux);

  if(strlen(aux) <= TAM_TEXTO)
  {
    strcpy(TEXTO, aux);
    printf("\n Texto recebido com sucesso!\n");
    printf("\n Criptografando texto ...\n");
    ok = true;
  }else
  {
    printf("\n ERRO!\n   O tamanho do texto exece o limite de caracteres!\n");
    ok = false;
    pause("\nPressione Enter para continuar.");
  }

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

      pause("\n Pressione Enter para abrir a pasta do arquivo gerado.");
      system("nemo /home/hugo/Documentos/Projetos/Criptografia/cript/arquivo_gerado");
    }else
      printf("\n\n Não foi possivel criptografar o texto!\n\n");
    //-----END Criptografar-----

  }//------- END ok -------------------

}//---------- END Recebe_texto ----------

void ReceberArquivo_cript()
{

  printf("\n\nInstruções para importar um arquivo criptografado:");
  printf("\n\n 1 - Renomeie o arquivo para 'criptografado.txt'");
  printf("\n\n 2 - Copie o arquivo da pasta arquivo_gerado para a pasta que sera aberta a seguir");
  printf("\n\n 3 - Feche o explorador e retorne a aplicação");
  pause("\n\n Pressione Enter para abrir a pasta \n");

  system("nemo /home/hugo/Documentos/Projetos/Criptografia/cript/arquivo_recebidos");
  pause(" Pressione Enter apos colar o arquivo na pasta \n");

  printf(" Importando ARQUIVO...\n\n");

  if (Descriptografar() )
  {
    printf("\n Arquivo descriptografado com sucesso!\n");
    pause(" Pressione Enter para continuar\n");
    system("clear");
    printf("\n%s\n\n",TEXTO);
    pause("Pressione Enter para continuar\n");
  }else
  {
    printf("\n Não foi possivel descriptografar o arquivo!\n");
    pause("Pressione Enter para continuar\n");
  }//------ END Descriptografar ------------

}//------END ReceberArquivo_cript-----------------------------------------------

void Menu_Criptografar()
{
  system("clear");
  int opcao;
  printf("\n\t\t\t >>> Criptografia de dados <<<\n");
  printf("\nCriptografar texto ou arquivo");
  printf("\n\n 1 - Digitar texto a ser criptografado");
  printf("\n\n 2 - Voltar ao menu principal");
  printf("\n\n Informe a opção desejada:\n");
  printf("  >>> ");
  scanf("%d", &opcao);
  setbuf(stdin, NULL);
  switch (opcao)
  {
    case 1:
      system("clear");
      Recebe_texto();
      break;

    case 2:
      break;

  default:
    pause("\n Opcao invalida! Aperte Enter e tente novamente...\n");
    Menu_Criptografar();

  }//------END switch opcao------

}//------END Menu_Criptografar--------------------------------------------------

void menu()
{
  int opcao;

  while (1)
  {
    system("clear");
    printf("\n\t\t\t >>> Criptografia de dados <<<");
    printf("\n\n 1 - Criptografar mensagem");
    printf("\n\n 2 - Receber arquivo para descriptografar");
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
      pause("");

    }//------END switch opcao------

  }//END while(1)------------

}//------END menu---------------------------------------------------------------


int main()
{
  DIR *dir1, *dir2, *dir3;
  dir1 = opendir("cript");
  dir2 = opendir("cript/arquivo_gerado");
  dir3 = opendir("cript/arquivo_recebidos");

  if (!dir1)
  {
    system("mkdir cript");
  }

  if (!dir2)
  {
    system("mkdir cript/arquivo_gerado");
  }

  if (!dir3)
  {
    system("mkdir cript/arquivo_recebidos");
  }

  TAM_CHAVE = strlen(CHAVE);
  //TAM_TEXTO = strlen(TEXTO);
  menu();
  return 0;
}//------ END MAIN--------------------------------------------------------------
