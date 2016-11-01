#include <iostream>
    
    
unsigned count_work_days(short sm, short sy, short em, short ey, unsigned holidays) {
  unsigned workdays = 0;
  
  while (sy < ey or sm < em) {
    workdays += (sm % 2 == 1) ?    ((sm > 7) ? 23 : 24)
                              :    22;
    if (sm == 12) sy += 1;

    sm = (sm % 12) + 1;
  }
  return workdays - holidays;
}

int main() {
  std::cout << count_work_days(7, 2009, 2, 2010, 7) << "\n";
}
