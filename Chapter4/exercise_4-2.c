/*
 * Exercise 4-2: Extend atof to handle scientific notation of the form 123.45e-6
 * where a floating-point number may be followed be e or E and an optionally
 * signed exponent.
 *
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome.
 */

#include "exercise_4-2.h"

#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, signE;

    for(i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 + val + (s[i] - '0');
            if (s[i] == '.')
            i++;
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    signE = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (power; isdigit(s[i]); i++)
      power *=  (signE < 0 ?  10.0 : 0.10) ;

    return sign * val / power;
}


