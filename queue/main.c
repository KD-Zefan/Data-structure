// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){

	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test1,1);
	printf("Removing: %d\n",queue_dequeue(test1));	

	free_queue(test1);
}

void unitTest2(){

	queue_t* test2 = create_queue(5);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test2,1);
	printf("size: %d\n", queue_size(test2));
	printf("Attempting to add %d\n",2);
	queue_enqueue(test2,2);
	printf("size: %d\n", queue_size(test2));
	printf("Attempting to add %d\n",3);
	queue_enqueue(test2,3);
	printf("size: %d\n", queue_size(test2));
	printf("Attempting to add %d\n",4);
	queue_enqueue(test2,4);
	printf("size: %d\n", queue_size(test2));
	printf("Attempting to add %d\n",5);
	queue_enqueue(test2,5);
	printf("size: %d\n", queue_size(test2));
	printf("Attempting to add %d\n",6);
	queue_enqueue(test2,6);
	printf("size: %d\n", queue_size(test2));
	printf("Attempting to add %d\n",7);
	queue_enqueue(test2,7);
	printf("size: %d\n", queue_size(test2));
	printf("Removing: %d\n",queue_dequeue(test2));
	printf("Removing: %d\n",queue_dequeue(test2));
	printf("Removing: %d\n",queue_dequeue(test2));
	printf("Removing: %d\n",queue_dequeue(test2));
	printf("Removing: %d\n",queue_dequeue(test2));
	printf("Attempting to add %d\n",5);
	queue_enqueue(test2,5);
	printf("Attempting to add %d\n",4);
	queue_enqueue(test2,4);
	printf("Attempting to add %d\n",3);
	queue_enqueue(test2,3);
	printf("Attempting to add %d\n",2);
	queue_enqueue(test2,2);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test2,1);
	printf("Removing: %d\n",queue_dequeue(test2));
	printf("Removing: %d\n",queue_dequeue(test2));
	printf("Removing: %d\n",queue_dequeue(test2));
	printf("Removing: %d\n",queue_dequeue(test2));
	printf("Removing: %d\n",queue_dequeue(test2));

	free_queue(test2);
}


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();
	unitTest2();

	return 0;
}
