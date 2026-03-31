#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

#define A 3                             // temp + A... - A
#define S 4                             // byte swap
#define W -1                            // temp xor 0xff (-1) = NOT temp

/* 8-bit bitwise rotate, should compile to a ror/rol (x86)
 * How we rotate before the std::bit in C++20 */
static inline uint8_t
lrot8 (uint8_t c, unsigned int n)
{
    const unsigned int mask = (CHAR_BIT*sizeof(c) - 1);

    // assert ( (c<=mask) &&"rotate by type width or more");
    n &= mask;                                  // o <= N
    return (c << n) | (c >> ( (-n) & mask) );   // do rotate
    /* flip the << shift >> to rotate the other way */
}