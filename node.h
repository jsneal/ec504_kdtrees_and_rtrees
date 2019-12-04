#include<stdio.h>

struct Node {

    // "Feature Vector"
    int *coordinates;

    // Left Child
    Node *lo_child;

    // Right Child
    Node *hi_child;

    // DISC
    int DISC;
};

int next_disc(int disc, int d);

Node* insert_or_find_node(Node* Q, int* point, int d, bool insert, int disc);