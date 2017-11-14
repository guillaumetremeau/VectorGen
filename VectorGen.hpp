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
    const T operator[](int) const;
    VectorGen<T> operator=(const VectorGen&);

    //à Catch
    friend VectorGen operator+(const VectorGen &a, const VectorGen &b){
        VectorGen res(a.size()+b.size());
        if(res.capacity()){
            std::copy(a.tab, a.tab + a.size(),res.tab);
            std::copy(b.tab, b.tab + b.size(), res.tab + a.size());
            res.taille = a.size() + b.size();
        }
        return res;
    }
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
    if(taille >= capacite){
        T * oldTab = tab;
        capacite = 2*capacite;
        tab = new T[capacite*2];
        std::copy(oldTab, oldTab + taille, tab);
        delete [] oldTab;
    }
    tab[taille] = el;
    ++taille;
}

template <typename T>
VectorGen<T>::~VectorGen(){
    delete tab;
}

template <typename T>
const T VectorGen<T>::operator[](int index) const {
    if((index < 0) || (index >= capacite)){
        std::out_of_range e("index out of boundaries");
        throw e;
    }
    return tab[index];
}

template <typename T>
VectorGen<T> VectorGen<T>::operator=(const VectorGen &source){
    delete [] tab;
    taille = source.size();
    capacite = source.capacity();
    if(capacite){
        tab = new T[capacite];
        for(int i = 0; i++; i < taille){
            tab[i] = source[i];
        }
    }else tab = nullptr;
    return *this;
}
