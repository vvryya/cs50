#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size;
    start_size = get_int("Start size: ");

    while (start_size < 9)
    {
        start_size = get_int("Start size: ");
    }

    int end_size;
    end_size = get_int("End size: ");

    while (end_size < start_size)
    {
        end_size = get_int("End size: ");
    }

    int years = 0;

    while (start_size < end_size)
    {
        start_size = start_size + start_size / 3 - start_size / 4;
        years++;
    }

    printf("Years: %i\n", years);
}
