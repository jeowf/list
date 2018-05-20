#ifndef LIST
#define LIST

#include <initializer_list>

namespace ls{

	template <typename T>
	/*! @class list
	 *
	 * @brief A class that manages actions on a dinamic list
	*/
	class list {
	private:
		struct Node{
			T data;
			Node *prev;
			Node *next;

			Node(const T & d = T(), Node * p = nullptr,Node * n = nullptr)
				:data(d),prev(p),next(n){}

		};

		int m_size;
		Node *m_head;
		Node *m_tail;

	public:
		class const_iterator {
		public:
			const_iterator();
			Node * operator* () const;
			const_iterator & operator++();
			const_iterator operator++(int);
			const_iterator & operator--();
			const_iterator operator-- (int);
			bool operator==(const const_iterator & rhs) const;
			bool operator!=(const const_iterator & rhs) const;

 		protected:
			Node *current;
			const_iterator( Node * p ) : current( p ){}
			friend class list<T>;
		};

		class iterator : public const_iterator{
		public:
			iterator(): const_iterator(){}
			Node * operator*() const;
			Node * operator*();

			iterator & operator++();
			iterator operator++(int);
			iterator & operator--();
			iterator operator-- (int);

		protected:

			iterator( Node * p ) : const_iterator( p ){}
			friend class list<T>;
		};

		list();

		list( const std::initializer_list<T> il );

		//template <typename InputItr>
		//list(InputItr begin, InputItr end);

		~list();
		list(const list &);
		list & operator=(const list &);

		iterator begin();
		const_iterator cbegin() const;
		iterator end();
		const_iterator cend() const;

		int size() const;
		bool empty() const;

		void clear();
		T & front();
		const T & front() const;
		T & back() ;
		const T & back() const;
		void push_front(const T & value);
		void push_back(const T & value);
		void pop_front();
		void pop_back();
		void assign(const T& value);

		template <class InItr>
		void assign (InItr first, InItr last);

		void assign (std::initializer_list<T> ilist);
		iterator insert(const_iterator itr, const T & value);
		iterator insert(const_iterator pos,std::initializer_list<T> ilist);
		iterator erase(const_iterator itr);
		iterator erase(const_iterator first, const_iterator last);
		const_iterator find(const T & value) const;

		bool operator==(const list & rhs);
		//bool operator!=(const list & rhs);

		
	};
}

#include "iterator.inl"
#include "const_iterator.inl"
#include "list.inl"

#endif