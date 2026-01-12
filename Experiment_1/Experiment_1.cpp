#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long operationCount = 0;
int maxDepth = 0;

void complexRec(int n, int currentDepth) {
    operationCount++;
    maxDepth = max(maxDepth, currentDepth);

    if (n <= 2) {
        operationCount++;
        return;
    }

    int p = n;
    while (p > 0) {
        operationCount++;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operationCount++;
        }
        p >>= 1;
        operationCount++;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operationCount++;
    }

    if (n % 3 == 0) {
        reverse(small.begin(), small.end());
    } else {
        reverse(small.begin(), small.end());
    }
    operationCount++;

    complexRec(n / 2, currentDepth + 1);
    complexRec(n / 2, currentDepth + 1);
    complexRec(n / 2, currentDepth + 1);
}

int main() {
    vector<int> inputSizes = {8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};

    cout << "n\tOperations\tMaxDepth\tTime(ms)\n";

    for (int n : inputSizes) {
        operationCount = 0;
        maxDepth = 0;

        auto start = high_resolution_clock::now();
        complexRec(n, 1);
        auto end = high_resolution_clock::now();

        double timeTaken = duration<double, milli>(end - start).count();

        cout << n << "\t"
             << operationCount << "\t\t"
             << maxDepth << "\t\t"
             << timeTaken << "\n";
    }

    return 0;
}
