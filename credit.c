#include <cs50.h>
#include <stdio.h>

void sum(int card[], int size);
void is_valid(int card[], int size);

int main(void)
{
    long n = get_long("Number: ");
    int length = 0;
    long temp = n;

    while (temp != 0)
    {
        temp = temp / 10;
        length++;
    }

    if ((length != 13) && (length != 15) && (length != 16))
    {
        printf("INVALID\n");
        return 0;
    }

    int card[length];

    for (int i = 0; i < length; i++)
    {
        card[i] = n % 10;
        n = n / 10;
    }

    sum(card, length);
}

void sum(int card[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 != 0)
        {
            int n = card[i] * 2;
            if (n > 9)
            {
                while (n != 0)
                {
                    sum += n % 10;
                    n = n / 10;
                }
            }
            else
            {
                sum += card[i] * 2;
            }
        }
        else
        {
            sum += card[i];
        }
    }

    if ((sum % 10) != 0)
    {
        printf("INVALID\n");
        return;
    }
    else
    {
        is_valid(card, size);
    }
}

void is_valid(int card[], int size)
{
    if ((size == 15) && (card[size - 1] == 3) && ((card[size - 2] == 4) || (card[size - 2] == 7)))
    {
        printf("AMEX\n");
    }
    else if ((size == 16) && (card[size - 1] == 5) && (card[size - 2] > 0) && (card[size - 2] < 6))
    {
        printf("MASTERCARD\n");
    }
    else if (((size == 16) || (size == 13)) && (card[size - 1] == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}