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

void kd_tree::print_kd() {
    for (int i = 0; i < d; i++)
        printf("%d ", root->coordinates[i]);
    printf("\n");
    return;
}

void kd_tree::insert_node(int* array) {
    printf("Insert\n");
    // true set for insert function
    Node* Q = insert_or_find_node(root, array, d, true, d);

    if (Q == nullptr)
        printf("Should not get a nullptr for insert");

    root = Q;

    return;
}

void kd_tree::delete_node(int* array) {
    printf("Delete\n");
    return;
}

Node* kd_tree::find_node(int* array) {
    printf("Found Node\n");

    Node* Q = insert_or_find_node(root, array, d, true, d);

    return Q;
}

