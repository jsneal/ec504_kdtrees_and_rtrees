#include<stdio.h>

struct Node {

    // "Feature Vector"
    int *coordinates;

    // Left Child
    Node *lo_child;

    // Right Child
    Node *hi_child;
};

class kd_tree{
public:
    // constructs empty kd tree
    kd_tree();
    
    // constructs a one node empty kd tree
    kd_tree(int* array, int dim);

    void print_kd();

    void insert_node(int* array);

    void delete_node(int* array);

    void find_node(int* array);

private:


    
public:
    // dimension of the coordinates of each node
    int d;
    Node *root;

};