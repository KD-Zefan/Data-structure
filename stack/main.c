// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){

	stack_t* test1 = create_stack(MAX_DEPTH);
	printf("Attempting to push %d\n",1);
	stack_enqueue(test1,1);
	printf("size: %d", stack_size(test1));
	stack_enqueue(test1,2);	
	stack_enqueue(test1,3);	
	stack_enqueue(test1,4);	
	stack_enqueue(test1,5);	
	stack_enqueue(test1,6);	
	stack_enqueue(test1,7);	
	stack_enqueue(test1,8);	
	stack_enqueue(test1,9);	
	stack_enqueue(test1,10);	
	stack_enqueue(test1,11);	
	stack_enqueue(test1,12);	
	stack_enqueue(test1,13);	
	stack_enqueue(test1,14);	
	stack_enqueue(test1,15);	
	stack_enqueue(test1,16);	
	stack_enqueue(test1,17);	
	stack_enqueue(test1,18);	
	stack_enqueue(test1,19);	
	stack_enqueue(test1,20);	
	stack_enqueue(test1,21);	
	stack_enqueue(test1,22);	
	stack_enqueue(test1,23);	
	stack_enqueue(test1,24);	
	stack_enqueue(test1,25);	
	stack_enqueue(test1,26);	
	stack_enqueue(test1,27);	
	stack_enqueue(test1,28);	
	stack_enqueue(test1,29);	
	stack_enqueue(test1,30);	
	stack_enqueue(test1,31);	
	stack_enqueue(test1,32);	
	stack_enqueue(test1,33);		
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	stack_enqueue(test1,1);	
	stack_enqueue(test1,2);	
	stack_enqueue(test1,3);	
	stack_enqueue(test1,4);	
	stack_enqueue(test1,5);	
	stack_enqueue(test1,6);	
	stack_enqueue(test1,7);	
	stack_enqueue(test1,8);	
	stack_enqueue(test1,9);	
	stack_enqueue(test1,10);
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));
	printf("Removing: %d\n",stack_dequeue(test1));



	free_stack(test1);
}
void unitTest2(){
	stack_t* test2 = create_stack(0);
	printf("Attempting to push %d\n",1);
	stack_enqueue(test2,1);	
	stack_enqueue(test2,2);	
	stack_enqueue(test2,3);
	printf("Removing: %d\n",stack_dequeue(test2));
	printf("Removing: %d\n",stack_dequeue(test2));
	printf("Removing: %d\n",stack_dequeue(test2));
	printf("Removing: %d\n",stack_dequeue(test2));
	printf("Removing: %d\n",stack_dequeue(test2));
	printf("Removing: %d\n",stack_dequeue(test2));

}


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();

	return 0;
}
