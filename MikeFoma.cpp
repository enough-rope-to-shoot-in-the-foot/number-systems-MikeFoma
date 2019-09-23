
#include <iostream>

#include <assert.h>

using namespace std;


// Можете использовать.
static const char * alphabet = "0123456789ABCDEF";



std::string to_system( int num, int base )
{
    assert( base >= 2 && base <= 16 );

    string out;

//    if( base == 10 )
//        return out=to_string(num);

    int abs_num = abs(num);

    // Вместо этого, написать свою реализацию.
    //throw runtime_error("to_system Not implemented.");
    do {
       out = alphabet[abs_num % base] + out;
       abs_num = abs_num / base;
    } while ( abs_num > 0);

    if( num < 0 )
        out = to_string(~(stoi(out))+1);

    cout << num << " in " << base << " = " << out << endl;

    return out;
}


int main()
{
    //cout << "1 in 2th system == " << to_system(1, 2) << endl;

    assert( to_system(10, 10) == "10" );
    assert( to_system(-10, 10) == "-10" );
    assert( to_system(10, 2) == "1010" );
    //assert( to_system(10, 3) == "11" );
    assert( to_system(10, 3) == "101" );
    //assert( to_system(11, 3) == "12" );
    assert( to_system(11, 3) == "102" );
    //assert( to_system(-12, 3) == "-20" );
    assert( to_system(-12, 3) == "-110" );
    assert( to_system(42, 16) == "2A" );
    // to_system(12, 17)  -- ошибка по assert.

    return 0;
}
