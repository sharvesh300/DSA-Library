#ifndef VECTOR_HPP
#define VECTOR_HPP

template<class T>
class Vector{

    public:
    //constructor and destructor 
    Vector(int initSize = 0);
    Vector(const Vector<T> &rhs);
    ~Vector();

    void reserve(int newCapacity);
    void resize(int newSize);

    //meta data
    bool empty() const;
    int getSize() const;
    int getCapacity()const;

    //important functions
    void push_back(const T& element);
    void pop_back();
    T& back();

    //iterators
    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin() {
        return &objects[0];
    };
    iterator end() {
        return &objects[size];
    };
    const_iterator begin()const {
        return &objects[0];
    };
    const_iterator end() const {
        return &objects[size];
    };

    //operator
    T& operator[](int index);
    const T& operator[](int index)const;

     Vector& operator=(const Vector& rhs) {
        if(this != &rhs){
            delete[] objects;
            size = rhs.getSize();
            capacity = rhs.getCapacity();
            objects = new T[capacity];
            for (int i = 0; i < size; i++){
                objects[i] = rhs[i];
            }
        }
        return *this;
    };

    private:
    T* objects;
    int size;
    int capacity;
    int SPARSE_CAPACITY = 16;

};

template<class T>
Vector<T>::Vector(const Vector<T> &rhs) {
    operator=(rhs);
}


template<class T>
T& Vector<T>::operator[](int index){
    return objects[index];
}

template<class T>
const T& Vector<T>::operator[](int index)const{
    return objects[index];
}


template<class T>
void Vector<T>::push_back(const T& element){
    if(size == capacity){
        reserve(2*size+1);
    }
    objects[size++] = element;
}

template<class T>
void Vector<T>::pop_back(){
    this->size--;
}

template<class T>
T& Vector<T>::back(){
    return objects[size-1];
}



template<class T>
int Vector<T>::getSize()const{
    return this->size;
}

template<class T>
bool Vector<T>::empty()const{
    return this->size == 0;
}

template<class T>
int Vector<T>::getCapacity()const{
    return this->capacity;
}

template<class T>
void Vector<T>::resize(int newSize){
    if(newSize > capacity){
        reserve(newSize*2+1);
    }
    size = newSize;
}

template<class T>
void Vector<T>::reserve(int newCapacity){
    if(newCapacity < size) return;
    T* oldArray = objects;
    objects = new T[newCapacity];
    for(int i = 0; i < size;i++){
        objects[i] = oldArray[i];
    }
    capacity = newCapacity;


    delete[] oldArray;
}

template<class T>
Vector<T>::Vector(int initSize){
    this->size = initSize;
    this->capacity = initSize + SPARSE_CAPACITY;
    this->objects = new T[capacity]; 
}

template<class T>
Vector<T>::~Vector(){
    delete[] objects;
}




#endif 