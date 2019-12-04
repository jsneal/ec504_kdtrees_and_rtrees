#include"node.h"


int next_disc(int disc, int d) {
    return (disc+1) % d;
}

Node* insert_or_find_node(Node* Q, int* point, int d, bool insert, int disc) {
    bool equal_coordinates = false;
    int child_disc = next_disc(disc, d);
    Node* child;
    if (Q == nullptr) {
        // insert_node acts as find_node, but node not found
        if (insert == false) {
            printf("NULL/Find\n");
            return nullptr;
        }
        // insert_node acts as insert_node,
        // node not found in tree
        else {
            printf("NULL/Insert\n");
            Q = new Node;
            Q->hi_child = nullptr;
            Q->lo_child = nullptr;
            Q->DISC = child_disc;
            Q->coordinates = new int[d];
            for (int i = 0; i < d; i++) {
                Q->coordinates[i] = point[i];
            }
            return Q;
        }
    }

    for (int i = 0; i < d; i++) {
        if (point[i] != Q->coordinates[i])
            equal_coordinates = true;
    }

    if (equal_coordinates == true)
        return Q;

    // left_subtree if disc keys are equal
    if (point[disc] == Q->coordinates[disc]) {
        child = insert_or_find_node(Q->lo_child, point, d, insert, child_disc);
    } else {
        if (point[disc] > Q->coordinates[disc])
            child = insert_or_find_node(Q->hi_child, point, d, insert, child_disc);
        else
            child = insert_or_find_node(Q->lo_child, point, d, insert, child_disc);
    }

    return child;
}