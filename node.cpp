#include "node.h"


int next_disc(int disc, int d) {
    /* 
       Inputs:
       -------
       disc - current discriminator
       d - dimension of each point in the kd-tree
       
       Output:
       --------
       Returns the next discriminator of the next node
       (at the next depth).
    */

    return (disc+1) % d;
}


Node* insert_or_find_node(Node* Q, int* point, int d, bool insert, int disc) {
    /* 
       Inputs:
       -------
       Q - current node
       point - coordinates of node to be found/inserted.
       d - dimensions of every point in the kd-tree
       insert - boolean flag that determines whether this function call is
                either for the insert or find function.
        disc - discriminator of the next level (for insertion)

       
       Output:
       --------
       1. If insert == true, then a pointer is returned to the root node
       2. if insert != true, then a pointer is returned to the found node

    */

    bool equal_coordinates = true;
    int child_disc = next_disc(disc, d);
    Node* child;
    if (Q == nullptr) {
        /* function acts as find_node, but node is not in tree */
        if (insert == false) {

            return nullptr;
        }
        /* function acts as insert_node and node is not in tree (yet) */
        else {

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
    cout << Q->coordinates[0] << ", " << Q->coordinates[1] ;
    /* Checking if the current node's coordinates match the queried/inserted point */
    for (int i = 0; i < d; i++) {
        if (point[i] != Q->coordinates[i]) {
            equal_coordinates = false;
        }
    }

    /* Current node's coordinates match the queried/inserted point */
    if (equal_coordinates == true) {
        return Q;
    }
    cout << " -> ";
    /* 
        To determine whether to continue search for queried/inserted node
        down right or left subtree.
    */

    if (point[Q->DISC] > Q->coordinates[Q->DISC]) {
        child = insert_or_find_node(Q->hi_child, point, d, insert, child_disc);
        if (insert) {
            Q->hi_child = child;
        }
        else {
            if (child == nullptr)
                return nullptr;
            equal_coordinates = true;
            for (int i = 0; i < d; i++) {
                if (point[i] != Q->hi_child->coordinates[i])
                    equal_coordinates = false;
            }
            if (equal_coordinates)
                return Q;
            else
                return child;
        }
        
    }
    else {

        child = insert_or_find_node(Q->lo_child, point, d, insert, child_disc);
        if (insert) {
            Q->lo_child = child;
        }
        else {
            if (child == nullptr)
                return nullptr;
            equal_coordinates = true;
            for (int i = 0; i < d; i++) {
                if (point[i] != Q->lo_child->coordinates[i])
                    equal_coordinates = false;
            }
            if (equal_coordinates)
                return Q;
            else
                return child;
        }
        
    }

    return Q;
}



void find_min_key_in_subtree(Node* Q, Node* Parent_Q, Node* best_min_node, Node* best_min_node_parent, bool* is_hi, int j_disc) {
    // cout << "__find min__";
    /* Determining if the minimum node is the hi or lo child of parent */
    if (*is_hi) {
        best_min_node = best_min_node_parent->hi_child;
    }
    else {
        best_min_node = best_min_node_parent->lo_child;
    }

    /* Q being a j_disc node guarantees the best min node cannot be found in Q's hi subtree */
    if (Q->DISC == j_disc) {

        if (Q->coordinates[j_disc] < best_min_node->coordinates[j_disc]) {
            best_min_node = Q;
            best_min_node_parent = Parent_Q;
            if (best_min_node_parent->hi_child == best_min_node)
                *is_hi = true;
            else
                *is_hi = false;
        }

        /* If Q's lo subtree exists than best min node could be found there */
        if (Q->lo_child != nullptr) {
            find_min_key_in_subtree(Q->lo_child, Q, best_min_node, best_min_node_parent, is_hi, j_disc);
        }

        if (best_min_node_parent->hi_child == best_min_node)
            *is_hi = true;
        else
            *is_hi = false;

    }
    /* Q not being a j_disc node implies the best min node cannot be found in either of Q's subtrees */
    else {

        /* Q is new best max node */
        if (Q->coordinates[j_disc] < best_min_node->coordinates[j_disc]) {
            best_min_node = Q;
            best_min_node_parent = Parent_Q;

            
            if (best_min_node_parent->hi_child == best_min_node)
                *is_hi = true;
            else
                *is_hi = false;


        }

        /* Q is not a j_disc node, the best min node could be found in Q's lo subtree */
        if (Q->lo_child != nullptr) {

            find_min_key_in_subtree(Q->lo_child, Q, best_min_node, best_min_node_parent, is_hi, j_disc);

            if (best_min_node_parent->hi_child == best_min_node)
                *is_hi = true;
            else
                *is_hi = false;
        }

        /* Q is not a j_disc node, the best min node could also be found in Q's hi subtree */
        if (Q->hi_child != nullptr) {
            if (Q->hi_child->coordinates[j_disc] < best_min_node->coordinates[j_disc]) {
                find_min_key_in_subtree(Q->hi_child, Q, best_min_node, best_min_node_parent, is_hi, j_disc);

                if (best_min_node_parent->hi_child == best_min_node)
                    *is_hi = true;
                else
                    *is_hi = false;
            }
        }


    }
    // cout << "__Q: " << Q->coordinates[0] << ", " <<  Q->coordinates[1] << "__";
    // cout << "__best_min_node: " << best_min_node->coordinates[0] << ", " << best_min_node->coordinates[1] << "__" << endl;
    return;
}

Node* find_max_key_in_subtree(Node* Q, Node* Parent_Q, Node* best_max_node, Node* best_max_node_parent, bool* is_hi, int j_disc) {
  
    /* Determining if the maximum node is the hi or lo child of parent */
    if (*is_hi)
        best_max_node = best_max_node_parent->hi_child;
    else
        best_max_node = best_max_node_parent->lo_child;

    /* Q being a j_disc node guarantees the best max node cannot be found in Q's lo subtree */
    if (Q->DISC == j_disc) {
        /* Q is new best max node */
        if (Q->coordinates[j_disc] >= best_max_node->coordinates[j_disc]) {
            best_max_node = Q;
            best_max_node_parent = Parent_Q;

            if (best_max_node_parent->hi_child == best_max_node)
                *is_hi = true;
            else
                *is_hi = false;
        }

        /* If Q's hi subtree exists than best max node could be found there */
        if (Q->hi_child != nullptr) {
            best_max_node = find_max_key_in_subtree(Q->hi_child, Q, best_max_node, best_max_node_parent, is_hi, j_disc);

        }

        if (best_max_node_parent->hi_child == best_max_node)
            *is_hi = true;
        else
            *is_hi = false;
      
    }
    /* Q not being a j_disc node implies the best max node cannot be found in either of Q's subtrees */
    else {

        /* Q is new best max node */
        if (Q->coordinates[j_disc] >= best_max_node->coordinates[j_disc]) {
            best_max_node = Q;
            best_max_node_parent = Parent_Q;

            if (best_max_node_parent->hi_child == best_max_node)
                *is_hi = true;
            else
                *is_hi = false;

        }

        /* Q is not a j_disc node, the best max node could be found in Q's hi subtree */
        if (Q->hi_child != nullptr) {

            best_max_node = find_max_key_in_subtree(Q->hi_child, Q, best_max_node, best_max_node_parent, is_hi, j_disc);
            if (best_max_node_parent->hi_child == best_max_node)
                *is_hi = true;
            else
                *is_hi = false;
        }

        /* Since Q is not a j_disc node, the best max node could also be found in Q's lo subtree */
        if (Q->lo_child != nullptr) {
            if (Q->lo_child->coordinates[j_disc] > best_max_node->coordinates[j_disc]) {
                best_max_node = find_max_key_in_subtree(Q->lo_child, Q, best_max_node, best_max_node_parent, is_hi, j_disc);
                
                if (best_max_node_parent->hi_child == best_max_node)
                    *is_hi = true;
                else
                    *is_hi = false;
            }
        }


    }

    return best_max_node;
}

Node* remove_node(Node* P) {
    /* 
       Inputs:
       -------
       P - pointer to node to be removed

       
       Output:
       --------
       Returns pointer to parent node

    */

    // cout << "__REMOVE NODE__";
    Node* Parent_Q = new Node;
    Node* Q = new Node;
    bool is_hi_child;

    /* If for some reason remove_node was passed a nullptr */
    /* This should never happen */
    if (P == nullptr) {
        return nullptr;
    }

    /* Storing the discriminator of the parent node to be removed */
    /* The replacement node cannot violate the parent's discriminator */
    int j_disc = P->DISC;

    /* D.1: P is a leaf */
    if ((P->hi_child == nullptr) &&  (P->lo_child == nullptr)) {
        /* Set P to NULL and no need for a replacement node */
        P = nullptr;
        return P;
    }

    /* Since P is not a leaf, finding replacement node: */
    Parent_Q = P;
    /* D.2: Finding root of P's replacement node */
    if (P->lo_child == nullptr) {
        /* Replacement must be in hi subtree since lo_child is NULL */
        is_hi_child = true;
        Q = P->hi_child;
        // cout << "_best_min_key_" << endl;
        /* D.3: Get root of replacement node from hi subtree */
        find_min_key_in_subtree(P->hi_child, Parent_Q, Q, Parent_Q, &is_hi_child, j_disc);

    } else {
        /* Replacement must be in lo subtree since hi_child is NULL */
        is_hi_child = false;
        Q = P->lo_child;
        // cout << "_best_max_key_" << endl;
        /* D.4: Get root of P's successors from P->lo_child subtree */
        find_max_key_in_subtree(P->lo_child, Parent_Q, Q, Parent_Q, &is_hi_child, j_disc);
    } 

    /* Need to put replacement node at its current place in the tree */
    /* (Find a replacement for it) and replace P with Q */
    /* D.5: Delete Q (recursive) */
    if (is_hi_child) {
        Parent_Q->hi_child = remove_node(Q);
    }
    else {
        Parent_Q->lo_child = remove_node(Q);
    }

    /* D.6: Make Q new root */
    Q->DISC = j_disc;
    Q->hi_child = P->hi_child;
    Q->lo_child = P->lo_child;

    if (Q != nullptr) {
        // cout << "__P: " << P->coordinates[0] << ", " << P->coordinates[1] << "__";
        // cout << "__Replacement: " << Q->coordinates[0] << ", " << Q->coordinates[1] << "__";
    }

    return Q;
}