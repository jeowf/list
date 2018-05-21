#include "list.h"

namespace ls{
    template <typename T>
    list<T>::list(void) : m_size (0),
                          m_head (new Node()),
    	                  m_tail (new Node()) {
        m_head->prev = nullptr;
        m_tail->next = nullptr;
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }

    template<typename T>
    list<T>::list( size_t count ): m_size (count),
                          m_head (new Node()),
                          m_tail (new Node()) {
      m_head->prev = nullptr;
      m_tail->next = nullptr;
      m_head->next = m_tail;
      m_tail->prev = m_head;
      T *generic = new T();
      for(size_t i = 0; i < count; i++){
        push_back(*generic);
      }
    }

    template <typename T>
    template <typename InputItr>
		list<T>::list(InputItr first, InputItr last): m_size ((last - first)),
                          m_head (new Node()),
    	                    m_tail (new Node()){
    m_head->prev = nullptr;
    m_tail->next = nullptr;
    m_head->next = m_tail;
    m_tail->prev = m_head;
    size_t size = last - first;
    for(size_t i = 0; i < size; i++){
        Node * tmp = new Node();
        tmp->data = *(first+i);
        push_back(tmp->data);
    }

    }

    template <typename T>
    list<T>::list(std::initializer_list<T> ilist ) :
                   m_size (ilist.size()),
                   m_head (new Node()),
                   m_tail (new Node()) {

        m_head->prev = nullptr;
        m_tail->next = nullptr;
        m_head->next = m_tail;
        m_tail->prev = m_head;


        for (size_t i = 0; i < ilist.size(); i++){
            Node * tmp = new Node();
            tmp->data = *(ilist.begin()+i);
            push_back(tmp->data);
        }

    }


    template <typename T>
    list<T>::~list(void){
        clear();
        delete this->m_head;
        delete this->m_tail;
    }

    template <typename T>
    list<T>::list(const list & other){
        m_head = new Node();
    	m_tail = new Node();
    	m_head->prev = nullptr;
    	m_tail->next = nullptr;
    	m_head->next = m_tail;
    	m_tail->prev = m_head;
    	m_size = other.size();
        for(const_iterator iter = other.cbegin(); iter != other.cend(); iter++){
            push_front( (*iter)->data );
        }
    }

    template <typename T>
    typename list<T>::list & list<T>::operator=( const list<T> & other){
        clear();
        m_size = other.size();
        for(const_iterator iter = other.cbegin(); iter != other.cend(); iter++){
            push_front( (*iter)->data );
        }
        return *this;
    }

    template <typename T>
    typename list<T>::list & list<T>::operator=( std::initializer_list<T> ilist){
      clear();
      m_size = ilist.size();
      for (size_t i = 0; i < ilist.size(); i++){
          Node * tmp = new Node();
          tmp->data = *(ilist.begin()+i);
          push_back(tmp->data);
      }
      return *this;
    }

    template <typename T>
    typename list<T>::iterator list<T>::begin(){
        return iterator((this->m_head)->next);
    }

    template <typename T>
    typename list<T>::const_iterator list<T>::cbegin() const{
        return const_iterator((this->m_head)->next);
    }

    template <typename T>
    typename list<T>::iterator list<T>::end(){
        return iterator((this->m_tail));
    }

    template <typename T>
    typename list<T>::const_iterator list<T>::cend() const{
        return const_iterator((this->m_tail));
    }

    template <typename T>
    int list<T>::size() const{
        return m_size;
    }

    template <typename T>
    bool list<T>::empty() const{
        return (m_size == 0);
    }

    template <typename T>
    void list<T>::clear(){
        while(m_head->next != m_tail)
            pop_back();
    }

    template <typename T>
    T & list<T>::front(){
        return (m_head->next)->data;
    }

    template <typename T>
    const T & list<T>::front() const{
        return (m_head->next)->data;
    }

    template <typename T>
    T & list<T>::back(){
        return (m_tail->prev)->data;
    }

    template <typename T>
    const T & list<T>::back() const{
        return (m_tail->prev)->data;
    }

    template <typename T>
    void list<T>::push_front(const T & value){
        Node * tmp = new Node();
        tmp->data = value;
        tmp->next = m_head->next;
        (m_head->next)->prev = tmp;
        m_head->next = tmp;
        tmp->prev = m_head;
        m_size++;
    }

    template <typename T>
    void list<T>::push_back(const T & value){
        Node * tmp = new Node();
        tmp->data = value;
        tmp->prev = m_tail->prev;
        (m_tail->prev)->next = tmp;
        tmp->next = m_tail;
        m_tail->prev = tmp;
        m_size++;
    }

    template <typename T>
    void list<T>::pop_front(){
        if(empty() == false){
            Node * tmp = new Node();
            tmp = m_head->next;
            (tmp->next)->prev = m_head;
            m_head->next = tmp->next;
            delete tmp;
            m_size--;
        }
    }

    template <typename T>
    void list<T>::pop_back(){
        if(empty() == false){
            Node * tmp = new Node();
            tmp = m_tail->prev;
            (tmp->prev)->next = m_tail;
            m_tail->prev = tmp->prev;
            delete tmp;
            m_size--;
        }
    }

    template <typename T>
    void list<T>::assign(size_t count,const T& value){
        typename list<T>::iterator temp = begin();
        for(size_t i = 0; i < count; i++){
            (*temp)->data = value;
            temp++;
        }
    }

    template <typename T>
    template <class InItr>
    void list<T>::assign (InItr first, InItr last){
        typename list<T>::iterator temp = begin();
        size_t size = last - first;
        for(size_t i = 0; i < size; i++){
            (*temp)->data = *(first+i);
            temp++;
        }
    }

    template <typename T>
    void list<T>::assign (std::initializer_list<T> ilist){
        typename list<T>::iterator temp = begin();
        for(size_t i = 0;i < ilist.size(); i++){
            (*temp)->data = *(ilist.begin()+i);
            temp++;
        }
    }

    template <typename T>
    typename list<T>::iterator list<T>::insert(const_iterator itr, const T & value){
        typename list<T>::iterator iter = begin();

        if(itr == end()){
          return nullptr;
        }

        while(iter != itr){
            if(iter == end()){
                return nullptr;
            }
            iter++;
        }

        Node * tmp = new Node();
        tmp->data = value;
        tmp->next = ((*iter)->prev)->next;
        tmp->prev = ((*iter)->prev);
        ((*iter)->prev)->next = tmp;
        ((*iter)->prev) = tmp;
        m_size++;

        return (tmp->next);

    }

    template <typename T>
    template < typename InItr>
		typename list<T>::iterator list<T>::insert( iterator pos, InItr first, InItr last ){
      typename list<T>::iterator iter = begin();
      typename list<T>::iterator gen = begin();

      size_t size = (last - first);
      if(pos == cend()){
          return nullptr;
      }

      while(iter != pos){
          if(iter == end()){
              return nullptr;
          }
          iter++;
      }

      for (size_t i = 0; i < size; i++){
          Node * tmp = new Node();
          tmp->data = *(first+i);
          tmp->next = ((*iter)->prev)->next;
          tmp->prev = ((*iter)->prev);
          ((*iter)->prev)->next = tmp;
          ((*iter)->prev) = tmp;
          m_size++;
          gen = iter;
      }
      return ((*gen)->next);
    }

    template <typename T>
    typename list<T>::iterator list<T>::insert(const_iterator pos,std::initializer_list<T> ilist){
        typename list<T>::iterator iter = begin();
        typename list<T>::iterator last = begin();

        if(pos == cend()){
            return nullptr;
        }

        while(iter != pos){
            if(iter == end()){
                return nullptr;
            }
            iter++;
        }

        for (size_t i = 0; i < ilist.size(); i++){
            Node * tmp = new Node();
            tmp->data = *(ilist.begin()+i);
            tmp->next = ((*iter)->prev)->next;
            tmp->prev = ((*iter)->prev);
            ((*iter)->prev)->next = tmp;
            ((*iter)->prev) = tmp;
            m_size++;
            last = iter;
        }
        return ((*last)->next);
    }

    template <typename T>
    typename list<T>::iterator list<T>::erase(const_iterator itr){
        typename list<T>::iterator iter = begin();

        if(itr == end()){
            return nullptr;
        }
        while(iter != itr){
            if(iter == end()){
                return nullptr;
            }
        iter++;
        }

        ((*iter)->prev)->next = (*iter)->next;
        ((*iter)->next)->prev = (*iter)->prev;
        m_size--;

        return (((*iter)->prev)->next);
    }

    template <typename T>
    typename list<T>::iterator list<T>::erase(const_iterator first, const_iterator last){
        typename list<T>::iterator iter = begin();

        while(iter != first){
            if(iter == end())
                return nullptr;
            iter++;
        }
        while(iter != last){
            iter = erase(iter);
        }
        return iter;
    }

    template <typename T>
    typename list<T>::const_iterator list<T>::find(const T & value) const{
        typename list<T>::const_iterator iter = cbegin();

        while(iter != cend()){
            if((*iter)->data == value)
                return (*iter);
            iter++;
        }

        return nullptr;
    }

    template <typename T>
    bool list<T>::operator==(const list & rhs){
        if (rhs.m_size != m_size){
            return false;
        }

        const_iterator lhs_i = cbegin();
        const_iterator rhs_i = rhs.cbegin();

        while (lhs_i != cend()){
            if ((*lhs_i)->data != (*rhs_i)->data)
                return false;
            lhs_i++;
            rhs_i++;
        }

        return true;

    }

    template <typename T>
    bool list<T>::operator!=(const list & rhs){
        if (rhs.m_size != m_size){
            return true;
        }

        const_iterator lhs_i = cbegin();
        const_iterator rhs_i = rhs.cbegin();

        while (lhs_i != cend()){
            if ((*lhs_i)->data != (*rhs_i)->data)
                return true;
            lhs_i++;
            rhs_i++;
        }

        return false;

    }
}
