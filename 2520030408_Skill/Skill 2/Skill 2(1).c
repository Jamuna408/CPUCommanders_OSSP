#include <stdio.h>

int main()
{
    char input[50];
    char ch;
    int i = 0;

    while (1)
    {
        printf("myshell> ");

        while ((ch = getchar()) != '\n')
        {
            input[i++] = ch;
        }

        input[i] = '\0';

        if (input[0] == 'e' && input[1] == 'x' &&
            input[2] == 'i' && input[3] == 't' &&
            input[4] == '\0')
        {
            break;
        }

        printf("You entered: %s\n", input);
        i = 0;
    }

    printf("Program ended\n");

    return 0;
}
