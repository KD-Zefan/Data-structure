// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
  	struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
	int count;		// count keeps track of how many items are in the DLL.
	node_t* head;		// head points to the first node in our DLL.
        node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
dll_t* create_dll(){
	// Modify the body of this function as needed.
	dll_t* myDLL= (dll_t*)malloc(sizeof(dll_t));
	myDLL->count = 0;
	myDLL->head = NULL;
	myDLL->tail= NULL;
	return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t* l){
	if (l->head == NULL && l->tail == NULL) {
		return 1;
	}
	return 0;
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if (newNode == NULL) {
		return -1; // Note: you should have two return statements in this function.
	}
	newNode->data = item;
	newNode->previous = NULL;
	if (dll_empty(l)) {
		l->head = newNode;
		l->tail = newNode;
		newNode->next = NULL;
	}
	else {
		l->head->previous = newNode;
		newNode->next = l->head;
		l->head = newNode;
	}
	l->count += 1;
	return 0;		
}

// push a new item to the end of the DLL ( after the last node in the list).
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if (newNode == NULL) {
		return -1; // Note: you should have two return statements in this function.
	}
	newNode->data = item;
	newNode->next = NULL;
	if (dll_empty(l)) {
		l->head = newNode;
		l->tail = newNode;
		newNode->previous = NULL;
	}
	else {
		l->tail->next = newNode;
		newNode->previous = l->tail;
		l->tail = newNode;
	}
	l->count += 1;
	return 0;
	}
	

// Returns the first item in the DLL. 
// Removes an item from the DLL.
// Removing from an empty DLL should crash the program, call exit(1).
int dll_pop_front(dll_t* t){
	if (dll_empty(t)) {
		exit(1);
	}
	node_t * temp = t->head;
	int item = temp->data;
	if (t->count == 1) {
		t->head = NULL;
		t->tail = NULL;
	}
	else {
		t->head = temp->next;
		t->head->previous = NULL;
	}
	t->count -= 1;
	free(temp);
	return item; // Note: This line is a 'filler' so the code compiles.
}

// Returns the last item in the DLL. 
// Removes the last item from the DLL.
// Removing from an empty DLL should crash the program, call exit(1).
int dll_pop_back(dll_t* t){
	if (dll_empty(t)) {
		exit(1);
	}
	node_t * temp = t->tail;
	int item = temp->data;
	if (t->count == 1) {
		t->head = NULL;
		t->tail = NULL;
	}
	else {
		t->tail = temp->previous;
		t->tail->next = NULL;
	}
	t->count -= 1;
	free(temp);
	return item; // Note: This line is a 'filler' so the code compiles.
}

// Inserts a new node before the node at the specified position.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed or trying to insert at a negative position or at 
//  a position past the size of the DLL ).
int dll_insert(dll_t* l, int pos, int item){
	node_t * newNode = (node_t*)malloc(sizeof(node_t));
	if (newNode == NULL || pos < 0 || pos >= l->count) {
		return -1; // Note: you should have two return statements in this function.
	}
	newNode->data = item;
	if (pos == 0) {
		l->head->previous = newNode;
		newNode->next = l->head;
		newNode->previous = NULL;
		l->head = newNode;
	}
	else {
		node_t * iterator = l->head;
		while(pos >= 1) {
			iterator = iterator->next;
			pos--;
			}
		newNode->next = iterator;
		newNode->previous = iterator->previous;
		iterator->previous->next = newNode;
		iterator->previous = newNode;
	}
	l->count += 1;
	return 0;
	
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the position is negative or trying to retrive an item at or past the size,
// or the list is empty.
int dll_get(dll_t* l, int pos){
	if (pos < 0 || pos >= l->count || dll_empty(l)) {
		return -1; // Note: you should have two return statements in this function.
	}
	int item;
	if (pos == 0) {
		item = l->head->data;
	}
	else {
		if (pos == l->count - 1) {
		item = l->tail->data;
	}
		else {
			node_t * iterator = l->head;
			while (pos >= 1) {
			iterator = iterator->next;
			pos -= 1;
			}
			item = iterator->data;			
		}	
	}
	return item;
	}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the position is negative or trying to remove an item at or past the size,
// or if the list is empty
int dll_remove(dll_t* l, int pos){
	if (pos < 0 || pos >= l->count || dll_empty(l)) {
		return -1; // Note: you should have two return statements in this function.
	}
	if (pos == 0) {
		node_t* temp = l->head;
		if (l->count == 1) {
			l->head = NULL;
			l->tail = NULL;
		}
		else {
			l->head = temp->next;
			l->head->previous = NULL;
		}
		free(temp);
	}
	else {
		if (pos == l->count - 1) {
			node_t* temp = l->tail;
			l->tail = l->tail->previous;
			l->tail->next = NULL;
			free(temp);
			}
		else { 
			node_t * iterator = l->head;
				while(pos >= 1) {
				iterator = iterator->next;
				pos -= 1;}
			iterator->previous->next = iterator->next;
			iterator->next->previous = iterator->previous;
			free(iterator);
		}	
	}	
	l->count -= 1;
	return 0;
}

// DLL Size
// Queries the current size of a DLL
// A DLL that has not been previously created will crash the program.
// (i.e. A NULL DLL cannot return the size)
unsigned int dll_size(dll_t* t){
	if (t == NULL) {
		exit(1);
	}
	if (t->head == NULL && t->tail == NULL) {
		return 0;
	}
	return t->count;
}

// Free DLL
// Removes a DLL and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
	node_t* iterator = t->head;
	while (iterator) {
		node_t* next = iterator->next;
		free(iterator); 
		iterator = next;
	}
	free(t);

}



#endif
