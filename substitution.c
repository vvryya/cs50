#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decode(char key[]);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        char key[strlen(argv[1])];
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        for (int i = 0; i < strlen(argv[1]); i++)
        {
            for (int j = 0; j < strlen(argv[1]); j++)
            {
                if ((toupper(argv[1][i]) == toupper(argv[1][j])) && (i != j))
                {
                    printf("Key must not contain duplicate characters.\n");
                    return 1;
                }
            }
        }

        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must contain letters only.\n");
                return 1;
            }
            else if (islower(argv[1][i]))
            {
                argv[1][i] = toupper(argv[1][i]);
            }
            key[i] = argv[1][i];
        }

        decode(key);
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

void decode(char key[])
{
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            int number = plaintext[i];
            if (islower(plaintext[i]))
            {
                printf("%c", tolower(key[number - 97]));
            }
            else
            {
                printf("%c", key[number - 65]);
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}