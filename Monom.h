#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

class Monom {
private:
    double _koef;
    Monom* _next;
    std::vector<int> _degrees; 

public:
    // Конструктор для одночленного числа с коэффициентом и степенями
    Monom(double koef, const std::vector<int>& degrees) : _koef(koef), _degrees(degrees) {
    } //Прямая инициализация
    // Конструктор копирования
    Monom(const Monom& other) : _koef(other._koef), _degrees(other._degrees) {
    } //Прямая инициализация
    // Оператор присвоения копии
    Monom& operator=(const Monom& other) {
        if (this != &other) {
            _koef = other._koef;
            _degrees = other._degrees; 
        }
        return *this;
    }
    ~Monom(){}
    Monom operator+(const Monom& other) const {
        return Monom(_koef + other._koef, _degrees);
    }
    Monom operator-(const Monom& other) const {
        return Monom(_koef - other._koef, _degrees);
    }
    Monom operator*(const Monom& other) const {
        std::vector<int> newDegrees(_degrees.size());
        for (size_t i = 0; i < _degrees.size(); ++i) {
            newDegrees[i] = _degrees[i] + other._degrees[i];
        }
        return Monom(_koef * other._koef, newDegrees);
    }
    Monom operator/(const Monom& other) const {
        std::vector<int> newDegrees(_degrees.size());
        for (size_t i = 0; i < _degrees.size(); ++i) {
            newDegrees[i] = _degrees[i] - other._degrees[i];
        }
        return Monom(_koef / other._koef, newDegrees);
    }
    friend std::ostream& operator<<(std::ostream& os, const Monom& monom) {
        os << monom._koef;
        for (size_t i = 0; i < monom._degrees.size(); ++i) {
            if (monom._degrees[i] > 0) {
                os << "x_" << i + 1 << "^" << monom._degrees[i];
            }
        }
        return os;
    }
};
