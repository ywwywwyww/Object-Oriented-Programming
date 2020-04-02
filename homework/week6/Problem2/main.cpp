#include <iostream> // cout, endl
#include <cstring> // strlen , strcpy
using namespace std;
class BugFix {
  int len_;
  char* data_;
 public:
  BugFix(const char *str) :
      len_{int(strlen(str))}, data_{new char[len_ + 1]} {
    strcpy(data_, str);
  }
  /**
   * The copy constructor
   * @param bug_fix
   */
  BugFix(const BugFix &bug_fix) :
      len_{bug_fix.len_}, data_{new char[len_ + 1]} {
    strcpy(data_, bug_fix.data_);
  }
  /**
   * The overloaded assignment operator
   * @param bug_fix
   * @return
   */
  BugFix &operator =(const BugFix& bug_fix) {
    len_ = bug_fix.len_;
    delete[] data_;
    data_ = new char[len_ + 1];
    strcpy(data_, bug_fix.data_);
    return *this;
  }
  /**
   * The move constructor
   * @param bug_fix
   */
  BugFix(BugFix&& bug_fix) :
      len_{bug_fix.len_}, data_{bug_fix.data_} {
    bug_fix.data_ = nullptr;
  }
  ~BugFix() {
    delete[] data_;
  }
  void show() {
    cout << data_ << endl;
  }
};
void test(BugFix str1) {
  str1.show(); // 2
  BugFix str2{"tsinghua"};
  str2.show(); // 3
  str2 = str1;
  str2.show(); // 4
}
int main () {
  BugFix str1{"2020"};
  str1.show(); // 1
  test(str1);
  str1.show(); // 5
  BugFix str2 = move(str1);
  str2.show(); // 6
  cout << "finish" << endl;
  return 0;
}