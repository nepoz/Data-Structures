#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int data;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

//Complete functions
void add(Node *new_element, LinkedList *list);
LinkedList* create_linked_list();
Node* create_node(int data);
int data_at(LinkedList *list, int node_pos);
void print_list_contents(LinkedList *list);
void clear_list(LinkedList* list);
int remove_at(LinkedList* list, int node_pos);
int add_at(Node* new_element, LinkedList* list, int node_pos);
int replace_at(Node* new_element, LinkedList* list, int node_pos);
int remove_last(LinkedList *list);

//Adds a new node to the end of the linked list
void add(Node *new_element, LinkedList *list) {
    if (list -> size == 0) {
        list -> head = new_element;
        list -> tail = list -> head;
        list -> size++;
    }
    else {
        list -> tail -> next = new_element;
        list -> tail = new_element;
        list -> tail -> next = NULL;
        list -> size++;    
    }

}

int add_at(Node* new_element, LinkedList* list, int node_pos) {
    if (node_pos > list -> size || node_pos < 1) {
        return -1;
    }
    else if (node_pos == 1) {
        new_element -> next = list -> head;
        list -> head = new_element;
        list -> size++;
        return 1;
    }
    else {
        Node *trav = list -> head;

        for (int i = 1; i < node_pos - 1; i++) {
            trav = trav -> next;
        }

        //At this point, trav is one before the position where node is being added
        new_element -> next = trav -> next;
        trav -> next = new_element; 
        list -> size++;

        return 1;
    }
}

//Removes the last element from the linked list
int remove_last(LinkedList *list) {
    if(list -> size <= 0) {
        return 0;
    }
    else if (list -> size == 1) {
        free(list -> head);
        list -> head = list -> tail = NULL;
        list -> size = 0;
        return 1;
    }
    else {
        Node *trav = list -> head;

        while (trav -> next != list -> tail) {
        trav = trav -> next;
    } 

        //At this point, the Node's next pointer will point to tail
        free(trav -> next);
        trav -> next = NULL;
        list -> tail = trav;
        list -> size--;

        return 1;
    }
    
}

void clear_list(LinkedList* list) {
    while (list -> size != 0) {
        remove_last(list);
    }
}

int remove_at(LinkedList* list, int node_pos) {
    if (node_pos > list -> size || node_pos < 1) {
        return -1;
    }
    else if (list -> size == 1 || node_pos == list -> size) {
        remove_last(list);
        list -> size--;
        
        return 1;
    }
    else if (node_pos == 1) {
        Node* temp = list -> head -> next;
        free(list -> head);
        list -> size--;
        list -> head = temp;
        
        return 1;
    }
    else {
        Node *trav = list -> head;

        for (int node = 1; node < node_pos - 1; node++) {
            trav = trav -> next;
        }

        //At this point trav is one before what we want to remove
        Node *temp = trav -> next;
        trav -> next = temp -> next;
        free(temp);
        list -> size--;

        return 1;
    }
}

//Creates a new, empty linked list
LinkedList* create_linked_list() {
    LinkedList* new_list = (LinkedList*) malloc(sizeof(LinkedList));

    new_list -> head = NULL;
    new_list -> tail = NULL;
    new_list -> size = 0;
    
    return new_list;
}

//Creates a new node initially pointing to no 'next' node
Node* create_node(int data) {
    Node* fresh_node = (Node*) malloc(sizeof(Node));

    fresh_node -> data = data;
    fresh_node -> next = NULL;

    return fresh_node;
}

//MISBEHAVING METHOD: EXPECTING RETURN VALUE OF 12 IN PROGRAM
int data_at(LinkedList *list, int node_pos) {
    Node* trav = list -> head;

    //If user enters node_pos less than 1, return error value
    if (node_pos > list -> size || node_pos < 1) {
        return -1;
    }
    else {
        for (int i = 1; i != node_pos; i++) {
            trav = trav -> next;
        }

        return trav -> data;
    }
}

void print_list_contents(LinkedList *list) {
    if (list -> size > 0) {
        for (int i = 1; i <= list -> size; i++) {
            printf("Data = %d\n", data_at(list, i));
        }
    }
    else {
        printf("Did not find any elements!\n");
    }
}