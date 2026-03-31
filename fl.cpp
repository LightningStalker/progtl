/* Compile with $ g++ -o fl fl.cpp
 * Project Crew™ 12/28/2025
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "fl.hpp"
#include "hxd.hpp"

//#define DBG     1
#define MYB     "Lorem ipsum dolor sit amet, " \
                "consectetuer adipiscing elit."

void
fl (unsigned char *myb, unsigned long int mybsize)
{
/* turn the string to unprintable junk chars */
    unsigned long int c;
    /* register */ uint8_t t;

    for(c = 0; c < mybsize - 1; c++)
    {
#ifdef DBG
        cout << c << ' ';
#endif
        t = myb[c];                     // take each char and ...
        t += A;                         // add (pretty obvious)
        t = lrot8(t, S);                // bitwise nybble swap
        t ^= W;                         // ...     NOT
        t -= A;                         // subtract
        myb[c] = t;                     // store back to array
    }
}

int
main()
{
    unsigned char myb[] = MYB;
    unsigned long int mybsize = sizeof(myb);

    fl(myb, mybsize);

/* take a lQQk at what we got */
    hxd(myb, mybsize);

    cout << "\n\n";
    cout << '"' << myb << '"' << endl;
}