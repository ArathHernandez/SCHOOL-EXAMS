#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void separator9000(string NombreDeArchivo)
{
    ifstream archivo;
    string texto;
    //ofstream archivo_salida ("c:\\batch\\procesado9000.txt")

    archivo.open(NombreDeArchivo.c_str(), ios::in);
    if(archivo.fail())
        {
            cout<<"No fue posible ejecutar el programa"<<endl;
            exit(1);
        }

    while(!archivo.eof())
        {
            getline(archivo, texto);
        }

    cout << texto << endl;

    archivo.close();
}

int main(int argc, const char* argv[])
{
    cout << "BONITO DIA BENDICIONES ERES ESPECIAL" << endl;

    for(int i = 0; i < argc; i++)
        {
            cout << argv[i] << endl;
        }

    string utilidad = argv[1];

    if(utilidad == "separator9000")
    {
        string nombreDelArchivo = argv[2];
        separator9000(nombreDelArchivo);
    }

    return 0;
}
