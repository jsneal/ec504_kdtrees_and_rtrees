#include "kd_tree.h"
#include <stdio.h>
#include <iostream>

using namespace std;

// Read-In Code based off of HW5 code
int main(int argc, char *argv[]) {
    // number of points in input_file
    int n;
    // dimension of points in kd_tree
    int d;
    char *infile;
    FILE *fp1;

    infile =  argv[1];

    cout <<" infile  " << infile << endl;
    fp1 = fopen(infile,"r");
    if (fp1 == NULL) {
      printf("Did not find input file \n");
      exit(1);
    }
    fscanf(fp1,"%d %d",&n,&d);

    kd_tree tree_1 = kd_tree(d);

    int point[d];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < d; j++) {
            fscanf(fp1,"%d",&point[j]);
            // cout << point[j] << " ";
            if (j < d-1)
                fscanf(fp1, " ");
        }
        // cout << endl;
        tree_1.insert_node(point);
    }



    // int array[4] = {1, 2, 3, 4};

    // kd_tree a = kd_tree(array, 4);

    // a.print_kd();

    // a.insert_node(array);

    // a.delete_node(array);

    // a.find_node(array);
    return 0;
}