
#include "kd_tree.h"


kd_tree::kd_tree() {
    root = nullptr;
}

kd_tree::kd_tree(int x) {

    root = new Node;
    root->key = x;
}

void kd_tree::print_kd() {
    printf("%d\n", root->key);
    return;
}

