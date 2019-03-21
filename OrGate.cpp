#include "OrGate.h"

#include <stdio.h>

OrGate OrGate::m_orGate("OR");

OrGate::OrGate(std::string uValue) : Node(uValue) {}
                        
OrGate::OrGate() {}

void OrGate::action() 
{
	this->draw();
	printf("This node has %lu input pins: ", IN.size());

	this->output = 0;
	for(auto& node : this->IN) {
		if(node.lock()->output == 1) {
			this->output = 1;
			break;
		}
	}

	for(auto& node : this->IN) {
                printf("[%s: %d] ", node.lock()->id.c_str(), node.lock()->output);
        }

	printf("\n\n");
}

std::string OrGate::getType() {
	return type;
}

void OrGate::draw() const
{
    	printf("This is %s an %s gate!\n", id.c_str(), type.c_str());
}

Node* OrGate::clone() const
{
    return new OrGate;
}

