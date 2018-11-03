#ifndef SIMPLELIST_H
#define SIMPLELIST_H

template< class T > struct nodoS
{
    T data;// tipo de dato que se va a almacenar
     //inicializadoe de punteros

     nodoS *next = nullptr;

    nodoS *prev = nullptr;

    nodoS(T data){
        this->data= data;

};


template < typename T>
class SimpleList
  {

      int length;
      nodoS<T> *primero;
      public :
          SimpleList(){// ponemos a escuchar el primer nodo a null para saber que esté vacio
                          primero = nullptr;
                          }

};

 void add(T data){
        nodoS<T> *nuevo = new nodoS<T>(data);
        if (this->primero == nullptr)
            {
            primero = nuevo;
        }

        else{

            nodoS<T> *temp;
            temp = primero;
            while(temp->next)
            {
                temp = temp->next;
            }
            temp->next = nuevo;
            nuevo->prev = temp;
        }

        this->length ++;
    }

     T getData(int pos)
     {
        nodoS<T> *temp = primero;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }

        return temp->data;
    }
    /**
     * inserta  un nuevo dato en la posición que  se desee
     * \param pos
     * \param newData
     *
     *
     */

    void setData(int pos, T newData) {
        nodoS<T> *temp = primero;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
        temp->data = newData;
    }
    /**

    retorna el tamaño de la lista.
     */

       int getLength(){
        return this->length;
    }

    bool isEmpty(){
        return this->length == 0;
    }
/**
 *
 * \param pos
 * Elimina el nodo  a  que le corresponde esa posición
 */

    void deleteNode(int pos){
        nodoS<T> *aux = primero;
        if(pos == 0){
            primero = aux->next;
            free(aux);
        } else {
            nodoS<T> * prev = aux;
            for (int i = 0; i < this->length; i++) {
                if (i == pos) {
                    prev->next = aux->next;
                    free(aux);
                    break;
                }
                prev = aux;
                aux = aux->next;
            }
        }
        this->length--;
    }

} ;// se cierra la clase.

////////////////////////////////// me cago en Roy
#endif // SIMPLELIST_H
