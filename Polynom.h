#include <iostream>
#include "Monom.h"

class Polynom{
private:
    Monom* _head;
public:
    Polynom(){
        _head = nullptr;
    }

    void AppendMonom(Monom* monom){
        if (_head == nullptr){
            _head = monom;
        }
        else{
            Monom* tmp = _head -> GetNext();
            while(tmp != nullptr){
                tmp = tmp->GetNext();
            }
        }
    }
    void Print(){
        Monom* tmp = _head;
        while (tmp != nullptr){
            tmp->Print();
            std::cout<<" + ";
            tmp = tmp -> GetNext();
        }
    }
};