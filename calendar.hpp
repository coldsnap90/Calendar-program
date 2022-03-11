#include<iostream>
#include<string>
#include<iomanip>
#include<limits>
#include "time.hpp"
#include "date.hpp"
#include <cctype>
#ifndef CALENDAR_HPP_
#define CALENDAR_HPP_


//declared classes
class Date;
class TimeRange;

 class Calendar : public TimeRange, public Date
{
  public:
  //constructors
    Calendar();
    Calendar(int newBeginHour,int newBeginMinute,int newEndHour,int newEndMinute, int newDay,int newMonth);
    //member functions 
    bool book(const Date& date,const TimeRange& time);
    bool query(const Date& date,const TimeRange& time);
   //copys parent to child
    void copy(const Calendar& Cal,const Date& date);
    int getCopy() const;
    bool cancel(const Date& date, const TimeRange& time);
    //assignment operator
    Date& operator=(const Date& date);
    //input for book,cancel,query
    void input(TimeRange& T1,Date& D1,char entry);
    //menu
    void menu();
    
    //print functions
    void printFreeDays(Calendar& C1,Date& date);
    void printFreeTimeSlots(Calendar& C1,Date& date);
    void print(Date& date);
  
    //error and overloading
    bool isFull(const Date& date);
    friend std::ostream& operator <<(std::ostream& out, const Calendar& C1);
    ~Calendar();
    
  private:
   //date arrays
    Date CalendarDec[DEC_DAYS];
    Date CalendarNov[NOV_DAYS];
    Date CalendarOct[OCT_DAYS];
    Date CalendarSept[SEPT_DAYS];
    std::string e[50];
    std::string s[50];
    int appointments[4][31]={0};
    int appointmentCountCopy = 0;

};
#endif