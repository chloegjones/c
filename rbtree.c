#include <stdio.h>
#include <stdlib.h>

//RB tree node structure
struct node
{
    int data;
    char color;
    struct node *left, *right, *parent;
};

void leftRotate(struct node **root, struct node *r)
{
    if (!r || !r->right) return;
    
    struct node *temp = r->right;
    r->right = temp->left;

    if (r->right != NULL) r->right->parent = x;
    
    temp->parent = r->parent;

    if (r->parent == NULL) (*root) = temp;
    else if (r == r->parent->left) r->parent->left = temp;
    else r->parent->right = temp;

    temp->left = r;
    r->parent = temp;
}

void rightRotate(struct node **root, struct node *temp)
{
    if (!temp || !temp->left)return;
    
    struct node *r = temp->left;
    temp->left = r->right;
    
    if (r->right != NULL) r->right->parent = temp;
    
    r->parent = temp->parent;
    
    if (r->parent == NULL) (*root) = r;
    else if (temp == temp->parent->left) temp->parent->left = r;
    else temp->parent->right = r;
    
    r->right = temp;
    temp->parent = r;
}
void insertFixUp(struct node **root, struct node *n){
    while (n != *root && n != (*root)->left && n != (*root)->right && n->parent->color == 'R'){
        struct node *temp;
        
        //Find uncle and store in temp
        if(n->parent && n->parent->parent == n->parent->parent->left) temp = n->parent->parent->right;
        else temp = n->parent->parent->left;
        
        //Case 1: Uncle node is Red
        //(i) change color of grandparent red
        //(ii) change color of parent and uncle as black
        //(iii) move n to grandparent
        
        if(!temp) n = n->parent->parent;
        else if(temp->color == "r"){
            temp->color = 'b';
            n->parent->color = 'b';
            n->parent->parent->color = 'b';
        }else{
            
            //Case 2/3: Uncle node is black
            //(i) left case, swap color of parent and grandparent
            //(ii) left rotate parent
            //(iii) right rotate grandparent
            
            if(n->parent == n->parent->parent->left && n == n->parent->left){
                char c = n->parent->color ;
                n->parent->color = n->parent->parent->color;
                n->parent->parent->color = c;
                rightRotate(root, n->parent->parent);
            }
            
            //Case 2/3: Uncle node is black
            //(i) left/right case, swap color of current node and grandparent
            //(ii) left rotate parent
            //(iii) right rotate grandparent
            
            if(n->parent && n->parent->parent == n->parent->parent->left && n == n->parent->right){
                char c = n->color ;
                n->color = n->parent->parent->color;
                n->parent->parent->color = c;
                leftRotate(root, n->parent);
                rightRotate(root, n->parent->parent);
            }
            
            //Case 2/3: Uncle node is black
            //(i) right/right case, swap color of parent and grandparent
            //(ii) left rotate grandparent
            
            if(n->parent && n->parent->parent == n->parent->parent->right && n == n->parent->right){
                char c = n->parent->color ;
                n->parent->color = n->parent->parent->color;
                n->parent->parent->color = c;
                leftRotate(root, z->parent->parent);
            }
            
            //Case 2/3: Uncle node is black
            //(i) right/left case, swap color of current node and grandparent
            //(ii) right rotate parent
            //(iii) left rotate grandparent
            
            if(n->parent == n->parent->parent->left && n == n->parent->left){
                char c = n->color ;
                n->color = n->parent->parent->color;
                n->parent->parent->color = c;
                rightRotate(root, n->parent);
                leftRotate(root, n->parent->parent);
            }
        }
    }
    
    //root is always black
    (*root)->color = 'b';
}
void insert(struct node **root, int data){
    //allocate memory for new node
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = n->parent = null;
    
    //if root is null, make n root and black
    if(*root == NULL){
        n->color = 'b';
        (*root) = n;
    }else{
        struct node *temp = NULL;
        struct node *r = (*root);
        
        //left tree or right tree
        while(r != NULL){
            temp = r;
            if(n->data < r->data) r = r->left;
            else r = r->right;
        }
        
        //change color, insert node
        n->color = 'r';
        n->parent = temp;
        
        if(n->data < temp->data) temp->left = n;
        else temp->right = n;
        
        //fix red-black tree's property if violated
        insertFixUp(root, n);
    }
}