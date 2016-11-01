#include <iostream>
#include <string>

void solve(int n) {
   auto padding = [](int cnt) { return std::string(cnt, ' '); };

   std::cout << padding(n-1) << '/' << std::string(n, '-') << "\\\n";
   int x = n + 2;
   for (; --n > 1; x += 2) {
       std::cout << padding(n-1) << '/' << std::string(x, '+') << "\\\n";
   }
   std::cout << '/' << std::string(x, '-') << "\\\n";
}

int main() {
  solve(6);
}
