#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
   string text = get_string("Text: ");

   float L = (count_letters(text) * 100.0) / count_words(text);
   float S = (count_sentences(text) * 100.0) / count_words(text);

   int index = round(0.0588 * L - 0.296 * S - 15.8);

   if(index > 16){
    printf("Grade 16+\n");
   }
   else if(index < 1){
    printf("Before Grade 1\n");
   }
   else{
   printf("Grade %i\n", index);
   }
}

int count_letters(string text)
{
    int i, j = 0;
    for(i = 0; i < strlen(text); i++){
        if(isupper(text[i]) || islower(text[i])){
         j++;
        }
    }
  return j;
}

int count_words(string text)
{
     int a, b = 0;
     for(a = 0; a < strlen(text); a++){
        if(isspace(text[a])){
            b++;
        }
     }
   return b + 1;
}

int count_sentences(string text)
{
    int x, y =0;
    for(x = 0; x < strlen(text); x++){
        if(text[x] == '.' || text[x] == '!' || text[x] == '?'){
            y++;
        }
    }
   return y;
}