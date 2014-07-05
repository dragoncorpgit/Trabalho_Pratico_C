#include "date.h"

bool isCorrectDate(Date date)
{
 short int maxDay=0;
 switch(date.month)
 {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12: maxDay=31;
         break;
  case 4:
  case 6:
  case 9:
  case 11: maxDay=30;
         break;
  case 2: if(yearIsLeap(date.year))
          {
           maxDay=29;
          }
          else
          {
           maxDay=28;
          }
        break;
 }
 if(date.year>0 && inBetween(date.month,1,12) && inBetween(date.day,1,maxDay))
 {
  return true;
 }
 else
 {
     printf("\nData invalida");
  return false;
 }
}

bool yearIsLeap(short unsigned int year)
{
 if(year%4==0)
 {
  return true;
 }
 else
 {
  return false;
 }
}

bool inBetween(short unsigned int number, short unsigned int minValue, short unsigned int maxValue)
{
 if(number<=maxValue&&number>=minValue)
 {
  return true;
 }
 else
 {
  return false;
 }
}

Date fillDate(short unsigned int day, short unsigned int month, short unsigned int year)
{
 Date date;
 date.day=day;
 date.month=month;
 date.year=year;
 return date;
}