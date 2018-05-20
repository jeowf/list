#include "list.h"

namespace ls{

    template<typename T>
    list<T>::const_iterator::const_iterator(){
    }

    template<typename T>
    typename list<T>::Node * list<T>::const_iterator::operator*() const{
        return current ;
    }

    template<typename T>
    typename list<T>::const_iterator & list<T>::const_iterator::operator++(){
        this->current = (this->current)->next;
        return *this;
    }

    template<typename T>
    typename list<T>::const_iterator list<T>::const_iterator::operator++(int){
        const_iterator temp = *this;
        this->current = (this->current)->next;
        return *temp;
    }

    template<typename T>
    typename list<T>::const_iterator & list<T>::const_iterator::operator--(){
        this->current = (this->current)->prev;
        return *this;
    }

    template<typename T>
    typename list<T>::const_iterator list<T>::const_iterator::operator--(int){
        const_iterator temp = *this;
        this->current = (this->current)->prev;
        return *temp;
    }

    template<typename T>
    bool list<T>::const_iterator::operator==(const const_iterator & rhs ) const{
       return this->current == rhs.current;
     }

    template<typename T>
    bool list<T>::const_iterator::operator!=(const const_iterator & rhs ) const{
        return this->current != rhs.current;
    }
}