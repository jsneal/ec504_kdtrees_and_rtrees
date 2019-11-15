#include<stdio.h>

struct Node {
    int key;
    Node *lo_child;
    Node *hi_child;
};

class kd_tree{
public:
    // constructs empty kd tree
    kd_tree();
    
    // constructs a one node empty kd tree
    kd_tree(int x);

    void print_kd();

private:
    

    
public:
    Node *root;
};