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

string convertirInttoString(int f){
    // proceso para convertir un entero en cadena
    stringstream ss;
    ss << f;
    string valor = ss.str();
    return valor;
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
    string cadena = "";
    string s;
    ifstream f( "datacuatro.txt" );
    if ( f.is_open() )
    {
        // getline( f, s );

        while( !f.eof() )
        {
            vector<string> v;

            split(s, ',', v);

            for (int i = 0; i < v.size(); ++i) {
                // cout << v[i];
                if(i == 0){
                    suma = suma + convertirStringToInt(v[i])  ;
                    cout << suma << endl;
                }
            }
            // cout << endl;
            //cout << s << endl;
            getline( f, s );
        }
    }else{
        cout << "Error de apertura del archivo." << endl;
    }

    string presenta = "El valor de la fila es " + convertirInttoString(suma) + " en base al valor de la fila se afirma que resultado es: "  + cadena + "\n";
    cout << presenta;
    //cout << "La suma de los datos es: " << suma << endl;

    return 0;
}
