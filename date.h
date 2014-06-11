/* 
 * File:   date.h
 * Author: y2l1
 *
 * Created on June 9, 2014, 12:55 PM
 */

#ifndef DATE_H
#define	DATE_H
typedef struct
{
 unsigned short int day;
 unsigned short int month;
 unsigned short int year;
}Date;

 bool isCorrectDate(Date);
 bool yearIsLeap(unsigned short int);
 bool inBetween(unsigned short int, unsigned short int, unsigned short int);
#endif	/* DATE_H */

