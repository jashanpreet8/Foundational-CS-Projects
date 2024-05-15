#include<stdio.h>
#include<cs50.h>

int main(void)
{
    string word = get_string("Word: ");

    

        for(int i = 0; i < word; i++)
        {
           if (word[i] > word[i - 1])
           {
             printf("Yes");
           }
        }
         else
        {
            printf("No");
        }
printf("\n");
}