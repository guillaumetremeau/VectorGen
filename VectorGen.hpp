#include <iostream>

template <typename T>
class VectorGen
{
private:
    int capacite;
    int taille;
    T * tab;
public:
    VectorGen(int = 10);
    int capacity() const;
    int size() const;
    void pop_back();
    void push_back(const T &);
    ~VectorGen();
    const T &operator[](int) const;
    VectorGen &operator=(const VectorGen&);
};

template <typename T>
VectorGen<T>::VectorGen(int capa) : capacite(capa), taille(0) {
    tab = new T[capacite];
}

template <typename T>
int VectorGen<T>::capacity() const {
    return capacite;
}

template <typename T>
int VectorGen<T>::size() const {
    return taille;
}

template <typename T>
void VectorGen<T>::pop_back(){
    --taille;
}

template <typename T>
void VectorGen<T>::push_back(const T & el){
    tab[taille] = el;
    ++taille;
}

template <typename T>
VectorGen<T>::~VectorGen(){
    delete tab;
}
