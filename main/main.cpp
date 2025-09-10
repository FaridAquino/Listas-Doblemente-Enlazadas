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
      auto new_nodo = new Nodo<T>(dato);
      new_nodo->next = sentinela->next;
      new_nodo->preview = sentinela;
      sentinela->next->prev = new_nodo;
      sentinela->next = new_nodo;

    }  

    void push_back(T dato){
      auto new_nodo =new Nodo<T>(dato);
      new_nodo->preview = sentinela->preview;
      new_nodo->next = sentinela;
      sentinela->preview->next = new_nodo;
      sentinela->preview = new_nodo;
    }  

    T pop_front() {
        if (sentinela->next == sentinela) {
            throw("La lista esta vacia");
        }
        Nodo<T>* first_nodo = sentinela->next;
        Nodo<T>* temp = first_nodo->next;
        sentinela->next = temp;
        temp->preview = sentinela;
        delete first_nodo;
        return sentinela;
    }

    T pop_back() {
        if (sentinela->next == sentinela) {
            throw("La lista esta vacia");
        }
        Nodo<T>* lastnode = sentinela->preview;
        Nodo<T>* temp = lastnode->preview;
        sentinela->preview = temp;
        temp->next = sentinela;
        delete lastnode;
        return sentinela;
    }

    void insert(T nuevo_dato, int index) {
        auto new_nodo = new Nodo<T>(nuevo_dato);
        Nodo<T>* temp = sentinela;
        for (int i = 0; i < index; i++) {
            if (temp == sentinela) {
                cout << "Index no válido" << endl;
                break;
            }
            if (i == index-1) {
                Nodo<T>* temp2 = temp->next;
                temp->next = new_nodo;
                new_nodo->preview = temp;
                new_nodo->next = temp2;
                temp2->preview = new_nodo;
                break;
            }
            temp = temp->next;
        }
    } //Derek

    void remove(int index) {
        Nodo<T>* temp = sentinela->next;
        for (int i = 0; i <= index; i++) {
            if (temp == sentinela) {
                cout << "Index no válido" << endl;
                break;
            }
            if (i == index) {
                Nodo<T>* temp2 = temp->next;
                temp->preview->next = temp2;
                temp2->preview = temp->preview;
                delete temp;
                break;
            }
            temp = temp->next;
        }
    }

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
