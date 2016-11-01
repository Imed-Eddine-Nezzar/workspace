#include <iostream>
#include <string>     // std::getline
#include <vector>     // std::vector
#include <iterator>   // std::osteram_iterator
#include <algorithm>  // std::copy
#include <sstream>    // std::istringstream

int main() {
  std::string word;
  std::string line;
  std::vector<std::string> words;
  
  // read whole line then split it into words
  std::cout << "Enter something: ";
  
  std::getline(std::cin, line);
  
  std::istringstream iss(line);
  while (iss >> word)
    words.push_back(word);
    
  std::cout << "You entered: ";  
  std::copy(words.begin(), words.end(),
            std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << "\n";
}
