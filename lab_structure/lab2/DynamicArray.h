#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstdint>

class DynamicArray {
private:
    float* data;
    std::int64_t size = -1;
    std::int64_t capacity;

public:
    DynamicArray();
    DynamicArray(std::int64_t capacity);
    DynamicArray(DynamicArray& other);
    ~DynamicArray();

    void push_back(float x);
    void push_front(float val);
    float front();
    float back();
    void insert(std::int64_t idx, float val);
    void delete_idx(std::int64_t idx);
    void erase_after(std::int64_t idx);
    void increase_capacity(std::int64_t newCapacity);
    void decrease_capacity(std::int64_t newCapacity);
    float add(std::int64_t idx1, std::int64_t idx2);
    float max();
    float min();
    void clear();
    void reinitialize();
    void printData();

    float operator[](std::int64_t idx);
    float operator()();

    bool isEmpty() const {
        return size == -1;
    }

    std::int64_t length() const {
        if (isEmpty()) {
            return 0;
        } else {
            return size + 1;
        }
    }

};

#endif // DYNAMICARRAY_H
