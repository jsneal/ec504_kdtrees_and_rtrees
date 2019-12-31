#include <stdio.h>
#include "node.h"


class kd_tree{
public:
    /* Constructs empty kd tree with d = 1 */
    kd_tree();

    /* Constructs an empty node kd_tree with d = dim */
    kd_tree(int dim);

    /* Prints the coordinates of a node given a pointer to that node */
    void print_node(Node* a);

    /* Inserts a node into the kd-tree starting at the root */
    void insert_node(int* array);

    /* Deletes a node in the kd-tree */
    void delete_node(int* array);

        /* Deletes a node in the kd-tree with O(n) complexity */
    void new_delete_node(int* array);

    /* Performs an exact match query for a node in the kd-tree */
    Node* exact_match_query(int* array);

private:


    
public:
    /* Dimension of the coordinates of each node */
    int d;
    /* Pointer to the root node of the kd-tree */
    Node* root;

};