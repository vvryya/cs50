#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");

    while ((height < 1) || (height > 8))
    {
        height = get_int("Height: ");
    }

    for (int i = 1; i <= height; i++)
    {
        for (int k = 0; k < height - i; k++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}