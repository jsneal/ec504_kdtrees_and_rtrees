#include<iostream>
#include<fstream>
#include<string.h>
#include<assert.h>
#include "selection_algorithms.h"

using namespace std;


int main(int argc, char *argv[]) {
    /* number of points in input_file */
    int N;
    /* dimension of points in kd_tree */
    int d;
    char *infile;
    ofstream outfile;
    FILE *fp1;
    FILE *fp2;
    FILE *of1;

    if (argv[1] == NULL) {
        cout << "No input file. Will create random array of a random size from 1 to 100." << endl;

        srand(time(NULL));

        int d = rand()%100;
        cout << "d: " << d << endl;
        int A[d];
        int original_A[d];

        int med_val = (d-1)/2;

        cout << "Before Sort: " << endl;
        for (int l = 0; l < d; l++) {
            A[l] = rand()%d;
            cout << A[l] << " ";
            original_A[l] = A[l];
        }
        cout << endl;

        /* Finding the median by first sorting entire array with quick sort */
        int quick_sort_median = Quick_Sort_Select(A, d, med_val);
        printf("Quick Sort Median: %d\n", quick_sort_median);
        outfile << "Quick Sort Median: " << quick_sort_median << " ";
        
        cout << "After Sort: " << endl;
        for (int i = 0; i < d; i++) {
            cout << A[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < d; i++) {
            A[i] = original_A[i];
        }

        /* Finding the median using the Randomized Select algorithm from CLRS */
        int randomized_median = Randomized_Select(A, 0, d-1, med_val);
        printf("Randomized Select Median: %d\n", randomized_median);
        outfile << "Randomized Sort Median: " << randomized_median << " ";

        for (int i = 0; i < d; i++) {
            A[i] = original_A[i];
        }

        /* Finding the median using the Select [worst case O(n)] algorithm from CLRS */
        int select_median = Select(A, 0, d-1, med_val);
        printf("Select Median: %d\n", select_median);
        outfile << "Select Sort Median: " << select_median << endl;


        /* If assert is caught, then test fails */
        assert((quick_sort_median == randomized_median) == (randomized_median == select_median));

        return 0;
    }

    infile =  argv[1];
    cout << " infile  " << infile << endl;
    fp1 = fopen(infile,"r");
    if (fp1 == NULL) {
      printf("Did not find input file \n");
      assert(fp1 == NULL);
    }
    fscanf(fp1,"%d %d",&N,&d);

    cout << "Read in N and d for test arrays" << endl;
    cout << "n: " << N << " " << "d: " << d << endl;
    // int permutations[N][d];
    // TOO LARGE!

    char fname[20] = "";
    char suffix[5] = "_out";
    strcat(fname, infile);
    strcat(fname, suffix);

    // cout << fname << endl;


    outfile.open(fname);
    outfile << N << " " << d << endl;
    outfile.close();
    
    cout << fname << endl;
    outfile.open(fname, ofstream::app);


    /* 
       Tested to find the median since this will be
       necessary for nearest-neighbor query implementation
    */
    for (int p = 0; p < N; p++) {

       int original_A[d];
       int A[d];

       cout << "Before Sort: " << endl;
        /*
            Reading in permutations of array for testing
        */

       for (int j = 0; j < d; j++) {
            fscanf(fp1,"%d",&A[j]);
            original_A[j] = A[j];
            outfile << A[j] << " ";
            cout << A[j] << " ";
            if (j < d-1) {
                fscanf(fp1, " ");
            }
        }
        cout << endl;
        fscanf(fp1, "\n");
        outfile << "--- ";

        int med_val = (d-1)/2;


        /* Finding the median by first sorting entire array with quick sort */
        int quick_sort_median = Quick_Sort_Select(A, d, med_val);
        printf("Quick Sort Median: %d\n", quick_sort_median);
        outfile << "Quick Sort Median: " << quick_sort_median << " ";
        
        cout << "After Sort: " << endl;
        for (int i = 0; i < d; i++) {
            cout << A[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < d; i++) {
            A[i] = original_A[i];
        }

        /* Finding the median using the Randomized Select algorithm from CLRS */
        int randomized_median = Randomized_Select(A, 0, d-1, med_val);
        printf("Randomized Select Median: %d\n", randomized_median);
        outfile << "Randomized Sort Median: " << randomized_median << " ";

        for (int i = 0; i < d; i++) {
            A[i] = original_A[i];
        }

        /* Finding the median using the Select [worst case O(n)] algorithm from CLRS */
        int select_median = Select(A, 0, d-1, med_val);
        printf("Select Median: %d\n", select_median);
        outfile << "Select Sort Median: " << select_median << endl;


        /* If assert is caught, then test fails */
        assert((quick_sort_median == randomized_median) == (randomized_median == select_median));
    }
    outfile.close();

    return 0;
}
