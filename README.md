# LogicGateSimulator

# Assignment description
The task was to read a text file that contains data about a certain circuit. The circuit has to be read, built, checked on errors and at the end the result of the circuit has to be printed and the error state if an error occured.

# An example of text file
Description of all the nodes
A: INPUT_HIGH;
B: INPUT_HIGH;
Cin: INPUT_LOW;
Cout: PROBE;
S: PROBE;
NODE1: OR;
NODE2: AND;
NODE3: AND;
NODE4: NOT;
NODE5: AND
NODE6: OR;
NODE7: NOT;
NODE8: NOT;
NODE9: AND;
NODE10: AND;
NODE11: OR;

Description of all the edges
Cin: NODE3,NODE7,NODE10;
A: NODE1,NODE2;
B: NODE1,NODE2;
NODE1: NODE3,NODE5;
NODE2: NODE4,NODE6;
NODE3: NODE6;
NODE4: NODE5;
NODE5: NODE8,NODE9;
NODE6: Cout;
NODE7: NODE9;
NODE8: NODE10;
NODE9: NODE11;
NODE10: NODE11;
NODE11: S;

# Explanation
The purpose is to connect all nodes that have a relation with another node and quickly find the end result of that circuit.  
This approach could be done with for example; the BFS algorithm or the feed forward algorithm and more.  

# The design patterns I used in this assignment
Factory method . 
Prototype . 
Strategy . 
