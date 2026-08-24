#include <stdio.h>

int main()
{
    char input[50];
    char ch;
    int i = 0;

    printf("Enter command: ");

    while (1)
    {
        ch = getchar();

        if (ch == '\n')
        {
            input[i] = '\0';

            printf("\nYou entered: %s\n", input);
            i = 0;

            printf("Enter command: ");
        }
        else if (ch == 8 || ch == 127)
        {
            if (i > 0)
                i--;
        }
        else if (i < 49)
        {
            input[i++] = ch;
        }
    }

    return 0;
}
