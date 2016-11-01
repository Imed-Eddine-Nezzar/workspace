#include <iostream>
#include <vector>

int getMode(const std::vector<int>& v){
  unsigned max = 0, mod = -1;
  for (int i = 1, cnt; i < v.size(); ++i) {
    if (v[i] == v[i - 1])
      cnt += 1;
    else if (max < cnt){
      max = cnt;
      cnt = 0;
      mod = v[i - 1];
    }
  }
  
  return mod;
}

int main(void) {
  std::vector<int> v{1, 1, 1, 2, 2, 3, 7, 7, 7, 7, 7, 9, 9};
  std::cout << getMode(v)<< "\n";
}
