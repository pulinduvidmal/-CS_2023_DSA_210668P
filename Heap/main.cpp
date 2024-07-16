#include <iostream>
#include <vector>
#include <stdexcept>

// Function to return the index of the parent node of node i
int Parent(int i) {
    return (i - 1) / 2;
}

// Function to return the index of the left child node of node i
int Left(int i) {
    return 2 * i + 1;
}

// Function to return the index of the right child node of node i
int Right(int i) {
    return 2 * i + 2;
}

// Function to maintain the max-heap property for a subtree rooted at index i
void MaxHeapify(std::vector<int>& A, int i) {
    int l = Left(i);
    int r = Right(i);
    int largest = i;

    // Find the largest among root, left child, and right child
    if (l < A.size() && A[l] > A[i])
        largest = l;
    if (r < A.size() && A[r] > A[largest])
        largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        std::swap(A[i], A[largest]);
        MaxHeapify(A, largest);
    }
}

// Function to build a max-heap from an unordered array
void BuildMaxHeap(std::vector<int>& A) {
    for (int i = A.size() / 2 - 1; i >= 0; i--) {
        MaxHeapify(A, i);
    }
}

// Function to return the maximum element in the heap
int HeapMaximum(const std::vector<int>& A) {
    return A[0];
}

// Function to remove and return the maximum element from the heap
int HeapExtractMax(std::vector<int>& A) {
    if (A.size() < 1) {
        throw std::underflow_error("Heap underflow");
    }
    int max = A[0];
    A[0] = A[A.size() - 1];
    A.pop_back();
    MaxHeapify(A, 0);
    return max;
}

// Function to insert a new key into the max-heap
void MaxHeapInsert(std::vector<int>& A, int key) {
    A.push_back(key);
    int i = A.size() - 1;
    // Fix the max-heap property if it is violated
    while (i > 0 && A[Parent(i)] < A[i]) {
        std::swap(A[i], A[Parent(i)]);
        i = Parent(i);
    }
}

// Function to increase the value of a specified element in the heap
void HeapIncreaseKey(std::vector<int>& A, int i, int key) {
    if (key < A[i]) {
        throw std::invalid_argument("New key is smaller than current key");
    }
    A[i] = key;
    // Fix the max-heap property if it is violated
    while (i > 0 && A[Parent(i)] < A[i]) {
        std::swap(A[i], A[Parent(i)]);
        i = Parent(i);
    }
}

int main() {
    // Initializing the priority queue
    std::vector<int> A = {3, 2, 1, 7, 8, 4, 10, 16, 12};

    // Building the max-heap
    BuildMaxHeap(A);

    // Display the maximum element
    std::cout << "Max element: " << HeapMaximum(A) << std::endl;

    // Insert a new element into the heap
    MaxHeapInsert(A, 15);
    std::cout << "Max element after insertion: " << HeapMaximum(A) << std::endl;

    // Extract the maximum element
    int max = HeapExtractMax(A);
    std::cout << "Extracted max element: " << max << std::endl;
    std::cout << "Max element after extraction: " << HeapMaximum(A) << std::endl;

    // Increase the value of an element at index 2
    HeapIncreaseKey(A, 2, 14);
    std::cout << "Max element after increase key: " << HeapMaximum(A) << std::endl;

    return 0;
}
