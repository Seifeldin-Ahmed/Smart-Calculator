/*
 * BIT_utils.h

 *
 *  Created on: Aug 24, 2022
 *      Author: Seif
 */

#ifndef LIB_BIT_UTILS_H_
#define LIB_BIT_UTILS_H_

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)   CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /* LIB_BIT_UTILS_H_ */





/*
 #define  x 5
 #define  y 4
 
 
#define conc(x,y)        conchelp(x,y)
conchelp(x,y)            x##y





1.        conc(x,y) >>>>> conchelp(x,y) >>>>>>>> conchelp(5,4) >>>>> 5##4 >>>> 54

*/


/*

 #define  x 5 
 #define  y 4
 
 #define conc(x,y)  x##y                        

int main()
{
	
	printf("%d",conc(x,y));
*/











