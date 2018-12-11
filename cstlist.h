#ifndef CSTLIST_H
#define CSTLIST_H

template <typename ltype>
class CstList
{
public:
    CstList();
    ~CstList();
    CstList(const CstList &rv);

    CstList& operator =(const CstList& rv);
    CstList& operator <<(const CstList& rv);
    CstList& operator [](const CstList& rv);

    ltype& front();
    ltype& back();

    ltype& get(unsigned long pos);
    bool isEmpty();
    unsigned long getSize() const;
    void clear();
    void insert(unsigned long pos, ltype var);
    void erase(unsigned long pos);
    void push_back(ltype var);
    void push_front(ltype var);
    ltype pop_back();
    ltype pop_front();
    void merge(CstList target);
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

    CstList copyList(const CstList &rv);
    cell* find(unsigned long pos);

    unsigned long size;
    cell *first;
    cell *last;
};

#endif // CSTLIST_H
