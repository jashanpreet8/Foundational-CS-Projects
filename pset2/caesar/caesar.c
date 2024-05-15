#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char rotate(char c, int i);

int main(int argc, string argv[])
{
  if(argc != 2){
     printf("Usage: ./caesar key\n");
     return 1;
  }

  for(int i = 0; i < strlen(argv[1]); i++){
      if(!isdigit(argv[1][i])){
         printf("Usage: ./caesar key\n");
         return 1;
    }
  }

  int x = atoi(argv[1]);
  string ptext = get_string("Plaintext:  ");

  printf("Ciphertext: ");
  for(int j = 0; j < strlen(ptext); j++){
    if(!isalpha(ptext[j])){
      printf("%c", ptext[j]);
    }
    else{
      rotate(ptext[j], x);
    }
  }
   printf("\n");
}

char rotate(char c, int n)
{
  if(isupper(c)){
    printf("%c", ((((c - 65) + n)% 26)+ 65));
  }

  if(islower(c)){
   printf("%c", ((((c - 97) + n)% 26)+ 97));
  }
  return 0;

}