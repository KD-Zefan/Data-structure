// =================== Support Code =================
// Graph.
//
//
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H
#include "myqueue.h"
#include "mystack.h"


// Create a neighbor data structure to server as the neighbor's list.
// In our case, we will stores 'integers' as our neighbors that 
// corresponding to the data that the actual nodes store.
typedef struct neighbor{
	int data;
	struct neighbor * next;
}neighbor_t;

// Create a node data structure to store data within
// our graph. In our case, we will stores 'integers'
// as our data in the nodes
typedef struct node{
	int data;
	int visited;
	struct node *next;
	struct neighbor * neighbor;
}node_t;

// Create a graph data structure
// Our graph keeps track of the number of nodes, the number of edges and an array
// of all the nodes in the graph, and the maximum number of nodes we store in our graph.
typedef struct graph{
	int numNodes;		
        int numEdges;
	node_t* nodes;	 //an array of nodes storing all of our nodes.
}graph_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
graph_t* create_graph(){
	// Modify the body of this function as needed.
	graph_t* myGraph= (graph_t*)malloc(sizeof(graph_t));
	myGraph->numNodes = 0;
	myGraph->numEdges = 0;
	myGraph->nodes = NULL;
	return myGraph;
}

// Graph Empty
// Check if the graph is empty
// Returns 0 if true (The graph is completely empty, i.e. numNodes == 0 )
// Returns -1 if false (the graph has at least one node)
int graph_empty(graph_t* g){
	if (g->numNodes == 0) {
		return 0;
	}
	return -1;
}


// Returns the number of neighbors for value.
int numNeighbors(graph_t * g, int value){
	if (graph_empty(g) == 0) {
		return 0;
	}
	int counter = 0;
	node_t* iteratorNode = g->nodes; 
	while (iteratorNode != NULL) {
		if (iteratorNode->data == value) {
			neighbor_t* iteratorNeighbor = iteratorNode->neighbor;
			while (iteratorNeighbor != NULL) {
				counter++;
				iteratorNeighbor = iteratorNeighbor->next;
			}
		}
		iteratorNode = iteratorNode->next;
	}
	return counter;
}

//Returns an int array of all the neighbors of the node with data=value.
int * getNeighbors( graph_t * g, int value ){
	if (graph_empty(g) == 0) {
		return NULL;
	}
	int size = numNeighbors(g, value);
	int* arr = (int*)malloc(size * sizeof(int));
	int i = 0;
	node_t* iteratorNode = g->nodes;
	while (iteratorNode != NULL) {
		if (iteratorNode->data == value) {
			neighbor_t* iteratorNeighbor = iteratorNode->neighbor;
			while (iteratorNeighbor != NULL) {
				arr[i] = iteratorNeighbor->data;
				i++;
				iteratorNeighbor = iteratorNeighbor->next;
			}
		}
		iteratorNode = iteratorNode->next;
	}
	return arr;
}
//Returns 0 if the node with value is in the graph, otherwise returns -1;
int contains_node(graph_t * g, int value){
	node_t* iterator = g->nodes;
	while (iterator != NULL) {
		if (iterator->data == value) {
			return 0;
		}
		iterator = iterator->next;
	}
   	return -1;
}

//Returns 0 if an edge from source to destination exists, -1 otherwise.
int contains_edge(graph_t * g, int source, int destination){
	node_t* iteratorNode = g->nodes;
	while (iteratorNode != NULL) {
		if (iteratorNode->data == source) {
			neighbor_t* iteratorNeighbor = iteratorNode->neighbor;
			while (iteratorNeighbor != NULL) {
				if (iteratorNeighbor->data == destination) {
					return 0;
				}
				iteratorNeighbor = iteratorNeighbor->next;
			}
		}
		iteratorNode = iteratorNode->next;
	}
	return -1;
}


// Creates a node
// Input: the data that store in a node.
// Returns a pointer to a newly created node.
node_t* create_node(int item) {
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = item;
	newNode->visited = 0;
	newNode->next = NULL;
	newNode->neighbor = NULL;
	return newNode;
}


// Adds a new node withe the correspoding item in the graph.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
// Duplicates nodes should not be added. For a duplicate node returns 0.
int graph_add_node(graph_t* g, int item){
	node_t* newNode = create_node(item); // call the creat_node function to creat a new node that store the item.
	if (newNode == NULL) { // if the meory allocation for a new node failed, return -1.
		return -1; 
	}
	if (contains_node(g, item) == 0) { // if there already exits a duplicate node, return 0;
		return 0;
	}
	else {
		if (g->nodes == NULL) { // checking if the graph's node is null
			g->nodes = newNode; // if it is so, graph's head node point to the newNode.
			g->numNodes += 1; // and number of nodes plus one.
		}
		else{ // in this situiation, add the newNode at the end of the list of nodes.
			node_t * iterator = g->nodes; 
			while (iterator != NULL) {
				if (iterator->next == NULL) {
					iterator->next = newNode;
					g->numNodes += 1;
					break;
				}
				iterator = iterator->next;
			}
		}
		return 0;
	}
}

//Removes an edge from source to destination. 
//If source or desination is not found in the graph returns -1.
//If no such edge exists also returns -1.
//Otherwise it returns 0
int graph_remove_edge(graph_t * g, int source, int destination){
	if (contains_edge(g, source, destination) == -1) { // if no such edge exists also returns -1.
		return -1;
	}
	node_t* iteratorNode = g->nodes; 
	while (iteratorNode != NULL) {
		if (iteratorNode->data == source) { // checking if found the source node.
			neighbor_t* iteratorNeighbor = iteratorNode->neighbor; // if it does found, creat a neighbor pointer point to the head of the source node's neighbor's head
			neighbor_t* temp = iteratorNode->neighbor; // creat another neighbor head pointer, this will point to the neighbor previous if the destination neighbor 
													   // is not stroing in the first neighbor.
			while (iteratorNeighbor != NULL) {
				if (iteratorNeighbor->data == destination) { // checking if the destination found.
					if (temp->data == iteratorNeighbor->data) { // if it does found, checking is the head neighbor.
						iteratorNode->neighbor = iteratorNeighbor->next; // point the head current iteratorNeighbor's next.
						free(iteratorNeighbor); // free the node.
						g->numEdges -= 1;
					} else { // if jump to this line, it means that destination is not in the head neighbor node, the the temp is pointing to the previous neighbor.
						temp->next = iteratorNeighbor->next; // connect the previous neighbor to the next neighbor of the iteratorNeighbor.
						free(iteratorNeighbor); // remove the destination neighbor.
						g->numEdges -= 1;
					}
					return 0;
				}
				temp = iteratorNeighbor; // point the temp neighbor node the current neighbor node, it will become the previous neighbir when it in the next loop.
				iteratorNeighbor = iteratorNeighbor->next;  // point the iteratorNode to its next, go to next loop.
			}
		}
		iteratorNode = iteratorNode->next;
	}
	return 0;
}


// Removes the node from the graph and the corresponding edges connected 
// to the node.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (the node to be removed doesn't exist in the graph).
int graph_remove_node(graph_t* g, int item){
	if (graph_empty(g) == 0 || contains_node(g, item) == -1) {
		return -1;
	}
	node_t* iteratorNode = g->nodes;
	if (iteratorNode->data == item) { // checking if the head node is the node that we want to remove.
		while (iteratorNode->neighbor != NULL) { // if it is, checking it has neighbor or not.
			neighbor_t* nextNeighbor = iteratorNode->neighbor->next; // if it has neighbor, creat a new neighbor pointer point to its next 
																	// (no matter what it is, whether neighbor node or null).
			free(iteratorNode->neighbor); // free the current neighbor node.
			g->numEdges -= 1; // numedge minus one
			iteratorNode->neighbor = nextNeighbor; // set the iteratorNode to the next neighbor node.
		}
		g->nodes = iteratorNode->next; // if the item node has not neighbors, it will skip the above while loop, and jump to here, setting the head node to the 
									  // iteratorNode's next.
		free(iteratorNode); // free the current node.
		g->numNodes -= 1; // number of nodes minus one.
		}
	else { // if run this line, it means the item node is not the head node, so it always impossible run the if statement in the first run.
		node_t* temp = g->nodes; // I creat one more node to point to the head node, it will be used as the previous node of iteatorNode.
		while (iteratorNode != NULL) { // loop nodes.
			if (iteratorNode->data == item) { // checking if we found the item node.
				neighbor_t* iteratorNeighbor = iteratorNode->neighbor; // if we found it, creat a neighbor pointer point to the iteratorNode's head neighbor.
				while (iteratorNeighbor != NULL) { // in this while loop, remove all the neighbors in the item node.
					neighbor_t* nextNeighbor = iteratorNeighbor->next;
					free(iteratorNeighbor);
					g->numEdges -= 1;
					iteratorNeighbor = nextNeighbor;
				}
				temp->next = iteratorNode->next; // connect the previous node to the next node.
				free(iteratorNode); // free the item node
				g->numNodes -= 1;
				break;
			}
			temp = iteratorNode; // point the temp node the current node, it will become the previous node when it in the next loop.
			iteratorNode = iteratorNode->next; // point the iteratorNode to its next, go to next loop.
		}
	}
	node_t* iterator = g->nodes; // come to this next line, it means we alread removed the item node and its neighbor.
	while (iterator != NULL) { // we still need to check if the item node we just removed is a neighbor of other nodes.
		if (contains_edge(g, iterator->data, item) == 0) { // we go to every node, and check it, uses the cotains_edeg function.
			graph_remove_edge(g, iterator->data, item); // if it is. uses the graph_remove_egde function to remove the edge.
		}
		iterator = iterator->next;
	}
return 0;	 
}

// Creates a neighbor
// Input: the data stores in a neighbor.
// Returns a pointer to a newly created neighbor.
neighbor_t* create_neighbor(int data) {
	neighbor_t* newNeighbor = (neighbor_t*)malloc(sizeof(neighbor_t));
	newNeighbor->data = data;
	newNeighbor->next = NULL;
	return newNeighbor;
}

//Adds an edge from source to destination. 
//If source or desination is not found in the graph returns -1.
//Otherwise it returns 0 ( even for trying to add a duplicate edge )
int graph_add_edge(graph_t * g, int source, int destination){
	if (graph_empty(g) == 0 || contains_node(g, source) == -1 || contains_node(g, destination) == -1) {
		return -1;
	}
	if (contains_edge(g, source, destination) == 0) {
		return 0;
	}
	else {
		node_t* iteratorNode = g->nodes;
		while (iteratorNode != NULL){
			if (source == iteratorNode->data) {
				neighbor_t* newNeighbor = create_neighbor(destination);
				if (iteratorNode->neighbor == NULL) {
					iteratorNode->neighbor = newNeighbor;
					g->numEdges += 1;
				}
				else {
					neighbor_t* neighborNode = iteratorNode->neighbor;
					while (neighborNode != NULL) {
						if (neighborNode->next == NULL) {
							neighborNode->next = newNeighbor;
							g->numEdges += 1;
							break;
							}
						neighborNode = neighborNode->next;
					}
				}
				break;
				}
			iteratorNode = iteratorNode->next;
			}
		return 0;
		}
	}

// Get node
// Inputs:
//	g - a pointer to a graph.
//	value - the data node we are looking for.
// Returns a pointer to a node that store the data we are looking for if we found it, otherwise return NULL.
node_t* get_node(graph_t*g, int value) {
	if (graph_empty(g) == 0) {
		return NULL;
	}
	node_t* iterator = g->nodes;
	while (iterator != NULL) {
	if (iterator->data == value){
		return iterator;
	}
	iterator = iterator->next;
	}
	return NULL;
}

// Modify visited node status.
// Input: a pointer to a graph.
// No value is returned, but all the nodes visited status should be changing to 0.
void modify_visited_status(graph_t* g) {
	node_t* iteator = g->nodes;
	while (iteator != NULL) {
		iteator->visited = 0;
		iteator = iteator->next;
	}
}

// Prints the the graph using BFS
// For NULL or empty graph it should print nothing. 
void graph_print(graph_t * g){
	modify_visited_status(g);
	int size = g->numNodes;
	queue_t * queue = create_queue(size);
	int root = g->nodes->data;
	queue_enqueue(queue, root);
	while (queue_size(queue) > 0) {
		int element = queue_dequeue(queue);
		printf("%d\n", element);
		node_t* node = get_node(g, element);
		node->visited = 1;
		int* neighbors = getNeighbors(g, element);
		int i, n;
		n = numNeighbors(g, element);
		for (i = 0; i < n; i++) {
			node_t* neighborNode = get_node(g, neighbors[i]);
			if (neighborNode->visited == 0) {
				queue_enqueue(queue, neighbors[i]);
				neighborNode->visited = 1;
			}
		}	
		free(neighbors);
	}
	free_queue(queue);
}

// Graph Size
// Returns the number of nodes in the graph
unsigned int graph_num_nodes(graph_t* g){
	return g->numNodes;
}

// Graph Size
// Returns the number of edges in the graph
unsigned int graph_num_edges(graph_t* g){
	return g->numEdges;
}

// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_graph(graph_t* g){
	node_t* iteratorNode = g->nodes;
	while (iteratorNode != NULL) {
		neighbor_t* iteratorNeighbor = iteratorNode->neighbor;
		while (iteratorNeighbor != NULL) {
			neighbor_t* nextNeighbor = iteratorNeighbor->next;
			free(iteratorNeighbor);
			iteratorNeighbor = nextNeighbor;
		}
		node_t* nextNode = iteratorNode->next;
		free(iteratorNode);
		iteratorNode = nextNode;
	}
	free(g);
}
// Is reachable
// Inputs:
//	g - a pointer to a graph
//	source - the data in the source node
//	dest - the data in the destination node.
// Returns 0 if I can reach the destination from source, -1 otherwise.
int is_reachable(graph_t * g, int source, int dest){
	if (graph_empty(g) == 0 || contains_node(g, source) == -1 || contains_node(g, dest) == -1) {
		return -1;
	}
	modify_visited_status(g);
	int size = g->numNodes;
	queue_t* queue = create_queue(size);
	queue_enqueue(queue, source);
	while (queue_size(queue) > 0) {
		int element = queue_dequeue(queue);
		node_t* node = get_node(g, element);
		node->visited = 1;
		int* neighbors = getNeighbors(g, element);
		int i, n;
		n = numNeighbors(g, element);
		for (i = 0; i < n; i++) {
			if (neighbors[i] == dest) {
				free(neighbors);
				free_queue(queue);	
				return 0;
			}
			else {
				node_t* neighborNode = get_node(g, neighbors[i]);
				if (neighborNode->visited == 0) {						
					queue_enqueue(queue, neighbors[i]);
					neighborNode->visited = 1;
				}
			} 
		}
		free(neighbors);
	}
	free_queue(queue);
	return -1;
}

// Has cycle
// Input: a pointer to a graph.
// Returns 0 if there is a cycle in the graph, -1 otherwise.
int has_cycle(graph_t * g) {
	if (graph_empty(g) == 0) {
		return -1;
	}
	modify_visited_status(g);
	queue_t* queue = create_queue(g->numNodes);
	int roof = g->nodes->data;
	queue_enqueue(queue, roof);
	while (queue_size(queue) > 0) {
		int element = queue_dequeue(queue);
		node_t* node = get_node(g, element);
		node->visited = 1;
		int* neighbors = getNeighbors(g, element);
		int i, n;
		n = numNeighbors(g, element);
		for (i = 0; i < n; i++) {
			node_t* neighborNode = get_node(g, neighbors[i]);
			if (neighborNode->visited == 1) {
				free(neighbors);
				free_queue(queue);
				return 0;
			}
			else if (neighborNode->visited == 0) {						
				queue_enqueue(queue, neighbors[i]);
				neighborNode->visited = 1;
				}
		}
		free(neighbors);
	}
	free_queue(queue);
	return -1;
}
// Print path
// Input: 
//	g - a pointer to a graph
//	source - the data store in the source node
//	dest - the data store in the destination node
// No value is returned, but prints any path from source to destination if there exists one 
void print_path(graph_t * g, int source, int dest) {
	if (is_reachable(g, source, dest) == 0) {
		modify_visited_status(g);
		stack_t* stack = create_stack(g->numNodes);
		stack_enqueue(stack, source);
		while (stack_size(stack) > 0) {
			int element = stack_dequeue(stack);
			printf("%d ", element);
			node_t* node = get_node(g, element);
			node->visited = 1;
			int* neighbors = getNeighbors(g, element);
			int i, n;
			n = numNeighbors(g, element);
			int checker = 0;
			for (i = 0; i < n; i++) {
				if (neighbors[i] == dest) {
					printf("%d\n", neighbors[i]);
					checker = 1;
					break;
				} else {
					node_t* neighborNode = get_node(g, neighbors[i]);
					if (neighborNode->visited == 0) {
						stack_enqueue(stack, neighbors[i]);
						neighborNode->visited = 1;
						}
					}
				}
			free(neighbors);
			if (checker == 1) {
				break;
			}
			}
		free_stack(stack);
		}	
	}


#endif
