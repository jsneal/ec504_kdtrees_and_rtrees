
#include "kd_tree.h"


kd_tree::kd_tree() {
    root = nullptr;
}

kd_tree::kd_tree(int* array, int dim) {

    root = new Node;
    d = dim;
    root->coordinates = new int[d];
    for (int i = 0; i < d; i++) {
        root->coordinates[i] = array[i];
    }
}

void kd_tree::print_kd() {
    for (int i = 0; i < d; i++)
        printf("%d ", root->coordinates[i]);
    printf("\n");
    return;
}

void kd_tree::insert_node(int* array) {
    printf("Insert\n");
    return;
}

void kd_tree::delete_node(int* array) {
    printf("Delete\n");
    return;
}

void kd_tree::find_node(int* array) {
    printf("Found Node\n");
    return;
}

