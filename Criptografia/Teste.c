#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

void pause(char msg[])
{
  printf("%s\n", msg);
  getchar();
  setbuf(stdin, NULL);
}

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

  pause("");


  return 0;
}
