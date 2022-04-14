#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#include <ctime>
#include<cstdlib>
int main() {
    srand(time(NULL));
    int heap[1000], no = 100, i, j, c, x = 0, y, root, temp;
    for (y = 1; y <= 10; y++) {
        cout << "Scenario:" << y << endl;
        for (i = 0; i < no; i++) {
            x = (rand() % 1000000) + 1;
            heap[i] = x;
        }
        //Start of assortment
        for (i = 1; i < no; i++) {

            c = i;
            do {
                root = (c - 1) / 2;
                if (heap[root] < heap[c]) {
                    temp = heap[root];
                    heap[root] = heap[c];
                    heap[c] = temp;
                }
                c = root;
            } while (c != 0);
        }
        cout << "Heap array:" << endl;
        for (j = no - 1; j >= 0; j--) {
            temp = heap[0];
            heap[0] = heap[j];
            heap[j] = temp;
            root = 0;
            do {
                c = 2 * root + 1;
                if ((heap[c] < heap[c + 1]) && c < j - 1) {
                    c++;
                }
                if (heap[root] < heap[c] && c < j) {
                    temp = heap[root];
                    heap[root] = heap[c];
                    heap[c] = temp;
                }
                root = c;
            } while (c < j);
        }
        cout << "The sorted array is:" << endl;
        for (i = 0; i < no; i++) {
            cout << heap[i] << endl;
        }
        no = no + 100;
    }
    cout << "Complexity:" << '\n' << "Best case=Avg case=Worst case=0(n logn)" << endl;
    return 0;
}