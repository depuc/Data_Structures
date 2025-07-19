#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct node {

    char* key;
    int value;
    struct node* next;
}node;

typedef struct HashMap {

    node** buckets;

}HashMap;

unsigned int hash(const char* key){

    unsigned long hash = 5381;
    int c;

    while(( c = *key++))
        hash = ((hash << 5) + hash) +c;

    return hash % TABLE_SIZE;
}

HashMap* create_table(){

    HashMap* map = malloc(sizeof(HashMap));
    map->buckets = calloc(TABLE_SIZE, sizeof(node*));
    return map;
}

void insert(HashMap* map, int value, const char* key){
    
    unsigned int index = hash(key);
    node* head = map->buckets[index];
    
    while(head){
        if(strcmp(head->key, key)){
            head->value = value;
            return;
        }
        head = head->next;
    }
    
    node* new_node = malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = map->buckets[index];
    map->buckets[index] = new_node;
}
