/*
    EXAMEN SEGUNDO PARCIAL
    ERBEY ARATH HERNANDEZ VILLARREAL
    A00825343
*/

#include <iostream>

using namespace std;

enum Note {Re0, Fa, La, Si, Re};
enum N64B {A, CUp, CRight, CDown, CLeft};


class ICoded
{
public:
    virtual string getCode() = 0;
    virtual bool operator==(ICoded* other) = 0;
    virtual bool operator!=(ICoded* other) = 0;
};


class AbstractCodedSequence
{
protected:
    unsigned length;
public:
    AbstractCodedSequence(unsigned _length): length(_length){}

    unsigned getLength()
    {
        return length;
    }

    virtual ICoded* operator[](unsigned index) = 0;

    virtual bool operator==(AbstractCodedSequence& other)
    {
        //TODO
        return (getLength() == other.getLength());
    }
};


class OcarinaNote : public ICoded
{
private:
    Note note;
public:
    OcarinaNote(){}

    OcarinaNote(Note _note): note(_note){}

    string getCode()
    {
        switch(note)
        {
            case Re0: return "A";
            case Fa: return "CDown";
            case La: return "CRight";
            case Si: return "CLeft";
            case Re: return "CUp";
            default: return "Error";
        }
    }

     bool operator==(ICoded* other)
    {
        return (getCode() == other -> getCode());
    }

    bool operator!=(ICoded* other)
    {
        return (getCode() != other -> getCode());
    }
};


class OcarinaScore : public AbstractCodedSequence
{
friend std::ostream& operator<<(std::ostream& os, OcarinaScore& ocarinaScore);

private:
    string title;
    string composer;
    OcarinaNote* notes;
public:
    OcarinaScore(string _title, string _composer, unsigned _length, OcarinaNote _notes[]):
        title(_title), composer(_composer), AbstractCodedSequence(_length)
    {
        //TODO
        notes = _notes;
        title = _title;
        composer = _composer;
        length = _length;
    }

    ~OcarinaScore()
    {
        delete[] notes;
        //TODO
    }

    OcarinaNote* operator[](unsigned index)
    {
        //TODO
        if (index < length)
        {
           return &notes[index];
        }

        return NULL;
    }
};


std::ostream& operator<<(std::ostream& os, OcarinaScore& ocarinaScore)
{
    //TODO
    for(int i = 0; i < ocarinaScore.getLength(); i++)
    {
        os << ocarinaScore.operator[](i);
    }

    return os;
}


class N64Button : public ICoded
{
private:
    N64B button;
public:
    N64Button(){}

    N64Button(N64B _button): button(_button){}

    string getCode()
    {
        switch(button){
            case A: return "A";
            case CUp: return "CUp";
            case CDown: return "CDown";
            case CLeft: return "CLeft";
            case CRight: return "CRight";
            default: return "Error";
        }
    }

    bool operator==(ICoded* other)
    {
        //TODO
        return (getCode() == other -> getCode());
    }

    bool operator!=(ICoded* other)
    {
        //TODO
        return (getCode() != other -> getCode());
    }
};


class N64ButtonSequence : public AbstractCodedSequence
{
friend std::ostream& operator<<(std::ostream& os, N64ButtonSequence& n64Sequence);

private:
    N64Button* sequence;
public:
    N64ButtonSequence(unsigned _length, N64Button _sequence[]): AbstractCodedSequence(_length)
    {
        //TODO
        length = _length;
        sequence = _sequence;
    }

    ~N64ButtonSequence()
    {
        delete[] sequence;
        //TODO
    }

    ICoded* operator[](unsigned index)
    {
        //TODO
        if(index < length)
        {
            return &sequence[index];
        }

        return NULL;
    }

    N64ButtonSequence& operator+(N64Button& b)
    {
        //TODO
        N64Button* Auxiliar = new N64Button[length+1];

        for(int i = 0; i < length; i++)
        {
            Auxiliar[i] = sequence[i];
        }

        delete[] sequence;

        length++;
        Auxiliar[length] = b;
        sequence = Auxiliar;

        return *this;
    }
};

std::ostream& operator<<(std::ostream& os, N64ButtonSequence& n64Sequence)
{
    //TODO
    for(int i = 0; i < n64Sequence.length; i++)
    {
        os << n64Sequence.operator[](i);
    }

    return os;
}

int main()
{
    bool grades[12];
    fill_n(grades, 12, false);

    /* Completa la clase OcarinaNote y OcarinaScore. La primera hereda públicamente de la interfaz ICoded y la segunda
     * de la clase abstracta AbstractCodedSequence. Verifícalas para asegurarte de que implementas lo necesario. */

    OcarinaNote re0 = OcarinaNote(Re0);
    OcarinaNote re = OcarinaNote(Re);

    OcarinaNote notes[] = {re0, re,
                           OcarinaNote(Si), OcarinaNote(La),
                           OcarinaNote(Si), OcarinaNote(La)};

    OcarinaScore minuetOfForest("Minuet of Forest", "Koji Kondo", 6, notes);

    //Test 1
    grades[0] = (minuetOfForest.getLength() == 6);

    /* Asegúrate de que la implementación del operador [] sea correcta en OcarinaScore. Recuerda que regresa un puntero.*/

    //Test 2
    grades[1] = (*minuetOfForest[0] == &re0);

    //Test 3
    grades[2] = (*minuetOfForest[5] != &re);

    /* Completa la sobrecarga del operador[] para AbstractCodedSequence, de manera que pudas comparar dos
     * OcarinaScore y determinar si son iguales con base en su longitud y código de cada elemento */

    OcarinaScore unknown("", "", 6, notes);

    //Test 4
    grades[3] = (unknown == minuetOfForest);

    /* Sobrecarga el operador de << con una función amiga para habilitar la impresión de un OcarinaScore en
     * consola a través de cout */

    // cout << minuetOfForest; //Imprime Re0 Re Si La Si La

    //Test 5
    grades[4] = true; //Si imprime correctamente

    /* Implementar la clase N64Button, que hereda públicamente de la interfaz ICoded.
     * Debe tener un constructor vacío y otro que tenga como parámetro un enumerador N64B.*/

    N64Button a(A);
    N64Button cUp(CUp);
    N64Button cLeft(CLeft);
    N64Button cRight(CRight);

    //Test 6
    grades[5] = (cUp.getCode() == "CUp");

    /* Sobrecargar el operador de == y != (igualdad y desigualdad) para completar los requisitos
     * de la interfaz ICoded. Debiste implementarlos también para OcarinaNote. La implementación es similar. */

    //Test 7
    grades[6] = (a == &a);

    //Test8
    grades[7] = (a != &cLeft);

    /* Implementar la clase N64ButtonSequence que hereda públicamente de la clase abstracta AbstractButtonSequence*/

    N64Button buttons[] = {a, cUp, cLeft, cRight};
    N64ButtonSequence minuetOfForestInN64(4, buttons);

    //Test 9
    grades[8] = (minuetOfForestInN64.getLength() == 4);

    /* Sobrecargar el operador de << con una función amiga para habilitar la impresión de una secuencia de botones
     * del Nintendo 64 en consola a través de cout */

    //cout << minuetOfForestInN64; //Imprime A CUp CLeft CRight

    //Test 10
    grades[9] = true; //Si imprime correctamente

    /* Sobrecargar el operador de + para N64ButtonSequence, de manera que se pueda añadir un botón a la secuencia.
     * El resultado es una secuencia con un botón añadido. Hint: Hay que alojar en memoria un nuevo arreglo... */

    N64Button cleft(CLeft);
    N64Button cright(CRight);

    minuetOfForestInN64 + cleft + cright;

    //Test 11
    grades[10] = (minuetOfForestInN64.getLength() == 6);

    //cout << minuetOfForestInN64; //Imprime A CUp CLeft CRight CLeft CRight

    /* Comparar la secuencia de botones con la partitura de ocarina para saber si se activa la canción */

    //Test 12
    grades[11] = (minuetOfForestInN64 == minuetOfForest);


    /*Felicidades, si la implementación es correcta, ahora te puedes teletransportar al Templo del Bosque
     * en Zelda: Ocarina of Time ¡Arriba la Trifuerza! */

    double grade = 0;
    for(int i = 0; i < 12; i++)
    {
        grade += grades[i] * (100.0/12.0);
        cout << i+1 << ". " << grades[i] << endl;
    }
    cout << "Calificación: " << grade << endl;

    return 0;
}
