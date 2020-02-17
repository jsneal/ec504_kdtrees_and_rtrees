#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int* a1, int* a2) {
    /* Borrowed from CLRS */
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;

    return;
}

int partition(int* A, int p, int r) {
    /* Borrowed from CLRS */
    int x = A[r];
    int i = p-1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            ++i;
            swap(&(A[i]), &(A[j]));
        }
    }
    swap(&(A[i+1]), &(A[r]));
    return i+1;
}

int randomized_partition(int* A, int p, int r) {
    /* Borrowed from CLRS */
    srand(time(NULL));
    int i = rand()%(r-p) + p;
    swap(&(A[r]), &(A[i]));
    return partition(A, p, r);
}

void quick_sort(int* A, int p, int r) {
    /* Borrowed from CLRS */
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
    return;
}

void insertion_sort(int* A, int n) {
    /* Borrowed from CLRS */
    if (n == 1)
        return;
    int min, min_i;
    for (int i = 0; i < n; i++) {
        min = A[i];
        min_i = i;
        for (int j = i+1; j < n; j++) {
            if (A[j] < min) {
                min = A[j];
                min_i = j;   
            }

        }
        swap(&(A[i]), &(A[min_i]));
    }
    return;
}

int Quick_Sort_Select(int* A, int n, int i) {
    quick_sort(A, 0, n-1);
    return A[i];
}

int Randomized_Select(int* A, int p, int r, int i) {
    /* Borrowed from CLRS */
    if (p == r) {
        return A[p];
    }
    int q = randomized_partition(A, p, r);
    int k = q - p;
    if (i == k) {
        return A[q];
    } else if (i < k) {
        return Randomized_Select(A, p, q-1, i);
    } else {
        return Randomized_Select(A, q+1, r, i-k-1);
    }
}

int get_median_of_medians_index(int median, int* A, int p, int r) {

    for (int i = p; i < r+1; i++) {
        if (A[i] == median)
            return i;
    }
    return -1;
}

int Select(int* A, int p, int r, int i) {
    /* Borrowed from CLRS */
    /* 
       CLRS suggests a modified version of partition be used for this algorithm
       where you simply have the median of medians as the input to parition as "x,"
       but the algorithm does not work correctly if the pivot element is not swapped
       to split the hi and lo sections of the array into two.
    */
    if (p == r)
        return A[p];

    if (r-p <= 4) {
        insertion_sort(&(A[p]), r-p+1);
        return A[i+p];
    }

    /* Deteriming how many groups of 5 */
    int num_groups_of_five = (r-p+1)/5;
    int remainder = (r-p+1)%5;
    int num_of_medians = num_groups_of_five;

    if (remainder > 0)
        num_of_medians++;

    int medians[num_of_medians];
    int medians_idx[num_of_medians];

    /* Finding medians */
    for (int j = 0; j < num_groups_of_five; j++) {
        insertion_sort(&(A[5*j+p]), 5);
        medians[j] = A[5*j+2+p];
        medians_idx[j] = 5*j+2+p;
    }

    /* Getting median of remainder group */
    if (remainder > 0) {
        insertion_sort(&(A[5*num_groups_of_five + p]), remainder);
        medians[num_of_medians-1] = A[5*num_groups_of_five + p + (remainder-1)/2];
        medians_idx[num_of_medians-1] = 5*num_groups_of_five + p + (remainder-1)/2;
    }

    /* Finding Pivot */
    int x = Select(medians, 0, num_of_medians-1, (num_of_medians-1)/2);

    int pivot_idx = get_median_of_medians_index(x, A, p, r);
    /* Getting index of pivot to swap A[r] with pivot for partition */
    // Function does not work since medians are re-sorted
    swap(&(A[pivot_idx]), &(A[r]));
    /* Partitioning */
    int q = partition(A, p, r);

    /* k is index of pivot after partition */
    int k = q - p;

    /* Recursive calls */
    if (i == k)
        return x;
    else if (i < k) {
        return Select(A, p, q-1, i);
    } else {
        return Select(A, q+1, r, i-k-1);
    }
}