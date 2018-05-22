#ifndef LIST
#define LIST

#include <iostream>
#include <stdexcept>
#include <initializer_list>

namespace ls{

	template <typename T>
	/*! @class list
	*
	* @brief A class that manages actions on a dinamic list
	*/
	class list {
	private:
		/*! @struct Node
		*
		* @brief A struct that represents the nodes of the list
		*/
		struct Node{
			T data;/*!< Variable to storage the current content of node */
			Node *prev;/*!< Variable to storage the previous node */
			Node *next;/*!< Variable to storage the next node */
			/*!
			* @brief Node Constructor
			*
			* Initializes a Node
			*
			*/
			Node(const T & d = T(), Node * p = nullptr,Node * n = nullptr)
				:data(d),prev(p),next(n){}

		};

		int m_size;
		Node *m_head;
		Node *m_tail;

	public:
		/*! @class list
		*
		* @brief A class that manage the acess the elements in a list
		*/
		class const_iterator {
		public:
			/*!
			* @brief Const_Iterator Constructor
			*
			* Initializes the iterator
			*
			*/
			const_iterator();
			/*!
      		* @brief '*' Overload
      		*
      		* Overload '*' operator to take the current element const in list
      		*
      		* @return Return a const reference to the object in the position poited by the iterator
      		*/
			Node * operator* () const;
			/*!
			* @brief '++' Overload
			*
			* Overload '++' operator to advances iterator to the next location within the list
			*
			* @return Return a reference to the object in the position poited by the iterator
			*/
			const_iterator & operator++();
			/*!
			* @brief '++' Overload
			*
			* Overload '++' operator to return the current element in the list and advances iterator to the next location within the list
			*
			* @return Return a reference to the object in the previous position poited by the iterator
			*/
			const_iterator operator++(int);
			/*!
      		* @brief '--' Overload
      		*
      		* Overload '--'operator to back iterator to the previous location within the list
      		*
      		* @return Return a reference to the object in the position poited by the iterator
      		*/
			const_iterator & operator--();
			/*!
 	  		* @brief '--' Overload
      		*
      		* Overload '--' operator to return the current element in the list and back iterator to the previous location within the list
      		*
      		* @return Return a reference to the object in the previous position poited by the iterator
      		*/
			const_iterator operator--(int);
			/*!
      		* @brief '==' Overload
      		*
      		* Overload '==' operator to verify if two iterators points to same localization in the list
      		*
      		* @return Return true if two iterators points to same localization in the list
      		*/
			bool operator==(const const_iterator & rhs) const;
			/*!
			* @brief '!=' Overload
			*
			* Overload '!=' operator to verify if two iterators points to differentes localization in the list
			*
			* @return Return true if two iterators points to differentes localization in the list
			*/
			bool operator!=(const const_iterator & rhs) const;

 		protected:
			Node *current;/*!< Variable to storage the current element in the list */
			const_iterator( Node * p ) : current( p ){}/*!< Initializes a const_iterator contructor */ 
			friend class list<T>;
		};
		/*! @class iterator
		*
		* @brief A class that manage the acess the elements in a list
		*/
		class iterator : public const_iterator{
		public:
			iterator(): const_iterator(){}
			/*!
      		* @brief '*' Overload
      		*
      		* Overload '*' operator to take the current element const in list
      		*
      		*		 @return Return a const reference to the object in the position poited by the iterator
      		*/
			Node * operator*() const;
			/*!
      		* @brief '*' Overload
      		*
      		* Overload '*' operator to take the current element const in list
      		*
      		* @return Return a reference to the object in the position poited by the iterator
      		*/
			Node * operator*();
			/*!
			* @brief '++' Overload
			*
			* Overload '++' operator to advances iterator to the next location within the list
			*
			* @return Return a reference to the object in the position poited by the iterator
			*/
			iterator & operator++();
			/*!
			* @brief '++' Overload
			*
			* Overload '++' operator to return the current element in the list and advances iterator to the next location within the list
			*
			* @return Return a reference to the object in the previous position poited by the iterator
			*/
			iterator operator++(int);
			/*!
      		* @brief '--' Overload
      		*
      		* Overload '--'operator to back iterator to the previous location within the list
      		*
      		* @return Return a reference to the object in the position poited by the iterator
      		*/
			iterator & operator--();
			/*!
			* @brief '--' Overload
			*
			* Overload '--' operator to return the current element in the list and back iterator to the previous location within the list
			*
			* @return Return a reference to the object in the previous position poited by the iterator
			*/
			iterator operator-- (int);

		protected:

			iterator( Node * p ) : const_iterator( p ){}/*!< Initializes a iterator constructor*/
			friend class list<T>;
		};
	  	/*!
	  	* @brief List Constructor
	  	*
	  	* Initializes the list with a empty values;
	  	*/
		list();
		/*!
	  	* @brief List Constructor size
	  	*
	  	* Initializes the list with a 'count' default-inserted instances of T;
	  	*/
		explicit list( size_t count );
		/*!
		* @brief List Range Constructor
		*
		* Initializes contructor with the content of the range [first, last)
		*
		*@param first begin of range
		*@param last end of range
		*/
		template <typename InputItr>
		list(InputItr first, InputItr last);

		/*!
    	* @brief List initializer_list Constructor
    	*
    	* Initializes the list with a initializer_list elements
		*
		*@param ilist list of elements
    	*/
		list( const std::initializer_list<T> ilist );
		/*!
		* @brief List Destructor
		*
		* Destructs the list
		*/
		~list();
		/*!
	 	* @brief List Copy Constructor
	 	*
	 	* Initializes the list with the elements of other list
	 	*
	 	*@param other list object
	 	*/
		list(const list &);
		/*!
    	* @brief '=' Overload
    	*
    	* Overload '=' operator to replace the content with the copy of the alterable content of other list
    	*
    	* @param rhs list object
    	*
    	* @return Return the new content from other list
    	*/
		list & operator=(const list &);
		/*!
		* @brief '=' Overload
		*
		* Overload '=' operator to replace the content with the copy of the alterable content of initializer_list
		*
		* @param ilist initializer_list object
		*
		* @return Return the new content from initializer_list
		*/
		list & operator=(std::initializer_list<T> ilist);
		/*!
		* @brief Begin
		*
		* Return a pointer to the first valid element on the list
		*
		* @return Returns an iterator pointing to the first item in the list
		*/
		iterator begin();
		/*!
		* @brief Begin
		*
		* Return a constant pointer to the first valid element on the list
		*
		* @return Returns a constant iterator pointing to the first item in the list
		*/
		const_iterator cbegin() const;
		/*!
		* @brief End
		*
		* Return a pointer to the first element after the last element on the list
		*
		* @return Returns an iterator pointing to the end mark in the list
		*/
		iterator end();
		/*!
		* @brief End
		*
		* Return a constant pointer to the first element after the last element on the list
		*
		* @return Returns a constant iterator pointing to the end mark in the list
		*/
		const_iterator cend() const;
		/*!
		* @brief Size
		*
		* Contain the number of elements on the list
		*
		* @return Return the number of elements in the list.
		*/
		int size() const;
		/*!
		* @brief Empty
		*
		* Verifies if the list is empty
		*
		* @return Return true if the list contains no elements
		*/
		bool empty() const;
		/*!
	  	* @brief Clear
	  	*
	  	* Remove all elements from the list
	  	*/
		void clear();
		/*!
		* @brief Front
		*
		* Returns the first element on list
		*/
		T & front();
		/*!
		* @brief Front Const
		*
		* Returns the first element on list like constant;
		*/
		const T & front() const;
		/*!
		* @brief Back
		*
		* Returns the last element on list
		*/
		T & back() ;
		/*!
		* @brief Back Const
		*
		* Returns the last element on list like constant
		*/
		const T & back() const;
		/*!
    	* @brief Push Front
		*
    	* Adds value to the front of the list
    	*
    	* @param value value to be added
    	*
    	*/
		void push_front(const T & value);
		/*!
    	* @brief Push Back
    	*
    	* Adds value to the end of the list
    	*
    	* @param value value to be added
    	*
    	*/
		void push_back(const T & value);
		/*!
  		* @brief Pop Front
    	*
    	* Delete value at front of the list
    	*
    	*/
		void pop_front();
		/*!
		* @brief Pop Back
		*
		* Delete value at end of the list
		*
		*/
		void pop_back();
		/*!
    	* @brief Assign
    	*
    	* Replaces the contents with count copies of value value
    	*
    	* @param value number os values
		* @param value number os values
    	*/
		void assign(const T& value);
		/*!
		* @brief Assign
		*
		* Replaces the contents of the list with copies of the elements in the range [first; last) .
		*
		* @param first begin of range
		* @param last end of range
		*/
		template <class InItr>
		void assign (InItr first, InItr last);
		/*!
    	* @brief Assign
    	*
    	* Replaces the contents of the list with the elements from the initializer list ilist .
    	*
    	* @param ilist initializer list
    	*/
		void assign (std::initializer_list<T> ilist);
		/*!
		* @brief Insert
		*
		* Adds value into the list before the position given by the iterator pos
		*
		* @param pos iterator object
		* @param value value to be added
		*
		* @return Returns an iterator to the position of the inserted item.
		*/
		iterator insert(const_iterator itr, const T & value);
		/*!
		* @brief Insert
		*
		* inserts elements from the range [first; last) before pos
		*
		* @param pos vector object
		* @param first begin of range
		* @param last end of range
		*
		* @return Returns an iterator to the position of the inserted item
		*/
		template < typename InItr>
		iterator insert( iterator pos, InItr first, InItr last );
		/*!
		* @brief Insert
		*
		* Inserts elements from the initializer list ilist before pos
		*
		* @param pos vector object
		* @param ilist list object
		*
		* @return Returns an iterator to the position of the inserted item
		*/

		iterator insert(const_iterator pos,std::initializer_list<T> ilist);
		/*!
		* @brief Erase
		*
		* Removes the object at position pos
		*
		* @param pos item to be deleted
		*
		* @return Returns an iterator to the element that follows pos before the call.
		*/
		iterator erase(const_iterator itr);
		/*!
		* @brief Erase
		*
		* Removes elements in the range [first; last)
		*
		* @param first begin of range
		* @param last end of range
		*
		* @return Return the iterator for the next element valid
		*/
		iterator erase(const_iterator first, const_iterator last);
		/*!
		* @brief Find
		*
		* Search for the value element on the list
		*
		* @param value search element
		*
		* @return Return the iterator for the element valid.
		*/
		const_iterator find(const T & value) const;
		/*!
		* @brief '==' Overload
		*
		* Overload '==' operator to verify if two lists are equals
		*
		* @param this list object
		*
		* @return Return true if  two lists are equals
		*/
		bool operator==(const list & rhs);
		/*!
		* @brief '!=' Overload
		*
		* Overload '!=' operator to verify if two lists are differents
		*
		* @param this list object
		*
		* @return Return true if  two lists are differents
		*/
		bool operator!=(const list & rhs);
		/*! 
        * @brief '<<' Operator
        *
        * Prints the list on the out stream
        *
        * @param os reference of output stream
        * @param v_ reference of list object
        *
        * @return Return ostream output stream
        */

	};
}

#include "iterator.inl"
#include "const_iterator.inl"
#include "list.inl"

#endif
