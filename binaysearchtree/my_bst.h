// =================== Support Code =================
// Binary Search Tree ( BST ).
//
//
//
// - Implement each of the functions to create a working BST.
// - Do not change any of the function declarations
//   - (i.e. bst_t* create_bst() should not have additional arguments)
// - You should not have any 'printf' statements in your BST functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYBST_H
#define MYBST_H

// Create a node data structure to store data within
// our BST. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* rightChild;
  	struct node* leftChild;
}node_t;

// Create a BST data structure
// Our BST holds a pointer to the root node in our BST called root.
typedef struct BST{
	int count;		// count keeps track of how many items are in the BST.
	node_t* root;		// root points to the root node in our BST.
}bst_t;

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values.
bst_t* create_bst(){
	// Modify the body of this function as needed.
	bst_t* myBST= (bst_t*)malloc(sizeof(bst_t));
	myBST->count = 0;
	myBST->root = NULL;
	return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element enqueued)
int bst_empty(bst_t* t){
	if (t->root == NULL) {
		return 1;
	}
	return 0;
}

// Add helper function.
// Add a newNode to a tree.
node_t* add_helper(node_t* node, node_t* newNode) {
	if (node == NULL) {
		node = newNode;
	}
	if (newNode->data < node->data) {
		node->leftChild = add_helper(node->leftChild, newNode);
	}
	else if (newNode->data > node->data) {
		node->rightChild = add_helper(node->rightChild, newNode);
	}
	return node;
}

// Adds a new node containng item in the correct place of the BST.
// If the data is less then the current node we go right, otherwise we go left.
// Same as described in the README.md file. 
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
// It should run in O(log(n)) time.
int bst_add(bst_t* t, int item){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
		if (newNode == NULL) {
			return -1;
		}
	newNode->data = item;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	if (t->root == NULL) {
		t->root = newNode;
	}
	else {
		add_helper(t->root, newNode);
	
	}
	t->count += 1;
	return 0;
}

// Print helper function.
// Print all the datas in nodes in a ascending order.
void print_helper_a(node_t* node) {
	if (node != NULL) {
		print_helper_a(node->leftChild);
		printf("%d\n", node->data);
		print_helper_a(node->rightChild);
	}
}

// Print helper function
// Print all the datas in nodes in a descending order.
void print_helper_d(node_t* node) {
	if (node != NULL) {
		print_helper_d(node->rightChild);
		printf("%d\n", node->data);
		print_helper_d(node->leftChild);
		
	}
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree it should print nothing. 
// It should run in O(n) time.
void bst_print(bst_t*t, int order){
	if (bst_empty(t)) {
		return;
	}
	else {
		if (order == 0) {
			print_helper_a(t->root);
		}
		else {
			print_helper_d(t->root);
		}
	}
}

// Sum helper function.
// Return the sum of all the data in the nodes.
int sum_helper(node_t* node) {
	int sum = node->data;
	if (node->leftChild != NULL) {
		sum += sum_helper(node->leftChild);
	}
	if (node->rightChild != NULL) {
		sum += sum_helper(node->rightChild);
	}
	return sum;
}

// Returns the sum of all the nodes in the tree. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int sum(bst_t *t){
	if (t == NULL) {
		exit(1);s
	}
	if (bst_empty(t)) {
		return 0;
	}
  return sum_helper(t->root);
}

// Find helper function.
// Return 1 if the given value in the node, otherwise return 0.
int find_helper(node_t* node, int value) {
	int left = 0;
	int right = 0;
	if (node == NULL) {
		return 0;
	}
	if (node->data == value) {
		return 1;
	}
	else {
		if (value < node->data) {
			left = find_helper(node->leftChild, value);
		}
		else if (value > node->data) {
			right = find_helper(node->rightChild, value);
		}
	}
	return left || right;
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int find(bst_t * t, int value){
	if (bst_empty(t)) {
		exit(1);
	}
  return find_helper(t->root, value);
}

// BST Size
// Queries the current size of the BST
// A BST that has not been previously created will crash the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
	if (t == NULL) {
		exit(1);
	}
	if (bst_empty(t)) {
		return 0;
	}
	return t->count;
}

// Free helper function.
// Free every node.
void free_helper(node_t* node) {
	if (node != NULL) {
		free_helper(node->leftChild);
		free_helper(node->rightChild);
		free(node);
		}	
	}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_bst(bst_t* t){
	free_helper(t->root);
	free(t);
}

#endif
