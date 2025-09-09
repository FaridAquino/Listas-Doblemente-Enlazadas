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

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}