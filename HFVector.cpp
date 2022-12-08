#include "HFVector.h"
template<class T>
HFVector<T>::HFVector(int initial_capacity) {    // Initialize by a specific capacity
    vector_capacity = initial_capacity;
    vector_size = 0;
    data = new T[vector_capacity];
}
template<class T>
HFVector<T>::HFVector(T* arr,int n) {           // Initialize by elements from another vector
    vector_capacity = n;
    vector_size = n;
    data = new T[vector_capacity];
    for(int i=0;i<n;i++){
        data[i] = arr[i];
    }
}

template<class T>
HFVector<T>::HFVector(const HFVector<T> &other) {
    vector_capacity = other.vector_capacity;
    vector_size = other.vector_size;
    data = new T[vector_capacity];
    for(int i=0;i<vector_size;i++){
        data[i] = other.data[i];
    }
}

template<class T>
HFVector<T>::~HFVector() {   //Free allocated space to prevent memory leak
    delete[] data;
    data = nullptr;
}

template<class T>
HFVector<T>& HFVector<T>::operator=(const HFVector<T> &other){ //Copy Assignment Operator
    delete[] data;
    data = new T[other.vector_capacity];
    for(int i=0;i<other.size();i++){
        data[i] = other.data[i];
    }
    vector_capacity = other.vector_capacity;
    vector_size = other.vector_size;
    return *this;
}

template<class T>
HFVector<T>& HFVector<T>::operator=(HFVector<T> &&other){ // Move Assignment Operator
    if(this != &other){
        delete[]data;
        vector_size = other.size();
        vector_capacity = other.capacity();
        data = other.data;
        other.data = nullptr;
        other.vector_size = 0;
        other.vector_capacity = 0;
    }
    return *this;
}

template<class T>
T& HFVector<T>::operator[](int index) {  //Access Items of Vector
    try{
        if(index>=vector_size || index<0){
            throw exception();
        }
        return data[index];
    }catch (exception& e) {
        cout<<"Out of bound access"<<endl;
        return data[0];
    }

}

template<class T>
int HFVector<T>::push_back(T item) {   //Add an element to end of the vector and increase capacity of necessary
    if(this->vector_size< this->vector_capacity) {
        data[vector_size++] = item;
    }else{
        T* new_data = new T[this->vector_capacity * 2];
        for(int i=0;i<this->vector_size;i++){
            new_data[i] = data[i];
        }
        new_data[vector_size++] = item;
        this->vector_capacity*=2;
        delete[] data;
        data = new_data;
        new_data = nullptr;
    }
    return this->vector_size;
}

template<class T>
T HFVector<T>::pop_back() {   //Removes last element from vector and returns it
    return data[--vector_size];
}

template<class T>
void HFVector<T>::erase(iterator it) {  //Remove item at iterator
    try{
        int idx = it-begin();
        if(idx<0 || idx>=vector_size){
            throw exception();
        }
        for(;it!=end();it++){
            *it = *(it+1);
        }
        vector_size--;
    }catch (exception& e) {
        cout<<"Invalid Iterator!"<<endl;
    }


}

template<class T>
void HFVector<T>::erase(iterator it1, iterator it2) {  //Erase elements in range
    try{
        int idx1 = it1-begin();
        int idx2 = it2-begin();
        if(idx2<idx1 || idx1<0 || idx2<0 || idx1>=vector_size || idx2>=vector_size){
            throw exception();
        }
        int amount = (it2-begin()) - (it1-begin()) + 1;
        vector_size-=amount;
        for(int i = it1-begin();i<vector_size;i++){
            data[i]=data[i+amount];
        }
    }catch (exception& e){
        cout<<"Invalid use of iterators"<<endl;
    }

}

template<class T>
void HFVector<T>::clear() { //Clear all contents
    vector_size = 0;
}

template<class T>
void HFVector<T>::insert(iterator it, T val) { // Insert element at specific position
    try{

        int idx = it-begin();
        if(idx>=vector_size || idx<0){
            throw exception();
        }

        if(vector_size<vector_capacity){
            for(int i=vector_size;i>it-begin();i--){
                data[i]=data[i-1];
            }
            *it = val;
        }
        vector_size++;
    }catch (exception& e){
        cout<<"Invalid iterator position!"<<endl;
    }

}

template<class T>
T* HFVector<T>::begin() { //Return first position of data
   return data;
}

template<class T>
T* HFVector<T>::end() { //Return last block of data
    return data+vector_size;
}

template<class T>
bool HFVector<T>::operator==(const HFVector<T> &other) {  //Operator overloading of equal operator
    if(vector_size!=other.vector_size) return false;
    for(int i=0;i<vector_size;i++){
        if(data[i]!=other.data[i]) return false;
    }
    return true;
}

template<class T>
bool HFVector<T>::operator<(const HFVector<T> &other) { //Compare item by item to find lexicographically smaller vector
    int distance = min(vector_size,other.vector_size);
    for(int i=0;i<distance;i++){
        if(other.data[i]>data[i]) return true;
    }
    return false;
}

template<class T>
int HFVector<T>::size() const { //Returns vector size
    return vector_size;
}

template<class T>
int HFVector<T>::capacity() const { // Returns vector capacity
    return vector_capacity;
}

template<class T>
int HFVector<T>::resize() { //Resize current array to bigger memory
    T* newSpace = new T[vector_capacity*2];
    for(int i=0;i<vector_size;i++){
        newSpace[i] = data[i];
    }
    vector_capacity*=2;
    delete[] data;
    data = newSpace;
    newSpace = nullptr;
    return vector_capacity;
}


template<class T>
bool HFVector<T>::empty() { //Returns true if vector is empty
    return vector_size==0;
}





