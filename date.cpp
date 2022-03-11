#include "date.hpp"
//145 overloaded set time
//57 set time
//default constructor
Date::Date()
{};

//Date constructor
Date::Date(int newDay,int newMonth) : Day(newDay), Month(newMonth){};

//getter day
int Date::getDay() const
{
  return Day;
}
//getter month
int Date::getMonth() const
{
  return Month;
}
//geter appointed bool array
bool Date::getAppointed(int i) const
{
  return appointed[i];
}
//appointment count getter
int Date::getAppointmentCount() const
{
  return appointmentCount;
}
//appointment count setter
void Date::setAppointmentCount(const int &newCount) const
{
  appointmentCount = newCount;
}
//setter for day
void Date::setDay(const int &newDay)
{
 Day = newDay;
}

//setter for month
void Date::setMonth(const int &newMonth)
{
 Month = newMonth;
}

//setter for appointed bool
void Date::setAppointed(const int &n,const bool &flag) const
{
  appointed[n] = {flag};
}
//getter for the output booked string
std::string Date::getStart(const int& i) const
{
 return start[i];
}

//function overloading for setting appointments
//works for query func
bool Date::setTime(const TimeRange& t1,const Date& d1) const
{
  std::cout << "Appointment Query\n";
  std::cout <<"----------------------\n";
  //counter variables
  int hourCount = 0;
  int hourCount1 = 0;
  int appCount = 0;
  // time objects from int to string for easy readability and checking
	std::string tempStart = std::to_string( t1.getBeginHour());
  if(0 == t1.getBeginMinute())
  { //adds a 0 for good outputting
    tempStart = tempStart.append(std::to_string(t1.getBeginMinute()) + '0');
  }
  else
	tempStart = tempStart.append(std::to_string(t1.getBeginMinute()));

	std::string tempEnd = std::to_string(t1.getEndHour());
	tempEnd = tempEnd.append(std::to_string(t1.getEndMinute())+'0');
    // for loops for allocating string arrays for hours
    for(int z = 0; z <= 49; z++)
  { 
  	if(z%2 == 0)
		{
			hours[z] = std::to_string(hourCount);
			hourCount++;
		}
		if(z%2 == 1)
		{
			hours[z] = std::to_string(hourCount1);
			hourCount1++;
		}
  }
  //same as above but for minutes
  for(int k = 0; k <= 49; k++)
  {
    if(0 == k % 2)
    {
      minutes[k] = "00";
    }
    else
    {
      minutes[k] =  "30";
    }
  }

  //holds string times for checking and output
	std::string Times[SIZE+1];
  std::string TimesOut[SIZE+1];
  
   	for(int j =0; j <=SIZE; j++)
	{
     //dynamic arrays for outputing time slots
		*(Times+j) = hours[j] + minutes[j];
    *(TimesOut+j) = hours[j] + ":"+minutes[j];
	}
   
  std::cout << " \n";
	for(int i =0; i <= SIZE; i++)
	{
		if(Times[i] == tempStart )
    {
      // 1 is booked 0 is closed
	    /*if(d1.getAppointed(i) == 1)
      {
        std::cout << "Appointment Slot : " << TimesOut[i] << " is booked.\n";
        appCount++;
      }
      else
        std::cout << "Appointment Slot : " << TimesOut[i] << " is open.\n";*/
			while(Times[i] != tempEnd )
			{
         
				if(d1.getAppointed(i) == 1)
        {
         std::cout << "Appointment Slot : " << TimesOut[i] << " - " << TimesOut[i+1] << " is booked.\n";
         appCount++;
        }
        else
          std::cout << "Appointment Slot : " << TimesOut[i] << " - " << TimesOut[i+1] << " is open.\n";
          
          
			 i++;
			}
		 	
		}	

	}
  
  if(appCount > 0)
  {
    return false;
  }
  else
    return true;
}

//functiom overloading for setting appointments
//polymorphism
void Date::setTime(const TimeRange& t1,const Date& d1,bool flag) const
{
  //confirmation for appointment book counters
  int countBooking = 0;
  int countCanceling = 0;
  //string operations to ouput final booked day
  //logical conditions based on user input
  //to output string in '00:00' format
  std::string stringStart = "Month : " + std::to_string(d1.getMonth()) +", Day : " +std::to_string(d1.getDay())+ ", Time: ";
  
  if(t1.getBeginHour() < 10)
  {
    stringStart = stringStart.append('0'+std::to_string(t1.getBeginHour()));
  }
  else
  stringStart = stringStart.append(std::to_string(t1.getBeginHour()));
  if(0 == t1.getBeginMinute())
  {
    stringStart = stringStart.append(':'+std::to_string(t1.getBeginMinute()) + '0');
  }
  else
  	stringStart = stringStart.append(':'+std::to_string(t1.getBeginMinute()));
   
    stringStart = stringStart.append(" - " + std::to_string(t1.getEndHour()));

	  stringStart = stringStart.append(':'+std::to_string(t1.getEndMinute())+'0');
    
    for(int i = getAppointmentCount();i <= getAppointmentCount();i++)
    { //for booking
      if(flag == true)
      {
       for(int i = getAppointmentCount();i <= getAppointmentCount();i++)
       {
        d1.start[i] = stringStart;
       }
      }
      else
      {
         for(int j = 0;j<=getAppointmentCount();j++)
         {
          // for cancelling, swap algorithim
          //i built to remove appointments
           if(d1.start[j] == stringStart)
           {
            std::string temp1="";
            temp1 = d1.start[j];
            d1.start[j] = d1.start[j+1];
            d1.start[j+1] = temp1;
          }
         } //decrements total appointments
         d1.appointmentCount--;
         setAppointmentCount(appointmentCount);
      }  
    }

  //counter variables
  int hourCount = 0;
  int hourCount1 = 0;
  //turn int objects for time and date to strings for checking and output
	std::string tempStart = std::to_string(t1.getBeginHour());
  if(0 == t1.getBeginMinute())
  {
    tempStart = tempStart.append(std::to_string(t1.getBeginMinute()) + '0');
  }
  else
	tempStart = tempStart.append(std::to_string(t1.getBeginMinute()));
  //same as above int object to string for easy reading
	std::string tempEnd = std::to_string(t1.getEndHour());
	tempEnd = tempEnd.append(std::to_string(t1.getEndMinute())+'0');
  
    for(int z = 0; z <= 49; z++)
  { 
  	if(z%2 == 0)
		{
      //populationg hour array for position
			d1.hours[z] = std::to_string(hourCount);
			hourCount++;
		}
		if(z%2 == 1)
		{
      //populating hour array
			d1.hours[z] = std::to_string(hourCount1);
			hourCount1++;
		}
  }
  
  for(int k = 0; k <= 48; k++)
  {
    if(0 == k % 2)
    {
      d1.minutes[k] = "00";
    }
    else
    {
      d1.minutes[k] =  "30";
    }
  }
	std::string Times[SIZE+1];
  std::string TimesOut[SIZE+1];

	for(int j =0; j <=SIZE; j++)
	{  //for loop to match time slots with bool for checking
  // and output
		*(Times+j) = hours[j] + minutes[j];
    *(TimesOut+j) = hours[j]+":"+minutes[j];
	}

	for(int i =0; i <= SIZE; i++)
	{ //if condition for booking appointments
    
		if(Times[i] == tempStart && flag == true)
		{
      //if he timeslot hasnt benn booked
      if(d1.getAppointed(i) == 0)
      { 
        d1.appointmentCount++;
        setAppointmentCount(appointmentCount);
        std::cout << "Booking Appointment...\n";     
        setAppointed(i,true);
        i++;
      }
         
			while(Times[i] != tempEnd && flag == true)
			{
        //if time hasnt been booked
        if(d1.getAppointed(i) == 0)
        {
				 d1.setAppointed(i,true);
         countBooking++;
        }
        else
        //message for previously booked timeslots
        std::cout << "Appointment Time "<< TimesOut[i] << " - " << TimesOut[i+1] << "  has been previously booked.";
        i++;
			}	
		}
    //this is for cancelling works same way as above but the
    //inverse
   if(Times[i] == tempStart && flag == false)
		{ std::cout << d1.getDay() << " \n";
      std::cout << d1.getMonth() << " \n";
      std::cout << d1.getAppointed(i);
      //if he timeslot has been booked
      if(d1.getAppointed(i) == 1)
      {
        std::cout << "Canceling Appointment...\n";
        setAppointed(i,false);
        i++; 
      }
     
			while(Times[i] != tempEnd && flag == false)
			{
        //if time hasnt been canceled
        if(d1.getAppointed(i) == 1)
        {
				 setAppointed(i,false);
         countCanceling++;
        }
        else
        //message for previously booked timeslots
        std::cout << "\nAppointment Time "<< TimesOut[i] << " - " << TimesOut[i] << " doesnt exist.";
        i++;
			}
		}
  }
  if(countBooking > 0)
  {
    std::cout << "Open appointments booked\n";
  }
  if(countCanceling > 0)
  {
    std::cout << "Closed appointments cancelled.\n";
  }
}

void Date::print() const
{ 
  Date d1;
  //prints time slots when done
  std::string *hours = new std::string[48+1];
  std::string *minutes = new std::string[48+1];
  int hourCount = 0;
  int hourCount1 = 0;
  //for loops to allocate numbers to appointment slots
  for(int z = 0; z <= 48; z++)
  { 
  	if(z%2 == 0)
		{
			hours[z] = std::to_string(hourCount);
			hourCount++;
		}
		if(z%2 == 1)
		{
			hours[z] = std::to_string(hourCount1);
			hourCount1++;
		}
  }

  for(int k = 0; k <= 48; k++)
  {
    if(0 == k % 2)
    {
      minutes[k] = "00";
    }
    else
    {
      minutes[k] =  "30";
    }
  }
      //print portions for booked or open appointments
      //bool condition below if appointment is open or closed
      
      for(int i = 0; i <48; i++)
      {  
         if(getAppointed(i) == 0)
        {
        std::cout << "Appointment: " << (i+1) <<" - " << std::setfill('0') << std::setw(2) << hours[i] << ":" << minutes[i] << " - " << std::setfill('0') << std::setw(2) << hours[i+1] << ":" << minutes[i+1];
        std::cout << " : Open \n";
        }
       
      }
        std::cout << "\n ----------------- \n";
        delete[] hours;
        delete [] minutes;
        return;
}

bool Date::isWeekend(const Date& d1) const
{
	/** input validation for days & month to check if
  a weekend has been chosen **/
	if (d1.getMonth() == 9)
	{
		int *sept {new int[6]{11,12,18,19,25,26}}; //dynamic allocation for weekends in sep
		for(int i = 0; i < 6; i++)
		{
			if (d1.getDay() == sept[i])
			{
				
				std::cout << "\nThis is a weekend, try again!\n";
				delete[] sept;
		    return false;
			}
		}
    return true;
	}

	if (d1.getMonth() == 10)
	{
		int *oct{new int[9]{2,9,10,16,17,23,24,30,31}};//dynamic allocation for weekends in oct to check ==
		for(int j =0; j < 9; j++)
		{
			if(d1.getDay() == oct[j])
			{
				std::cout << "\nThis is a weekend, try again!\n";
					delete[] oct;
		      return false;
			}
		}
    return true;
	}

	if(d1.getMonth() == 11)
	{
		int *nov{new int[8]{6,7,13,14,20,21,27,28}};/** dynamic allocation for weekends in nov to check == **/
		for(int k = 0; k < 8; k++)
		{
			if(d1.getDay() == nov[k])
			{
				std::cout << "\nThis is a weekend, try again!\n";
					delete[] nov;
		      return false;
			}
		}
    return true;
	}

	if(getMonth() == 12)
	{
		//two days dont need array
      if(getDay() == 5 || getDay() == 6)
      {
        std::cout << "\nThis is a weekend \n";
        return false;
      }
      else
      return true;	
	}
  else
    return true;
	
}

//holiday error func with given dates
bool Date::isHoliday(const Date& d1,const Date& TRUTH_AND_REC, const Date& THANKSGIVING, const Date& REMEMBERANCE_DAY) const
{
  //function to check ifholiday using equal func
  if(equal(d1,TRUTH_AND_REC))
  {
    std::cout << "\nError, this is truth and reconciliation "
                 "day.\n";
    return false;
  }

  else if(equal(d1,THANKSGIVING))
  {
     std::cout << "\nError, this is Thanksgiving day.\n"; 
      return false;
  }

  else if(equal(d1,REMEMBERANCE_DAY))
  {
   std::cout << "\nError, this is rememberance day.\n"; 
   return false;
  }

  else
    return true;
}

//error checking function
bool Date::isValid(const Date& d1) const
{
  //function to check to see if day and month
  //choice are valid
    bool valid = true;
    //checks if the month is valid.
    if(d1.getMonth() < 9 || d1.getMonth() > 12)
    {
     valid = false;
    }
    //checks if the Date is valid.
    if(d1.getDay() < 1)
    {
     valid = false;
    }
    d1.getMonth();
     switch(d1.getMonth())
    { 
      case 9: //sept
            if(d1.getDay() > SEPT_DAYS || d1.getDay() < 8)
            {
                valid = false;
            }
            break;
        case 10: //oct
            if(d1.getDay() > OCT_DAYS)
            {
             valid = false;
            }
            break;
        case 11: //nov
            if(d1.getDay() > NOV_DAYS)
            {
             valid = false;
            }
            break;
        case 12: //dec
            if(d1.getDay() > DEC_DAYS )
            {
             valid = false;
            }
            break;
        //default case not require
    }
     
    if(valid == false)
    {
     std::cout << "\nThe Date you have asked is not "
                     "in the calendar's range!\n";
    }
    return valid;
}

bool equal(const Date& date1,const Date& date2)
{ //friend func to test equality, accesses private mem's
 
 return ((date1.Day == date2.Day) && (date1.Month == date2.Month));
}
void Date::output(std::ostream& out,const Date& d1)
{
  //output function for member variabkes
  out << "The appointment you have booked is on : ";
  out << d1.getDay() << "th day and ";
  out << d1.getMonth() << "th month.\n";
}

//input function for re-useability
void Date::input(const Date& d1)
{
   int day,month;
  
  do
  {
    std::cout << "Please make all entries in '00' format.\n";
    std::cout << "Please enter the month you are looking for : ";
    std::cin >> month;
    std::cout << "\nPlease enter the day you are looking for : ";
    std::cin >> day;
    setDay(day);
    setMonth(month);
  	if(std::cin.fail())
		{
      std::cout << "fail\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Error - try again.\n";
		}
    
  }while((!d1.isWeekend(d1) || !d1.isValid(d1) || !d1.isHoliday(d1,TRUTH_AND_REC,THANKSGIVING,REMEMBERANCE_DAY)));  
}
//destructor
Date::~Date()
{}