#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

int LENGTH;

int write_count = 0;

using namespace std;

void swap(int* a1, int* a2);
void write_permutations_to_file(char* filename, int* a, int l, int current_index);

int main(int argc, char* argv[]) {
    if (argv[1] != NULL) {

        LENGTH = stoi(argv[1]);

        int A[LENGTH];
        // Number of permutations
        int Ncases = LENGTH;
        // Output if rand() == 1
        int max = 8;

        time_t t;

        srand(time(&t));

        for (int i = 0; i < LENGTH; i++)
            A[i] = i+1;

        for (int p = LENGTH-1; p > 0; p--)
            Ncases = Ncases*p;


        char filename[20];
        sprintf(filename, "%d_permuted.txt", LENGTH);
        
        ofstream outfile(filename);
        outfile << Ncases << " " << LENGTH << endl;
        outfile.close();


        write_permutations_to_file(filename, A, LENGTH, 0);

        cout << "Ncases: " << Ncases << " | " << "write_count: " << write_count << endl;

    } else {
        cout << "ERROR: No input LENGTH argument for array" << endl;
    }

    return 0;
}

void swap(int* a1, int* a2) {
    /* Borrowed from CLRS */
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;

    return;
}

void write_permutations_to_file(char* fname, int* a, int l, int current_index) {
    if (current_index == l) {
        ofstream outfile(fname, ofstream::app);
        write_count++;
        for (int k = 0; k < l; k++)
            outfile << a[k] << " ";
        outfile << endl;
        outfile.close();
        return;
    }

    for (int i = current_index; i < l; i++) {
        swap(&(a[current_index]), &(a[i]));
        write_permutations_to_file(fname, a, l, current_index+1);
        swap(&(a[current_index]), &(a[i]));
    }

    return;
}


