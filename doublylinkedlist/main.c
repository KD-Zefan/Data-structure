// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.



// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    dll_t * dll = create_dll();
    dll_push_front(dll, 5);
    dll_push_front(dll, 3);
    dll_push_front(dll, 2);
    dll_push_front(dll, 6);
    int c = dll_size(dll);
    printf("size: %d\n", c);
    dll_push_back(dll, 5);
    dll_push_back(dll, 3);
    dll_push_back(dll, 2);
    dll_push_back(dll, 9);
    int g = dll_size(dll);
    printf("size: %d\n", g);
    dll_push_front(dll, 5);
    dll_push_front(dll, 3);
    dll_push_front(dll, 2);
    dll_push_front(dll, 6);

    int j = dll_pop_front(dll);
    printf("remover front: %d\n", j);
    int q = dll_pop_front(dll);
    printf("remover front: %d\n", q);
    int w = dll_pop_front(dll);
    printf("remover front: %d\n", w);
    int y = dll_pop_front(dll);
    printf("remover front: %d\n", y);
    int r = dll_pop_front(dll);
    printf("remover front: %d\n", r);
    int t = dll_pop_front(dll);
    printf("remover front: %d\n", t);

    int z = dll_pop_back(dll);
    printf("remover back: %d\n", z);
    int x = dll_pop_back(dll);
    printf("remover back: %d\n", x);
    int e = dll_size(dll);
    printf("size: %d\n", e);
    
    int bbb = dll_get(dll, 0);
    printf("pos 0 is: %d\n", bbb);
    int bbbbbb = dll_get(dll, 1);
    printf("pos 1 is: %d\n", bbbbbb);
    int bb = dll_get(dll, 2);
    printf("pos 2 is: %d\n", bb);
    int b = dll_get(dll, 3);
    printf("pos 3 is: %d\n", b);
    dll_remove(dll, 3);
    int jj = dll_get(dll, 2);
    printf("pos 2 is: %d\n", jj);
    
    dll_remove(dll, 0);
    int jjj = dll_get(dll, 0);
    printf("pos 0 is: %d\n", jjj);
    int jjjj = dll_get(dll, 1);
    printf("pos 1 is: %d\n", jjjj);

    int ee = dll_size(dll);

    printf("size: %d\n", ee);

    dll_insert(dll, 0, 10);
    dll_insert(dll, 1, 10);
    dll_insert(dll, 1, 2222);

    int gg = dll_get(dll, 0);
    printf("pos 0 is: %d\n",gg);
    int ggg = dll_get(dll, 1);
    printf("pos 1 is: %d\n",ggg);
    int gggg = dll_get(dll, 2);
    printf("pos 2 is: %d\n",gggg);
    int ggggg = dll_get(dll, 3);
    printf("pos 3 is: %d\n",ggggg);

    int eeee = dll_size(dll);
    printf("size: %d\n", eeee);

    





    


    return 0;
}
