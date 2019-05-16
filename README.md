# LogicGateSimulator

# Assignment description
The task was to read a text file that contains data about a certain circuit. The circuit has to be read, built, checked on </br >errors and at the end the result of the circuit has to be printed and the error state if an error occured.</br >

# An example of text file
Description of all the nodes</br >
A: INPUT_HIGH;</br >
B: INPUT_HIGH;</br >
Cin: INPUT_LOW;</br >
Cout: PROBE;</br >
S: PROBE;</br >
NODE1: OR;</br >
NODE2: AND;</br >
NODE3: AND;</br >
NODE4: NOT;</br >
NODE5: AND</br >
NODE6: OR;</br >
NODE7: NOT;</br >
NODE8: NOT;</br ></br >
NODE9: AND;</br >
NODE10: AND;</br >
NODE11: OR;</br >
</br >
Description of all the edges</br >
Cin: NODE3,NODE7,NODE10; </br >
A: NODE1,NODE2;</br >
B: NODE1,NODE2;</br >
NODE1: NODE3,NODE5;</br >
NODE2: NODE4,NODE6;</br >
NODE3: NODE6;</br >
NODE4: NODE5;</br >
NODE5: NODE8,NODE9;</br >
NODE6: Cout;</br >
NODE7: NODE9;</br >
NODE8: NODE10;</br >
NODE9: NODE11;</br >
NODE10: NODE11;</br >
NODE11: S;</br >

# Explanation
The purpose is to connect all nodes that have a relation with another node and quickly find the end result of that circuit.  </br >
This approach could be done with for example; the BFS algorithm or the feed forward algorithm and more.  </br >

# The design patterns I used in this assignment
Factory method</br >
Prototype</br >
Strategy </br >
