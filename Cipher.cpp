#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char output[1000];

void encode(char*);
void decode();

int main()
{
     int choice;
     bool flag = false;
     char input[1000],*var;

     do
     {
          printf(" \n 1. Encrypt Text");
          printf("\n 2. Decrypt Text");
          printf("\n 3. Exit ");
          printf("\n Enter Your Choice :   ");
          scanf("%d",&choice);
          fflush(stdin);
          if(choice == 3) 
               break;
          else if(choice == 1) {

               flag = true;
               
               printf("Give text to encrypt:");
               fflush(stdin);
               scanf("%s",input);
               fflush(stdin);
               encode(input);
          }
            
          // }
          else if(choice == 2 && flag)
               decode();
          else
               printf("\n Please Enter Valid Option. \n");
     }while(true);

     return 0;
}

void encode(char *input)
{
     int i,j;
     char key[]="deceptivedeceptivedeceptive";
      puts(input);
     for(i=0,j=0;i<strlen(input);i++,j++)
     {
          //repeat the key if you are at end of it.
          if(j>=strlen(key))
          {
               j=0;
          }
          //character from input + character from key % 26 is encrypted charater
          output[i] = 65+(((toupper(input[i])-65)+(toupper(key[j])-65))%26);
     }
     puts(output);
     FILE *fp;
               fp = fopen("CipherText.txt", "w");

                    fputs(output,fp);
                    fclose(fp);

}

void decode()
{
     unsigned int i,j;
     char key[]="deceptivedeceptivedeceptive",value;
     
      printf("\n");

     for(i=0,j=0;i<strlen(output);i++,j++)
     {
          //repeat the key if you are at end of it.
          if(j>=strlen(key))
          {
               j=0;
          }
          //similar to encipher only difference is you need to subtract
          value = (toupper(output[i])-64)-(toupper(key[j])-64);
          //if value is negative. We have to rotate it backwards 
          //so add it to 26 (it's a negative value to adding will actually cause subtraction) to get original character.
          if( value < 0)
          {
               value = 26 + value;
          }          
          printf("%c",tolower(65 + (value % 26)));
     }
      printf("\n");

}