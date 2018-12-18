#ifndef CSTLIST_H
#define CSTLIST_H

#include <iostream>

template <typename ltype>
class CstList
{
public:
    CstList();
    ~CstList();
    CstList(const CstList &rv);

    CstList& operator =(const CstList& rv);
    CstList& operator <<(const ltype rv);
    ltype& operator [](int n);

    ltype& front();
    ltype& back();

    ltype& get(unsigned long pos);
    void set(unsigned long pos, ltype value);
    bool isEmpty();
    unsigned long getSize() const;
    void clear();
    void insert(unsigned long pos, ltype var);
    void erase(unsigned long pos);
    void push_back(ltype var);
    void push_front(ltype var);
    ltype pop_back();
    ltype pop_front();
    void merge(CstList &with);
    void split(CstList &right, unsigned long pos);
    void reverse();
    void unique();
    void sort(bool ascending = false);
    void swap(unsigned long cell1, unsigned long cell2);
    void print();

private:
    struct cell
    {
        cell *prev;
        ltype data;
        cell *next;
    };

    unsigned long size;
    cell *first;
    cell *last;

    CstList copyList(const CstList &rv);

    /** @brief Returns pointer to the cell with the pos number.
      *
      * @param[in]  pos    Number of cell which ponter will be returned.
      */
    cell* find(unsigned long pos)
    {
        if(pos > size) {
            return nullptr;
        }

        cell *l_next;
        l_next = first;
        for(unsigned long i=0; i<pos; i++) {
            l_next = l_next->next;
        }
        return l_next;
    }
};

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

    last = first;
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

/** @brief Overloaded << operator, used to insert elements at the back of the list.
  *
  * @param[in]  data    Data element which will be inserted.
  */
template <typename ltype>
CstList<ltype>& CstList<ltype>::operator<<(const ltype rv)
{
    push_back(rv);
    return *this;
}

/** @brief Overloaded << operator, used to insert elements at the back of the list.
  *
  * @param[in]  data    Data element which will be inserted.
  */
template <typename ltype>
ltype& CstList<ltype>::operator [](int n)
{
    return get(n);
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
    return first->data;
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
    return first->data;
}

/** @brief Sets element at pos to value.
  *
  * @param[in]  pos      Position of the element.
  * @param[in]  value    Value to be setted.
  */
template <typename ltype>
void CstList<ltype>::set(unsigned long pos, ltype value)
{
    cell *target = find(pos);
    target->data = value;
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
        erase(i);
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

/** @brief Inserts element before the pos number.
  *
  * @param[in]  pos    Number of cell before the element will be inserted
  * @param[in]  var    Data to be inserted
  */
template <typename ltype>
void CstList<ltype>::insert(unsigned long pos, ltype var)
{
    if(size < pos) {
        return;
    }

    if(size == 0) { // if list is empty
        first->data = var;
        size++;
        return;
    }

    cell *new_cell = new cell;
    cell *next, *previous;
    if(size == pos) { // last position
        next = nullptr;
        previous = last;
    }
    else {
        next = find(pos);
        previous = next->prev;
    }

    new_cell->prev = previous;
    new_cell->next = next;
    new_cell->data = var;

    if(pos == 0) { // first position
        first = new_cell;
        next->prev = new_cell;
    }
    else if(pos == size) { // last position
        last = new_cell;
        previous->next = new_cell;
    }
    else { // middle position
        previous->next = new_cell;
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
    cell *target = find(pos);
    return target->data;
}

/** @brief Erases element from list.
  *
  * @param[in]  pos    Number of cell which will be erased.
  */
template <typename ltype>
void CstList<ltype>::erase(unsigned long pos)
{
    if(size <= pos) {
        return;
    }

    if(size == 1) {
        first->data = 0;
        first->next = nullptr;
        size = 0;
        return;
    }

    cell *target = find(pos);
    cell *previous, *next;

    if(target == first) { // first position
        first = target->next;
        first->prev = nullptr;
    }
    else if(target == last) { // last position
        last = target->prev;
        last->next = nullptr;
    }
    else { // middle position
        previous = target->prev;
        next = target->next;

        next->prev = previous;
        previous->next = next;
    }

    delete target;
    size--;
}

/** @brief Inserts element to the back of the list.
  *
  * @param[in]  var     Data to insert.
  */
template <typename ltype>
void CstList<ltype>::push_back(ltype var)
{
    insert(size, var);
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

/** @brief Merges one list to another, clears target_which.
  *
  * @param[in]  target_to       Link to list which will include second list.
  * @param[in]  target_which    Link to list which will be merged into the first list and will be cleared.
  */
template <typename ltype>
void CstList<ltype>::reverse()
{
    cell *current = first;
    first = last;
    last = current;

    cell *temp;
    for(unsigned long i=0; i<size; i++) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;
    }
}

/** @brief Erases excess similar elements if they stand in a row
  *
  * Use it for sorted lists!
  */
template <typename ltype>
void CstList<ltype>::unique()
{
    cell *current = first;
    for(unsigned long i=0; i<size; i++) {
        if(current->next->data == current->data) {
            erase(i+1);
        }
    }
}

/** @brief Merges one list to another, clears with.
  *
  * @param[in]  with    Link to list which will be merged into the list and will be cleared.
  */
template <typename ltype>
void CstList<ltype>::merge(CstList<ltype> &with)
{
    if(isEmpty() || with.isEmpty()) {
        return;
    }

    last->next = with.first;
    last = with.last;
    size += with.size;

    with.size = 0;
    with.first = new cell;
    with.last = with.first;
    with.first->data = 0;
}

/** @brief Splits list into to parts
  *
  * @param[in]  right      List for the right side of the splitted list (will be cleared).
  * @param[in]  pos        Position before list will be splitted.
  */
template <typename ltype>
void CstList<ltype>::split(CstList<ltype> &right, unsigned long pos)
{
    if(size < 2) {
        return;
    }

    right.clear();
    cell *crack = find(pos);
    cell *first_right = crack->next;

    right.size = size-pos-1;
    right.first = first_right;
    right.last = last;
    first_right->prev = nullptr;

    size = pos+1;
    last = crack;
    crack->next = nullptr;
}

/** @brief Sorts list
  *
  * @param[in]  ascending   If it will be ascending sort - set it to true
  */
template <typename ltype>
void CstList<ltype>::sort(bool ascending)
{
    if(size > 1) {
        const unsigned long left_size = size / 2;
        const unsigned long right_size = size - left_size;

        CstList right, left, temp;
        left = *this;
        split(right, left_size);

        sort(ascending);
        right.sort(ascending);

        unsigned long lidx = 0, ridx = 0;

        while (lidx < left_size || ridx < right_size) {
            if (left.get(lidx) < right.get(ridx)) {
                temp.push_back(left.get(lidx));
                lidx++;
            }
            else {
                temp.push_back(right.get(ridx));
                ridx++;
            }

            if (lidx == left_size) {
                temp.merge(right);
                break;
            }
            if (ridx == size) {
                temp.merge(left);
                break;
            }
        }

        *this = temp;
    }
}


#endif // CSTLIST_H
