//COLTON FARBATUK
//date: 2020-09-20
#include <iostream>
#include <string>
#include "time.hpp"
#include "date.hpp"
#include "calendar.hpp"



int main() 
{
  Calendar C1;
  Calendar C2;
  TimeRange T1;
  Date D1;
  C2 = D1;
  
  
  char choice;
  int i;
 
  do
  {
   std::cout << "\nHello, welcome to the calendar app, please make a choice...\n";
   C1.menu();
   std::cin >> choice;
   if(choice == 'a' || choice == 'A')
   {
     C1.input(T1,D1,choice);
    C1.book(D1,T1);
  
   }

   if(choice == 'b' || choice == 'B')
   {
     C1.input(T1,D1,choice);
     C1.cancel(D1,T1);

   }
      if(choice == 'c' || choice == 'C')
   {
     C1.input(T1,D1,choice);
     C1.query(D1,T1);
   }
     if(choice == 'd' || choice == 'D')
   {
     C1.printFreeDays(C1,D1);
   }
     if(choice == 'f' || choice == 'F')
   {
     C1.printFreeTimeSlots(C1,D1);
   }
   if(choice == 'h' || choice =='H')
   {
     C1.copy(C2,D1);
     std::cout << C1;
   }
  }
   while(choice != 'e' || choice != 'E');
   
  std::cout << "\n Goodbye.";

return 0;
}



  
