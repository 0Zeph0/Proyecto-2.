#ifndef COLA_H
#define COLA_H

template <class T>
struct Nodo{
    T elemento;
    Nodo *siguiente;
};

template <class T>
class Cola{
    int numElementos;
    Nodo<T> *inicio;
    Nodo<T> *final;

public:
    Cola(){
        numElementos = 0;
    }
    ~Cola(){
        while (numElementos != 0) pop();
    }
    void push(const T& elem){
        Nodo<T>* aux = new Nodo<T>;
        aux->elemento = elem;
        if (numElementos == 0) {
            inicio = aux;
        }
        else {
            final->siguiente = aux;
        }
        final = aux;
        numElementos++;
    }
    T pop(){
        Nodo<T>* aux = inicio;
        inicio = inicio->siguiente;
        numElementos--;
        return aux->elemento;
    }
    T consultar() const{
        return inicio->elemento;
    }
    bool vacia() const{
        return numElementos == 0;
    }
    int size() const{
        return numElementos;
    }
};
#endif // COLA_H
