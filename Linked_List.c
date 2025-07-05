#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int data;
    struct node* next;

}node;

node* create_node(int data){

    node* newnode = (node* ) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void insert_beginning(node** head, int data){

    node* newnode = create_node(data);
    
    newnode->next = *head;
    *head = newnode;
}

void insert_end(node** head, int data){
    
    node* newnode = create_node(data);

    if(*head == NULL){
        *head =  newnode;
        return;
    }

    node* temp = *head;

    while(temp -> next != NULL){

        temp = temp->next;
            
    }

    temp->next = newnode;
}

void delete_node(node** head, int data){

    node* temp = *head;
    node* prev = NULL;

    if(temp->data == data && temp != NULL){
        
        *head = temp->next;
        free(temp);
        return; 

    }

    while(temp->next != NULL && temp->data != data){
        prev = temp;
        temp = temp->next; 
    }

    if(temp->next ==NULL) return;
    prev->next = temp->next;
    free(temp);

}

void print_list(node *head){
    
    while(head->next != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");


}
void free_list(node*head){

    node* temp;  

    while(head != NULL){

        temp = head;
        head = head->next;
        free(temp);
    }

}
int main(){
    
    node* head = NULL;
    insert_beginning(&head, 8);
    insert_end(&head, 9);
    insert_end(&head, 10);
    insert_end(&head, 11);
    insert_end(&head, 12);
    insert_end(&head, 13);
    insert_beginning(&head, 14);
    print_list(head);
    printf("\n");
    delete_node(&head, 8);
    delete_node(&head, 14);
    print_list(head);
    free_list(head);
}
