#include "Probe.h"
  
#include <stdio.h>

Probe Probe::m_PROBE("PROBE");

Probe::Probe(std::string uValue) : Node(uValue) {}

Probe::Probe() {}

void Probe::action()
{
        this->draw();
        printf("This node has %lu input pins: ", IN.size());
        for(auto& node : this->IN) {
                 printf("[%s: %d] ", node.lock()->id.c_str(), node.lock()->output);
        }
        printf("\n\n");
}

std::string Probe::getType() {
	return type;
}

void Probe::draw() const
{
        printf("This is %s a %s node\n", id.c_str(), type.c_str());
}

Node* Probe::clone() const
{
    return new Probe;
}
