#pragma once

#include <iostream>

template <typename T> class Array 
{
protected:
    T* m_array;
    int m_size;       // number of elements currently in array
    int m_capacity;   // max number before expanding
    int m_growth;     // next growth size (2, 4, 8, ...)

    void Expand() {
        // Expand capacity based on increasing growth factor
        m_growth = (m_growth == 0) ? 2 : m_growth * 2;
        m_capacity += m_growth;

        T* newArray = new T[m_capacity];
        for (int i = 0; i < m_size; i++) {
            newArray[i] = m_array[i];
        }
        delete[] m_array;
        m_array = newArray;
    }

public:
    Array(int capacity = 2)
        : m_size(0), m_capacity(capacity), m_growth(0) {
        m_array = new T[m_capacity];
    }

    virtual ~Array() {
        delete[] m_array;
    }

    int GetSize() const { return m_size; }
    int GetCapacity() const { return m_capacity; }

    virtual void Push(const T& value) = 0; // pure virtual
    T& operator[](int index) { return m_array[index]; }
    const T& operator[](int index) const { return m_array[index]; }
};

