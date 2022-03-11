#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cstddef>
#include "time.hpp"
#ifndef DATE_HPP_
#define DATE_HPP_

//consts for days in momth
const int SEPT_DAYS = 30;
const int OCT_DAYS = 31;
const int NOV_DAYS = 30;
const int DEC_DAYS = 9;
const int SIZE = 48;
//const string arrays
const std::string stringDays[5] ={"Monday","Tuesday","Wednesday","Thursday","Friday"};
const std::string stringMonths[4] = {"September","October","November","December"};

class TimeRange;    
class Date
{
  public:
  //constructors
    Date();
    Date(int newDay,int newMonth);
    //getters
    int getDay() const;
    int getMonth() const;
    bool getAppointed(int i) const;
    int getTime() const;
    friend std::ostream& getBooked(std::ostream& out,const Date& d1);
    int getAppointmentCount() const;

    //setters
    void setAppointed(const int &n,const bool &flag) const;
    std::string getStart(const int& i) const;
    
    void setDay(const int &newDay);
    void setMonth(const int &newMonth);
    void setTime(const TimeRange& t1,const Date& d1,bool flag) const;
    bool setTime(const TimeRange& t1,const Date& d1) const;
    void setAppointmentCount(const int &newCount) const;

    //various member funcs, and ones for pt 2
    void print() const;
    bool isValid(const Date& d1) const;
    bool isHoliday(const Date& d1,const Date& TRUTH_AND_REC, const Date& THANKSGIVING, const Date& REMEMBERANCE_DAY) const;
    bool isWeekend(const Date& d1) const;
    friend bool equal(const Date& date1,const Date& date2);
    void output(std::ostream& out,const Date& d1);
    void input(const Date& d1);
    ~Date();
  
  private:
  //member vars
    mutable int Day;
    mutable int Month;
    mutable bool appointed[SIZE] ={0};
    mutable int appointmentCount = 0;
    mutable std::string hours[SIZE+1];
    mutable std::string minutes[SIZE+1];
    mutable std::string start[50];
    mutable std::string end[50];
  
};
//holiday dates
const Date TRUTH_AND_REC(30,9);
const Date THANKSGIVING(10,11);
const Date REMEMBERANCE_DAY(11,11);

#endif

