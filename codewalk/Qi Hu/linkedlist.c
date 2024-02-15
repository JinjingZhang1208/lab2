// Modify this file
// compile with: gcc -Wall linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// do not add any additional libraries

// use the following struct verbatim for your linked list

typedef struct node {
    int years;
    int numWins;
    struct node* next;
} node_t;

// TODO: Complete the functions below.
// You may create as many helper functions as you like.
// Don't edit main for this assignment.

// a helper function to create a new node with given data
node_t* create_node(int year, int win) {
    // allocate memory of size of node_t on heap	
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    newNode->years = year;
    newNode->numWins = win;
    // newnode's next pointer points to NULL, indicating it is the last node
    newNode->next = NULL;
    return newNode;
}

// create a list by using nodes
node_t* create_list(int* scores, int* years, int length) {

    //TODO complete me!
    node_t* head = NULL;
    // use index i to point to next nodes and get corresponding years and scores
    for (int i = 0; i < length; i++) {
        node_t* newNode = create_node(years[i], scores[i]);
        // point the new node to the current head
        newNode->next = head; 
        // update head to the new node
        head = newNode; 
    }
    return head;
}

// use the iterator pattern!
void print_list(node_t* list) {

    //TODO complete me!
    // create an iterator node
    node_t* iterator = list;
    // while the iterator is not NULL, continue pointing to new things
    while (iterator != NULL) {
        printf("%d, %d wins \n", iterator->years, iterator->numWins);
	// move iterator to 'next' node in the linked list
        iterator = iterator->next;
    }
}

// use the iterator pattern here too!
void free_list(node_t* list) {

    //TODO complete me!
    node_t* current = list;
    while (current != NULL) {
        node_t* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {

    // we're using statically allocated arrays here
    // in the bonus activity, you can work on importing data from a file
    //      using a bash script
    // do not change any code in main in your submitted lab

    int wins[] = {83, 93, 89, 76, 73, 67, 32, 91, 92};
    int years[] = {2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022};
    node_t* blueJays_stats = create_list(wins, years, 9);
    print_list(blueJays_stats);
    free_list(blueJays_stats);

    return 0;
}
