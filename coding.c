#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


//letters of Alphabet in their order, for alter use with ASCII code
const char *ABC[] = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",};


//Coding the whole line using the upper function for each letter
void coding(FILE* file,char* s){
    int num_coded_dashes=0;   //number of dashes for the statistics
    int num_coded_dots=0;     //number of dots for the statistics


    char res[100];      //res will get the result of the coding process
    int n=0;           //n is a counter for the string res
    for(int i=0;s[i]!='\0';++i){
        char c = s[i];        //getting the strings characters one by one

        if(isalpha(c)){       //isalpha is a function that checks if a character is in alphabet or not
            c = toupper(c);   //we work with uppercase letters

            for(int j=0;j<strlen(ABC[c-'A']);j++ ){
                res[n++]=ABC[c-'A'][j];  }         //here c-'A' will return an integer between 0 and 25 which is the letter order
                                                  // and which will return the specific code from the ABC array
                                                  //j is a counter to run through the morse code of the letter to copy it all
            res[n++]=' ';
            }

        else if(c == ' '){
            res[n++]='/';                        //' / ' means there is a space between two words
            res[n++]=' ';
            }




    }
    res[n]='\0';                                //closing the result array
    printf("the Morse code is: %s\n",res) ;


    //this loop is used to count the number of dashes and dots
    for(int i=0;i<n;i++){
        if(res[i]=='-') num_coded_dashes++;
        else if(res[i]=='.') num_coded_dots++;
    }

    //here we're puting the result and the statistics into a file
    fputs(res,file);
    printf("dashes: %d\n",num_coded_dashes);
    fprintf(file,"\n number of coded dashes is: %d",num_coded_dashes );

    printf("dots: %d\n",num_coded_dots);
    fprintf(file,"\n number of coded dots is: %d\n",num_coded_dots);
    printf("the string contains\n");
    stat1(file,s);

}


    //a function of the statistics of a the input string according to the ASCII code
    //then the result is printed on the screen and in the file


void stat1(FILE* file,char*s){
    int abc[26]={0};
    for(int i=0;i<strlen(s);i++){
        if (isalpha(s[i]))
            abc[toupper(s[i])-65]++;
    }
    fprintf(file,"this string contains \n");
    for(int j=0;j<26;j++)
        if(abc[j]!=0){
            fprintf(file," %c: %d  ",j+65,abc[j]);
            printf(" %c: %d  ",j+65,abc[j]);}
    fprintf(file,"\n");
    printf("\n");
}
