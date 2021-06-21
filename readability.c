#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
// Declaring variavles    
    int NumberOfLettres = 0;
    int NumberOfWords = 1;
    int NumberOfSentences = 0;
// Receiving prompt from the user.
    string text = get_string("Text: ");

// Counting number of lettres, words, sentences.
    for (int k = 0; k < strlen(text); k++)
    {
      if ((text[k] >= 'A' && text[k] <= 'Z') || (text[k] >= 'a' && text[k] <= 'z'))
      {
          NumberOfLettres++;
      }
       else if (text[k] == ' ')
      {
          NumberOfWords++;
      }
       else if (text[k] == '!' || text[k] == '?' || text[k] == '.')
      {
          NumberOfSentences++;
      }
    }
// Calculating Coleman-Liau index.
    float L = (100 * (float) NumberOfLettres / (float) NumberOfWords);
    float S = (100 * (float) NumberOfSentences / (float) NumberOfWords);
    float grade = 0.0588 * L - 0.296 * S - 15.8;
// Printing the results.
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade ");
    }

}