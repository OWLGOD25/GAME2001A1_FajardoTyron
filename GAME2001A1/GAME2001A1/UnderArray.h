#pragma once

#include "Array.h"

template <typename T> class UnderArray : public Array<T> {
public:
    UnderArray(int capacity = 2) : Array<T>(capacity) {}

    void Push(const T& value) override {
        if (this->m_size >= this->m_capacity) {
            this->Expand();
        }
        this->m_array[this->m_size++] = value;
    }
};


