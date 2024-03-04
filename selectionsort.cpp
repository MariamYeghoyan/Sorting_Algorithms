#include <iostream>  
#include <vector> 

int FindLargestIndex(const std::vector<int>& vec, int index) {
    int largestindex {0};
    for (int i{1}; i < index; ++i) {
        if (vec[i] > vec[largestindex]) {
            largestindex = i;
        }
    }
    return largestindex;
}

void SelectionSort(std::vector<int>& vec) {
    int lastindex = vec.size() - 1;
    for (int i{lastindex}; i >= 1; --i) {
        int larger = FindLargestIndex(vec, i + 1);
        std::swap(vec[larger], vec[i]);
    }
}

int main() {
    std::vector<int> vec = {10, 9, 7, 12, 15};
    SelectionSort(vec);
    for (int v : vec) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}