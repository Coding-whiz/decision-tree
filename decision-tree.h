#pragma once

#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstring>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include "list-array.h"

using namespace std::chrono;
using namespace std;

namespace tree
{

    enum Error
    {
        OK,
        FAIL
    };

    enum End
    {
        HIGH,
        LOW,
        NOTHING
    }; // The prediction can be: HIGH (=A iin our test file), LOW (=B in out test file) o NOTHING (no prediction)

    typedef string Label;     // Labels of the nodes
    typedef string TextValue; // Conditions on the arcs

    const Label emptyLabel = "$#$#$";
    const TextValue noTextValue = "*&^*^&";

    struct treeNode; // Forward declaration; the struct is in the file decision-tree.cpp

    typedef treeNode *Tree; // The tree in this implementation is identified by the pointer to its root; the terms "tree" and "pointer to node" will be used without distinction

    const Tree emptyTree = NULL;

    Tree createEmpty();
    bool isEmpty(const Tree &);
    Error addElem(const Label, const Label, TextValue, Tree &);
    Error modifyNode(Label, Label, TextValue, Tree &);
    Error deleteElemI(const Label, Tree &);
    End predictionFromInputAtBeginning(const string, Tree &);
    End predictionFromInput(Tree &);

    // TDD Tree functions used by the decision tree editing functions
    Tree getNode(const Label l, const Tree t);
    Label father(const Label, const Tree &);
    listt::List children(const Label, const Tree &);
    int degree(const Label, const Tree &);
    bool member(const Label, const Tree &);
}

// Functions that do not refer to the TDD Tree, but which serve as input / output
tree::Tree readFromFile(string);
void printTree(const tree::Tree &);
void printVariables(tree::Tree);