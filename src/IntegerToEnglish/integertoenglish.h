//=================================
// include guard
#ifndef __INTEGER_TO_ENGLISH_INCLUDED__
#define __INTEGER_TO_ENGLISH_INCLUDED__


//=================================
// forward declared dependencies

//=================================
// included dependencies
#include <string>
using namespace std;

class IntegerToEnglish
{
    public:
        // Takes any integer and turns it into its "english" equivilent
        string numberToWords(int num);
    private:
        // Takes the portion of the int <1000 and turns it into its "english" equivilant
        string hundredsToString(int num);
};

#endif