#include "kd_tree.h"
#include <stdio.h>


int main() {
    int array[4] = {1, 2, 3, 4};

    kd_tree a = kd_tree(array, 4);

    a.print_kd();

    a.insert_node(array);

    a.delete_node(array);

    a.find_node(array);
    return 0;
}