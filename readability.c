#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Promt the user for text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the promted text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate Coleman-Liau index
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the assessed grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("After Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    // Number of letters in user prompt
    int letters = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    // Number of words in user prompt
    int words = 0;
    bool inside_word = false;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isspace(text[i]))
        {
            inside_word = false;
        }
        else if (!inside_word)
        {
            words++;
            inside_word = true;
        }
    }
    return words;
}

int count_sentences(string text)
{
    // Number of sentences in user prompt
    int sentences = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
