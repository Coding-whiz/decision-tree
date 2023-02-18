
#include <iostream>
#include <string>
#include "decision-tree.h"

using namespace std;

int main()
{

    int choice = 0;
    char fileInput[100];
    string conditionString;

    tree::Tree tree3 = tree::emptyTree;
    tree::End endd = tree::End::NOTHING;
    tree::Tree tree = tree::createEmpty();
    string filename;
    tree::Label fatherLabel = tree::emptyLabel, newLabel = tree::emptyLabel;
    tree::TextValue newValue = tree::noTextValue;

    while (true)
    {
        cout << endl;
        cout << "1. Read the decision tree from file\n";
        cout << "2. Insert a node labeled labelChild attached to a father labeled labelFather\n";
        cout << "3. Delete a node from the tree\n";
        cout << "4. Modify a node in the tree\n";
        cout << "5. Visualize the decision tree\n";
        cout << "6. Print the variables in the decision tree\n";
        cout << "7. Make a prediction by entering all the values one at a time\n";
        cout << "8. Make prediction by entering all the values at the beginning\n";
        cout << "0. Exit\n";
        cout << "\nEnter your choice and press ENTER ---> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Insert the name of the file\n";
            cin >> filename;
            tree = readFromFile(filename);
            break;
        case 2:
            cout << "Insert the label of the father node" << endl;
            cin >> fatherLabel;

            if (tree::getNode(fatherLabel, tree) == tree::emptyTree)
            {
                cout << "There is no node with this label in the tree" << endl;
                break;
            }

            cout << "Insert the label of the node to add" << endl;
            cin >> newLabel;

            cout << "Enter the condition of the new node (e.g. '=Family' or '=A' or '<=23')" << endl;
            cin >> newValue;

            if (tree::addElem(fatherLabel, newLabel, newValue, tree) == tree::Error::OK)
                cout << "The node has been successfully added" << endl;
            else
                cout << "Operation failed" << endl;
            break;
        case 3:
            cout << "Insert the label of the node to delete" << endl;
            cin >> newLabel;

            if (tree::deleteElemI(newLabel, tree) == tree::Error::OK)
                cout << "The node has been successfully deleted" << endl;
            else
                cout << "Operation failed" << endl;
            break;
        case 4:
            cout << "Insert the label of the node to modify" << endl;
            cin >> fatherLabel;

            if (tree::getNode(fatherLabel, tree) == tree::emptyTree)
            {
                cout << "There is no node with this label in the tree" << endl;
                break;
            }

            cout << "Insert the new label of the node" << endl;
            cin >> newLabel;

            cout << "Insert the new condition of the node (e.g. <=23)" << endl;
            cin >> newValue;

            if (modifyNode(fatherLabel, newLabel, newValue, tree) == tree::Error::OK)
                cout << "The node has been successfully modified" << endl;
            else
                cout << "Operation failed" << endl;

            break;
        case 5:
            cout << "\nThe decision tree is:\n";
            printTree(tree);
            break;
        case 6:
            printVariables(tree);
            break;
        case 7:
            tree3 = tree;
            endd = predictionFromInput(tree);
            tree = tree3;

            if (endd == tree::End::HIGH)
                cout << "Prediction: High Risk" << endl;
            else if (endd == tree::End::LOW)
                cout << "Prediction: Low Risk" << endl;
            break;
        case 8:
            cout << "Enter the pairs (variable value) separated by ';'. \nE.g.: (Tipo Family); (Eta 49)" << endl;
            cin.ignore();
            cin.getline(fileInput, 100);

            filename = string(fileInput);

            tree3 = tree;
            endd = predictionFromInputAtBeginning(filename, tree);
            tree = tree3;

            if (endd == tree::End::HIGH)
                cout << "Prediction: High Risk" << endl;
            else if (endd == tree::End::LOW)
                cout << "Prediction: Low Risk" << endl;
            break;
        case 0:
            return 0;
            break;
        }
    }

    return 0;
}