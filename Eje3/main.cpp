#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int convertirStringToInt(string v){
    // proceso para convertir un cadena en entero

    int i;
    std::istringstream(v) >> i;
    return i;
}


void split(const string& s, char c,
           vector<string>& v) {
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}

int main()
{
    int suma = 0;
    string s;
    ifstream f( "datados.txt" );
    if ( f.is_open() )
    {
        // getline( f, s );

        while( !f.eof() )
        {
            vector<string> v;

            split(s, '|', v);

            for (int i = 0; i < v.size(); ++i) {
                // cout << v[i];
                suma = suma + convertirStringToInt(v[i]);
            }
            // cout << endl;
            //cout << s << endl;
            getline( f, s );
        }
    }else{
        cout << "Error de apertura del archivo." << endl;
    }

    cout << "La suma de los datos es: " << suma << endl;

    return 0;
}
