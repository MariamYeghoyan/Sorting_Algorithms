#include <iostream>
#include <vector>

std::vector<int> CountingSort(std::vector<int>& A, int k) {
    std::vector<int> B(A.size());
    std::vector<int> C(k + 1, 0);

    for (int i{0}; i < A.size(); ++i) {
        ++C[A[i]];
    }
    for (int j{1}; j <= k; ++j) {
        C[j] += C[j - 1];
    }
    int last = A.size() - 1;
    for (int i{last}; i >= 0; --i) {
        B[C[A[i]] - 1] = A[i];
        --C[A[i]];
    }
    return B;
}

int main() {
    std::vector<int> A = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    std::vector<int> B = CountingSort(A, 6);
    for (int b : B) {
        std::cout << b << ' ';
    }
    std::cout << std::endl;
}