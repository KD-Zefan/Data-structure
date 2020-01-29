// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_bst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    bst_t * testBST = create_bst();
    bst_add(testBST, 20);
    bst_add(testBST, 10);
    bst_add(testBST, 15);
    bst_add(testBST, 30);
    bst_add(testBST, 25);
    bst_add(testBST, 5);
    bst_add(testBST, 35);
    bst_print(testBST, 0);
    printf("-----------\n");
    bst_print(testBST, 10);
    // int a = sum(testBST);
    // printf("%d\n", a);
    // int b = find(testBST, 55);
    // printf("I cannt find 0 = %d\n", b);
    // int c = find(testBST, 35);
    // printf("I find 1 = %d\n", c);
    // int d = bst_size(testBST);
    // printf("my size: %d\n", d);
    
    // int e = bst_size(testBST);
    // printf("my size: %d\n", e);

    // bst_t * testBST1 = create_bst(); 
    // int aa = bst_empty(testBST1);
    // printf("empty: %d\n", aa);

    // bst_add(testBST1, 10);
    // int bb = bst_size(testBST1);
    // printf("size: %d\n", bb);
    // int aaa = bst_empty(testBST1);
    // printf("empty: %d\n", aaa);
    // int ccc = sum(testBST1);
    // printf("find %d\n",ccc);
    //bst_print(testBST1, 5);

    free_bst(testBST);
    return 0;
}
