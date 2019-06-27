/*Casos de prueba
Tipo de alfombra|Metros a comprar|Total s/desc|Tipo de cliente|Descuento|Valor descuento|Total a pagar
      L                 10              60          F              20          12             48
      L                 1000           6000         N              15          900            5100
      L                500             3000         N              10          300            2700
      E                 10              40          F              20          8              32
      E                 2000           8000         N              15          1200           6800
      E                 1000           4000         N              10          400            3600
      S                 10              20          F              20           4             16
      S                 3000           6000         N              15          900            5100
      S                 1000           2000         N              10          200            1800



/*Programa creado para conocer precios antes del descuento, cantidad de dinero otorgada en el descuento y el total a pagar.
Creado por Erbey Arath Hernández Villarreal
Creado el 11 de septiembre del 2018*/

#include <iostream>
using namespace std;

int main()
{
    char cliente, alf;
    double total, precAlf, compra, desc, totalsd;

    //cout << "Inserte tipo de alfombra";
    cin >> alf;
    //cout << "Inserte metros a comprar";
    cin >> compra;

    if (alf == 'L'){
        precAlf = 6;
    total = precAlf*compra;
        totalsd = precAlf*compra;
    //cout << "Tipo de cliente";
    cin >> cliente;
    if (cliente == 'F'){
        desc = total*.20;
        total = total-desc;
    cout << totalsd << endl;
    cout << desc << endl;
    cout << total << endl;}
    if (cliente == 'N')
        if (total>=2000&&total<5000){
            desc = total*.10;
            total = total-desc;
    cout << desc << endl;
    cout << total << endl;}
    if (total>=5000){
        desc = total*.15;
            total = total-desc;
        cout << totalsd << endl;
    cout << desc << endl;
    cout << total << endl;}}

    if (alf == 'E'){
        precAlf = 4;
    total = precAlf*compra;
        totalsd = precAlf*compra;
    //cout << "Tipo de cliente";
    cin >> cliente;
    if (cliente == 'F'){
        desc = total*.20;
        total = total-desc;
        cout << totalsd << endl;
    cout << desc << endl;
    cout << total << endl;}
    if (cliente == 'N')
        if (total>=2000&&total<5000){
            desc = total*.10;
            total = total-desc;
            cout << totalsd << endl;
    cout << desc << endl;
    cout << total << endl;}
    if (total>=5000){
        desc = total*.15;
            total = total-desc;
        cout << totalsd << endl;
    cout << desc << endl;
    cout << total << endl;}}

    if (alf == 'S'){
        precAlf = 2;
    total = precAlf*compra;
        totalsd = precAlf*compra;
    //cout << "Tipo de cliente";
    cin >> cliente;
    if (cliente == 'F'){
        desc = total*.20;
        total = total-desc;
        cout << totalsd << endl;
    cout << desc << endl;
    cout << total << endl;}
    if (cliente == 'N')
        if (total>=2000&&total<5000){
            desc = total*.10;
            total = total-desc;
            cout << totalsd << endl;
    cout << desc << endl;
    cout << total << endl;}
    if (total>=5000){
        desc = total*.15;
            total = total-desc;
        cout << totalsd << endl;
    cout << desc << endl;
    cout << total << endl;}}

    return 0;
}
