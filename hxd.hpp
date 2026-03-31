/* hex dump
 * Project Crew™ 12/28/2025
 */

void
hxd(unsigned char * myb, unsigned long int bytec)
{  /* dumps contents of a char array */
    unsigned long int i, j;

    bytec--;

    cout << hex << setfill('0');
    i = 0;
    while(i < bytec)
    {      /* begin w/byte offset */
        cout << setw(8) << i << ":";
        for(j = 0; j < 4; j++)
        {  /* first half of hexi  */
            cout << ' ' << setw(2) << static_cast<uint16_t>(myb[i]);
            if (++i >= bytec) break;  // break if done
            cout << setw(2) << static_cast<uint16_t>(myb[i]);
            if (++i >= bytec) break;
        }  /* middle ...          */
        if (i >= bytec) break;
        cout << '.';
        for(j = 0; j < 4; j++)
        {  /* second half ...     */
            cout << setw(2) << static_cast<uint16_t>(myb[i]);
            if (++i >= bytec) break;
            cout << setw(2) << static_cast<uint16_t>(myb[i]) << ' ';
            if (++i >= bytec) break;
        }
        if (i >= bytec) break;
        cout << ' ';
        for (j = i - 16; j < i; j++)  // print ASCII at end
            {
                if (myb[j] >= ' ' && myb[j] < '~') cout << myb[j]
                ;else cout << '.';    // unprintable chars = '.'
            }
        cout << endl;
    }
/* last line is bit special */
    i = bytec % 16;
    if(i)  /* we have a partial line? */
    {
           /* ugly but we need to find how many to the ASCII area */
        for(j = 41 - (i * 2 + (i < 9 ? (i - 1) / 2 : i / 2)); j > 0; j--)
        {  /* equation only needs to be done one time anyway */
            cout << ' ';
        }
    }else
    {      /* hex area was full       */
        i = 16;
        cout << ' ';
    }      /* only need 1 more space  */
    for(j = bytec - i; j < bytec; j++)
    {      /* print last of the chars */
        if (myb[j] >= ' ' && myb[j] < '~') cout << myb[j]
        ;else cout << '.';        // unprintable = '.'
    }
}
/* end hexdump */