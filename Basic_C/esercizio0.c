#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>
int main()
{
    char ch;
    char frase[100];
    int index = 0;
    int counterA = 0;

    printf("Enter a sentence and press ENTER: ");
    scanf("%s", frase);

    while ((ch=getchar())!=EOF && ch!='\n'){
        frase[index++] = ch;
        if (isspace(ch)!=0){ //Important to use "!=0" and not "==0"
                counterA = counterA +1;
        }
    }

    printf("The number of white-spaces is: %d", counterA);

    return 0;
}
