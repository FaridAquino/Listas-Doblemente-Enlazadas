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
    Nodo<T>* head=nullptr;
public:
    T front(){} //Carlos

    T back(){} //Carlos

    void push_front(){}  //Carlos

    void push_baack(){}  //Carlos

    T pop_front(){}  //Derek

    T pop_back(){}  //Derek

    void insert(T, int){} //Derek

    void remove(int){} //Derek

    T operator[](){} //Farid

    bool empty(){} //Farid

    int size(){}  //Farid

    void clear(){}  //Farid

    void reverse(){} //Farid
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}