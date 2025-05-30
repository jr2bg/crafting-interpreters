#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

struct Node {
    // pointer to the prev node
    struct Node* prev;

    // pointer to the next node
    struct Node* next;

    // stores a value, in this case, the value is a pointer of char
    // later on, space memory will be assigned to this pointer by using malloc
    char* string;
};

int traverse_forward_dll(struct Node* node){
    // traverses forward the linked list printing the current element
    // it is, goes from node to the next
    while (node != NULL){
        printf("%s\n", (*node).string);
        Sleep(2000);
        //node = node -> next;
        node = (*node).next;
    }
    return 0;
}

int traverse_backwards_dll(struct Node* node){
    // traverses forward the linked list printing the current element
    // it is, goes from node to the next
    while (node != NULL){
        printf("%s\n", (*node).string);
        Sleep(2000);
        //node = node -> prev;
        node = (*node).prev;
    }
    return 0;
}

int create_and_insert_in_dll(char* s, struct Node* head){
    struct Node *node = head; 

    // creates a new Node with string the pointer s 
    // at the end of the double ll
    struct Node new_node;
    new_node.next = NULL;
    new_node.string = s;

    // to get easy, lets consider head is a Node
    while ((*node).next != NULL){
        node = (*node).next;
    }

    // assign the corresponding addresses
    new_node.prev = node;
    (*node).next = &new_node;

    return 0;
}

int insert_node_in_dll(struct Node *node, struct Node *head){
    struct Node *trav = head;
    while (trav -> next != NULL) {
        trav = trav -> next;
    }

    (*node).prev = trav;
    trav->next = node;

    return 0;
}

int main(){
    struct Node *begin = (struct Node*)malloc(sizeof(struct Node));

    (*begin).prev = NULL;
    (*begin).next = NULL;
    (*begin).string = (char*)malloc(sizeof(char) * 15);

    *((*begin).string +  0) = 'c';
    *((*begin).string +  1) = 'h';
    *((*begin).string +  2) = 'o';
    *((*begin).string +  3) = 'n';
    *((*begin).string +  4) = 'c';
    *((*begin).string +  5) = 'h';
    *((*begin).string +  6) = 'i';
    *((*begin).string +  7) = 'n';
    *((*begin).string +  8) = '\0';

    (*begin).string = "chonchin2 OMG";

    // printf(begin.string);

    struct Node *second_n = (struct Node*)malloc(sizeof(struct Node));
    // take the addresses of both nodes to mutual reference
    // begin.next = &second_n;
    // second_n.prev = &begin;

    (*second_n).next = NULL;
    (*second_n).prev = NULL;
    (*second_n).string = "paloma";

    insert_node_in_dll(second_n, begin);

    struct Node *third_n = (struct Node*)malloc(sizeof(struct Node));
    (*third_n).next = NULL;
    (*third_n).prev = NULL;
    (*third_n).string = "my dear";
    insert_node_in_dll(third_n, begin);

    //insert_node_in_dll("paloma", &begin);

    traverse_forward_dll(begin);


    return 0;
}