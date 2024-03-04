#include <iostream>
#include <vector>

void merge(std::vector<int>& vec, int low, int middle, int high) {
    int i = low;
    int j = middle + 1;
    int k = low;
    std::vector<int> B;
    while (i <= middle and j <= high) {
        if (vec[i] < vec[j]) {
            B.push_back(vec[i++]);
        }
        else {
            B.push_back(vec[j++]);
        }
    }
    while (i <= middle) {
        B.push_back(vec[i++]);
    }
    while (j <= high) {
        B.push_back(vec[j++]);
    }
    for (int i = 0; i < B.size(); ++i) {
        vec[low + i] = B[i];
    }
}

void MergeSort(std::vector<int>& vec, int low, int high) {
    if (low < high) {
        int middle = low + (high - low) / 2;
        MergeSort(vec, low, middle);
        MergeSort(vec, middle + 1, high);
        merge(vec, low, middle, high);
    }
}

int main() {
    std::vector<int> vec = {10, 9, 7, 15, 12};
    MergeSort(vec, 0, 4);
    for (int v : vec) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}