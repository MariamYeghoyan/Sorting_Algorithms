#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> CountingSort(std::vector<int>& A, int k, int exp) {
    std::vector<int> B(A.size());
    std::vector<int> C(k + 1, 0);

    for (int i = 0; i < A.size(); ++i) {
        ++C[(A[i] / exp) % 10];
    }
    for (int j = 1; j <= k; ++j) {
        C[j] += C[j - 1];
    }
    for (int i = A.size() - 1; i >= 0; --i) {
        B[C[(A[i] / exp) % 10] - 1] = A[i];
        --C[(A[i] / exp) % 10];
    }
    return B;
}

void RadixSort(std::vector<int>& vec, int d) {
    for (int i = 0; i < d; ++i) {
        vec = CountingSort(vec, 9, pow(10, i));
    }
}

int main() {
    std::vector<int> A = {329, 457, 657, 839, 436, 720, 355};
    RadixSort(A, 3); 
    for (int a : A) {
        std::cout << a << ' ';
    }
    std::cout << std::endl;
    return 0;
}