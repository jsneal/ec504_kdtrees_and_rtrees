#include<iostream>
#include<assert.h>
#include "selection_algorithms.h"

using namespace std;


int main(int argc, char *argv[]) {
    /* number of points in input_file */
    int N;
    /* dimension of points in kd_tree */
    int d;
    char *infile;
    char *actionfile;
    FILE *fp1;
    FILE *fp2;
    FILE *of1;

    if (argv[1] == NULL) {

        N = 20;
        // int A[N];
        int A[20] = {2, 7, 17, 13, 0, 15, 14, 9, 11, 9, 2, 16, 5, 4, 3, 12, 8, 13, 12, 8};
        // int A[20] = {6, 11, 3, 18, 4, 16, 17, 15, 17, 18, 6, 9, 10, 16, 10, 18, 13, 7, 11, 3};
        // int A[10] = {0, 0, 5, 0, 7, 9, 9, 2, 6, 1};
        // int B[5] = {5, 4, 3, 2, 1};
        int original_A[N];

        srand(time(NULL));

        int med_val = (N-1)/2;

        cout << "Before Sort: " << endl;
        for (int l = 0; l < N; l++) {
            A[l] = rand()%N;
            cout << A[l] << " ";
            original_A[l] = A[l];
        }
        cout << endl;

        /* Finding the median by first sorting entire array with quick sort */
        int quick_sort_median = Quick_Sort_Select(A, N, med_val);
        printf("Quick Sort Median: %d\n", quick_sort_median);
        
        cout << "After Sort: " << endl;
        for (int l = 0; l < N; l++) {
            cout << A[l] << endl;
        }

        for (int i = 0; i < N; i++) {
            A[i] = original_A[i];
        }

        /* Finding the median using the Randomized Select algorithm from CLRS */
        int randomized_median = Randomized_Select(A, 0, N-1, med_val);
        printf("Randomized Select Median: %d\n", randomized_median);

        for (int i = 0; i < N; i++) {
            A[i] = original_A[i];
        }

        /* Finding the median using the Select [worst case O(n)] algorithm from CLRS */
        int select_median = Select(A, 0, N-1, med_val);
        printf("Select Median: %d\n", select_median);

        //  If assert is caught, then test fails 
        // assert((quick_sort_median == randomized_median) == (randomized_median == select_median));

    } else {
        infile =  argv[1];

        cout << " infile  " << infile << endl;
        fp1 = fopen(infile,"r");
        if (fp1 == NULL) {
          printf("Did not find input file \n");
          assert(fp1 == NULL);
        }
        fscanf(fp1,"%d %d",&N,&d);

        cout << "Read in data to test selection algorithms" << endl;
        cout << "n: " << N << " " << "d: " << d << endl;
        int A[N*d];
        int original_A[N*d];

        for (int i = 0; i < N; i++){
            for (int j = 0; j < d; j++) {
                fscanf(fp1,"%d",&A[2*i+j]);
                if (j < d-1)
                    fscanf(fp1, " ");
            }
        }

        /* 
           Tested to find the median since this will be
           necessary for nearest-neighbor query implementation
        */

        int med_val = (N*d)/2;

        cout << "Before Sort: " << endl;
        for (int l = 0; l < N*d; l++) {
            cout << A[l] << endl;
            original_A[l] = A[l];
        }

        /* Finding the median by first sorting entire array with quick sort */
        int quick_sort_median = Quick_Sort_Select(A, N*d, med_val);
        printf("Quick Sort Median: %d\n", quick_sort_median);
        
        cout << "After Sort: " << endl;
        for (int l = 0; l < N*d; l++) {
            cout << A[l] << endl;
        }

        for (int i = 0; i < N*d; i++) {
            A[i] = original_A[i];
        }

        /* Finding the median using the Randomized Select algorithm from CLRS */
        int randomized_median = Randomized_Select(A, 0, N*d-1, med_val);
        printf("Randomized Select Median: %d\n", randomized_median);

        for (int i = 0; i < N*d; i++) {
            A[i] = original_A[i];
        }

        /* Finding the median using the Select [worst case O(n)] algorithm from CLRS */
        int select_median = Select(A, 0, N*d-1, med_val);
        printf("Select Median: %d\n", select_median);

        /* If assert is caught, then test fails */
        assert((quick_sort_median == randomized_median) == (randomized_median == select_median));
    }

    return 0;
}
