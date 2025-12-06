#include <iostream>
#include <stdexcept>
#include "stack.h"
#include "queue.h"

int main() {
  stack<int> st(5);

  std::cout << "start stack пустой=" << st.isEmpty() << " size=" << st.size() << "\n";

  std::cout << "\n5 элемов: 10, 20, 30, 40, 50\n";
  for (int i = 1; i <= 5; ++i) {
    int val = i * 10;
    std::cout << "пуш(" << val << ") ";
    st.push(val);
    std::cout << "топ=" << st.top() << " сайз=" << st.size() << "\n";
  }

  std::cout << "\nпробую запушить 60 (должно оверфлоу)\n";
  try {
    st.push(60);
  } catch (const std::overflow_error& e) {
    std::cout << "оверфлоу " << e.what() << "\n";
  }

  std::cout << "\nвыгребаю всё из стека по одному\n";
  while (!st.isEmpty()) {
    std::cout << "перед поп топ=" << st.top() << " сайз=" << st.size() << "\n";
    int x = st.pop();
    std::cout << "попнул " << x << " сайз=" << st.size() << "\n";
  }

  std::cout << "\nчекаю поп с пустого стека (предикт андерфлоу)\n";
  try {
    st.pop();
  } catch (const std::underflow_error& e) {
    std::cout << "словил андерфлоу " << e.what() << "\n";
  }

  std::cout << std::endl;

  queue<int> q(5);

  std::cout << "старт куэуе пустая=" << q.isEmpty() << " сайз=" << q.size() << "\n";

  std::cout << "\nкидаю в куеуэ 100, 200, 300\n";
  q.enqueue(100);
  std::cout << "после пуш(100) сайз=" << q.size() << "\n";
  q.enqueue(200);
  std::cout << "после пуш(200) сайз=" << q.size() << "\n";
  q.enqueue(300);
  std::cout << "после пуш(300) сайз=" << q.size() << "\n";

  std::cout << "\nделаю два попа (должно 100 и 200)\n";
  int v1 = q.dequeue();
  std::cout << "pop " << v1 << " сайз=" << q.size() << "\n";
  int v2 = q.dequeue();
  std::cout << "pop " << v2 << " сайз=" << q.size() << "\n";

  std::cout << "\nтуда-сюда\n";
  q.enqueue(400);
  std::cout << "пуш(400) сайз=" << q.size() << "\n";
  int v3 = q.dequeue();
  std::cout << "поп" << v3 << " сайз=" << q.size() << "\n";
  q.enqueue(500);
  std::cout << "пуш(500) сайз=" << q.size() << "\n";

  std::cout << "\nдоедаю куеуе до конца\n";
  while (!q.isEmpty()) {
    int x = q.dequeue();
    std::cout << "поп " << x << " сайз=" << q.size() << "\n";
  }

  std::cout << "\nчек pop с пустой куеуе (андерфлоу)\n";
  try {
    q.dequeue();
  } catch (const std::underflow_error& e) {
    std::cout << "эмпти " << e.what() << "\n";
  }

  return 0;
}
