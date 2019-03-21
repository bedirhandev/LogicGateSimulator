#include "AndGate.h"

#include <stdio.h>

AndGate AndGate::m_andGate("AND");

AndGate::AndGate(std::string uValue) : Node(uValue) {}
                        
AndGate::AndGate() {}

void AndGate::action()
{
        this->draw();
        printf("This node has %lu input pins: ", IN.size());

	for(auto& node : this->IN) {
		this->output = 1;
		if(node.lock()->output == 0) {
			this->output = 0;
			break;
		}
	}

	for(auto& node : this->IN) {
		printf("[%s: %d] ", node.lock()->id.c_str(), node.lock()->output);
	}
        printf("\n\n");
}

std::string AndGate::getType() {
	return this->type;
}

void AndGate::draw() const
{
        printf("This is %s an %s gate!\n", id.c_str(), type.c_str());
}

Node* AndGate::clone() const
{
    return new AndGate;
}

