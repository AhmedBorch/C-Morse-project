#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct node{
    char val;

    struct node* left;
    struct node* right;
}node;

void coding(FILE* file,char* s);


node* creat_node(char let);

node* creat_tree();

char morse_to_char(node* root,char * mor,int* num_dash,int* num_dot);

void decoding(node* root,char* input,FILE* file);

void destroy_tree(node* root);

#endif // HEADER_H_INCLUDED
