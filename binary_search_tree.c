#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int data;
    struct node *left;
    struct node *right;
} node;


node* create_node(int data){
   
   node* new_node = (node*)malloc(sizeof(node));

   new_node->left = new_node->right = NULL;
   new_node->data = data;

   return new_node;
}

node* insert(node* root, int data){

    if(root == NULL)
        return create_node(data);

    if(root->data < data)
        root->right =  insert(root->right,data);
    
    else if(root->data > data)
        root->left =  insert(root->left,data);

    return root;

}

void print_inorder(node* root){

    if(root == NULL) return;

    print_inorder(root->left);
    printf("%d ",root->data);
    print_inorder(root->right);

}

int main(){
    node* root = NULL;

    root = insert(root,50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    print_inorder(root);
    return 0;
}
