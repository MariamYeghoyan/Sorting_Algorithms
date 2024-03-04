#include <iostream>
#include <vector>

int partitionwithend(std::vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for (int j{low}; j <= high - 1; ++j) {
        if (vec[j] <= pivot) {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

int partitionwithstart(std::vector<int>& vec, int low, int high) {
    std::swap(vec[low], vec[high]);
    return partitionwithend(vec, low, high);
}

int partitionwithrandom(std::vector<int>& vec, int low, int high) {
    int randomindex = low + rand() % (high - low + 1);
    std::swap(vec[randomindex], vec[high]);
    return partitionwithend(vec, low, high);
}

void QuickSortwithend(std::vector<int>& vec, int low, int high) {
    if (low < high) {
        int i = partitionwithend(vec, low, high);
        QuickSortwithend(vec, low, i - 1);
        QuickSortwithend(vec, i + 1, high);
    }
}

void QuickSortwithstart(std::vector<int>& vec, int low, int high) {
    if (low < high) {
        int i = partitionwithstart(vec, low, high);
        QuickSortwithstart(vec, low, i - 1);
        QuickSortwithstart(vec, i + 1, high);
    }
}

void QuickSortwithrandom(std::vector<int>& vec, int low, int high) {
    if (low < high) {
        int i = partitionwithrandom(vec, low, high);
        QuickSortwithrandom(vec, low, i - 1);
        QuickSortwithrandom(vec, i + 1, high);
    }
}
int main() {
    std::vector<int> vec1 = {2, 8, 7, 1, 3, 5, 6, 4};
    QuickSortwithend(vec1, 0, 7);
    for (int v : vec1) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    std::vector<int> vec2 = {1, 8, 7, 4, 3, 5, 6, 2};
    QuickSortwithstart(vec2, 0, 7);
    for (int v : vec2) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    std::vector<int> vec3 = {8, 1, 6, 4, 2, 5, 7, 3};
    QuickSortwithstart(vec3, 0, 7);
    for (int v : vec3) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}