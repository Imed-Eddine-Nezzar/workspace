#include <iostream>
#include <iomanip>

void solve(int n) {
  for (int i = n, cnt = 1; i > 0; --i) {
    for (int j = 0; j < i; ++j)
	std::cout << std::setw(2) << cnt++ << " ";
    std::cout << "\n";
  }
}

int main() {
  solve(5);
}
