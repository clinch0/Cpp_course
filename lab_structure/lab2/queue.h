#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include <stdexcept>
#include <cstdint>

template <typename T>
class queue {
private:
  stack<T> s1;
  stack<T> s2;

public:
  explicit queue(std::int64_t maxSize): s1(maxSize), s2(maxSize) {}

  void enqueue(const T& x) {
    s1.push(x);
  }

  T dequeue() {
    if (s2.isEmpty()) {
      while (!s1.isEmpty()) {
        s2.push(s1.pop());
      }
    }

    if (s2.isEmpty()) {
      throw std::underflow_error("Queue is empty");
    }

    return s2.pop();
  }

  bool isEmpty() const {
    return s1.isEmpty() && s2.isEmpty();
  }

  std::int64_t size() const {
    return s1.size() + s2.size();
  }
};

#endif // QUEUE_H
