#include <iostream>

using  namespace std;

template <typename G>
struct Nodo {
    G dato;
    Nodo* next;
    Nodo* preview;
    explicit Nodo(G _dato) : dato(_dato), next(nullptr), preview(nullptr) {
    }
};
template <typename T>
class Lista {
private:
    Nodo<T>* sentinela=nullptr;
public:
    Lista() {
        sentinela= new Nodo<T>(T{});
        sentinela->next = sentinela;
        sentinela->preview = sentinela;
    }
    T front(){
      if(sentinela->next != sentinela){
	return sentinela->next->dato;
      }else{
	throw("La lista esta vacia");
      }
    }

    T back(){
      if(sentinela->next != sentinela){
       return sentinela->preview->dato;
      }else{
	throw("La lista esta vacia");
      }

    } 

    void push_front(T dato){
      Nodo<T>* new_nodo = new Nodo<T>(dato);
      
      new_nodo->next = sentinela->next;
      new_nodo->preview = sentinela;
      sentinela->next->prev = new_nodo;
      sentinela->next = new_nodo;

    }  

    void push_back(T dato){
      Nodo<T>* new_nodo =new Nodo<T>(dato);
      new_nodo->preview = sentinela->preview;
      new_nodo->next = sentinela;
      sentinela->preview->next = new_nodo;
      sentinela->preview = new_nodo;
    }  

    T pop_front(){}  //Derek

    T pop_back(){}  //Derek

    void insert(T, int){} //Derek

    void remove(int){} //Derek

    T operator[](int indice) {
        auto* p1=sentinela->next;

        int contador=0;
        while (contador<=indice+1 and p1!=sentinela) {
            p1=p1->next;
            contador++;
        }

        if (p1==sentinela) {
            throw out_of_range("Indice fuera de rango");
        }

        return p1->dato;

    }

    bool empty() {
        if (sentinela->next==sentinela) {
            return true;
        }

        return false;
    }

    int size() {
        int contador=0;
        Nodo<T>* p1=sentinela->next;

        while (p1!=sentinela) {
            p1=p1->next;
            contador++;
        }

        return contador;
    }

    void clear() {

        Nodo<T>* head=sentinela->next;

        while (head!=sentinela) {
            Nodo<T>* temp = head;
            head = head->next;
            delete temp;
        }

        sentinela->next = sentinela;
        sentinela->preview = sentinela;

    }

    void reverse() {
        Nodo<T>* actual = sentinela;

        do {
            Nodo<T>* temp = actual->next;
            actual->next = actual->preview;
            actual->preview = temp;

            actual = temp;


        } while (actual != sentinela);
    }

    Nodo<T>* getSentinela() {
        return sentinela;
    }
};

int main() {

    return 0;
}
