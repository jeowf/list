#include "list.h"

namespace ls{
    template<typename T>
    typename list<T>::Node * list<T>::iterator::operator*() const{
        return this->current;
    }

    template<typename T>
    typename list<T>::Node * list<T>::iterator::operator*(){
         return this->current;
    }

    template<typename T>
    typename list<T>::iterator & list<T>::iterator::operator++(){
        this->current = (this->current)->next;
        return *this;
    }

    template<typename T>
    typename list<T>::iterator list<T>::iterator::operator++(int){
        iterator temp = *this;
        this->current = (this->current)->next;
        return *temp;
    }

    template<typename T>
    typename list<T>::iterator & list<T>::iterator::operator--(){
        this->current = (this->current)->prev;
        return *this;
    }

    template<typename T>
    typename list<T>::iterator list<T>::iterator::operator--(int){
        iterator temp = *this;
        this->current = (this->current)->prev;
        return *temp;
    }
}