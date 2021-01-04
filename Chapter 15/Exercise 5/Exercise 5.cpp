#include <iostream> 
#include <set>
#include <vector>
#include <algorithm>


int main() {
    int array[] = { 2, 4, 6, 8, 10, 12, 14, 16 };
    std::set<int, std::less<int>> set({ 1, 3, 5, 7, 9, 11, 13, 15 });
    
    std::vector<int> vector;

    std::merge(array, array + 8, set.begin(), set.end(), std::back_inserter(vector));

    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}