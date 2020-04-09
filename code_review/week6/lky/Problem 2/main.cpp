#include <iostream> // cout, endl 
#include <cstring> // strlen , strcpy 
using namespace std;
class BugFix {
    char* data_{NULL};
public:
    BugFix(const char* str) {
        data_ = new char[strlen(str) + 1];
        strcpy(data_, str);
    }
    BugFix(const BugFix& a);
    BugFix(BugFix&& a);
    BugFix& operator = (BugFix&);
    ~BugFix() {
        delete data_;
    }
    void show() {
        cout << data_ << endl;
    }
};
//copy constructor
BugFix::BugFix(const BugFix& OldOne) {
    if (data_ != NULL) delete[] data_;
    int len = strlen(OldOne.data_);
    data_ = new char[len + 1];
    strcpy(data_, OldOne.data_);
}
//move constructor
BugFix::BugFix(BugFix&& a){
    if (data_ != NULL) delete[] data_;
    data_ = a.data_;
    a.data_ = NULL;
}
//overloading of =
BugFix& BugFix::operator=(BugFix& OldOne){
    if (data_ != NULL) delete[] data_;
    int len = strlen(OldOne.data_);
    data_ = new char[len + 1];
    strcpy(data_, OldOne.data_);
    return *this;
}

void test(BugFix str1) {
    str1.show();
    BugFix str2{ "tsinghua" };
    str2.show();
    str2 = str1;
    str2.show();
}
int main() {
    BugFix str1{ "2020" };
    str1.show();
    test(str1);
    str1.show();
    BugFix str2 = move(str1);
    str2.show();
    cout << "finish" << endl;
    return 0;
}


