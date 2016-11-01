#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    std::vector<int> input;
    int x, cnt = 0;
    for(;;) {
        std::cout << "Enter a number: ";
        std::cin >> x;
        if (x == 0) break;
        input.push_back(x);
    }
    
    auto min_max = std::minmax_element(input.begin(), input.end());
    if (not input.empty())
    std::cout << "Average: " << int(std::accumulate(input.begin(), input.end(), 0) / input.size() ) << "\n"
              << "Max: " << *(min_max.second) << "\n"
              << "Min: " << *(min_max.first) << "\n";
    else
        std::cout << "No data, so no answers\n";
}f
