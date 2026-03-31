/* Compile with $ g++ -o hxd hxd.cpp
 * Demonstration of the hexadecimal dumper for the char[]
 * Project Crew™ 12/28/2025
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "hxd.hpp"

#define MYB     "\x5a\xed\x44\x7d\x3b\x39\xe5\x8b" \
                "\x04\xdb\xf7\x40\x61\x18\x42\x90" \
                "Lorem ipsum dolor si\x88""t amet, " \
                "conse\x8""ctet\x10""uer adi\x13""piscing el\xed""it."

int
main()
{
    unsigned char myb[] = MYB;

/* pass in the array of character */
    hxd(myb, sizeof(myb));
    
/* try print the array as raw */
    cout << "\n\n";
    cout << " string originale:\n\n";
    cout << "   " << myb << endl;
}