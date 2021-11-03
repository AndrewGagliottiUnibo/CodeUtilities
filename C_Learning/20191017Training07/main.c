#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    while (1)                   //salva in un buffer la stringa e ne analizza lettera per lettera
{
    if (ch != '#')
    {

    (ch = getchar());
    //printf("%c", ch);

    }
    else
        break;
}
    printf("%c", ch);

    return 0;

    }
