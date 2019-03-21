#include "Circuit.h"

Circuit::Circuit() {}
Circuit::~Circuit() {}

void Circuit::draw()
{
}

void Circuit::calculate()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CALCULATING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
        for(auto const& id : Path)
        {
                if(id.find("NODE") != std::string::npos) {
                        NodeMap[id]->action();
                }
        }


	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FINAL RESULTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
	for(auto const& probe : NodeMap) {
                if(probe.second->getType() == "PROBE") {
                        probe.second->action();
                }
        }
}
