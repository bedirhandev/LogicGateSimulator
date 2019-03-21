#include "CircuitReader.h"
#include "Circuit.h"
#include <stdio.h>

#define GATE "NODE"

typedef std::map<std::string, std::shared_ptr<Node>> _NodeMap;
typedef std::vector<std::string> _Path;

_NodeMap NodeMap;
_Path Path;

// circuit behaviour this calls the draw() method 
// from all nodes existing in the circuit
inline void draw(_NodeMap map, _Path path) 
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CALCULATING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
	for(auto const& id : path) 
	{
		if(id.find(GATE) != std::string::npos) {	
			map[id]->action();
		}
	} 
}

int main(void) {
	CircuitReader circuitReader("circuits/circuit3.txt");
	circuitReader.initialize(NodeMap, Path);

	draw(NodeMap, Path);

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FINAL RESULTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
	
	for(auto const& probe : NodeMap) {
		if(probe.second->getType() == "PROBE") {
			probe.second->action();	
		}
	}
	
	return 0;
}
