#include "cstlist.h"

#include <iostream>

/** @brief Constructor
  *
  * Doing some initialization and allocating space storage for the first cell
  */
template <typename ltype>
CstList<ltype>::CstList()
{
    first = new cell;
    first->prev = nullptr;
    first->data = 0;
    first->next = nullptr;

    last = nullptr;
    size = 0;
}

/** @brief Destructor
  *
  * Frees all of the allocated storage
  */
template <typename ltype>
CstList<ltype>::~CstList()
{
    clear();
}

/** @brief Copying constructor
  *
  * Allocates new space and copies all cells of the target to it
  * @param[in]  rv     Instant of class which we will be copying
  */
template <typename ltype>
CstList<ltype>::CstList(const CstList<ltype> &rv)
{
    size = rv.size;
    first = new cell;
    first->prev = nullptr;

    cell* current_rv = rv.first;
    cell* current = first;
    for(unsigned long i=0; i<size; i++) {
        current->data = current_rv->data;
        if(current_rv->next != nullptr) {
            current->next = new cell;
            cell* prev = current;
            current = current->next;
            current_rv = current_rv->next;
            current->prev = prev;
        }
        else {
            current->next = nullptr;
            last = current;
        }
    }
}

/** @brief Overloaded = operator
  *
  * Allocates new space and copies all cells of the target to it
  * @param[in]  rv     Instant of class which we will be copying
  */
template <typename ltype>
CstList<ltype>& CstList<ltype>::operator=(const CstList<ltype>& rv)
{
    size = rv.size;
    first = new cell;
    first->prev = nullptr;

    cell* current_rv = rv.first;
    cell* current = first;
    for(unsigned long i=0; i<size; i++) {
        current->data = current_rv->data;
        if(current_rv->next != nullptr) {
            current->next = new cell;
            cell* prev = current;
            current = current->next;
            current_rv = current_rv->next;
            current->prev = prev;
        }
        else {
            current->next = nullptr;
            last = current;
        }
    }
    return *this;
}

/** @brief Gets last element, deletes it and return it.
  *
  */
template <typename ltype>
ltype CstList<ltype>::pop_back()
{
    ltype val = back();
    erase(size-1);
    return val;
}

/** @brief Gets first element, deletes it and return it.
  *
  */
template <typename ltype>
ltype CstList<ltype>::pop_front()
{
    ltype val = front();
    erase(0);
    return val;
}

/** @brief Returns link to the first element.
  *
  */
template <typename ltype>
ltype& CstList<ltype>::front()
{
    if(!isEmpty()) {
        return first->data;
    }
}

/** @brief Returns link to the last element.
  *
  */
template <typename ltype>
ltype& CstList<ltype>::back()
{
    if(!isEmpty()) {
        return last->data;
    }
}

/** @brief Returns true if list is empty.
  *
  */
template <typename ltype>
bool CstList<ltype>::isEmpty()
{
    if(size == 0) {
        return true;
    }
    return false;
}

/** @brief Clears all cells of list and reallocates all memory.
  *
  */
template <typename ltype>
void CstList<ltype>::clear()
{
    for(unsigned long i=0; i<size; i++) {
        pop_back();
    }
    size = 0;
}

/** @brief Returns size of the list.
  *
  */
template <typename ltype>
unsigned long CstList<ltype>::getSize() const
{
    return size;
}

/** @brief Swaps cells of argument numbers.
  *
  * @param[in]  cell1    Number of first cell.
  * @param[in]  cell2    Number of second cell.
  */
template <typename ltype>
void CstList<ltype>::swap(unsigned long cell1, unsigned long cell2)
{
    if(size < cell2 || size < cell1) {
        return;
    }

    ltype data1, data2, tmp;
    data1 = get(cell1);
    data2 = get(cell2);

    tmp = data1;
    data1 = data2;
    data2 = tmp;
}

/** @brief Inserts element after the pos number.
  *
  * @param[in]  pos    Number of cell after which element will be inserted
  * @param[in]  var    Data to be inserted
  */
template <typename ltype>
void CstList<ltype>::insert(unsigned long pos, ltype var)
{
    if(size < pos) {
        return;
    }

    cell* find;
    find = first;
    for(unsigned long i=0; i<pos; i++) { // TODO ???
        find = find->next;
    }

    cell* new_cell = new cell;
    cell* previous = find;
    cell* next = find->next;
    previous->next = new_cell;
    new_cell->data = var;

    if(find->next == nullptr) { // TODO ??
        next->prev = nullptr;
    }
    else {
        next->prev = new_cell;
    }

    size++;
}

/** @brief Returns link to data of the pos number.
  *
  * @param[in]  pos    Number of cell which data will be returned
  */
template <typename ltype>
ltype& CstList<ltype>::get(unsigned long pos)
{
    cell *l_next;
    l_next = first;
    for(unsigned long i=0; i<pos; i++) {
        l_next = l_next->next;
    }
    return l_next->data;
}

/** @brief Erases element from list.
  *
  * @param[in]  pos    Number of cell which will be erased.
  */
template <typename ltype>
void CstList<ltype>::erase(unsigned long pos)
{
    cell *l_next;
    l_next = first;
    for(unsigned long i=0; i<pos; i++) {
        l_next = l_next->next;
    }

    cell* previous = l_next->prev;
    cell* next = l_next->next;

    next->prev = previous;
    previous->next = next;
    delete l_next;
    size--;
}

/** @brief Inserts element to the back of the list.
  *
  * @param[in]  var     Data to insert.
  */
template <typename ltype>
void CstList<ltype>::push_back(ltype var)
{
    insert(size-1, var);
}

/** @brief Inserts element to the front of the list.
  *
  * @param[in]  var     Data to insert.
  */
template <typename ltype>
void CstList<ltype>::push_front(ltype var)
{
    insert(0, var);
}

/** @brief Prints all of elements of list into cout.
  *
  */
template <typename ltype>
void CstList<ltype>::print()
{
    for(unsigned long i=0; i<size; i++) {
        std::cout << i << " value: " << get(i) << std::endl;
    }
}

/** @brief Erases element from list.
  *
  * @param[in]  pos    Number of cell which will be erased.
  */
template <typename ltype>
cell* CstList<ltype>::find(unsigned long pos)
{

}

template class CstList<int>;
template class CstList<double>;
template class CstList<bool>;

/*
CstList& operator [](const CstList& rv);
CstList& operator <<(const CstList& rv);

void merge(CstList target);
void reverse();
void unique();
void sort(bool ascending = false);
*/
