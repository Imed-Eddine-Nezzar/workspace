#include <iostream>
#include "pairlist.hpp"


bool valLess20(KeyValuePair& p) { return p.value() < 20; }

int main()
{
  KeyValuePair p1;
  p1 = "count:1";

  //default constructor
  //set the the key and value of p1 to "count" and 1
  //respectively
  KeyValuePair p2("size", 10); //create a KeyValuePair with
  // key and value: "size" and 10
  KeyValuePair p3 = p1;
  // copy p1's data into the new KeyValuePair, p3
  KeyValuePair p4("width", 20);
  // create a KeyValuePair with
  // key and value: "width" and 20
  PairList plist;
  // create a PairList
  plist + p1 + p2 + "depth:10" + p3 + p4; // Add to plist: p1, p2,
  //a pair defined by key:"depth" and value:10, p3 and p4
  std::cout << plist;
  //display all elements in the list
  std::cout << std::endl;
  PairList temp = plist.findAll<decltype(valLess20)>(valLess20); // create a new PairList with all
  // values less than 20 using the function valLess20
  std::cout << temp;
  // display the new list
  std::cout << plist["width"] << std::endl;
  // display the value for key = "width"
  std::cout << std::string(plist[3]) << std::endl;
  //display the 3rd element of plist
  return 0;
}
