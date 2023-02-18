decision-tree
In a decision tree each internal node represents a variable, an arc towards a child node represents a possible value (or a set of values) for that variable and a leaf the value predicted by the decision tree from the values ​​of the other variables, which in the tree is represented by the path (path) from the root node to the leaf node.

In mine implementation of a decision tree we assume that the values ​​that a variable can take can be numeric or simple belonging to a certain category. In particular, we can divide the types of variables that can be used in a decision tree into two:

Quantitative variables. For example: weight, height, age, cost of a product
Qualitative variables with values ​​that cannot be ordered (nominal scale). They are also called categorical variables. For example the Blood Group (which can take the following values: O, A, B, AB) or the type of disease. On the quantitative variables are present the equality relations (equal and different) and the order relations (ie: minor, major, minor and equal, greater and equal) while for qualitative variables with non-ordinable values ​​(nominal scale) is present only the relationship of equality.
Input file format The first line of the file must contain the label of the root and the following lines must contain as the first label that of a node (which must already have been listed before) followed by the label pairs of one of its children and the corresponding label that represents the condition of the arc. In order not to complicate things too much, node labels and conditions are strings that do not contain the space character. Conditions are strings that begin with a relational operator between the following {=, ≠, <,>, <=,> =} followed by a value of a variable (in the case of the example the values of the variable Age are numbers integers, while the values of the Type variable are Sportiva, Truck and Family strings.

root

root node1 cond1 node2 cond2 node3 cond3

node1 node4 cond4 node5 cond5 node6 cond6 .......

node2 node7 cond7 node8 cond8 node9 cond9 .......

In our Test.txt file, the example input is as follows:

Age_1

Age_1 Risk_1 <=23 Type_1 >23

Risk_1 END_1 =A

Type_1 Risk_2 =Sports Risk_3 =Truck Risk_4 =Family

Risk_2 END_2 =A

Risk_3 END_3 =B

Risk_4 END_4 =B

Functionalities of this Implementation This C++ Decision Tree implementations allows users to:

read a decision tree from file and modify it with the operations delete node, add node, edit node;
display the decision tree in a textual way on the terminal;
infer and view the decision tree variables (in our example in the figure the program displays Age, Risk and Type);
carry out a prediction starting from a previously entered decision tree. In particular, the program asks the user, one at a time, the values to be associated with the variables during the path leading to the prediction;
carry out a prediction starting from a previously inserted decision tree and from a set of variable values. The program requests a set of pairs (variable, value) separated with a ';'.
Handling of special cases

There may be cases, depending on the input, in which there is more than one true condition on the edges (for example if we have two conditions a = 5 and a > 4 on the two edges and the value of 'a' is equal to '5') or cases where none condition is true (for example when we have the conditions a = 5 and a > 5 on the only two edges and the value of 'a' is '4'). In the first case the program will randomly choose one of the arcs that have the true condition. In the second case the program will print the text: "the prediction cannot take place because there is a node for which there is no viable arc".
