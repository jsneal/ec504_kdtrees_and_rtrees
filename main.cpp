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

    time_t t;

    srand(time(&t));
    for (int i = 0; i < 100; i++) {
        int rand_i = (int) ((((float) rand())/RAND_MAX)*n);
        tree_1.delete_node(points[rand_i]);

    }



    // int a[2] = {5, 8};
    // tree_1.delete_node(a);
    // cout << "After Deletion" << endl;
    // tree_1.print_node(tree_1.root);
    // cout << "lo_child: "; tree_1.print_node(tree_1.root->lo_child); cout << endl;
    // cout << "hi_child of lo_child: "; tree_1.print_node(tree_1.root->lo_child->hi_child); cout << endl;
    // cout << "hi_child: "; tree_1.print_node(tree_1.root->hi_child); cout << endl;
    // cout << "hi_child of hi_child: "; tree_1.print_node(tree_1.root->hi_child->hi_child); cout << endl;

    // int array[4] = {1, 2, 3, 4};

    // kd_tree a = kd_tree(array, 4);

    // a.print_kd();

    // a.insert_node(array);

    // a.delete_node(array);

    // a.find_node(array);
    return 0;
}