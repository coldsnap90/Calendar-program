#include <iostream>
#include <string>
#include<iomanip>
#ifndef TIME_HPP_
#define TIME_HPP_


class date;
class TimeRange 
{
  //gives date access to private data of TimeRange
  friend class date;
  public:
    //default constructor
    TimeRange();
    //construcot
    TimeRange(int newBeginHour,int newBeginMinute,int newEndHour, int newEndMinute);
    //getters
    int getBeginHour() const;
    int getBeginMinute() const;
    int getEndHour() const;
    int getEndMinute() const;
    //setters
    void setBeginHour(const int &newBeginHour);
    void setBeginMinute(const int &newBeginMinute) ;
    void setEndHour(const int &newEndHour) ;
    void setEndMinute(const int &newEndMinute);
    
    //various mem funcs
  
    void input(const TimeRange& t1); 
    bool isValid(const TimeRange& t1) const;
    void print(const TimeRange& t1) const;
    bool error(const TimeRange& t1) const;
    void output(std::ostream &out) const;

  //mem vars
  private:
    mutable int beginHour;
    mutable int beginMinute;
    mutable int endHour;
    mutable int endMinute;

};
#endif