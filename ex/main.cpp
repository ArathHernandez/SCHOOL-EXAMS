/*Programa creado para conocer el precio de una canción según la clave insertada.
Creado por Erbey Arath Hernández Villarreal.
Creado el 07/09/2018*/

#include <iostream>

using namespace std;

int valor (char x)
{
    int precio;
    if (x == 'A')
        precio = 11;
    else
        if (x == 'B')
           precio = 14;
        else
            precio = -1;
return precio;
}
int main ()
{
    int precio;
    char clave;

//cout << Inserte una clave << endl;
cin >> clave;
precio= valor (clave);
    if (precio == -1)
        cout << "CLAVE INCORRECTA" << endl;
    else
    cout << precio << endl;

return 0;
}
