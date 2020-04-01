#include <stdio.h>
#include <stdlib.h>

//RB tree node structure
struct node
{
    int data;
    char color;
    struct node *left, *right, *parent;
};

void insert(Struct node **root, int data){
    
    //allocate memory for new node
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = n->parent = null;
    
    //if root is null, make n root
    if(*root == NULL){
        n->color = 'black';
        (*root) = n;
    }else{
        
    }
    
}