#include <stdio.h>

char arr[18][3] = {
    {'E','+','F'}, {'E','*','F'}, {'E','(','F'},
    {'E',')','F'}, {'E','i','F'}, {'E','$','F'},

    {'F','+','F'}, {'F','*','F'}, {'F','(','F'},
    {'F',')','F'}, {'F','i','F'}, {'F','$','F'},

    {'T','+','F'}, {'T','*','F'}, {'T','(','F'},
    {'T',')','F'}, {'T','i','F'}, {'T','$','F'}
};

int main()
{
    int i, j;

    printf("\nOPERATOR PRECEDENCE RELATION TABLE\n");
    printf("\nGrammar:\n");
    printf("E -> E+T | T\n");
    printf("T -> T*F | F\n");
    printf("F -> (E) | i\n\n");

    printf("Non-Terminal\tTerminal\tRelation\n");

    for(i = 0; i < 18; i++)
    {
        printf("%c\t\t%c\t\t", arr[i][0], arr[i][1]);

        if(arr[i][0] == 'E')
        {
            if(arr[i][1] == '+')
                printf("<");
            else if(arr[i][1] == '*')
                printf("<");
            else if(arr[i][1] == '(')
                printf("<");
            else if(arr[i][1] == ')')
                printf(">");
            else if(arr[i][1] == 'i')
                printf("<");
            else if(arr[i][1] == '$')
                printf(">");
        }
        else if(arr[i][0] == 'T')
        {
            if(arr[i][1] == '+')
                printf(">");
            else if(arr[i][1] == '*')
                printf("<");
            else if(arr[i][1] == '(')
                printf("<");
            else if(arr[i][1] == ')')
                printf(">");
            else if(arr[i][1] == 'i')
                printf("<");
            else if(arr[i][1] == '$')
                printf(">");
        }
        else if(arr[i][0] == 'F')
        {
            if(arr[i][1] == '+')
                printf(">");
            else if(arr[i][1] == '*')
                printf(">");
            else if(arr[i][1] == '(')
                printf(">");
            else if(arr[i][1] == ')')
                printf(">");
            else if(arr[i][1] == 'i')
                printf(">");
            else if(arr[i][1] == '$')
                printf(">");
        }

        printf("\n");
    }

    return 0;
}
