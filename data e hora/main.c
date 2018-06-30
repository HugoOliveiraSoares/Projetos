#include <stdio.h>
#include <stdlib.h>
#include "c:\windows\desktop\Datahora.h"

int main()
{
    while( ! kbhit() ) //fazer enquanto nenhuma tecla for pressionada.
    {
        gotoxy(38,12); //posiciosna na coluna e linha.
        cprintf("%s", ObtemStrHora() ); //mostra a hora local.
    }

    printf("\n\nPressione uma tecla para finalizar...");
    getch();
}
