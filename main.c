#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"



int main(){

        char a[100];
        char s[100];
        int choice;

        printf("                      Morse Program welcomes you!\n");
        do{
            printf("To code press 1: \nTo decode press 2: \nTo exit press 0: ");
            scanf("%d",&choice);
        } while(choice!= 0 && choice!=1 && choice!=2);
        while(choice!= 0){

            switch(choice){

                case 1:
                    //This is the call for the coding part

                printf("Enter a line of alphabet letters to code it into Morse: ");
                scanf(" %[^\n]",a) ;
                FILE* fp=fopen("Coding.txt","a");
                if(fp==NULL){
                    printf("file not found");

                }
                fprintf(fp,"the input is: %s and the result is: ",a);
                coding(fp,a);
                fprintf(fp,"           _____________________________________           \n");
                fclose(fp);

                break;


                //This is the call for the decoding part


                case 2:

                printf("Enter a line coded in Morse to decode it: ");
                scanf(" %[^\n]",s) ;
                FILE* fp2=fopen("Decoding.txt","a");
                if(fp2==NULL){
                    printf("file not found");

                }
                node* root=creat_tree();
                fprintf(fp2,"the input is: %s and the result is: ",s);
                decoding(root,s,fp2);
                destroy_tree(root);
                fprintf(fp2,"           _____________________________________           \n");
                fclose(fp2);

                break;

        }
            do{
            printf("To code press 1 \nTo decode press 2 \nTo exit press 0: ");
            scanf("%d",&choice);
        } while(choice!= 0 && choice!=1 && choice!=2);
        }
        return 1;
}


















