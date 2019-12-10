#include "kd_tree.h"
#include <time.h>
#include <fstream>


// Read-In Code based off of HW5 code
int main(int argc, char *argv[]) {
    // number of points in input_file
    int n;
    // dimension of points in kd_tree
    int d;
    char *infile;
    FILE *fp1;

    infile =  argv[1];

    cout << " infile  " << infile << endl;
    fp1 = fopen(infile,"r");
    if (fp1 == NULL) {
      printf("Did not find input file \n");
      exit(1);
    }
    fscanf(fp1,"%d %d",&n,&d);

    kd_tree tree_1 = kd_tree(d);

    int point[d];
    int points[n][d];
    int already_deleted[n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < d; j++) {
            fscanf(fp1,"%d",&point[j]);
            points[i][j] = point[j];
            // cout << point[j] << " ";
            if (j < d-1)
                fscanf(fp1, " ");
        }
        // cout << endl;
        tree_1.insert_node(point);

    }

    // int point_1[2] = {47, 171};
    // int point_2[2] = {945, 1};
    // int point_3[2] = {981, 334};

    // tree_1.delete_node(point_1);
    // tree_1.delete_node(point_2);
    // tree_1.delete_node(point_3);

    // time_t t;

    // srand(time(&t));
    // for (int i = 0; i < 100; i++) {
    //     int rand_i = (int) ((((float) rand())/RAND_MAX)*n);
    //     if (already_deleted[rand_i] == 1) {
    //         cout << "already deleted" << endl;
    //     }
    //     else {
    //         tree_1.delete_node(points[rand_i]);
    //         already_deleted[rand_i] = 1;
    //     }

    // }

// Delete from root works
        // for (int i = 0; i < 100; i++) {
        //     tree_1.delete_node(tree_1.root->coordinates);
        // }


    // tree_1.delete_node(points[1]);
    // tree_1.delete_node(points[4]);
    // tree_1.delete_node(points[12]);
    // tree_1.delete_node(points[11]);
    // tree_1.delete_node(points[8]);
    // tree_1.delete_node(points[5]);
    // tree_1.delete_node(points[6]);
    tree_1.delete_node(points[2]);
    Node* ab = tree_1.find_node(points[6]);
    cout << ab->hi_child->coordinates[0] << ", " << ab->hi_child->coordinates[1] << endl;
    Node* bc = tree_1.find_node(points[n-1]);
    cout << bc->coordinates[0] << ", " << bc->coordinates[1] << endl;
    cout << points[n-1][0] << ", "  << points[n-1][1] << endl;

    // tree_1.delete_node(points[10]);
    // tree_1.delete_node(points[9]);
    // tree_1.delete_node(points[0]);
    // tree_1.delete_node(points[7]);
    // tree_1.delete_node(points[n-1]);




    // cout << "After Deletion" << endl;
    // tree_1.print_node(tree_1.root);
    // cout << "lo_child: "; tree_1.print_node(tree_1.root->lo_child); cout << endl;
    // cout << "hi_child of lo_child: "; tree_1.print_node(tree_1.root->lo_child->hi_child); cout << endl;
    // cout << "lo_child of lo_child: "; tree_1.print_node(tree_1.root->lo_child->lo_child); cout << endl;
    // cout << "hi_child: "; tree_1.print_node(tree_1.root->hi_child); cout << endl;
    // cout << "hi_child of hi_child: "; tree_1.print_node(tree_1.root->hi_child->hi_child); cout << endl;
    // cout << "lo_child of hi_child: "; tree_1.print_node(tree_1.root->hi_child->lo_child); cout << endl;

    // int array[4] = {1, 2, 3, 4};

    // kd_tree a = kd_tree(array, 4);

    // a.print_kd();

    // a.insert_node(array);

    // a.delete_node(array);

    // a.find_node(array);
    return 0;
}