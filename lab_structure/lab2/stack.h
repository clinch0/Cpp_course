#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <stdexcept>
#include <cstdint>

template <typename T>
class stack {
private:
  DynamicArray arr;
  std::int64_t maxSize;

public:
  explicit stack(std::int64_t maxSize): arr(), maxSize(maxSize) {}

  void push(const T& x) {
    if (size() >= maxSize) {
      throw std::overflow_error("Stack overflow");
    }

    arr.push_back(static_cast<float>(x));
  }

  T top() {
    if (arr.isEmpty()) {
      throw std::underflow_error("Stack is empty");
    }

    return static_cast<T>(arr.back());
  }

  T pop() {
    if (arr.isEmpty()) {
      throw std::underflow_error("Stack is empty");
    }

    T value = static_cast<T>(arr.back());
    arr.delete_idx(arr.length() - 1);

    return value;
  }

  bool isEmpty() const {
    return arr.isEmpty();
  }

  std::int64_t size() const {
    return arr.length();
  }
};

#endif // STACK_H
