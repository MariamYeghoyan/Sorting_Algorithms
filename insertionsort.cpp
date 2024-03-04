#include <iostream>
#include <vector> 

void InsertionSort(std::vector<int>& vec) {
    for (int i {1}; i < vec.size(); ++i) {
        int x = vec[i];
        int j = i - 1;
        while (j >= 0 and vec[j] > x) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = x;
    }
}

int main() {
    std::vector<int> vec = {10, 9, 7, 15, 12};
    InsertionSort(vec);
    for (int v : vec) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}