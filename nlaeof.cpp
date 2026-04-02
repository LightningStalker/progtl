/* No (or some number) new lines at end the file
 * Project Crew™ 3/28/2026
 */

#define PROGNAME    "nlaeof"

#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

void
usage()
{
    cerr << endl
         << "  " PROGNAME" adjusts the number of trailing newlines at end of "
               "the file" << endl
         << endl
         << "  use like:  $ " PROGNAME" FILE [NEWLINES_COUNT]" << endl
         << endl
         << "    No wildcards in FILE, one at a time." << endl
         << "    Optional NEWLINES_COUNT default to 0 if not given." << endl
         << endl
         << "  example:   $ " PROGNAME" hello.c 1" << endl
         << "    (make sure exactly 1 trailing newline at end of the file)" << endl
         << endl
         << "  Be VERY careful! No guarantees, use at your own risk." << endl
         << endl;
    exit(EXIT_FAILURE);
}


int
main(int argc, char* argv[])
{
    string filename;
    unsigned long int count{0}, desired{0}, size;
    char c;

    if(argc == 3)
    {
        try
        {
            filename = argv[1];
            desired  = stoi(argv[2]);
            if(desired > 100)
            {
                cerr << "ERROR: Do you really want "
                     << desired << " newlines?" << endl;
                usage();
            }
        }catch(invalid_argument& e)
        {
            cerr << "ERROR: argument 2 must be numeric." << endl;
            usage();
        }
    }else if(argc == 2)
    {
        try
        {
            filename = argv[1];
        }catch(invalid_argument& e)
        {
            cerr << "ERROR: file name exception." << endl;
            usage();
        }
    }else
    {
        cout << "ERROR: no args / too many args / wildcards" << endl;
        usage();
    }

    fstream file(filename, ios::in | ios::out | ios::binary | ios::ate);
    if (!file.is_open())
        std::cout << "failed to open " << filename << '\n';
    else
    {
        cout << PROGNAME": Looking at file \"" << filename << "\"..." << endl;
        file.seekg(-1, ios_base::cur);
        while(file.tellg() >= 0)
        {
            file.get(c);
            file.seekg(-2, ios_base::cur);
            if(c == 10)
            {
                count++;
            }else
            {
                break;
            }
        }
        cout << PROGNAME": Found " << count << " newlines at end of file" << endl;
        if(count != desired)
            cout << PROGNAME": Adjusting to " << desired << " newlines..." << endl;
        if(count < desired)
        {
            file.seekp(2, ios_base::cur);
            for(size = 0; size < desired; size++)
                file.put('\n');
        }else if(count > desired)
        {
            file.close();
            size = filesystem::file_size(filename);
            filesystem::resize_file( filename, size - (count - desired) );
        }else
        {
            cout << PROGNAME": Nothing to do." << endl;
        }
    }
}