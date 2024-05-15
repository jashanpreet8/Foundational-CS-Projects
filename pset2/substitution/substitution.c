#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
   if(argc != 2){
    printf("Usage: ./substitution key\n");
    return 1;
   }

   for(int i = 0; i < strlen(argv[1]); i++){
      if(!isalpha(argv[1][i])){
         printf("Key must contain only characters.\n");
         return 1;
      }
      else if(strlen(argv[1]) != 26){
         printf("Key must contain 26 characters.\n");
         return 1;
      }
      for(int j = i +1; j < strlen(argv[1]); j++){
         if(toupper(argv[1][i]) == toupper(argv[1][j])){
            printf("Key must not contain repeated characters.\n");
            return 1;
         }
      }
   }

   string ptext = get_string("Plaintext:  ");

   for(int i = 0; i < strlen(argv[1]); i++){
      if(islower(argv[1][i])){
        argv[1][i] -= 32;
      }
   }

   printf("Ciphertext: ");

   for(int j = 0; j < strlen(ptext); j++){
      if(isupper(ptext[j])){
         int letter = ptext[j] - 65;
         printf("%c", argv[1][letter]);
      }
      else if(islower(ptext[j])){
          int letter = ptext[j] - 97;
         printf("%c", argv[1][letter] + 32);
      }
      else{
         printf("%c", ptext[j]);
      }
   }
    printf("\n");
  return 0;
}