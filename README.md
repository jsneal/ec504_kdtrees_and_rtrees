k-d Tree Implementation in C++
==============================

This project is an implmentation of the k-d tree data structure in C++. I began the project in EC504 at Boston University, but after finishing what was necessary for that class I wanted to take the project further. This project is still in progress and is not designed with the use of others in mind, so please forgive the lack of documention and GUI.

Goals of this project:
---
- To implement the k-d tree for all positive integer inputs.
- To implement the k-d tree methods of insert, delete, find (exact match query), balance.
- To implement both unbalanced k-d trees and balanced k-d trees.
- To implement multiple selection algorithms for balanced insertion. These algorithms include (see CLRS textbook for algorithns):
    - selection using Quicksort
    - selection using Randomized Select
    - selection using Select

Criteria by which these goals are achieved:
---
- The implementation should pass a series of tests found in the respective Makefile.
- Pass randomized input test as well as exhaustive tests up to a reasonable input size.

Sources:
---
Any knowledge of k-d trees used in this project is dervied from my EC504 class at Boston University with Professor Brower, the wikipedia page for k-d trees, and this article:

Bentley, Jon Louis, and Stanford Univ. “Multidimensional Binary Search Trees Used for Associative Searching.” Communications of the ACM, 1 Sept. 1975, dl.acm.org/doi/10.1145/361002.361007.

Some of the variable names in the code for k-d trees correspond to variable names given in that paper.

The Selection algorithms come from the CLRS Introduction to Algorithms textbook. The names for each algorithm correspond to the names given in that textbook. To clear up any confusion Select is the O(n) selection algorithm.

Currently implemented:
---
- Implemented the k-d tree for all positive integer inputs.
- Implemented the k-d tree methods of insert, delete, find (exact match query).
- Implemented unbalanced k-d trees.
- Implemented multiple selection algorithms.

Currently working on:
---
- Implementing k-d tree balance method.
- Implementng balanced k-d trees.
- Implementing balanced insertion.


