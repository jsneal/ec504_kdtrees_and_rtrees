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
    for (int i = 0; i < d; i++)
        printf("%d ", a->coordinates[i]);
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
    // Node* Q = insert_or_find_node(root, array, d, false, d);
    // if 

    return;
}

Node* kd_tree::find_node(int* array) {
    printf("Find Node\n");

    Node* Q = insert_or_find_node(root, array, d, false, d-1);

    return Q;
}

