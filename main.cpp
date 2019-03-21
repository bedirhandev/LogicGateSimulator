#include "CircuitReader.h"
#include "Circuit.h"

#include <stdio.h>

int main() {
	Circuit circuit;
	
	CircuitReader circuitReader("circuits/circuit1.txt");
	circuitReader.initialize(circuit.NodeMap, circuit.Path);
	
	circuit.calculate();

	return 0;
}
