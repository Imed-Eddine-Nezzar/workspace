#include "pairlist.hpp"
/****************************************
* constructors
****************************************/

// default
PairList::PairList() :
  m_data()
{}

// copy constructor
PairList::PairList(const PairList& other) {
  auto temp = other.m_data;
  std::swap(m_data, temp);
}

PairList& PairList::operator+(const KeyValuePair& kvpair) {
  m_data.push_back(kvpair);
  return *this;
}

PairList& PairList::operator+(const std::string& str) {
  m_data.push_back(KeyValuePair(str));
  return *this;
}

PairList::iterator PairList::begin() {
  return m_data.begin();
}

PairList::const_iterator PairList::begin() const {
  return m_data.cbegin();
}

PairList::iterator PairList::end() {
  return m_data.end();
}

PairList::const_iterator PairList::end() const {
  return m_data.cend()  ;
}

/****************************************
* operators
****************************************/
int PairList::operator[](const std::string& key) {
  auto res = std::find_if(begin(), end(), [&key](const KeyValuePair& kvp) {
    return kvp.key() == key;
  });

  // key not found check
  if (res == end())
    throw key_not_found_exception();

  return res->value();
}

std::string PairList::operator[](std::size_t pos) {
  // out of bounds check
  if (pos >= m_data.size())
    throw index_out_of_bounds();

  std::ostringstream oss;
  oss << m_data[pos];
  return oss.str();
}

std::ostream& operator<< (std::ostream& os, const PairList& plist) {
for (auto kvp = plist.begin(); kvp != plist.end(); ++kvp)
  os << *kvp << " ";
return os;
}
