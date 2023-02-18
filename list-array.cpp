#include "list-array.h"

using namespace listt;

/****************************************************************/
/* 		  Operations with side effect                    */
/****************************************************************/

/****************************************************************/
void listt::clear(List &l)
{
    l.size = 0;
    l.maxsize = BLOCKDIM;
    Elem *aux = new Elem[BLOCKDIM];
    delete[] l.list;

    l.list = aux;
}

/****************************************************************/
void listt::set(int pos, Elem e, List &l) // "set" as in setting a value, not the TDD Set
{
    if (pos < 0 || pos > (l.size) - 1)
        return;
    l.list[pos] = e;
}

/****************************************************************/
void listt::add(int pos, Elem e, List &l) // adds e at position pos
{
    if (pos < 0 || pos > l.size)
        return;

    if (l.size == l.maxsize) // the array is full, in order to insert a new element I have to resize the array expanding it; the only way is to create a larger array and copy the elements of l into it
    {
        List auxList;
        auxList.size = l.size + 1;
        auxList.maxsize = l.maxsize + BLOCKDIM;
        Elem *auxArray = new Elem[auxList.maxsize];
        auxList.list = auxArray;
        for (int i = 0; i < pos; ++i)
            auxList.list[i] = l.list[i];
        auxList.list[pos] = e;
        for (int i = pos + 1; i < auxList.size; ++i)
            auxList.list[i] = l.list[i - 1];
        delete[] l.list;
        l = auxList;
        return;
    }

    // if the function has not encountered a return, it means that pos is in the correct range and the array is not full; we just have to place the item in pos and shift the others to the right, updating the size of the list
    l.size++;
    for (int i = l.size - 1; i > pos; --i)
        l.list[i] = l.list[i - 1];
    l.list[pos] = e;
}

/****************************************************************/
void listt::addBack(Elem e, List &l) // adds e at the back
{
    add(l.size, e, l);
}

/****************************************************************/
void listt::addFront(Elem e, List &l) // adds e at the front
{
    add(0, e, l);
}

/****************************************************************/
void listt::removePos(int pos, List &l)
{
    if (pos < 0 || pos >= l.size)
        return;

    // if removing the element frees BLOCKDIM cells, then we have to resize the array; the only way is to create a smaller array and copy the elements of l into it
    if (l.maxsize - l.size + 1 == BLOCKDIM && l.maxsize > BLOCKDIM)
    {
        List auxList;
        auxList.size = l.size - 1;
        auxList.maxsize = l.maxsize - BLOCKDIM;
        Elem *auxArray = new Elem[auxList.maxsize];
        auxList.list = auxArray;
        for (int i = 0; i < pos; ++i)
            auxList.list[i] = l.list[i];
        for (int i = pos; i < auxList.size; ++i)
            auxList.list[i] = l.list[i + 1];
        delete[] l.list;
        l = auxList;
        return;
    }

    // if the function has not encountered a return, it means that pos is in the correct range and the list cannot be reduced in size; we just have to shift the others to the left, updating the size of the list.
    for (int i = pos + 1; i < l.size; ++i)
        l.list[i - 1] = l.list[i];
    l.size--;
}

/****************************************************************/
/* 		  Operations without side effect                    */
/****************************************************************/

List listt::createEmptyList()
{
    List l;
    l.size = 0;
    l.maxsize = BLOCKDIM;
    Elem *aux = new Elem[BLOCKDIM];
    l.list = aux;
    return l;
}

/****************************************************************/
Elem listt::get(int pos, const List &l)
{
    if (pos < 0 || pos >= l.size)
        return emptyElem;
    return l.list[pos];
}

/****************************************************************/
bool listt::isEmpty(const List &l)
{
    return (l.size == 0);
}

/****************************************************************/
int listt::size(const List &l)
{
    return l.size;
}

/****************************************************************/
void printList(const List &l)
{
    cout << endl;
    for (int i = 0; i < l.size; ++i)
        cout << l.list[i] << "; ";
    cout << endl;
}
