#pragma once

// List implementation with indexed structures and basic Elem type with sorting
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

namespace listt
{

    /**************************** Types and costants *********************************************/
    const int BLOCKDIM = 100;
    typedef string Elem; // base type, compatible with the Label type of the tree

    const Elem emptyElem = "$#$#$";
    struct list
    {
        Elem *list;
        int size;
        int maxsize;
    };

    typedef list List;

    /************************* Stateful operations (with side effect) ******************************************/

    void clear(List &);          /* "dismantles" the list */
    void set(int, Elem, List &); /* changes the element at position pos */
    void add(int, Elem, List &); /* adds the element at position pos, shifting to the right the other elements */
    void addBack(Elem, List &);  /* adds the element at the end of the list */
    void addFront(Elem, List &); /* adds the element at the beginning of the list */
    void removePos(int, List &); /* deletes the element at position pos  */

    /************************* Stateless operations (functional) ******************************************/

    Elem get(int, const List &); /* returns the element at position pos */
    List createEmptyList();      /* creates and returns the empty list */
    bool isEmpty(const List &);
    int size(const List &);
}

void printList(const listt::List &);