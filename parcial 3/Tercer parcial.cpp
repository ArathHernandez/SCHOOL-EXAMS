/*
    Erbey Arath Hern�ndez Villarreal
    A00825343
    Tercer examen parcial 03/05/2019
*/
#include <iostream>
#include <exception>


class UniquenessException : public std::exception
{
//TODO
    public:
    const char* what() const throw(){
    return "UniquenessException";}
};

class EmptinessException : public std::exception
{
//TODO
    public:
    const char* what() const throw(){
    return "EmptinessException";}
};

class OutOfBoundsException : public std::exception
{
//TODO
    public:
    const char* what() const throw(){
    return "OutOfBoundsException";}
};


class AbstractCompareable
{
public:
    virtual int value()=0;

    bool operator<(AbstractCompareable* other)
    {
        //TODO
        return (other -> value() > value());
    }

    bool operator>(AbstractCompareable* other)
    {
        //TODO
        return (other -> value() < value());
    }

    bool operator==(AbstractCompareable* other)
    {
        //TODO
        return (other -> value() == value());
    }

    bool operator!=(AbstractCompareable* other)
    {
        //TODO}
        return (other -> value() != value());
    }
};

class FunkoPop : public AbstractCompareable
{
private:
    std::string name;
    unsigned awesomeness;

public:
    FunkoPop(std::string _name = "Generic", unsigned _awesomeness = 0):
        name(_name), awesomeness(_awesomeness){}

        //TODO
        //Implementar todas las funciones puras y virtuales
        //para hacer de FunkoPop una clase concreta y poderla instanciar

        int value()
        {
            return awesomeness;
        }
};

template<typename T> class MinMaxSet
{
private:
    T* contents;
    unsigned size;
    unsigned count;
    unsigned minPos;
    unsigned maxPos;

    void grow()
    {
        //TODO
        //Si ha llegado al límite, incrementar el tamaño al doble
        //Ejemplo, si tengo un tamaño de 4 y un conteo de 3 elementos
        //al llegar el cuarto se debe expandir a un tamaño de 8
        //con lo cual me queda un tamaño de 8 y un conteo de 4

            size = size*2;
            T *arr = new T[size];

            for(int i = 0; i < count ; i++)
            {
                arr[i] = contents[i];
            }

            delete[] contents;
            contents = arr;
    }

public:
    MinMaxSet(): size(0), count(0), minPos(0), maxPos(0){
    contents = new T[1];}

    ~MinMaxSet()
    {
        //TODO
        delete[] contents;
    }

    T operator[](unsigned index)
    {
        //TODO
        if(index < size)
            return contents[index];

        throw OutOfBoundsException();
    }

    int operator[](T element)
    {
        //TODO
        //Regresa la posición del element, si existe en el conjunto
        //De lo contrario, regresa -1
        for(int i = 0; i < count; i++)
        {
            if(contents[i] == element)
                return i;
        }

        return -1;
    }

    void add(T element)
    {
        //TODO
        //Si el valor del elemento es repetido, regresa una UniquenessException
        //Si no, y hay suficiente espacio, se almacena
        //Si no hay suficiente espacio, crece en memoria de acuerdo a la
        //política de alojamiento de grow() y después lo almacena
        int a = 0;

        for(int i = 0; i < size; i++)
        {
            if(contents[i].value() > contents[minPos].value())
                minPos = i;

            if(contents[i].value() < contents[maxPos].value())
                maxPos = i;
        }

        if(size != 0){
        for(int i = 0 ; i < size; i++){
            if(contents[i].value() == element.value())
                    throw UniquenessException();
            }
        if(count < size)
        {
            contents[count] = element;
            count++;
        }
        else
        {
            grow();
            contents[count] = element;
            count++;
        }
        }
    else
    {
        size = 1;
        count = 1;
        contents[0] = element;
    }
    }

    unsigned getSize()
    {
        //TODO
        return size;
        return 0;
    }

    unsigned getCount()
    {
        //TODO
        return count;
        return 0;
    }

    T min()
    {
        //TODO
        //Si no hay elementos existentes, regresa una EmptinessException
        //Si hay, regresa el mínimo
        if(getCount() == 0)
            throw EmptinessException();

        return contents[maxPos];
    }

    T max()
    {
        //TODO
        //Si no hay elementos existentes, regresa una EmptinessException
        //Si hay, regresa el máximo
        if(getCount() == 0)
            throw EmptinessException();

        return contents[minPos];
    }
};


int main()
{
    bool grades[12];
    std::fill_n(grades, 12, false);

    FunkoPop pixelJason("Pixel Jason", 10);
    FunkoPop redRanger("Red Ranger", 7);
    FunkoPop leono("Leono", 8);
    FunkoPop megaman("Megaman", 11);
    FunkoPop pinhead("Pinhead", 9);
    FunkoPop pennywise("Pennywise", 10);

    grades[0] = (redRanger.value() == 7);
    grades[1] = (pixelJason == &pennywise);
    grades[2] = (!(leono > &pinhead));

    MinMaxSet<FunkoPop> minMaxSet;

    grades[3] = (minMaxSet.getSize() == minMaxSet.getCount());

    try
    {
        minMaxSet.max();
    }
    catch(EmptinessException& ee)
    {
        grades[4] = true;
        std::cout << ee.what() << std::endl;
    }

    minMaxSet.add(pixelJason);
    grades[5] = (minMaxSet.getSize() == 1 && minMaxSet.getCount() == 1);

    minMaxSet.add(redRanger);
    minMaxSet.add(leono);
    grades[6] = (minMaxSet.getCount() == 3 && minMaxSet.getSize() == 4);

    minMaxSet.add(megaman);
    minMaxSet.add(pinhead);
    grades[7] = (minMaxSet.getCount() == 5 && minMaxSet.getSize() == 8);

    grades[8] = (minMaxSet.min().value() == 7);
    grades[9] = (minMaxSet.max().value() == 11);

    try
    {
        minMaxSet.add(pennywise);
    }
    catch(UniquenessException& ue)
    {
        grades[10] = true;
        std::cout << ue.what() << std::endl;
    }

    try
    {
        minMaxSet[13];
    }
    catch(OutOfBoundsException& obe)
    {
        grades[11] = true;
        std::cout << obe.what() << std::endl;
    }

    double grade = 0;
    for(int i = 0; i < 12; i++)
    {
        grade += grades[i] * (100.0/12.0);
        std::cout << i+1 << ". " << grades[i] << std::endl;
    }
    std::cout << "Calificación: " << grade << std::endl;

    return 0;
}
