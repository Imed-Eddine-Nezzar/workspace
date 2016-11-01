#ifndef __pairlist_hpp__
#define __pairlist_hpp__

#include <string>
#include <algorithm>
#include <ostream>
#include <vector>
#include <exception>
#include "keyvaluepair.hpp"

class PairList {
public:

  /****************************************
  * exceptions
  ****************************************/
  class pairlist_exception : public std::exception {
  public:
    virtual const char* what() const throw(){
      return "unknown exception";
    }
  };

  class key_not_found_exception : public std::exception {
  public:
    virtual const char* what() const throw(){
      return "key not found";
    }
  };

  class index_out_of_bounds : public std::exception {
  public:
    virtual const char* what() const throw(){
      return "index out of bounds";
    }
  };


  /****************************************
  * constructors
  ****************************************/

  // default
  PairList();

  // copy constructor
  PairList(const PairList& other);

  PairList& operator+(const KeyValuePair& kvpair);

  PairList& operator+(const std::string& str);


  /****************************************
  * iterators
  ****************************************/
  typedef std::vector<KeyValuePair>::iterator iterator;
  typedef std::vector<KeyValuePair>::const_iterator const_iterator;

  iterator begin();
  const_iterator begin() const;

  iterator end();
  const_iterator end() const;

  /****************************************
  * operators
  ****************************************/
  int operator[](const std::string& key);

  std::string operator[](std::size_t pos);


  template <typename UnaryPred>
  PairList findAll(UnaryPred pred) {
    PairList res;
    for (auto kvp = begin(); kvp != end(); ++kvp) {
      if (pred(*kvp))
        res = res + *kvp;
    }
    return res;
  }



private:
  std::vector<KeyValuePair> m_data;

  friend std::ostream& operator<<(std::ostream& os, const PairList& plist);
};

#endif // __pairlist_hpp__
