- 👋 Hi, I’m @TycheLime
- 👀 I’m interested in ...
- 🌱 I’m currently learning ...
- 💞️ I’m looking to collaborate on ...
- 📫 How to reach me ...

<!---
TycheLime/TycheLime is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->

an abstract class of number implements;

#include <iostream>
#include <limits>

class number{
public:
    virtual ~number(){}

    virtual number* clone() const =0;

    virtual number* add(const number& other) const =0;
    virtual number* sub(const number& other) const =0;
    virtual number* mul(const number& other) const =0;
    virtual number* div(const number& other) const =0;

};

class Int:public number{
private:
    int value;
public:
    Int(int value):value(value){}

    number* clone() const override{
        return new Int(value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Int& anInt){
        os<<anInt.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Int& anInt) {
        is >> anInt.value;
        return is;
    }

    operator int() const{
        return value;
    }

    number *add(const number& other) const override{
        const Int& otherInt =  dynamic_cast<const Int&>(other);
        return new Int(value+otherInt.value);
    }

    number* sub(const number& other) const override{
        const Int& otherInt = dynamic_cast<const Int&>(other);
        return new Int(value-otherInt.value);
    }

    virtual number* mul(const number& other) const override{
        const Int& otherInt = dynamic_cast<const Int&>(other);
        return new Int(value*otherInt.value);
    }
    virtual number* div(const number& other) const override{
        const Int& otherInt = dynamic_cast<const Int&>(other);
        if (otherInt.value != 0) {
            return new Int(value / otherInt.value);
        }
        throw std::runtime_error("Division by zero");
    }
};

class Float:public number{
private:
    int value;
public:
    Float(int value):value(value){}

    number* clone() const override{
        return new Int(value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Float& anFloat){
        os<<anFloat.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Float& anFloat) {
        is >> anFloat.value;
        return is;
    }

    number *add(const number& other) const override{
        const Float& otherFloat =  dynamic_cast<const Float&>(other);
        return new Float(value+otherFloat.value);
    }

    number* sub(const number& other) const override{
        const Float& otherFloat = dynamic_cast<const Float&>(other);
        return new Float(value-otherFloat.value);
    }

    virtual number* mul(const number& other) const override{
        const Float& otherFloat = dynamic_cast<const Float&>(other);
        return new Float(value*otherFloat.value);
    }
    virtual number* div(const number& other) const override{
        const Float& otherFloat = dynamic_cast<const Float&>(other);
        if (otherFloat.value != 0) {
            return new Float(value / otherFloat.value);
        }
        throw std::runtime_error("Division by zero");
    }
};

class Int8:number{
private:
    char value;
public:
    Int8(char value):value(value){}

    number* clone() const override{
        return new Int8(value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Int8& anInt){
        os<<static_cast<int>(anInt);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Int8& anInt) {
        is >> anInt.value;
        return is;
    }

    operator int() const{
        return static_cast<int>(value);
    }

    Int8& operator=(char newValue) {
        if (newValue > std::numeric_limits<char>::max() || newValue < std::numeric_limits<char>::min()) {
            throw std::overflow_error("Overflow occurred.");
        }
        value = newValue;
        return *this;
    }

    Int8 operator+(const Int8& other) const {
        int result = static_cast<int>(value) + static_cast<int>(other.value);
        if (result > std::numeric_limits<char>::max() || result < std::numeric_limits<char>::min()) {
            throw std::overflow_error("Overflow occurred.");
        }
        return Int8(static_cast<char>(result));
    }

    number *add(const number& other) const override{
        const Int8& otherInt =  dynamic_cast<const Int8&>(other);
        return new Int8(value + otherInt.value);
    }

    number* sub(const number& other) const override{
        const Int8& otherInt = dynamic_cast<const Int8&>(other);
        return new Int8(value - otherInt.value);
    }

    virtual number* mul(const number& other) const override{
        const Int8& otherInt = dynamic_cast<const Int8&>(other);
        return new Int8(value * otherInt.value);
    }

    virtual number* div(const number& other) const override{
        const Int8& otherInt = dynamic_cast<const Int8&>(other);
        if (otherInt.value != 0) {
            return new Int8(value / otherInt.value);
        }
        throw std::runtime_error("Division by zero");
    }
};

class Uint8:number{
private:
    unsigned char value;
public:
    Uint8(unsigned char value):value(value){}

    number* clone() const override{
        return new Int(value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Uint8& anInt){
        os<<anInt.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Uint8& anInt) {
        is >> anInt.value;
        return is;
    }

    operator int () const{
        std::cout<<"used";
        return value;
    }


    number *add(const number& other) const override{
        const Uint8& otherInt =  dynamic_cast<const Uint8&>(other);
        return new Int(value+otherInt.value);
    }

    number* sub(const number& other) const override{
        const Uint8& otherInt = dynamic_cast<const Uint8&>(other);
        return new Int(value-otherInt.value);
    }

    virtual number* mul(const number& other) const override{
        const Uint8& otherInt = dynamic_cast<const Uint8&>(other);
        return new Int(value*otherInt.value);
    }
    virtual number* div(const number& other) const override{
        const Uint8& otherInt = dynamic_cast<const Uint8&>(other);
        if (otherInt.value != 0) {
            return new Int(value / otherInt.value);
        }
        throw std::runtime_error("Division by zero");
    }
};

class Int16:number {
private:
    short value;
public:
    Int16(short value) : value(value) {}

    number *clone() const override {
        return new Int16(value);
    }

    friend std::ostream &operator<<(std::ostream &os, const Int16 &anInt) {
        os << anInt.value;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Int16 &anInt) {
        is >> anInt.value;
        return is;
    }

    operator short() const {
        return value;
    }

    number *add(const number &other) const override {
        const Int16 &otherInt = dynamic_cast<const Int16 &>(other);
        return new Int16(value + otherInt.value);
    }

    number *sub(const number &other) const override {
        const Int16 &otherInt = dynamic_cast<const Int16 &>(other);
        return new Int16(value - otherInt.value);
    }

    virtual number *mul(const number &other) const override {
        const Int16 &otherInt = dynamic_cast<const Int16 &>(other);
        return new Int16(value * otherInt.value);
    }

    virtual number *div(const number &other) const override {
        const Int16 &otherInt = dynamic_cast<const Int16 &>(other);
        if (otherInt.value != 0) {
            return new Int(value / otherInt.value);
        }
        throw std::runtime_error("Division by zero");
    }
};
