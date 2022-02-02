#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"header.h"



//Creating a node
node* creat_node(char let){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->val=let;
    newNode->left=NULL;
    newNode->right=NULL;


    return newNode;
}

//Creating the tree in its specific order
node* creat_tree(){

    node* root=(node*)malloc(sizeof(node));
    root->left=creat_node('E');
    root->right=creat_node('T');

        node *rootE= root->left;
        node *rootT=root->right;
        rootE->left=creat_node('I');
        rootE->right=creat_node('A');
        rootT->left=creat_node('N');
        rootT->right=creat_node('M');

            node *rootI= rootE->left;
            node *rootA=rootE->right;
            rootI->left=creat_node('S');
            rootI->right=creat_node('U');
            rootA->left=creat_node('R');
            rootA->right=creat_node('W');

                    node *rootS= rootI->left;
                    node *rootU=rootI->right;
                    rootS->left=creat_node('H');
                    rootS->right=creat_node('V');
                    rootU->left=creat_node('F');

                    node *rootR= rootA->left;
                    node *rootW=rootA->right;
                    rootR->left=creat_node('L');
                    rootW->left=creat_node('P');
                    rootW->right=creat_node('J');

            node *rootN= rootT->left;
            node *rootM=rootT->right;
            rootN->left=creat_node('D');
            rootN->right=creat_node('K');
            rootM->left=creat_node('G');
            rootM->right=creat_node('O');

                    node *rootD= rootN->left;
                    node *rootK= rootN->right;
                    rootD->left=creat_node('B');
                    rootD->right=creat_node('X');
                    rootK->left=creat_node('C');
                    rootK->right=creat_node('Y');

                    node *rootG= rootM->left;
                    rootG->left=creat_node('Z');
                    rootG->right=creat_node('Q');

    return root;


}


//decoding a Morse code to a single letter, getting the right value through traversing the tree
char morse_to_char(node* root,char * mor,int* num_dash,int* num_dot){

    int i=0;
    while(mor[i]=='.' || mor[i]=='-'){
        if(mor[i]=='.') {
            root=root->left;
            i++;
            (*num_dot)++;
        }
        else {
            root=root->right;
            i++;
            (*num_dash)++;
        }
    }
    return root->val;
}


//destroying the tree
void destroy_tree(node* root){
    if(root==NULL) return;

    destroy_tree(root->left);
    destroy_tree(root->right);

    free(root);



}


//decoding the whole line using morse_to_char function that decodes every letter
void decoding(node* root,char* input,FILE* file){
    char* tmp2;
    int j=0,n=0,i=0;    //i is the counter of the input,
                        //j is the counter of the temporary string tmp which will take the code of a letter each time
                        //n is the counter for the final result, the final string
    int num_dash=0;         //num_dash is the number of dashes
    int num_dot=0;          //num_dot is the number of dots
    char tmp[10];           //tmp takes the morse code of one letter each time
    char final_code[100];    //the final string

    while(input[i]!='\0'){

        if(input[i]==' ' || input[i]=='/' || input[i]=='.' || input[i]=='-'){


        if(input[i]!=' ' && input[i]!='/'){
        tmp[j++]=input[i++];

        }

        else if(input[i]==' '){
                if(input[i+1]=='/'){
                    tmp[j]='\0';
                    final_code[n++]=morse_to_char(root,tmp,&num_dash,&num_dot);
                    final_code[n++]=' ';
                    i=i+3;
                    j=0;
                }
                else{
                    tmp[j]='\0';
                    final_code[n++]=morse_to_char(root,tmp,&num_dash,&num_dot);

                    i++;
                    //printf("this is tmp %s\n",tmp);
                    j=0;
                }}

    }
    else {printf("Error in the code\n"); return;} }
    //This part is basically about printing the result/stats
    tmp[j]='\0';
    final_code[n++]=morse_to_char(root,tmp,&num_dash,&num_dot);
    final_code[n]='\0';
    printf("the string decoded is: %s\n",final_code);
    printf("the number of dashes is %d and the number of dots is %d\n", num_dash, num_dot);
    fprintf(file," %s\n",final_code);
    fprintf(file,"the number of dashes is: %d \nthe number of dots is: %d\n", num_dash, num_dot);
    stat_string(file,final_code);


    }

    //a function of the statistics of a the result string
void stat_string(FILE* file,char*s){
    int abc[26]={0};                       //abc will contain the number of occurences of each letter
    for(int i=0;i<strlen(s);i++){
        if (isalpha(s[i]))
            abc[toupper(s[i])-65]++;
    }
    fprintf(file,"this string contains \n");
    printf("this string contains \n");
    for(int j=0;j<26;j++)
        if(abc[j]!=0){
            fprintf(file," %c: %d  ",j+65,abc[j]);     //the ASCII code is used here
            printf(" %c: %d  ",j+65,abc[j]);}
    fprintf(file,"\n");
    printf("\n");
}
