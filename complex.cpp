#include <iostream>
#include "number.cpp"

class Complex:number{
private:
    number* real;
    number* image;
public:
    Complex(number *real,number *image):real(real),image(image){}

    number* clone() const override{
        return new Complex(real,image);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << complex.real << "+"<<complex.image<<"i"<<std::endl;
        return os;
    }


    number *add(const number& other) const override{
        const Complex& otherComplex =  dynamic_cast<const Complex&>(other);
        number* resultReal = real->add(*otherComplex.real);
        number* resultImaginary = image->add(*otherComplex.image);
        return new Complex(resultReal, resultImaginary);
    }

    number* sub(const number& other) const override{
        const Complex& otherComplex =  dynamic_cast<const Complex&>(other);
        number* resultReal = real->sub(*otherComplex.real);
        number* resultImaginary = image->sub(*otherComplex.image);
        return new Complex(resultReal, resultImaginary);
    }

    virtual number* mul(const number& other) const override{
        const Complex& otherComplex =  dynamic_cast<const Complex&>(other);
        number* resultReal = real->mul(*otherComplex.real);
        number* resultImaginary = image->mul(*otherComplex.image);
        return new Complex(resultReal, resultImaginary);
    }
    virtual number* div(const number& other) const override{
        const Complex& otherComplex = dynamic_cast<const Complex&>(other);
        number* resultReal = real->div(*otherComplex.real);
        number* resultImaginary = image->div(*otherComplex.image);
        if (resultReal != 0 and resultImaginary != 0 ) {
            return new Complex(resultReal,resultImaginary);
        }
        throw std::runtime_error("Division by zero");
    }
};