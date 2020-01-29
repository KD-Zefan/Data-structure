// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// Create your node_t type here
typedef struct node {
	struct node* next;
	int years;
	int wins;
}node_t;

// Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

node_t* create_list(){
   	 node_t* year2018 = (node_t*)malloc(sizeof(node_t));
   	 node_t* year2017 = (node_t*)malloc(sizeof(node_t));
   	 node_t* year2016 = (node_t*)malloc(sizeof(node_t));
   	 node_t* year2015 = (node_t*)malloc(sizeof(node_t));
   	 node_t* year2014 = (node_t*)malloc(sizeof(node_t));
	 // setting up data in each node
	 year2018->years = 2018;
   	 year2018->wins = 108;
   	 year2017->years = 2017;
   	 year2017->wins = 93;
   	 year2016->years = 2016;
   	 year2016->wins = 93;
   	 year2015->years = 2015;
  	 year2015->wins = 78;
   	 year2014->years = 2014;
   	 year2014->wins = 71;
	 // link the list!
	 year2018->next = year2017;
	 year2017->next = year2016;
	 year2016->next = year2015;
	 year2015->next = year2014;
	 year2014->next = NULL;
	
	return year2018;
}

void print_list(node_t* head) {
	node_t* iterator = head;
	while (iterator != NULL) {
	printf("%d, %d wins\n", iterator->years, iterator->wins);
	iterator = iterator->next;
	}
}

void free_list(node_t* head) {
	node_t* iterator = head;
	while (iterator != NULL) {
	free(iterator);
	iterator = iterator->next;
	}
}

int main(){
	
 	node_t* redsox = NULL;
	redsox = create_list();
	print_list(redsox);
	free_list(redsox);
    return 0;
}
