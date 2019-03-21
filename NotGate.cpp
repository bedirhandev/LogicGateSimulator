#include "NotGate.h"

#include <stdio.h>

NotGate NotGate::m_notGate("NOT");

NotGate::NotGate(std::string uValue) : Node(uValue) {}
                        
NotGate::NotGate() {}

void NotGate::action()
{
        this->draw();
        printf("This node has %lu input pins: ", IN.size());
        for(auto& node : this->IN) {
                this->output = !node.lock()->output; 
       	}

	for(auto& node : this->IN) {
                printf("[%s: %d] ", node.lock()->id.c_str(), node.lock()->output);
        }

        printf("\n\n");
}

std::string NotGate::getType() {
	return this->type;
}

void NotGate::draw() const
{
        printf("This is %s an %s gate!\n", id.c_str(), type.c_str());
}

Node* NotGate::clone() const
{
    return new NotGate;
}

