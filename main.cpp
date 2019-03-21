#include "CircuitReader.h"
#include "Circuit.h"

#include <stdio.h>

int main() {
	char index, c = 0;
	std::string circuits[4] { "circuit1.txt", "circuit2.txt", "circuit3.txt", "circuit4.txt" };

	std::cout << "Welcome, press a key to start reading the circuits.." << std::endl;

	while(std::cin.get(c)) 
	{
		if(index == sizeof(circuits) / sizeof(circuits[0])) break;

		Circuit circuit;

		CircuitReader circuitReader("circuits/" + circuits[index]);
		circuitReader.initialize(circuit.NodeMap, circuit.Path);

		circuit.calculate();
		
		index++;
	}

	return 0;
}
