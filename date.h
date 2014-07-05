/* 
 * File:   date.h
 * Author: y2l1
 *
 * Created on June 9, 2014, 12:55 PM
 */

#ifndef DATE_H
#define	DATE_H
#include <stdbool.h>
 typedef struct
 {
  short unsigned int day;
  short unsigned int month;
  short unsigned int year;
 }Date;

 bool isCorrectDate(Date);
 bool yearIsLeap(short unsigned int);
 bool inBetween(short unsigned int, short unsigned int, short unsigned int);
#endif	/* DATE_H */

