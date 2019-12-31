#include "kd_tree.h"
#include <time.h>
#include <string.h>
#include <fstream>



// Read-In Code based off of EC504 HW5 code
int main(int argc, char *argv[]) {
    ofstream outfile;
    // number of points in input_file
    int n;
    // dimension of points in kd_tree
    int d;
    char *infile;
    char *actionfile;
    FILE *fp1;
    FILE *fp2;
    FILE *of1;

    infile =  argv[1];

    cout << " infile  " << infile << endl;
    fp1 = fopen(infile,"r");
    if (fp1 == NULL) {
      printf("Did not find input file \n");
      exit(1);
    }
    fscanf(fp1,"%d %d",&n,&d);

    // char filename[30];
    // sprintf(filename, "%d_%d_.txt_out", n, d); 
    // of1 = fopen(filename, "a");

    kd_tree tree_1 = kd_tree(d);
    cout << "initialize kd_tree" << endl;
    cout << "n: " << n << " " << "d: " << d << endl;
    int point[d];
    int points[n][d];
    int already_deleted[n]; // for some reason this array causes me to seg fault

    for (int i = 0; i < n; i++){
        for (int j = 0; j < d; j++) {
            fscanf(fp1,"%d",&point[j]);
            // cout << point[j] << endl;
            points[i][j] = point[j];
            // cout << point[j] << " ";
            if (j < d-1)
                fscanf(fp1, " ");
        }
        // cout << endl;
        tree_1.insert_node(point);

    }

    /* Deletion file interface */
    actionfile =  argv[2];

    if (argv[2] == NULL) {
      for (int i = 0; i < n; i++) {
        int rand_i = (int) ((((float) rand())/RAND_MAX)*n);
        if (already_deleted[rand_i] == 1) {
            cout << "already deleted " << points[rand_i][0] << ", " << points[rand_i][1] << endl;
        }
        else {
        tree_1.delete_node(points[rand_i]);
            already_deleted[rand_i] = 1;
        }
      }
    } else {
        Node* P;
        cout << " infile  " << actionfile << endl;
        fp2 = fopen(actionfile,"r");
        int num_acts, dim_acts;
        int x[dim_acts];
        char action[7];
        fscanf(fp2,"%d %d",&num_acts,&dim_acts);
        for (int i = 0; i < num_acts; i++){
            cout << endl;
            fscanf(fp2, "%s", action);
            for (int j = 0; j < dim_acts; j++) {
                fscanf(fp2,"%d",&x[j]);
                if (j < dim_acts-1)
                    fscanf(fp2, " ");
            }
            if (!strcmp(action, "Delete"))
                tree_1.delete_node(x);
            if (!strcmp(action, "Insert"))
                tree_1.insert_node(x);
            if (!strcmp(action, "Find"))
                P = tree_1.exact_match_query(x);
            if (!strcmp(action, "Print")) {
                P = tree_1.exact_match_query(x);
                tree_1.print_node(P);
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     // cout << "Exception here?" << endl;
    //     int rand_i = (int) ((((float) rand())/RAND_MAX)*n);
    //     if (already_deleted[rand_i] == 1) {
    //         cout << "already deleted " << points[rand_i][0] << ", " << points[rand_i][1] << endl;
    //     }
    //     else {
    //     tree_1.delete_node(points[rand_i]);
    //         already_deleted[rand_i] = 1;
    //     }

    // }


    // fprintf(of1, "%f %f\n", difference_in_seconds_build, difference_in_seconds_finds);
    // fclose(of1);



// Delete from root works
    // for (int i = 0; i < 100; i++) {
    //         tree_1.delete_node(tree_1.root->coordinates);
    // }

    return 0;
}