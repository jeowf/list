#include "list.h"

namespace ls{
    //cria um construtor regular vazio
    template <typename T>
    list<T>::list(void) : m_size (0),
                          m_head (new Node()),
    	                  m_tail (new Node()) {
        //liga o head no tail e vice-versa.
        m_head->prev = nullptr;
        m_tail->next = nullptr;
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }
    //cria um contrutor com `count` instancias de T
    template<typename T>
    list<T>::list( size_t count ): m_size (0),
                          m_head (new Node()),
                          m_tail (new Node()) {
      //liga o head no tail e vice-versa
      m_head->prev = nullptr;
      m_tail->next = nullptr;
      m_head->next = m_tail;
      m_tail->prev = m_head;
      //instancia T
      T *generic = new T();
      for(size_t i = 0; i < count; i++){
        //adiciona as instancias no fim da lista
        push_back(*generic);
      }
    }
    //cria um construtor a partir de um range [first,last)
    template <typename T>
    template <typename InputItr>
		list<T>::list(InputItr first, InputItr last): m_size (0),
                          m_head (new Node()),
    	                    m_tail (new Node()){
    //liga o head no tail e vice-versa
    m_head->prev = nullptr;
    m_tail->next = nullptr;
    m_head->next = m_tail;
    m_tail->prev = m_head;
    //tamanho do range
    size_t size = last - first;
    //percorre o range
    for(size_t i = 0; i < size; i++){
        Node * tmp = new Node();
        tmp->data = *(first+i);
        //adiciona os elementos no fim da lista
        push_back(tmp->data);
    }

    }
    //cria um costrututor a partir de um objeto initializer_list
    template <typename T>
    list<T>::list(std::initializer_list<T> ilist ) :
                   m_size (0),
                   m_head (new Node()),
                   m_tail (new Node()) {
        //liga o head no tail e vice-versa
        m_head->prev = nullptr;
        m_tail->next = nullptr;
        m_head->next = m_tail;
        m_tail->prev = m_head;

        //percorre a lista
        for (size_t i = 0; i < ilist.size(); i++){
            Node * tmp = new Node();
            tmp->data = *(ilist.begin()+i);
            //adiciona os elementos no fim da lista
            push_back(tmp->data);
        }

    }

    //destrutor
    template <typename T>
    list<T>::~list(void){
        //limpa a lista
        clear();
        //deleta o head e o tail
        delete this->m_head;
        delete this->m_tail;
    }
    //cria um construtor copia
    template <typename T>
    list<T>::list(const list & other){
        m_head = new Node();
    	m_tail = new Node();
        //liga o head no tail e vice-versa
    	m_head->prev = nullptr;
    	m_tail->next = nullptr;
    	m_head->next = m_tail;
    	m_tail->prev = m_head;
        //inicializa com tamanho 0
    	m_size = 0;
        //percorre todo o outro objeto list copiando os elementos para o fim da lista
        for(const_iterator iter = other.cbegin(); iter != other.cend(); iter++){
            push_back( (*iter)->data );
        }
    }
    //atribui a uma lista existente elementos de outra lista
    template <typename T>
    typename list<T>::list & list<T>::operator=( const list<T> & other){
        //deleta os elementos antigos
        clear();
        m_size = 0;
         //percorre todo o outro objeto list copiando os elementos para o fim da lista
        for(const_iterator iter = other.cbegin(); iter != other.cend(); iter++){
            push_back( (*iter)->data );
        }
        return *this;
    }
    //atribui a uma lista existente elementos de uma initializer_list
    template <typename T>
    typename list<T>::list & list<T>::operator=( std::initializer_list<T> ilist){
        //apaga os elementos
      clear();
      //atribui o mesmo tamanho a lista
      m_size = ilist.size();
      //percorre todo o outro objeto initializer_list copiando os elementos para o fim da lista
      for (size_t i = 0; i < ilist.size(); i++){
          Node * tmp = new Node();
          tmp->data = *(ilist.begin()+i);
          //adiciona os elementos da lista
          push_back(tmp->data);
      }
      return *this;
    }
    //retorna um pointeiro para o elemento posterior ao head
    template <typename T>
    typename list<T>::iterator list<T>::begin(){
        return iterator((this->m_head)->next);
    }
    //retorna um pointeiro para o elemento posterior ao head sendo constante
    template <typename T>
    typename list<T>::const_iterator list<T>::cbegin() const{
        return const_iterator((this->m_head)->next);
    }
    //retorna um pointeiro para o elemento anterior ao tail
    template <typename T>
    typename list<T>::iterator list<T>::end(){
        return iterator((this->m_tail));
    }
    //retorna um pointeiro para o elemento anterior ao tail
    template <typename T>
    typename list<T>::const_iterator list<T>::cend() const{
        return const_iterator((this->m_tail));
    }
    //retorna a quantidade de elementos na lista
    template <typename T>
    int list<T>::size() const{
        return m_size;
    }
    //verifica se a lista esta vazia
    template <typename T>
    bool list<T>::empty() const{
        return (m_size == 0);
    }
    //remove todos os elementos da lista
    template <typename T>
    void list<T>::clear(){
        //percorre a lista retirando seu ultimo elemento
        while(m_head->next != m_tail){
            pop_back();
        }
    }
    //retorna o elemento a frente na lista
    template <typename T>
    T & list<T>::front(){
        return (m_head->next)->data;
    }
    //retorna o elemento a frente na lista sendo constante
    template <typename T>
    const T & list<T>::front() const{
        return (m_head->next)->data;
    }
    //retorna o elemento no fim da lista
    template <typename T>
    T & list<T>::back(){
        return (m_tail->prev)->data;
    }
    //retorna o elemento no fim da lista send costante
    template <typename T>
    const T & list<T>::back() const{
        return (m_tail->prev)->data;
    }
    //adiciona um elemento no inicio da lista
    template <typename T>
    void list<T>::push_front(const T & value){
        //cria um novo objeto Node
        Node * tmp = new Node();
        //adiciona um novo nó no inicio da lista
        tmp->data = value;
        tmp->next = m_head->next;
        (m_head->next)->prev = tmp;
        m_head->next = tmp;
        tmp->prev = m_head;
        //incrementa o tamanho da lista
        m_size++;
    }
    //adiciona um elemento no fim da lista
    template <typename T>
    void list<T>::push_back(const T & value){
        //cria um novo objeto Node
        Node * tmp = new Node();
        //adiciona um novo nó no fim da lista
        tmp->data = value;
        tmp->prev = m_tail->prev;
        (m_tail->prev)->next = tmp;
        tmp->next = m_tail;
        m_tail->prev = tmp;
        //incrementa o tamanho da lista
        m_size++;
    }
    //deleta o primeiro elemento da lista
    template <typename T>
    void list<T>::pop_front(){
        if(empty() == false){
            //cria um novo objeto Node
            Node * tmp = new Node();
            //deleta o nó no inicio da lista
            tmp = m_head->next;
            (tmp->next)->prev = m_head;
            m_head->next = tmp->next;
            //deleta o objeto Node
            delete tmp;
            //reduz o tamanho da lista
            m_size--;
        }
    }
    //deleta o primeiro elemento da lista
    template <typename T>
    void list<T>::pop_back(){
        if(empty() == false){
            //cria um novo objeto Node
            Node * tmp = new Node();
            //deleta o nó no fim da lista
            tmp = m_tail->prev;
            (tmp->prev)->next = m_tail;
            m_tail->prev = tmp->prev;
            //deleta o objeto Node
            delete tmp;
            //reduz o tamanho da lista
            m_size--;
        }
    }
    //atribui `value` a todos os elementos na lista
    template <typename T>
    void list<T>::assign(const T& value){
        typename list<T>::iterator temp;
        //percorre a lista e substitui os valores por `value`
        for(temp = begin();temp!=end(); temp++){
            (*temp)->data = value;
        }
    }
    //atribui aos elementos da lista os elementos no range [first,last)
    template <typename T>
    template <class InItr>
    void list<T>::assign (InItr first, InItr last){
        typename list<T>::iterator temp = begin();
        //pega o tamanho do range
        size_t size = last - first;
        //percorre a lista e atribui os valores do range a ela
        for(size_t i = 0; i < size; i++){
            (*temp)->data = *(first+i);
            temp++;
        }
    }
    //atribui aos elementos da lista os elementos do objeto initializer_list
    template <typename T>
    void list<T>::assign (std::initializer_list<T> ilist){
        typename list<T>::iterator temp = begin();
        //percorre a lista e atribui os valores d objeto initializer_list a ela
        for(size_t i = 0;i < ilist.size(); i++){
            (*temp)->data = *(ilist.begin()+i);
            temp++;
        }
    }
    //insere o elemento value antes da posicao indicada pelo iterador
    template <typename T>
    typename list<T>::iterator list<T>::insert(const_iterator itr, const T & value){
        typename list<T>::iterator iter = begin();
        //verifica se o iterador estar no fim da lista
        if(itr == end()){
          return nullptr;
        }
        //iguala os dois iteradores na mesma posicao
        while(iter != itr){
            if(iter == end()){
                return nullptr;
            }
            iter++;
        }
        //insere o elemento na lista
        Node * tmp = new Node();
        tmp->data = value;
        tmp->next = ((*iter)->prev)->next;
        tmp->prev = ((*iter)->prev);
        ((*iter)->prev)->next = tmp;
        ((*iter)->prev) = tmp;
        //aumenta o tamanho da lista
        m_size++;

        return (tmp->next);

    }
    //insere os elementos do range [first,last) antes da posicao indicada pelo iterador
    template <typename T>
    template < typename InItr>
		typename list<T>::iterator list<T>::insert( iterator pos, InItr first, InItr last ){
      typename list<T>::iterator iter = begin();
      typename list<T>::iterator gen = begin();
      //verifica se o iterador estar no fim da lista
      size_t size = (last - first);
      if(pos == cend()){
          return nullptr;
      }
      //iguala os dois iteradores na mesma posicao
      while(iter != pos){
          if(iter == end()){
              return nullptr;
          }
          iter++;
      }
      //percorre o range
      for (size_t i = 0; i < size; i++){
          //insere os elementos na lista
          Node * tmp = new Node();
          tmp->data = *(first+i);
          tmp->next = ((*iter)->prev)->next;
          tmp->prev = ((*iter)->prev);
          ((*iter)->prev)->next = tmp;
          ((*iter)->prev) = tmp;
          //aumenta o tamanho da lista
          m_size++;
          gen = iter;
      }
      return ((*gen)->next);
    }
    //insere os elementos do objeto initializer_list antes da posicao indicada pelo iteradores
    template <typename T>
    typename list<T>::iterator list<T>::insert(const_iterator pos,std::initializer_list<T> ilist){
        typename list<T>::iterator iter = begin();
        typename list<T>::iterator last = begin();
        //verifica se o iterador estar no fim da lista
        if(pos == cend()){
            return nullptr;
        }
        //iguala os dois iteradores na mesma posicao
        while(iter != pos){
            if(iter == end()){
                return nullptr;
            }
            iter++;
        }
        //percorre o initializer_list
        for (size_t i = 0; i < ilist.size(); i++){
            //insere os elementos na lista
            Node * tmp = new Node();
            tmp->data = *(ilist.begin()+i);
            tmp->next = ((*iter)->prev)->next;
            tmp->prev = ((*iter)->prev);
            ((*iter)->prev)->next = tmp;
            ((*iter)->prev) = tmp;
            //aumenta o tamanho da lista
            m_size++;
            last = iter;
        }
        return ((*last)->next);
    }
    //deleta o elemento na posicao indicada pelo iterador
    template <typename T>
    typename list<T>::iterator list<T>::erase(const_iterator itr){
        typename list<T>::iterator iter = begin();
        //verifica se o iterador estar no fim da lista
        if(itr == end()){
            return nullptr;
        }
        //iguala os dois iteradores na mesma posicao
        while(iter != itr){
            if(iter == end()){
                return nullptr;
            }
        iter++;
        }
        //deleta o elemento
        ((*iter)->prev)->next = (*iter)->next;
        ((*iter)->next)->prev = (*iter)->prev;
        //reduz o tamanho da lista
        m_size--;

        return (((*iter)->prev)->next);
    }
    //deleta os elementos do range  de iteradores[first,last)
    template <typename T>
    typename list<T>::iterator list<T>::erase(const_iterator first, const_iterator last){
        typename list<T>::iterator iter = begin();
        //iguala os dois iteradores na mesma posicao
        while(iter != first){
            if(iter == end())
                return nullptr;
            iter++;
        }
        //deleta os elementos ate o iterador last
        while(iter != last){
            iter = erase(iter);
        }
        return iter;
    }
    //procura um elemento na lista e retorna um iterador para ele
    template <typename T>
    typename list<T>::const_iterator list<T>::find(const T & value) const{
        typename list<T>::const_iterator iter = cbegin();
        //percorre a lista ate achar um elemento igual a value
        while(iter != cend()){
            if((*iter)->data == value)
                return (*iter);
            iter++;
        }

        return nullptr;
    }
    //compara se duas listas sao iguais
    template <typename T>
    bool list<T>::operator==(const list & rhs){
        if (rhs.m_size != m_size){
            return false;
        }
        //coloca iteradores no inicio de cada lista
        const_iterator lhs_i = cbegin();
        const_iterator rhs_i = rhs.cbegin();
        //compara os elementos para ver se sao todos iguais
        while (lhs_i != cend()){
            if ((*lhs_i)->data != (*rhs_i)->data)
                return false;
            lhs_i++;
            rhs_i++;
        }
        //se forem iguais retorna true
        return true;

    }
    //compara se duas listas sao diferentes
    template <typename T>
    bool list<T>::operator!=(const list & rhs){
        if (rhs.m_size != m_size){
            return true;
        }
        //coloca iteradores no inicio de cada lista
        const_iterator lhs_i = cbegin();
        const_iterator rhs_i = rhs.cbegin();
        //compara os elementos para ver se sao todos diferentes
        while (lhs_i != cend()){
            if ((*lhs_i)->data != (*rhs_i)->data)
                return true;
            lhs_i++;
            rhs_i++;
        }
        //se forem iguais retorna false
        return false;

    }
}
