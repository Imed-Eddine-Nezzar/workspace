#ifndef __KEYVALUEPAIR_HPP__
#define __KEYVALUEPAIR_HPP__

#include <string>
#include <utility>
#include <sstream>
#include <exception>

class KeyValuePair {
public:
  /****************************************
  * exceptions
  ****************************************/
  class kvpair_exception : public std::exception {
  public:
    virtual const char* what() const throw(){
      return "unknown exception";
    }
  };

  class malformed_constructor_argument : public std::exception {
  public:
    virtual const char* what() const throw(){
      return "malformed constructor argument";
    }
  };

  /****************************************
  * constructors
  ****************************************/
  // default
  KeyValuePair();

  KeyValuePair(std::string key, int value);

  // from string
  KeyValuePair(std::string str);

  KeyValuePair(const KeyValuePair& other);

  // assignement operators
  KeyValuePair& operator=(const std::string& str);

  KeyValuePair& operator=(KeyValuePair other);

  // getters
  int value() const;
  std::string key() const;

  void swap(KeyValuePair other);

private:
  std::pair<std::string, int> m_kvpair;

  friend std::ostream& operator<<(std::ostream& os, const KeyValuePair& kvpair);
};


#endif // __KEYVALUEPAIR_HPP__
