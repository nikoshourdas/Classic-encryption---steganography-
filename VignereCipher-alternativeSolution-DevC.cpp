#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <functional>


// this code only worked in the DevC compiler but not with the command gcc test.cpp 
// i am including it as an alternative solution 

std::string get_full_key(std::string , std::string);
std::string get_encryption(std::string , std::string);
std::string get_decryption(std::string,std::string);

// Function to extend the key to the length of plaintext
std::string get_full_key(std::string pt, std::string k){
    if(k.size() >= pt.size())
        return k;
    else{
        int psize = pt.size()-k.size();
        int ksize = k.size(); 
        while(psize >= ksize){
            k += k;
            psize -= ksize;
        }
 
        k += k.substr(0, psize);
        return k;
    }
}
// Encryption Function
std::string get_encryption(std::string pt, std::string k){
 
    std::string ct = "";
    for(int i=0;i<pt.size();i++)
        ct += (char) (((int)pt[i]-'A' + (int)k[i]-'A') % 26) + 'A';
 
    return ct;
}
 
// Decryption Function
std::string get_decryption(std::string ct, std::string k){
 
    std::string pt = "";
    for(int i=0;i<ct.size();i++)
        pt += (char) ((((int)ct[i]- 'A' - (k[i] -'A')) + 26) % 26) + 'A';
 
    return pt;
}

int main()
{
     int choice;
     int flag=0;
     while(true)
     {
          std::string plaintext = "wearediscoveredsaveyourself";
          std::string key = "deceptivedeceptivedeceptive";
          std::string ciphertext ;
          key = get_full_key(plaintext,key);
          
          std::cout<<" THE PLAINTEXT: "<< plaintext <<std::endl;
 
          std::cout<<" THE KEY: "<< key <<std::endl;

          printf(" \n 1. Encrypt Text");
          printf("\n 2. Decrypt Text");
          printf("\n 3. Exit if you have encode ");
          printf("\n Enter Your Choice :   ");
          scanf("%d",&choice);
          fflush(stdin);
          if(choice == 3){ 
               if(flag==1){
               break;
               }
               else
                    printf("nothing yet waiting to encode \n");
               }
          else if(choice == 1) {
               flag=1;
          
               FILE *fp = fopen("CipherText.txt", "w+");
                if (fp == NULL)
               {
                    printf("no txt detected");
        
               }
               else{
                    
               }
                    ciphertext = get_encryption(plaintext, key);
                    std::cout<<" THE CIPHERTEXT: "<< ciphertext << std::endl;
               }
     
          else if(choice == 2){
               if(flag==1){
               // Function call to decode the data
                    plaintext = get_decryption(ciphertext, key);
 
                    std::cout<<" THE DECODED PLAINTEXT: "<< plaintext << std::endl;
               }
               else{
                    printf("Encode text so it can be decoded. \n" );
               }
          }else
               printf("\n Please Enter Valid Option. \n");
     }

     return 0;
}
