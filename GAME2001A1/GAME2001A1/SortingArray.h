#pragma once

#include "Array.h"

template <typename T>
class SortingArray : public Array<T> 
{
private:
    bool m_allowDuplicates;
public:
    SortingArray(int capacity = 2, bool allowDuplicates = true)
        : Array<T>(capacity), m_allowDuplicates(allowDuplicates) {}

    void Push(const T& value) override
    {
        // Prevent duplicates if flag is off
        if (!m_allowDuplicates) {
            for (int i = 0; i < this->m_size; i++) {
                if (this->m_array[i] == value) return;
            }
        }

        if (this->m_size >= this->m_capacity) {
            this->Expand();
        }

        // Insert in sorted order
        int i = this->m_size - 1;
        while (i >= 0 && this->m_array[i] > value) {
            this->m_array[i + 1] = this->m_array[i];
            i--;
        }
        this->m_array[i + 1] = value;
        this->m_size++;
    }
};


