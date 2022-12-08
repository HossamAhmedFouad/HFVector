
#ifndef _HFVECTOR_H
#define _HFVECTOR_H

#include<bits/stdc++.h>
using namespace std;
template<class T>
class HFVector {
typedef T* iterator;
private:
    int vector_size{0},vector_capacity;
    T* data;
public:
                            // Constructors and Big 4
    HFVector (int);			// Initialize by specific capacity
                            // No content is added, size = 0
                            // Assign a default size value
    HFVector (T*, int  n );	// Initialize by n items from array
    HFVector (const HFVector&);	// Initialize with a copy
    ~HFVector();				// Delete allocated memory
    HFVector &operator=(const HFVector&);  // Copy assignment
    HFVector &operator=(HFVector&&); // Move assignment

    // Access operations
    T& operator[](int);     // Access item by reference
                            // Throw an exception if out of range

    // Modifying operations
    int push_back(T);       // Add item to end of vec & return # of items
                            // Increase capacity if needed
    T pop_back();           // Remove and return last element in vec
    void erase(iterator);        // Remove item at iterator
                                              // Throw exception if invalid iter
    void erase(iterator,iterator); // Remove items between
                                                                // iterator 1 <= iterator 2 otherwise do nothing
                                                                // Throw exception if any iterator outside range
    void clear();                   // Delete all vector content
    void insert(iterator, T);       // Insert item at iterator
                                                // Throw exception if invalid

// Iterators 		                            // Supports *, + and ++ operations at least
                                                // Can use: typedef T* iterator
                                                // Or u can use std::iterator so you can
                                                // apply STL algorithms on HFVector
    iterator begin();	                        // Return an iterator (T*)
    iterator end();                          // Return an iterator (T*)

// Comparison operations
    bool operator==(const HFVector<T>&); // Return true if ==
    bool operator< (const HFVector<T>&); // Compares item by item
    // Return true if first different item in this is < in other

// Capacity operations
    int size() const;    // Return current size of vec
    int capacity() const; // Return size of current allocated array
    int resize();         // Relocate to bigger space
    bool empty();         // Return true if size is 0

// Friends
    friend ostream& operator << (ostream& out,HFVector<T>&vector){
        out<<"[";
        if(vector.empty()){
            out<<"]";
            return out;
        }
        for(int i=0;i<vector.size()-1;i++){
            out<<vector.data[i]<<", ";
        }
        out<<vector.data[vector.size()-1]<<"]";
        return out;
    };
};



#endif //_HFVECTOR_H
