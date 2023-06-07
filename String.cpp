//
// Created by 15428 on 6/6/2023.
//

#include <cstring>
#include <iostream>

class String{
private:
    char *base;
    int length;
public:

    String(){
        length = 0;
        base = new char [length+1];
        base[0] = '\0';
    }

    String(const char* str){
        length = std::strlen(str);
        base = new char [length+1];
        std::strcpy(base,str);
    }

    ~String(){
        delete base;
    }

    int getLength(){
        return length;
    }

    char charAt(int index) {
        if (index >= 0 and index <= length) {
            return base[index];
        }
        return '\0';
    }

    String operator+(const String& other) const {
        int newLength = length + other.length;
        char* newData = new char[newLength + 1];
        strcpy(newData, base);
        std::strcat(newData, other.base);
        String result(newData);
        delete[] newData;
        return result;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] base;
            length = other.length;
            base = new char[length + 1];
            strcpy(base, other.base);
        }
        return *this;
    }

    String& operator+=(const char* str) {
        int strLength = strlen(str);
        int newLength = length + strLength;
        char* newData = new char[newLength + 1];
        strcpy(newData, base);
        strcat(newData, str);
        delete[] base;
        base = newData;
        length = newLength;
        return *this;
    }


    String& operator+=(const String& other) {
        int newLength = length + other.length;
        char* newData = new char[newLength + 1];
        strcpy(newData, base);
        strcat(newData, other.base);
        delete[] base;
        base = newData;
        length = newLength;
        return *this;
    }


    // 全局函数重载 +=
    friend String operator+(String lhs, const String& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend String operator+(String lhs, const char* rhs) {
        lhs += rhs;
        return lhs;

    }
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.base;
        return os;
    }

};