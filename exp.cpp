#include <iostream>
#include <iomanip>

double exp(double pressision = 0) {
  double cexp = 1, pexp;
  uint64_t f = 1; 
  uint8_t i = 1;

  do {
    pexp = cexp;
    cexp += 1.0 / (f *= i++);
  } while (cexp - pexp > pressision);

  return cexp;
}

int main() {
  std::cout.precision(10);

  std::cout << std::setw(20) << exp(1) << "\n";
  std::cout << std::setw(20) << exp(0.1) << "\n";
  std::cout << std::setw(20) << exp(0.01) << "\n";
  std::cout << std::setw(20) << exp(0.001) << "\n";
  std::cout << std::setw(20) << exp(0.0001) << "\n";
  std::cout << std::setw(20) << exp() << "\n";
}
