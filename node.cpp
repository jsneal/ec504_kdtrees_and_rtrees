#include"node.h"


int next_disc(int disc, int d) {
    return (disc+1) % d;
}

Node* insert_or_find_node(Node* Q, int* point, int d, bool insert, int disc) {
    bool equal_coordinates = true;
    int child_disc = next_disc(disc, d);
    Node* child;
    if (Q == nullptr) {
        // insert_node acts as find_node, but node not found
        if (insert == false) {
            // printf("NULL/Find\n");
            return nullptr;
        }
        // insert_node acts as insert_node,
        // node not found in tree
        else {
            // printf("NULL/Insert\n");
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
    // printf("Not NULL/Insert\n");

    for (int i = 0; i < d; i++) {
        if (point[i] != Q->coordinates[i])
            equal_coordinates = false;
    }

    if (equal_coordinates == true) {
        // printf("equal_coordinates\n");
        return Q;
    }

    // cout << "----------" << endl;
    // for (int j = 0; j < d; j++)
    //     cout << Q->coordinates[j] << " ";
    // cout << endl;
    // for (int k = 0; k < d; k++)
    //     cout << point[k] << " ";
    // cout << endl;
    // cout << "DISC: " << Q->DISC << endl;

    if (point[Q->DISC] > Q->coordinates[Q->DISC]) {
        // cout << "hi_child" << endl;
        child = insert_or_find_node(Q->hi_child, point, d, insert, child_disc);
        Q->hi_child = child;
    }
    else {
        // cout << "lo_child" << endl;
        child = insert_or_find_node(Q->lo_child, point, d, insert, child_disc);
        Q->lo_child = child;
    }
    // cout << "----------" << endl;
    // for (int i = 0; i < d; i++)
    //     printf("%d ", Q->coordinates[i]);
    // if (Q->lo_child == nullptr)
    //     printf("lo_child null ");
    // if (Q->hi_child == nullptr)
    //     printf("hi_child null ");
    // printf("\n");

    return Q;
}