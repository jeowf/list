template <typename T>
list<T>::list(void){
	m_head = new Node();
	m_tail = new Node();
	m_head->prev = nullptr;
	m_tail->next = nullptr;
	m_head->next = m_tail;
	m_tail->prev = m_head;
	m_size = 0;
}

template <typename T>
list<T>::~list(void){
  delete this->m_head;
  delete this->m_tail;
}

template <typename T>
list<T>::list(const list & other){

}

template <typename T>
typename list<T>::list & list<T>::operator=( const list<T> & other){

}

template <typename T>
typename list<T>::iterator list<T>::begin(){
  return iterador((this->m_head)->next);
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const{
  return const_iterador((this->m_head)->next);
}

template <typename T>
typename list<T>::iterator list<T>::end(){
  return iterador((this->m_tail)->prev);
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const{
  return const_iterador((this->m_tail)->prev);
}

template <typename T>
int list<T>::size() const{
  return m_size;
}

template <typename T>
bool list<T>::empty() const{
 return m_size == 0;
}

template <typename T>
void list<T>::clear(){
  while(m_head->next != m_tail){
    pop_back();
  }
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
    return (m_head->prev)->data;
}

template <typename T>
const T & list<T>::back() const{
    return (m_head->prev)->data;
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
void list<T>::assign(const T& value){
  typename list<T>::iterator temp;
  for(temp = begin(); temp != end(); temp++){
     (*temp)->data = value;
  }
  ((*temp)->next)->data = value;
}

template <typename T>
template <class InItr>
void list<T>::assign (InItr first, InItr last){
  iterator temp = begin();
  size_t size = last - first;
  for(size_t i = 0;i < size; i++){
      (*temp)->data = first+i;
      temp++;
  }
}

template <typename T>
void list<T>::assign (std::initializer_list<T> ilist){
  iterator temp = begin();
  for(size_t i = 0;i < ilist.size(); i++){
      (*temp)->data = *(ilist.begin()+i);
      temp++;
  }
}

template <typename T>
typename list<T>::iterator list<T>::insert(const_iterator itr, const T & value){

}

template <typename T>
typename list<T>::iterator list<T>::insert(const_iterator pos,std::initializer_list<T> ilist){

}

template <typename T>
typename list<T>::iterator list<T>::erase(const_iterator itr){

}

template <typename T>
typename list<T>::iterator list<T>::erase(const_iterator first, const_iterator last){

}

template <typename T>
typename list<T>::const_iterator list<T>::find(const T & value) const{

}
