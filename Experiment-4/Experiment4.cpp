#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int heap[MAX];
int heapSize = 0;

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    while (true) {
        int s = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < heapSize && heap[l] < heap[s]) s = l;
        if (r < heapSize && heap[r] < heap[s]) s = r;

        if (s == i) break;

        swap(heap[i], heap[s]);
        i = s;
    }
}

void insert(int val) {
    if (heapSize == MAX) return;
    heap[heapSize] = val;
    heapifyUp(heapSize);
    heapSize++;
}

void deleteMin() {
    if (heapSize == 0) return;
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}

void deleteAtIndex(int index) {
    if (index < 0 || index >= heapSize) return;
    heap[index] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(index);
    heapifyUp(index);
}

int main() {
    insert(10);
    insert(20);
    insert(1);
    insert(0);
    insert(15);

    for (int i = 0; i < heapSize; i++) cout << heap[i] << " ";
    cout << endl;

    deleteMin();
    for (int i = 0; i < heapSize; i++) cout << heap[i] << " ";
    cout << endl;

    deleteAtIndex(1);
    for (int i = 0; i < heapSize; i++) cout << heap[i] << " ";

    return 0;
}
