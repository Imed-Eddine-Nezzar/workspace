#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main(void) {
  std::vector<int> v;
  std::cout << "Enter element: ";
  std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(),

            std::back_inserter(v));
  v.erase(remove_if(v.begin(), v.end(), [](int x) { return x >= 10; }),
             v.end());

  std::cout << "int v[" << v.size() << "] = [";
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << "\b\b];\n";
}
