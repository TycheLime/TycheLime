//
// Created by 15428 on 7/6/2023.
//

#include <iostream>

// 通用版本的 print() 函数模板
template <typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

// 重载版本的 print() 函数，用于打印 C 风格字符串（const char*）
void print(const char* value) {
    std::cout << value << std::endl;
}

// 递归展开参数包并依次打印每个值
template <typename... Args>
void print(const Args&... args) {
    (print(args), ...);
}
