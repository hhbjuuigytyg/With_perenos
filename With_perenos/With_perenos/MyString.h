#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* str;
    int length;

public:
    MyString() {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0';
    }

    MyString(int size) {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
    }

    MyString(const char* input) {
        length = strlen(input);
        str = new char[length + 1];
        strcpy_s(str, length + 1, input);
    }

    MyString(MyString&& other) {
        str = other.str;
        length = other.length;

        other.str = nullptr;
        other.length = 0;
    }

    MyString& operator=(MyString&& other) {
        if (this != &other) {
            delete[] str;
            str = other.str;
            length = other.length;
            other.str = nullptr;
            other.length = 0;
        }
        return *this;
    }

    ~MyString() {
        delete[] str;
    }

    void print() const {
        cout << str << endl;
    }

    void MyStrcpy(MyString& obj) {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, obj.str);
    }

    bool MyStrStr(const char* substr) {
        return strstr(str, substr) != nullptr;
    }

    int MyChr(char c) {
        for (int i = 0; i < length; i++) {
            if (str[i] == c)
                return i;
        }
        return -1;
    }

    int MyStrLen() const {
        return strlen(str);
    }

    void MyStrCat(MyString& b) {
        int newLen = length + b.length;
        char* temp = new char[newLen + 1];
        strcpy_s(temp, newLen + 1, str);
        strcat_s(temp, newLen + 1, b.str);

        delete[] str;
        str = temp;
        length = newLen;
    }

    void MyDelChr(char c) {
        int j = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] != c)
                str[j++] = str[i];
        }
        str[j] = '\0';
        length = strlen(str);
    }

    int MyStrCmp(MyString& b) const {
        int res = strcmp(str, b.str);
        if (res < 0) return -1;
        if (res > 0) return 1;
        return 0;
    }

    void input() {
        char buffer[1000];
        cout << "Line - ";
        cin.getline(buffer, 1000);

        delete[] str;
        length = strlen(buffer);
        str = new char[length + 1];
        strcpy_s(str, length + 1, buffer);
    }
};