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
    //         tree_1.delete_node(tree_1.root->coordinates);
    // }

    // int a[2]; = {837, 400};
    //tree_1.delete_node(a);
    // a[0] = 139;
    // a[1] = 719;
    // tree_1.delete_node(a);

    // Node* ab = tree_1.find_node(a);
    // cout << ab->DISC << endl;
    // tree_1.print_node(ab->lo_child);
    // a[0] = 307;
    // a[1] = 93;
    // tree_1.delete_node(a);
    // a[0] = 813;
    // a[1] = 309;
    // tree_1.delete_node(a);
    // a[0] = 96;
    // a[1] = 455;
    // tree_1.delete_node(a);

    return 0;
}