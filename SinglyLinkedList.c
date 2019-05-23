#include <stdio.h>

typedef struct Node {
    struct Node *next;
    int data;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

typedef struct LinkedListTraversal {
    Node *current;
} LinkedListTraversal;

void add(Node new_element, LinkedList *list);
void remove_last(LinkedList *list);
LinkedList create_linked_list();
Node create_node(int data);
int data_at(LinkedList *list, int node_pos);
void print_list_contents(LinkedList *list);

//MAIN
int main() {
    
    //NEED THIS BLOCK TO PRINT 12
    LinkedList test = create_linked_list();
    Node test_node = create_node(12);
    add(test_node, &test);
    printf("Data: %d\n", data_at(&test, 1));

    return 0;
}

//Adds a new node to the end of the linked list
void add(Node new_element, LinkedList *list) {
    if (list -> size == 0) {
        list -> head = &new_element;
        list -> tail = list -> head;
        list -> size++;
    }
    else {
        list -> tail -> next = &new_element;
        list -> tail = &new_element;
        list -> tail -> next = NULL;
        list -> size++;    
    }

}

//Removes the last element from the linked list
void remove_last(LinkedList *list) {
    Node *trav = list -> head;

    while (trav -> next != list -> tail) {
        trav = trav -> next;
    } 

    //At this point, the Node's next pointer will point to tail
    trav -> next = NULL;
}

//Creates a new, empty linked list
LinkedList create_linked_list() {
    LinkedList new_list = {NULL,
                           NULL,
                           0};
    
    return (new_list);
}

//Creates a new node initially pointing to no 'next' node
Node create_node(int data) {
    Node fresh_node = {NULL, data}; 
    return fresh_node;
}

//MISBEHAVING METHOD: EXPECTING RETURN VALUE OF 12 IN PROGRAM
int data_at(LinkedList *list, int node_pos) {
    Node* trav = list -> head;

    //If user enters node_pos less than 1, return error value
    if (node_pos < 1) {
        return -1;
    }
    else {
        for (int i = 1; i != node_pos; i++) {
            trav = trav -> next;
        }

        return trav -> data;
    }
}

//Currently not working as a result of data_at malfunctioning
void print_list_contents(LinkedList *list) {
    for (int i = 1; i <= list -> size; i++) {
        printf("Data = %d\n", data_at(list, i));
    }
}