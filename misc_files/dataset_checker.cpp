#include <iostream>
#include <fstream>
#include <string.h>
#include "kd_tree.h"
#include <assert.h>

using namespace std;

int main(int argc, char* argv[]) {
    char* infile;
    // number of points in input_file
    int n;
    // dimension of points in kd_tree
    int d;
    FILE *fp1;

    infile = argv[1];
    cout << "infile  " << endl;
    fp1 = fopen(infile,"r");
    if (fp1 == NULL) {
      printf("Did not find input file \n");
      exit(1);
    }

    fscanf(fp1,"%d %d",&n,&d);

    int point[d];
    int points[n][d];

    kd_tree tree_1 = kd_tree(d);

    for (int i = 0; i < n; i++){
        // cout << "i: " << i << endl;
        for (int j = 0; j < d; j++) {
            fscanf(fp1,"%d",&point[j]);
            assert(point[j] >= 0);
            points[i][j] = point[j];
            // cout << point[j] << " ";
            if (j < d-1)
                fscanf(fp1, " ");
        }
        // cout << endl;
        tree_1.insert_node(point);

    }


    return 0;
}