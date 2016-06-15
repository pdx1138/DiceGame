// LinkedList.h
//
// Using the templeted method to define a list of abstract objects.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class LinkedList;

template <class T>
class ListElement{
	friend LinkedList<T>;

	ListElement(T _datum);
	ListElement(T const& _datum, ListElement* _next);

	public: 
		T const& Datum () const;
		ListElement const* Next() const;
	
	private:
		T datum;
		ListElement* next;
};

template <class T>
class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		
		LinkedList (LinkedList const& linkedList);
		LinkedList& operator = (LinkedList const& linkedList);

		ListElement<T> Head();
		ListElement<T> Tail();

		bool IsEmpty() const;

		void Prepend (T const& item);
		void Append (T const& item);
		void Remove (T const& item);
		T Export(int position);
		T Export(T item);
		void Purge();
		T const& First() const;
		T const& Last() const;
		void InsertAfter(ListElement<T> const* arg, T const& item);
		void InsertBefore(ListElement<T> const* arg, T const& item);
		int Size();
		T const& Find(int position) const;
		bool IsInList(T item);
		bool IsInList(T item, int& position);

	private:
		ListElement<T>* head;
		ListElement<T>* tail;
};

template <class T>
T const& ListElement<T>::Datum() const 
	{ return datum; }

template <class T>
ListElement<T> const* ListElement<T>::Next() const
	{ return next; }

template <class T>
ListElement<T>::ListElement(T const& _datum, ListElement<T>* _next) {
	this->datum = _datum;
	this->next = _next;
}

template <class T>
ListElement<T>::ListElement(T _datum) {
	this->datum = _datum;
	this->next = nullptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
LinkedList<T>::LinkedList() {
	this->head = nullptr;
	this->tail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() 
	{ Purge(); }

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> const& linkedList) : head(0), tail(0) {
	ListElement<T> const* ptr;
	for(ptr = linkedList.head; ptr!= 0; ptr = ptr->next) {
		Append(ptr->datum);
	}
}

template <class T>
void LinkedList<T>::Purge() {
	//this->tail = NULL;
	while(this->head != 0) {
		ListElement<T>* const tmp = this->head;
		this->head = this->head->next;
		delete tmp;
	}

	this->head = nullptr;
	this->tail = nullptr;
	/*if (tail != 0) {
		delete tail;
	}*/
}

template <class T>
ListElement<T> LinkedList<T>::Head()
	{ return *this->head; }

template <class T>
ListElement<T> LinkedList<T>::Tail()
	{ return *this->tail; }

template <class T>
bool LinkedList<T>::IsEmpty() const
	{ return (this->head == 0); }

template <class T>
void LinkedList<T>::Prepend(T const& item) {
	ListElement<T>* const tmp = new ListElement<T>(item, this->head);
	if(this->head == 0) this->tail = tmp;
	this->head = tmp;
}

template <class T>
void LinkedList<T>::Append(T const& item) {
	ListElement<T>* const tmp = new ListElement<T>(item, nullptr);
	if(head == nullptr) head = tmp;
	else tail->next = tmp;
	tail = tmp;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator = (LinkedList<T> const& linkedList) {
	if(&linkedList != this) {
		Purge();
		ListElement<T> const* ptr;
		for(ptr = linkedList.head; ptr != 0; ptr = ptr->next) Append(ptr->datum);
	}
	return *this;
}

template <class T>
void LinkedList<T>::Remove (T const& item) {
	ListElement<T>* ptr = this->head;
	ListElement<T>* prevPtr = 0;

	while(ptr != 0 && ptr->datum != item) {
		prevPtr = ptr;
		ptr = ptr->next;
	}

	if(ptr == 0) return;
	
	if(ptr == this->head) this->head = ptr->next;
	else prevPtr->next = ptr->next;

	if(ptr == this->tail) this->tail = prevPtr;

	delete ptr;
}

template <class T>
T LinkedList<T>::Export(int position) {
	int count = 0;
	ListElement<T>* ptr = this->head;
	ListElement<T>* prevPtr = 0;
	
	while(ptr != 0 && count != position) {
		prevPtr = ptr;
		ptr = ptr->next;
		++count;
	}

	if (ptr == 0) {
		return nullptr;//return T();
	}

	if (ptr == head && ptr == tail) {
		this->head = nullptr;
		this->tail = nullptr;
		return ptr->Datum();
	}
	if(ptr == head) {
		this->head = this->head->next;
		return ptr->Datum();
	}
	if(ptr == tail) {
		this->tail = prevPtr;
		return ptr->Datum();
	} 
	prevPtr->next = ptr->next;
	return ptr->datum;
}

template <class T>
T LinkedList<T>::Export(T item) {
	ListElement<T>* ptr = head;
	ListElement<T>* prevPtr = 0;
	
	while(ptr != nullptr) {
		if(ptr->Datum() == item) {
			if(ptr == this->head) {
				this->head = this->head->next;
				return ptr->Datum();
			}
			if(ptr == this->tail) {
				this->tail = prevPtr;
				return ptr->Datum();
			}

			else { 
				prevPtr->next = ptr->next;
				return ptr->Datum();
			}
		}

		prevPtr = ptr;
		ptr = ptr->next;

		
	}

	return false;
}

template <class T>
void LinkedList<T>::InsertAfter(ListElement<T> const* arg, T const& item) {
	ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);
	if(ptr == 0) return;
	ListElement<T>* const tmp = new ListElement<T> (item, ptr->next);
	ptr->next = tmp;
	if(this->tail == ptr) this->tail = tmp;
}

template <class T>
void LinkedList<T>::InsertBefore(ListElement<T> const* arg, T const& item) {
	ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);
	if(ptr == 0) return;
	ListElement<T>* const tmp = new ListElement<T> (item, ptr->next);
	ptr->next = tmp;
	if(this->head == ptr) this->head = tmp;
	else {
		ListElement<T> prevPtr = this->head;
		while(prevPtr != 0 && prevPtr->next != ptr) prevPtr = prevPtr->next;
		if(prevPtr == 0) return;
		prevPtr->next = tmp;
	}
}

template <class T>
T const& LinkedList<T>::First() const {
	if(this->head == 0) return nullptr;
	return this->head->datum;
}

template <class T>
T const& LinkedList<T>::Last() const {
	if(this->tail == 0) return nullptr;
	return this->tail->datum;
}

template <class T>
T const& LinkedList<T>::Find(int position) const {
	int count = 0;
	ListElement<T>* ptr = this->head;
	ListElement<T>* prevPtr = 0;
	
	while(ptr != 0 && count != position) {
		prevPtr = ptr;
		ptr = ptr->next;
		++count;
	}

	if(ptr == 0) return T();

	return ptr->datum;
}

template <class T>
int LinkedList<T>::Size() {
	ListElement<T>* current;
	if(this->head == nullptr) return 0;
	current = this->head;
	int count = 1;
	while(current->next != nullptr) {
		++count;
		current = current->next;
	}
	return count;
}

template <class T>
bool LinkedList<T>::IsInList(T item) {
	ListElement<T>* ptr = this->head;
	ListElement<T>* prevPtr = 0;
	
	while(ptr != nullptr) {
		if(ptr->Datum() == item) return true;

		prevPtr = ptr;
		ptr = ptr->next;
	}

	return false;
}

template <class T>
bool LinkedList<T>::IsInList(T item, int& position) {
	int count = 0;
	ListElement<T>* ptr = this->head;
	ListElement<T>* prevPtr = 0;
	
	while(ptr != nullptr) {
		if(ptr->Datum() == item) {
			return true;
			position = count;
		}
		prevPtr = ptr;
		ptr = ptr->next;
		++count;
	}
	return false;
}


#endif 