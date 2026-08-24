#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

int E();
int EP();
int T();
int TP();
int F();

int main()
{
    printf("\nRecursive Descent Parsing for the following grammar\n");
    printf("\nE  -> TE'");
    printf("\nE' -> +TE' / @");
    printf("\nT  -> FT'");
    printf("\nT' -> *FT' / @");
    printf("\nF  -> (E) / ID\n");

    printf("\nEnter the string to be checked: ");
    scanf("%s", input);

    i = 0;

    if (E())
    {
        if (input[i] == '\0')
            printf("\nString is accepted\n");
        else
            printf("\nString is not accepted\n");
    }
    else
    {
        printf("\nString is not accepted\n");
    }

    return 0;
}

int E()
{
    if (T())
    {
        if (EP())
            return 1;
    }

    return 0;
}

int EP()
{
    if (input[i] == '+')
    {
        i++;

        if (T())
        {
            return EP();
        }

        return 0;
    }

    return 1;
}

int T()
{
    if (F())
    {
        if (TP())
            return 1;
    }

    return 0;
}

int TP()
{
    if (input[i] == '*')
    {
        i++;

        if (F())
        {
            return TP();
        }

        return 0;
    }

    return 1;
}

int F()
{
    if (input[i] == '(')
    {
        i++;

        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                return 1;
            }
        }

        return 0;
    }
    else if ((input[i] >= 'a' && input[i] <= 'z') ||
             (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        return 1;
    }

    return 0;
}