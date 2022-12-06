#include <stdio.h>
#include <stdlib.h>


typedef struct htnode{
    int key; 
    int value; 
}Node;

typedef struct hashTable{
    Node** items; 
    int size; 
    int count; 
}Table; 

Table* table = NULL;
int lastUsed = 0; 

Node* create_node(int key, int value){
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->key = key; 
    node->value = value; 

    return node; 
}

Table* cache(int capacity){
    table = (Table*)malloc(sizeof(Table));
    table -> size = capacity; 
    table -> count = 0; 
    table -> items = (Node**)calloc(table->size, sizeof(Node*));
    for(int i=0; i<table->size; i++){
        table->items[i]=NULL;
    }
return table; 
}


//void collision(Node* item);

void put (int key, int value){
    //printf("\ninserting %d and %d\n", key, value);
    //printf("\n   last used is %d\n", lastUsed);
    //printf("\ncount:%d and size:%d\n", table->count, table->size);
    Node* item = create_node(key, value);

    //int* a = &key;
    //printf("\nkey: %d value:%d\n", key, value);
    //int index = hash_function(a); 
    //printf("\nindex: %d", index);
    //Node* temp = table->items[index];
    Node* temp1 = table->items[0];
    Node* temp2 = table->items[1];
    //printf("%d", temp1->key);
    if(temp1!=NULL){
        if(temp2!=NULL){
            //printf("\nlasy used %d\n", lastUsed);
            if(temp1->key==lastUsed){
                
                //free_node(table->items[1]);
                table->items[1]=item;

            }else{
                //printf("g");
                //free_node(table->items[2]);
                table->items[0]=item; 
            }
        }else{
            table->items[1]=item; 
        }
    }else{

       table->items[0]=item;

    }
    lastUsed=key;
    return; 




    // if(temp == NULL){
    //     if(table->count == table->size){
    //         printf("\nTABLE FULLLLLLLLLLL\n");
    //         if(temp1->key == lastUsed){
    //             temp2->key = key; 
    //             temp2->value = value; 
    //         }else{
    //             temp1->key = key;
    //             temp1->value = key;
    //         }
            
    //         return; 
    //     }
    //     //table->items[index] = item; 
    //     lastUsed = key;
    //     table->count++;
    // }else{
    //     if(temp->key==key){
    //         lastUsed = key;
    //         temp->value = value;
    //         return;
    //     }else{
    //         //collision(item);
    //         return;
    //     }
    // } 
}

void get(int key){
    //printf("\n   get value from %d\n", key);
    //printf("\n   last used is %d\n", lastUsed);
    //int* a = &key;
    //int index = hash_function(a);
    //Node* item = table->items[index];
    Node* temp1 = table ->items[0];
    Node* temp2 = table ->items[1];
    //printf("\n\nin in %d %d ",temp1->key, temp2->key);
    int value; 
    if(temp1->key == key){
        //printf("g");
        value = temp1->value;
        lastUsed=key;
        printf("\nThe value at %d is %d\n",key, value);
    }else if(temp2->key == key){
        value = temp2->value;
        lastUsed=key;
        printf("\nThe value at %d is %d\n",key, value);
    }else{
        
        printf("\n-1 (Not found)\n");
    
    }
    //printf("\nThe value at %d is %d", key, value);
    // if(item !=NULL){
    //     if(item->key == key){
    //         lastUsed = key;
    //         printf("\nvalue at %d is %d\n", key, item->value);
    //         return; 
    //     }
    // }
}




int main (void){
    
    Node* temp;
    Node* tem1;

    cache(2);
   // printf("g");
    put(1, 10); 
    put(2, 20); 
    get(1); 
//     temp = table->items[0];
//     tem1 = table->items[1];
//    // printf("\n\n%d %d ",temp->key, tem1->key);
    put(3, 30); 
    // temp = table->items[0];
    // tem1 = table->items[1];
    // //printf("\n\n%d %d ",temp->key, tem1->key);
    get(2); 
    // temp = table->items[0];
    // tem1 = table->items[1];
    // printf("\n\n%d %d ",temp->key, tem1->key);
    put(4, 40); 
    // temp = table->items[0];
    // tem1 = table->items[1];
    // printf("\n\n%d %d ",temp->key, tem1->key);
    get(1); 
    get(3); 
    get(4); 
    // temp = table->items[0];
    // tem1 = table->items[1];
    // printf("\n\n%d %d ",temp->key, tem1->key);
    put(5, 50); 
    // temp = table->items[0];
    // tem1 = table->items[1];
    // printf("\n\n%d %d ",temp->key, tem1->key);
    
}