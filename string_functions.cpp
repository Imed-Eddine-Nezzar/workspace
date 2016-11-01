#include <iostream>
#include <cstdint>        // std::size_t

namespace local {
  size_t strlen(const char* str) {
    size_t len = 0;
    while (*str++) ++len;
    return len;
  }
  
  void strcpy(const char* from, char* to) {
    while (*from) *to++ = *from++;
    *to = '\0';
  }
}

int main(void) {
  std::cout << local::strlen("hello world\n") << "\n";
  char s[100] = "hello world\n";
  local::strcpy("hello world", s);
  std::cout << s << "\n";
}
