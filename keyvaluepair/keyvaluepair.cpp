#include "keyvaluepair.hpp"

/****************************************
* constructors
****************************************/
// default
KeyValuePair::KeyValuePair() :
  m_kvpair{}
{}

KeyValuePair::KeyValuePair(std::string key, int value) :
  m_kvpair{key, value}
{}

// from string
KeyValuePair::KeyValuePair(std::string str) {
  auto sep = str.find(':');

  if (sep == std::string::npos)
    throw malformed_constructor_argument();

  m_kvpair.first = str.substr(0, sep);
  try {
    str = str.substr(sep + 1, str.size());
    std::istringstream iss(str);
    iss >> m_kvpair.second;
  } catch (const std::exception& e) {
    throw malformed_constructor_argument();
  }
}

KeyValuePair::KeyValuePair(const KeyValuePair& other) {
  m_kvpair = other.m_kvpair;
}

// assignement operators
KeyValuePair& KeyValuePair::operator=(const std::string& str) {
  swap(KeyValuePair(str));
  return *this;
}

KeyValuePair& KeyValuePair::operator=(KeyValuePair other) {
  swap(other);
  return *this;
}

// getters
int KeyValuePair::value() const {
  return m_kvpair.second;
}
std::string KeyValuePair::key() const {
  return m_kvpair.first;
}

void KeyValuePair::swap(KeyValuePair other) {
  std::swap(m_kvpair, other.m_kvpair);
}

std::ostream& operator<<(std::ostream& os, const KeyValuePair& kvpair) {
  os << kvpair.key() << std::string(" : ") << std::to_string(kvpair.value());
  return os;
}
