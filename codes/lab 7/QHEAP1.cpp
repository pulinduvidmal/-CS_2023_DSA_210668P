#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {
    int MAX_SIZE = 100000;
    vector<int> heap(MAX_SIZE);
    int num_of_queries;
    int option = 0;
    int num = 0;
    int tail = 0;
    cin >> num_of_queries;
    
    for (int i = 0; i < num_of_queries; i++) {
        cin >> option;
        if (option == 3) {
            //minimum value
            cout << heap[1] << endl;
        } else if (option == 1) {
            // Insert
            cin >> num;
            tail++;
            int j = tail;
            while (j > 1 && num < heap[j / 2]) {
                heap[j] = heap[j / 2];
                j /= 2;
            }
            heap[j] = num;
        } else {
            // Delete
            cin >> num;
            int k;
            for (k = 1; k <= tail; k++) {
                if (heap[k] == num) {
                    break;
                }
            }
            int temp = heap[tail];
            tail--;
            int i, j;
            for (i = k, j = 2 * i; j <= tail;) {
                if (j < tail && heap[j] > heap[j + 1]) {
                    j++;
                }
                if (temp < heap[j]) {
                    break;
                }
                else {
                    heap[i] = heap[j];
                    i = j;
                    j *= 2;
                }
            }
            heap[i] = temp;
        }
    }
    
    return 0;
}

