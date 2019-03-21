#include "Circuit.h"

#include <algorithm>

#define PROBE "PROBE"

Circuit::Circuit() {}
Circuit::~Circuit() {}

void Circuit::calculate()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CALCULATING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
        for(auto const& id : Path)
        {
		if(NodeMap[id]->getType() != PROBE) {
			NodeMap[id]->action();
		}
	}

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FINAL RESULTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
	for(auto const& id : Path) {
                if(NodeMap[id]->getType() == PROBE) {
                        NodeMap[id]->action();
                }
        }
}
