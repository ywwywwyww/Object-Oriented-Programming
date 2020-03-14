#include <iostream>
#include <cstring>

class A {
 public:
  A(int i) : m_size_{i} {
    m_arr_ = new int[m_size_];
    memset(m_arr_, 0, m_size_ * sizeof(int));
    num_objects_++;
  }

  /**
   * Initializes the object with an existing array
   * @param array The existing array
   */
  A(const A &array)
      : m_size_{array.m_size_}, m_arr_{new int[array.m_size_]} {
    memcpy(m_arr_, array.m_arr_, sizeof(int) * m_size_);
    num_objects_++;
  }

  ~A() { delete[]m_arr_; }

  void set(int index, int value) {
    m_arr_[index] = value;
  }

  void print();

  static void printObjNum() {
    std::cerr << "There are now " << num_objects_ << " array objects." << std::endl;
  }

 private:
  int *m_arr_;
  int m_size_;
  static inline int num_objects_{0}; // Num of array objects
};

void A::print() {
  std::cout << "m_arr_: ";
  for (int i = 0; i < m_size_; ++i) {
    std::cout << " " << m_arr_[i];
  }
  std::cout << std::endl;
}

int main() {
  A::printObjNum();
  A a(5);
  A::printObjNum();
  A b = a;
  A::printObjNum();
  a.print();
  b.print();
  b.set(2, 10);
  b.print();
  a.print();
}