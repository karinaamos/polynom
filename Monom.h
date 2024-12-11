#pragma once
#include <iostream>
#include <stdexcept>

class Monom {
private:
    double _koef;
    size_t _size;
    int16_t* _array;
    Monom* _next;

public:
    Monom(double koef, size_t size, int16_t* array){
        _koef = koef;
        _size = size;
        _array = array;
        _next = nullptr;
    }
    Monom* GetNext(){}

    // Конструктор копирования
    Monom(const Monom& mon) {
        _size = mon._size;
        _koef = mon._koef;
        _next = mon._next;
        _array = new int16_t[_size];
        for (size_t i = 0; i < _size; i++){
            _array[i] = mon._array[i];
        }
    } 

    // Оператор присвоения копии
    Monom& operator=(const Monom& mon) {
        if (this != &mon) {
            return *this;
        }
        delete[] _array;
        _array = new int16_t[mon._size];
        _size = mon._size;
        _koef = mon._koef;
        _next = mon._next;
        for (size_t i = 0; i < _size; i++){
            _array[i] = mon._array[i];
        }
        return *this;
    }

    ~Monom(){
        delete _array;
    }

    Monom operator+(const Monom& mon) const {
        Monom a(*this);
        if (a._size != mon._size){
            throw "Mnogo hochesh";
        }
        for (size_t i = 0; i < _size; i++){
            if (a._array[i] != mon._array[i]){
                throw "Mnogo hochesh";
            }
        }
        a._koef += mon._koef;
        return a;
    }

    Monom operator-(const Monom& mon) const {
        Monom a(*this);
        if (a._size != mon._size){
            throw "Mnogo hochesh";
        }
        for (size_t i = 0; i < _size; i++){
            if (a._array[i] != mon._array[i]){
                throw "Mnogo hochesh";
            }
        }
        a._koef -= mon._koef;
        return a;
    }

    Monom operator*(const Monom& mon) const {
        size_t mSize = std::max(this -> _size, mon._size);
        int16_t* array = new int16_t[mSize];
        size_t minSize = std::min(this -> _size, mon._size);
        for(size_t i = 0; i < minSize; i++){
            array[i] = _array[i] + mon._array[i];
        }
        if(this -> _size > mon._size){
            for (size_t i = 0; i < minSize; i++){
                array[i] = _array[i];
            }
        }
        else{
            for (size_t i = 0; i < minSize; i++){
                array[i] = mon._array[i];
            }
        }
        return Monom(_koef * mon._koef, mSize, array);
    }

    Monom operator/(const Monom& mon) const {
        size_t mSize = std::max(this -> _size, mon._size);
        int16_t* array = new int16_t[mSize];
        size_t minSize = std::min(this -> _size, mon._size);
        for(size_t i = 0; i < minSize; i++){
            array[i] = _array[i] - mon._array[i];
        }
        if(this -> _size > mon._size){
            for (size_t i = 0; i < minSize; i++){
                array[i] = -_array[i];
            }
        }
        else{
            for (size_t i = 0; i < minSize; i++){
                array[i] = -mon._array[i];
            }
        }
        return Monom(_koef / mon._koef, mSize, array);
    }

    void Print(){
        std::cout<<_koef;
        for (size_t i = 0; i < _size; i++){
            std::cout<<"X"<<i+1<<"^"<<_array[i];
        }
    }
};