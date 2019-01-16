#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string s;
    ifstream f( "data.txt" );
    if ( f.is_open() )
    {
        // getline( f, s );

        while( !f.eof() )
        {
            getline( f, s );
            cout << s << endl;
        }
    }else{
        cout << "Error de apertura del archivo." << endl;
    }
    return 0;
}
