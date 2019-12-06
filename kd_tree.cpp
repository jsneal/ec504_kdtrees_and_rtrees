#include "kd_tree.h"

kd_tree::kd_tree() {
    root = nullptr;
    d = 1;
}

// kd_tree::kd_tree(int* array, int dim) {

//     root = new Node;
//     root->hi_child = nullptr;
//     root->lo_child = nullptr;
//     root->DISC = 0;
//     d = dim;
//     root->coordinates = new int[d];
//     for (int i = 0; i < d; i++) {
//         root->coordinates[i] = array[i];
//     }
// }

kd_tree::kd_tree(int dim) {
    root = nullptr;
    d = dim;

}

void kd_tree::print_node(Node* a) {
    if (a == nullptr)
        printf("NULL");
    else {
        for (int i = 0; i < d; i++)
            printf("%d ", a->coordinates[i]);
    }
    printf("\n");
    return;
}

void kd_tree::insert_node(int* array) {
    printf("Insert\n");
    // true set for insert function
    Node* Q = insert_or_find_node(root, array, d, true, d-1);
    root = Q;

    if (Q == nullptr)
        printf("Should not get a nullptr for insert");

    return;
}

void kd_tree::delete_node(int* array) {
    printf("Delete\n");
    cout << array[0] << ", " << array[1] << endl;
    Node* Parent_P = insert_or_find_node(root, array, d, false, d);
    Node* P;
    bool equal_coordinates = true;
    bool is_hi_child = false;
    cout << "which child" << endl;
    if (Parent_P->hi_child != nullptr) {
        for (int i = 0; i < d; i++) {
            if (Parent_P->hi_child->coordinates[i] != array[i])
                equal_coordinates = false;
        }
        if (equal_coordinates) {
            P = Parent_P->hi_child;
            is_hi_child = true;
        }
    }

    if (Parent_P->lo_child != nullptr) {
        equal_coordinates = true;
        for (int i = 0; i < d; i++) {
            if (Parent_P->lo_child->coordinates[i] != array[i])
                equal_coordinates = false;
        }
        if (equal_coordinates) {
            P = Parent_P->lo_child;
            is_hi_child = false;
        }
    }

    if (Parent_P == root) {
        equal_coordinates = true;
        for (int i = 0; i < d; i++) {
            if (Parent_P->coordinates[i] != array[i])
                equal_coordinates = false;
        }
        if (equal_coordinates) {
            P = remove_node(root);
            root = P;
            return;
        }
    }

    // cout << P->coordinates[0] << ", " << P->coordinates[1] << endl;
    if (is_hi_child)
        Parent_P->hi_child = remove_node(P);
    else
        Parent_P->lo_child = remove_node(P);
    
    return;
}

Node* kd_tree::find_node(int* array) {
    printf("Find Node\n");

    Node* Parent_Q = insert_or_find_node(root, array, d, false, d-1);
    Node* Q;
    bool equal_coordinates = true;
    bool is_hi_child;

    for (int i = 0; i < d; i++) {
        if (Parent_Q->hi_child->coordinates[i] != array[i])
            equal_coordinates = false;
    }
    if (equal_coordinates) {
        Q = Parent_Q->hi_child;
        is_hi_child = true;
    }

    equal_coordinates = true;
    for (int i = 0; i < d; i++) {
        if (Parent_Q->lo_child->coordinates[i] != array[i])
            equal_coordinates = false;
    }
    if (equal_coordinates) {
        Q = Parent_Q->lo_child;
        is_hi_child = false;
    }


    return Q;
}

