template <typename T>
string_map<T>::string_map(){
    this->raiz = new Nodo(nullptr);
    this->_size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave) {
    return *(this->nodoAt(clave)->definicion);
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo *actual = this->raiz;
    for(unsigned int i = 0; i < clave.length(); i++) {
        char proxChar = clave.at(i);
        Nodo* siguiente = actual->siguientes[proxChar];
        if(siguiente == nullptr) {
            return 0;
        }
        actual = siguiente;
    }
    
    return 1;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    return (*this)[clave];
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    return (*this)[clave];
}

template <typename T>
typename string_map<T>::Nodo* string_map<T>::nodoAt(const string& clave) {
    Nodo* actual = this->raiz;
    for(int i = 0; i < clave.length(); i++) {
        actual->siguientes[clave[i]];
    }

    return actual;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    if(clave.empty()) return;

    this->_size--;
    delete this->nodoAt(clave);
    this->erase(clave.substr(0, clave.size() - 1));
}

template <typename T>
int string_map<T>::size() const{
    return this->_size;
}

template <typename T>
bool string_map<T>::empty() const{
    return this->size() == 0;
}

template<typename T>
void string_map<T>::insert(const pair<string, T> & pair) {
    string k = pair.first;


    if(pNodo->definicion != nullptr) this->_size++;
    *pNodo->definicion = pair.second;
}

template<typename T>
string_map<T>::Nodo::Nodo(T* definicion) : definicion(definicion) {
    this->siguientes = vector<Nodo*>();
    for(char ch = 'a'; ch <= 'z'; ch++) {
        this->siguientes[ch] = nullptr;
    }
}