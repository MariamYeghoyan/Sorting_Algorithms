#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& vec) {
    for (int i{0}; i < vec.size(); ++i) {
        for (int j{0}; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> vec = {10, 9, 7, 12, 15};
    BubbleSort(vec);
    for (int v : vec) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}