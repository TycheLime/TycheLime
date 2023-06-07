//
// Created by 15428 on 6/6/2023.
//
#include <iostream>
#include <cstring>

template<typename T>
class Var {
private:
    T value;

public:
    Var(const T& value) : value(value) {}

    const T& getValue() const {
        return value;
    }

    template<typename U>
    typename std::enable_if<!std::is_same<T, U>::value, Var<T>&>::type operator=(const U& other) {
        std::cout << "Invalid assignment!" << std::endl;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Var<T>& var) {
        os << var.value;
        return os;
    }
};

template<>
class Var<std::string> {
private:
    std::string value;

public:
    Var(const std::string& value) : value(value) {}

    const std::string& getValue() const {
        return value;
    }

    // 重载 << 运算符，使得可以直接打印 Var<std::string> 对象
    friend std::ostream& operator<<(std::ostream& os, const Var<std::string>& var) {
        os << var.value;
        return os;
    }
};

// 特化 Var 类模板的版本，用于处理字符数组类型
template<size_t N>
class Var<char[N]> {
private:
    char value[N];

public:
    Var(const char(&value)[N]) {
        std::memcpy(this->value, value, N * sizeof(char));
    }

    const char* getValue() const {
        return value;
    }

    // 重载 << 运算符，使得可以直接打印 Var<char[N]> 对象
    friend std::ostream& operator<<(std::ostream& os, const Var<char[N]>& var) {
        os << var.value;
        return os;
    }
};

// 特化 Var 类模板的版本，用于处理 C 风格字符串类型
template<>
class Var<const char*> {
private:
    const char* value;

public:
    Var(const char* value) : value(value) {}

    const char* getValue() const {
        return value;
    }

    // 重载 << 运算符，使得可以直接打印 Var<const char*> 对象
    friend std::ostream& operator<<(std::ostream& os, const Var<const char*>& var) {
        os << var.value;
        return os;
    }
};

template <typename T>
        Var<T> make_var(const T& value) {
    return Var<T>(value);
}

Var<const char*> make_var(const char* value) {
    return Var<const char*>(value);
}

// 用户定义字面量，用于整数类型
Var<int> operator"" _var(unsigned long long value) {
    return make_var(static_cast<int>(value));
}

// 用户定义字面量，用于字符串类型
Var<const char*> operator"" _var(const char* value, std::size_t) {
    return make_var(value);
}
