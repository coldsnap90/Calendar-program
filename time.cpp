#include "time.hpp"



//constructors
TimeRange::TimeRange(){};
TimeRange::TimeRange(int newBeginHour,int newBeginMinute,int newEndHour,int newEndMinute) : 
beginHour(newBeginHour), beginMinute(newBeginMinute), endHour(newEndHour), endMinute(newEndMinute){};

//getters
int TimeRange::getBeginHour() const
{
 return beginHour;
}
int TimeRange::getBeginMinute() const
{
 return beginMinute;
}
int TimeRange::getEndHour() const
{
 return endHour;
}
int TimeRange::getEndMinute() const
{
  return endMinute;
}

//setters
void TimeRange::setBeginHour(const int &newBeginHour)
{
 beginHour = newBeginHour;
}

void TimeRange::setBeginMinute(const int &newBeginMinute)
{
  beginMinute = newBeginMinute;
}

void TimeRange::setEndHour(const int &newEndHour) 
{
  endHour = newEndHour;
}

void TimeRange::setEndMinute(const int &newEndMinute) 
{
  endMinute = newEndMinute;
}

//input func for reusabiliy
void TimeRange::input(const TimeRange& t1) 
{ 
     int startHour,startMin,endHour,endMin;
   do{
    std::cout << "Please enter the Start Hour in '00' format, then the start minute in '00' format, and repeat for end hour and end minute.\n";
    std::cin >> startHour;
    std::cin >> startMin;
    std::cin >> endHour;
    std::cin >> endMin;
    setBeginHour(startHour);
    setBeginMinute(startMin);
    setEndHour(endHour);
    setEndMinute(endMin);
    if(std::cin.fail())
		{
      std::cout << "fail\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Error - try again.\n";
		}
  }while(false == t1.isValid(t1));

}
//output using osstream
void TimeRange::output(std::ostream& out) const
{
  //outputs time member functions
  out << std::setfill('0');
  out << "Your appointment is at " << std::setw(2) << getBeginHour() << ":" << std::setw(2) <<  getBeginMinute() << " until " << std::setw(2) << getEndHour() <<":"<< std::setw(2) << getEndMinute() <<"\n";
}


//checks for valid time entry in multiple cases
bool TimeRange::isValid(const TimeRange& t1) const
{
  
  if(t1.getBeginHour() > t1.getEndHour())
  {
    return false; 
  }
  else if(t1.getBeginHour() < 0 || t1.getEndHour() > 24)
  {
    return false;
  }

  else if((t1.getBeginHour() == t1.getEndHour()) &&(t1.getBeginMinute() == t1.getEndMinute()))
  {
    std::cout << "Warning, cannot book duplicates!\n ";
    return false;
  }

  else if((t1.getBeginMinute() % 3 == 0) && (t1.getEndMinute() % 3== 0))
  {
    return true;
  }
  
  else
    std::cout << "Your input is invalid! please try again\n";
    return false; 
  
}