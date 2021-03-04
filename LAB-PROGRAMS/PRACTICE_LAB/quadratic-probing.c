#include<stdio.h>
#define MAX_SIZE 11
int hashTable[MAX_SIZE] = {-1};

int hashValue(int value){
    return(value % MAX_SIZE);
}

void add(int value){
    int hashKey = hashValue(value);
    printf("Hashkey is %d \n", hashKey);
    if (hashTable[hashKey] == -1){
        hashTable[hashKey] = value;
    }
    
    else{
        int qp = 1;
        int store = hashKey;
        hashKey  = (hashKey + qp*qp) % MAX_SIZE;
        while(hashKey != store){
            if (hashTable[hashKey] == -1){
                hashTable[hashKey] = value;
                break;
            }
            //linear probing
            qp += 1;
            hashKey = (hashKey + qp*qp) % MAX_SIZE;
        }
        //loop entirely 
        if(hashKey == store){
            printf("The hashtable is full, no more elements can be entered \n");
        }
    }
}
void display(){
    printf("The contents of the hashtable are : \n");
    for(int i = 0; i < MAX_SIZE; i++){
        printf("[%d]  %d\n", i, hashTable[i]);
    }
}

void search(int value){
    int hashKey = hashValue(value);
    if (hashTable[hashKey] == value){
        printf("The value is at index %d ", hashKey);
    }
    
    else{
        int qp = 1;
        int store = hashKey;
        hashKey  = (hashKey + qp*qp) % MAX_SIZE;
        while(hashKey != store){
            if (hashTable[hashKey] == value){
                printf("The value is at index %d ", hashKey);
                break;
            }
            qp += 1;
            hashKey = (hashKey + qp*qp) % MAX_SIZE;
        }
        if(hashKey == store){
             printf("Cannot find the element \n");
        }
    }
}
void delete_key(int value){
    int hashKey = hashValue(value);
    if (hashTable[hashKey] == value){
        hashTable[hashKey] = -1;
    }
    
    else{
        int qp = 1;
        int store = hashKey;
        hashKey  = (hashKey + qp*qp) % MAX_SIZE;
        while(hashKey != store){
            if (hashTable[hashKey] == value){
                hashTable[hashKey] = -1;
                break;
            }
            qp += 1;
            hashKey = (hashKey + qp*qp) % MAX_SIZE;
        }
        if(hashKey == store){
            printf("Cannot find the element \n");
        }
    }
}
int main(){
    int choice;
     //printf("1 to add \n2 to search\n3 to delete\n4 to display\n");
    for(int i = 0; i < MAX_SIZE; i++){
        hashTable[i] = -1;
    }
    printf("***************************************");
    printf("\n               MENU\n");
    printf("****************************************");
    printf("\n1.Add a key\n2.Display the hashtable\n3.Delete a key\n4.Search for a key\n");
    while(1){
        printf("\n****************************************\n");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int value;
                printf("Enter the value : ");
                //fgets(message, 1000, stdin);
                scanf("%d", &value);
                add(value);
                break;
            }
            case 2:{
                display();
                break;
            }
            case 3:{
                int value;
                printf("Enter the value to be deleted : ");
                scanf("%d", &value);
                delete_key(value);
                break;
            }
            case 4:{
                int value;
                printf("Enter the value to be searched : ");
                scanf("%d", &value);
                search(value);
                break;
            }
            default:
            printf("Wrong Option! \n");
        }
    }
    return(0);
}