#include <stdio.h>
#include <stdlib.h>

typedef struct htnode{
    char* key; 
    int* value; 
}Node;

typedef struct hashTable{
    Node** items; 
    int size; 
    int count; 
}Table; 

Node* create_node(char* key, int* value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = (char*)malloc(stlen(key)+1);
    node->value = (int*)malloc(sizeof(value));
    
    node->key = key; 
    node->value = value; 

    return node; 
}

Table* cache(int capacity){
    Table* table = (Table*)malloc(sizeof(Table));
    table -> size = capacity; 
    table -> count = 0; 
    table -> items = (Node**)calloc(table->size, sizeof(Node*));
    for(int i=0; i<table->size; i++){
        table->items[i]=NULL;
    }
return table; 
}

void free_node(Node* item){
    free(item->key);
    free(item->value);
    free(item);
}

void free_table(Table* table){
    for(int i = 0; i<table->size; i++){
        Table* item = table->items[i];
        if(item!=NULL)free_node(item);
    }

    free(table->items); 
    free(table);
}

void put (Table* table, char* key, int*value){
    
}













int main (void){
    cache(2);
    put(1, 10); 
    put(2, 20); 
    get(1); 
    put(3, 30); 
    get(2); 
    put(4, 40); 
    get(1); 
    get(3); 
    get(4); 
    put(5, 50); 
 }
