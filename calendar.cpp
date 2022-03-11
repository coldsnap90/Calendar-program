#include "calendar.hpp"
//line 40 - book function
//line 98 - query
//line 158 - cancel
//line 499 - operator overload
//line 220 - printFreeTimeSlots
//line 286 - print free days
//other various helpers below
//costructor
Calendar::Calendar() : TimeRange(), Date()
{
	//Initialize may month in the Calendar array
	for(int i =1; i <= DEC_DAYS; i++)
	{
		CalendarDec[i].setDay(i);
		CalendarDec[i].setAppointed(48,0);
	}
	//Initialize june
	for(int i =1; i <= NOV_DAYS; i++)
	{
		CalendarNov[i].setDay(i);
		CalendarNov[i].setAppointed(48,0);
	}
	//Initialize july
	for(int i =1; i <=OCT_DAYS; i++)
	{
		CalendarOct[i].setDay(i);
		CalendarOct[i].setAppointed(48,0);
	}
	//Initialize aug
	for(int i =8; i <= SEPT_DAYS; i++)
	{
		CalendarSept[i].setDay(i);
		CalendarSept[i].setAppointed(48,0); 
	}
}

//callendar constructor with inherited classes
Calendar::Calendar(int new_BeginHour,int new_BeginMinute,int new_EndHour,int new_EndMinute, int new_Day,int new_Month) :
TimeRange(new_BeginHour,new_BeginMinute,new_EndHour,new_EndMinute), Date(new_Day,new_Month){};


//book func using date and time
bool Calendar::book(const Date &date, const TimeRange& time)
{
  //checks month and adds to monnth array for
  //months 9 -12
  if(date.getMonth() == 9)
  {
    for(int i = 0; i <- SIZE;i++)
    {
     //CalendarSept[date.getDay()] = date;
     CalendarSept[date.getDay()] = date;
     if(CalendarSept[date.getDay()].getAppointed(i)==0)
     {
      //keeps track of spet appointments for
      //print freedays
      appointments[0][date.getDay()]+=1;
     }
   }
  }
  if(date.getMonth() == 10)
  {
   for(int i = 1; i <= SIZE; i++)
   { //books for oct
     CalendarOct[date.getDay()] = date;

     if(CalendarOct[date.getDay()].getAppointed(i)==0)
     { //keeps track oct apppoints
      appointments[1][date.getDay()] +=1;
     }
   }
  }
   if(date.getMonth() == 11)
  {
   for(int i = 1; i <= SIZE; i++)
   { //books nov
     CalendarNov[date.getDay()] = date;
     if(CalendarSept[date.getDay()].getAppointed(i)==0)
     { //keeps track nov appointments
      appointments[2][date.getDay()]+=1;
     }  
   }
  }
   if(date.getMonth() == 12)
  {
   for(int i = 1; i <= SIZE; i++)
   { //books dec
     CalendarDec[date.getDay()]= date;
     if(CalendarSept[date.getDay()].getAppointed(i)==0)
     { //dec apppointments
      appointments[3][date.getDay()]+=1;
     }
   }
  }
  return true;
}

// QUERY FUNCTION, multiple is full error checks
bool Calendar::query(const Date& date,const  TimeRange& time)
{
  std::cout<< "\n";
  //various logical statements for
  //three choices for open, partial open, or closed
  //used setTime to facilitate this
  
  //case added for each month sept - dec
  if(9 == date.getMonth())
  {
  if(setTime(time,date) == false)
  {
   if(isFull(date))
   {
     std::cout << "Date is full booked";
     return false;
   }
   else
     std::cout << stringMonths[0] << " - " << date.getDay() << " is Partially open.";
      return true;
  }
  else
   std::cout << stringMonths[0] << " - " << date.getDay() << " is open.";
   return true;
  }

  if(10 == date.getMonth())
  { //checks isfull function for booked apps
   if(setTime(time,date) == false)
   {
    if(isFull(date))
    {
      std::cout << "Date is full booked";
      return false;
    }
    else
     std::cout << stringMonths[1] << " - " << " the " << date.getDay() << " is Partially open.";
      return true;
   }
    else
      std::cout << stringMonths[1] << " - " << " the " << date.getDay() << " is open.";

  }

  if(11 == date.getMonth())
  {
    if(date.setTime(time,date) == false)
    {
    if(isFull(date))
    {
      std::cout << "Date is full booked";
      return false;
    }
  
    else
      std::cout << stringMonths[2] << " - " <<  date.getDay() << " is Partially open.";
      return true;
    }
    else
      std::cout << stringMonths[2] << " - " <<  date.getDay() << " is open.";
      return true;
  }
 
  if(12 == date.getMonth())
  {
    if(date.setTime(time,date) == false)
    {
    if(isFull(date))
    {
      std::cout << "Date is full booked";
      return false;
    }
    else
       std::cout << stringMonths[3] << " - " <<  " the " << date.getDay() << " is Partially open.";
      return true;
    }
    else
      std::cout << stringMonths[3] << " - " <<  " the " << date.getDay() << " is open.";
      return true;
  }

  else
  return true;
}

//function to cancel appointment, takes date and time
//input sets it, adds to removes from calendar
bool Calendar::cancel(const Date& date, const TimeRange& time)
{
  //date and time input

  
  //checks month adds to sept cal
  if(date.getMonth() == 9)
  {
   for(int i = 0; i <= SIZE; i++)
   {
     CalendarSept[date.getDay()] = date;
     if(CalendarSept[date.getDay()].getAppointed(i)==1)
     {//removes appointment from month array
      appointments[0][30] -=1;
     }
   }
  }
  //checks month adds to oct cal
  if(date.getMonth() == 10)
  {
   for(int i = 0; i <= SIZE; i++)
   {
     CalendarOct[date.getDay()] = date;
     if(CalendarOct[date.getDay()].getAppointed(i)==1)
     {
     //removes appointment from month array
      appointments[1][30] -=1;
     }
   }
  }
  //checks month adds to nov cal
   if(date.getMonth() == 11)
  {
   for(int i = 0; i <= SIZE; i++)
   {
     CalendarNov[date.getDay()] = date;
     if(CalendarNov[date.getDay()].getAppointed(i)==1)
     {
     //removes appointment from month array
      appointments[2][30]-=1;
     }
   }
  }
   //checks month adds to dec cal
   if(date.getMonth() == 12)
  {
   for(int i = 0; i <= SIZE; i++)
   {
     CalendarDec[date.getDay()]= date;
     if(CalendarDec[date.getDay()].getAppointed(i)==1)
     {
     //removes appointment from month array
      appointments[3][30]-=1;
     }
   }
  }
  return true;
  
}

//prints all freetime slots using date&time objects
void Calendar::printFreeTimeSlots(Calendar& C1,Date& date)
{
 int day, month,enter;
 do{
    //enter month and day for time slots
    std::cout << "Enter a month then day to check for open times.\n";
    std::cin >> month;
    std::cin >> day;
   	if(std::cin.fail()) //error checking for faulty input
		{
      std::cout << "fail\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Error - try again.\n";
		}
    date.setMonth(month);
    date.setDay(day);

    //print for november, same format continues with
    //error checking
 	  if(9 == date.getMonth() && date.isWeekend(date) == true && date.isHoliday(date,TRUTH_AND_REC,THANKSGIVING,REMEMBERANCE_DAY) == true && date.isValid(date) == true)
	  { //prints month and day time slots
      std::cout << "Printing out all open time slots.\n\n";
      std::cout << "Printing appointments for " << stringMonths[0] << ", " << date.getDay() << "\n----------------------------------\n"; 
      C1.print(CalendarSept[date.getDay()]);
	  }
     
     //same format as above for different months
    if(10 == date.getMonth() && date.isWeekend(date) == true && date.isHoliday(date,TRUTH_AND_REC,THANKSGIVING,REMEMBERANCE_DAY) == true && date.isValid(date) == true)
    {
      std::cout << "Printing out all open time slots.\n\n";
      std::cout<< "Printing appointments for " << stringMonths[1] << ", " << date.getDay() << "\n----------------------------------\n"; 
      C1.print(CalendarOct[date.getDay()]);
    }
   
  if(11 == date.getMonth() && date.isWeekend(date) == true && date.isHoliday(date,TRUTH_AND_REC,THANKSGIVING,REMEMBERANCE_DAY) == true && date.isValid(date) == true)
  { 
    std::cout << "Printing out all open time slots.\n\n";
    std::cout << "Printing appointments for " << stringMonths[2] << "," << date.getDay() << "\n----------------------------------\n"; 
    C1.print(CalendarNov[date.getDay()]);
  }

  if(12 == date.getMonth() && date.isWeekend(date) == true && date.isHoliday(date,TRUTH_AND_REC,THANKSGIVING,REMEMBERANCE_DAY) == true && date.isValid(date) == true)
  {
    std::cout << "Printing out all open time slots.\n\n";
    std::cout << "Printing appointments for " << stringMonths[3] << ", " << date.getDay() << "\n----------------------------------\n"; 
    C1.print(CalendarDec[date.getDay()]);
  }
    else
    {
      std::cout << "Enter 1 to continue or 0 to exit.\n";
      std::cin >> enter;
    }

 }while(enter != 0);
}

//takes an input for dates, checks calendar objects
//and error functions and prints out open days
void Calendar::printFreeDays(Calendar& C1,Date& D1)
{
  int month;
  std::cout << "Enter a month: ";
  std::cin >> month;
  D1.setMonth(month);
  std::cout << "Printing Open Days.\n";
  std::cout << "-------------------\n"; 
  if(month == 9 && isFull(D1) == false)
  {
   std::cout << "Open days in September : \n";
   for(int i = 8; i <= SEPT_DAYS;i++)
   {
      D1.setDay(i);
      if(D1.isWeekend(D1) == false || D1.isHoliday(D1,TRUTH_AND_REC,THANKSGIVING,REMEMBERANCE_DAY) == false || D1.isValid(D1) == false)
      { //checks if appointments were booked
        std::cout <<"Day : " << i << " - CLOSED\n";
        std::cout << "-----------------------------\n";
      }
      else
      if(C1.appointments[0][i] > 0)
        { //if appointments are booked
         std::cout << "Day : " << CalendarSept[i].getDay() << " - Partially OPEN \n" ;
        }
        else
        std::cout << "Day : " << CalendarSept[i].getDay() << " - OPEN \n" ;   
   }
  }

  if(month == 10 && !isFull(D1))
  {
    std::cout << "Open days in October : \n";
    for(int i = 1; i <= OCT_DAYS;i++)
    {
         D1.setDay(i);
      if(D1.isWeekend(D1) == false || D1.isHoliday(D1,TRUTH_AND_REC,THANKSGIVING,REMEMBERANCE_DAY) == false || D1.isValid(D1) == false)
      { //checks if appointments were booked
        std::cout <<"Day : " << i << " - CLOSED\n";
        std::cout << "-----------------------------\n";
      }
      else
      if(C1.appointments[1][i] > 0)
        { //if appointments are booked
         std::cout << "Day : " << CalendarOct[i].getDay() << " - Partially OPEN \n" ;
        }
      else
        std::cout << "Day : " << CalendarOct[i].getDay() << " - OPEN \n" ;    
   }
  }

   if(month == 11 && !isFull(D1))
  {
    std::cout << "Open days in November : \n";
    for(int i = 1; i <= NOV_DAYS;i++)
    {  //error checking
      D1.setDay(i);
      if(D1.isWeekend(D1) == false || D1.isHoliday(D1,TRUTH_AND_REC,THANKSGIVING,REMEMBERANCE_DAY) == false || D1.isValid(D1) == false)
      { //checks if appointments were booked
        std::cout <<"Day : " << i << " - CLOSED\n";
        std::cout << "-----------------------------\n";
      }
      else
      if(C1.appointments[2][i] > 0)
        { //if appointments are booked
         std::cout << "Day : " << CalendarNov[i].getDay() << " - Partially OPEN \n" ;
        }
        else
        std::cout << "Day : " << CalendarNov[i].getDay() << " - OPEN \n" ;  
   }
  }
    if(month == 12 && !isFull(D1))
  {
    std::cout << "Open days in December : \n";
    for(int i = 1; i <= DEC_DAYS;i++)
    { //error checking before output
      D1.setDay(i);
      if(D1.isWeekend(D1) == false || D1.isHoliday(D1,TRUTH_AND_REC,THANKSGIVING,REMEMBERANCE_DAY) == false || D1.isValid(D1) == false)
      { //checks if appointments were booked
        std::cout <<"Day : " << i << " - CLOSED\n";
        std::cout << "-----------------------------\n";
      }

      else
        if(C1.appointments[3][i] > 0)
          { //if some appointments are booked
            std::cout << "Day : " << CalendarDec[i].getDay() << " - Partially OPEN \n" ;
           }
        else
          std::cout << "Day : " << CalendarDec[i].getDay() << " - OPEN \n" ;     
   }
  }
 return;
}

//isfull func checks array corresponding to month
//to see if appointments have been booked, returns bool
bool Calendar::isFull(const Date& date)
{
  //counter full september to see if full
  if(appointments[0][date.getDay()] >1)
  {
    int counter = 0;
    for(int i = 0; i < SIZE;i++)
    {
      if(CalendarSept[date.getDay()].getAppointed(i) == 1)
      {
        counter+=1;
      }
    }
    if(counter >= SIZE)
    {
      return true; //if number of appointments
    }//booked is equal to total appointments
    else
      return false; //else not full
  }
    //counter for october tto see if full
    if(appointments[1][date.getDay()] < 1)
  {
    int counter = 0;
    for(int i = 0; i < SIZE;i++)
    {
      if(CalendarOct[date.getDay()].getAppointed(i) == 1)
        {
          counter+=1;
        }
    }
    if(counter >= SIZE)
    {
      return true; 
    }
    else
      return false;
  }
    //counter for november to see if full
    if(appointments[2][date.getDay()] < 1)
  {
    int counter = 0;
    for(int i = 0; i < SIZE;i++)
    {
      if(CalendarNov[date.getDay()].getAppointed(i) == 1)
        {
          counter+=1;
        } 
    }
    if(counter >= SIZE)
    {
      return true;
    }
    else
      return false;
  }
    //counter for dec to see if full
    if(appointments[3][date.getDay()] < 1)
  {
    int counter = 0;
    for(int i = 0; i < SIZE;i++)
    {
      if(CalendarDec[date.getDay()].getAppointed(i) == 1)
        {
          counter+=1;
        }
    }
    if(counter >= SIZE)
    {
      return true;
    }
    else
      return false;
  }
 else
 return false;
}
//menu func
void Calendar::menu()
{
  std::cout << "\nEnter 'A' or 'a' to book an appointment.\n";
  std::cout << "Enter 'B' or 'b' to cancel an appointment.\n";
  std::cout << "Enter 'C; or 'c' to query an appointment.\n";
  std::cout << "Enter 'D; or 'd' to print free days.\n";
  std::cout << "Enter 'F' or 'f' to print free time slots.\n";
  std::cout << "Enter 'H' or 'h' to print booked appointments.\n";
  std::cout << "Enter 'E' or 'e' to exit.\n";
  return;
}

//used in printfree slots
void Calendar::print(Date& D1)
{ 
 //print func
 D1.print();
}

//input for calendar features
void Calendar::input(TimeRange& T1,Date& D1,char entry)
{

  if(entry == 'a' || entry == 'A')
 {
  T1.input(T1);
  D1.input(D1);
  D1.setTime(T1,D1,1);
 }
 if(entry == 'b' || entry == 'B')
 {
  T1.input(T1);
  D1.input(D1);
  D1.setTime(T1,D1,0);
 }
 if(entry == 'C' || entry == 'c')
 {
  T1.input(T1);
  D1.input(D1);
  //D1.setTime(T1,D1);
 }
}

std::ostream& operator <<(std::ostream& out, const Calendar& C1)
{
  
  for(int i = 0; i < C1.getCopy();i++)
  {
   
   out << "Appointments Booked : " << (i+1) <<" - " << std::setfill('0') << std::setw(13) << C1.s[i]<<  "\n";
  }
  return out;
}

//copys date,time objects to calendar
void Calendar::copy(const Calendar& C1,const Date& d1)
{
  appointmentCountCopy = d1.getAppointmentCount();
  for(int i = 0; i < d1.getAppointmentCount();i++ )
  {
    s[i] = d1.getStart(i);
  }
}

//assignment operator
Date& Calendar::operator=(const Date& D1)
{
  appointmentCountCopy = D1.getAppointmentCount();
   for(int i = 0; i < D1.getAppointmentCount();i++ )
  {
    s[i] = D1.getStart(i);
  }
  return *this;
}
//getter for appointmentCountCopy for outputting
//booked appointments
int Calendar::getCopy() const
{
  return appointmentCountCopy;
}
Calendar::~Calendar(){};