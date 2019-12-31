#include "kd_tree.h"

kd_tree::kd_tree() {
    root = nullptr;
    d = 1;
}

kd_tree::kd_tree(int dim) {
    root = nullptr;
    d = dim;

}

void kd_tree::print_node(Node* a) {
    if (a == nullptr)
        cout << "NULL" << endl;
    else {
        for (int i = 0; i < d; i++)
            printf("%d ", a->coordinates[i]);
    }
    printf("\n");
    return;
}

void kd_tree::insert_node(int* array) {
    printf("Insert ");
    cout << array[0] << ", " << array[1] << endl;
    /* Using insert_or_find_node with "insert" arg set to TRUE */
    Node* Q = insert_or_find_node(root, array, d, true, d-1);
    root = Q;

    if (Q == nullptr)
        printf("Should not get a nullptr for insert");
    else
        cout << array[0] << ", " << array[1] << endl;

    return;
}

void kd_tree::delete_node(int* array) {
    cout << "Delete: " << array[0] << ", " << array[1] << endl;
    /* Find node Parent_P */
    Node* Parent_P = insert_or_find_node(root, array, d, false, d-1);

    Node* P;
    bool equal_coordinates = true;
    bool is_hi_child = false;
    // cout << "Parent_P: " << Parent_P << endl;
    /* If P is not found */
    if (Parent_P == nullptr) {
        cout << "Node not found!" << endl;
        return;
    }
    
    /* Is P the hi_child of Parent_P? */
    if (Parent_P->hi_child != nullptr) {
        equal_coordinates = true;
        /* Checking for equality coordinate-by-coordinate */
        for (int i = 0; i < d; i++) {
            if (Parent_P->hi_child->coordinates[i] != array[i])
                equal_coordinates = false;
        }
        if (equal_coordinates) {
            P = Parent_P->hi_child;
            is_hi_child = true;
        }
    }
    /* Is P the lo_child of Parent_P? */
    if (Parent_P->lo_child != nullptr) {
        
        equal_coordinates = true;
        /* Checking for equality coordinate-by-coordinate */
        for (int i = 0; i < d; i++) {
            if (Parent_P->lo_child->coordinates[i] != array[i])
                equal_coordinates = false;
        }
        if (equal_coordinates) {
            P = Parent_P->lo_child;
            is_hi_child = false;
        }
    }
    /* Is P the root? */
    if (Parent_P == root) {
        
        equal_coordinates = true;
        /* Checking for equality coordinate-by-coordinate */
        for (int i = 0; i < d; i++) {
            if (Parent_P->coordinates[i] != array[i])
                equal_coordinates = false;
        }
        /* root removal case */
        if (equal_coordinates) {

            Parent_P = remove_node(root);
            root = Parent_P;
            // if (Parent_P != nullptr) {
            //     if (Parent_P->hi_child != nullptr) {
            //         while (Parent_P->coordinates[0] >= Parent_P->hi_child->coordinates[0]) {

            //             Node* tied_node = new Node;
            //             tied_node = Parent_P->hi_child;
            //             // cout << "tied_node: " << tied_node->coordinates[0] << ", " << tied_node->coordinates[1] << endl;
            //             Parent_P->hi_child = remove_node(Parent_P->hi_child);
            //             // cout << "Parent_P->hi_child: " << Parent_P->hi_child->coordinates[0] << ", " << Parent_P->hi_child->coordinates[1] << endl;
            //             Parent_P = insert_or_find_node(root, tied_node->coordinates, d, true, 1);
            //             root = Parent_P;
            //             if (Parent_P->hi_child == nullptr)
            //                 break;
            //         }
            //     }
            // }
            cout << endl << "delete complete" << endl;
            return;
        }
    }

    /* Removing either hi or lo child */
    if (is_hi_child) {
        Parent_P->hi_child = remove_node(P);
        // if (Parent_P->hi_child != nullptr) {
        //     while (Parent_P->coordinates[0] == Parent_P->hi_child->coordinates[0]) {
        //         Node* tied_node = new Node;
        //         tied_node = Parent_P->hi_child;
        //         Parent_P->hi_child = remove_node(Parent_P->hi_child);
        //         Parent_P = insert_or_find_node(root, tied_node->coordinates, d, true, 1);
        //         root = Parent_P;
        //         if (Parent_P->hi_child == nullptr)
        //             break;
        //     }
        // }
    }
    else {
        Parent_P->lo_child = remove_node(P);
    }
    // cout << "Parent_P: " << Parent_P->coordinates[0] << ", " << Parent_P->coordinates[1] << endl;
    cout << endl << "delete complete" << endl;
    return;
}

Node* kd_tree::exact_match_query(int* array) {
    cout << "Find Node " << array[0] << ", " << array[1] << endl; 
    /* Using insert_or_find_node with "insert" arg set to FALSE */
    Node* Parent_Q = insert_or_find_node(root, array, d, false, d-1);
    // cout << "Parent_Q: " << Parent_Q << endl;
    /* If queryed node does not exist */
    if (Parent_Q == nullptr) {
        cout << "Node not found!" << endl;
        return nullptr;
    }

    Node* Q;
    bool equal_coordinates = true;
    bool is_hi_child;

    /* If queried node was the hi_child of Parent_Q */
    if (Parent_Q->hi_child != nullptr) {
        for (int i = 0; i < d; i++) {
            if (Parent_Q->hi_child->coordinates[i] != array[i])
                equal_coordinates = false;
        }

        if (equal_coordinates) {
            Q = Parent_Q->hi_child;
            is_hi_child = true;
        }
    }

    /* If queried node was the lo_child of Parent_Q */
    if (Parent_Q->lo_child != nullptr) {
        equal_coordinates = true;
        for (int i = 0; i < d; i++) {
            if (Parent_Q->lo_child->coordinates[i] != array[i])
                equal_coordinates = false;
        }

        if (equal_coordinates) {
            Q = Parent_Q->lo_child;
            is_hi_child = false;
        }
    }

    return Q;
}
