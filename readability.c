#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float L = (float)(count_letters(text)) / (float)(count_words(text)) * 100;
    float S = (float)(count_sentences(text)) / (float)(count_words(text)) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int n = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            n++;
        }
    }

    return n;
}

int count_words(string text)
{
    int n = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' || (text[i] == '.' && text[i + 1] != ' ') || (text[i] == ',' && text[i + 1] != ' ') || (text[i] == '!'
                && text[i + 1] != ' ') || (text[i] == '?' && text[i + 1] != ' '))
        {
            //printf("%c", text[i-1]);
            n++;
        }
    }
    return n;
}

int count_sentences(string text)
{
    int n = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            n++;
        }
    }
    return n;
}