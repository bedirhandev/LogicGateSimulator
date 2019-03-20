#include "NotGate.h"

#include <stdio.h>

NotGate NotGate::m_notGate("NOT");

NotGate::NotGate(std::string uValue) : Node(uValue) {}
                        
NotGate::NotGate() {}

/* The method action for each type of gate (node)
 * takes other nodes as parameter
 * and links it to their input respectively
 * Eventually, rather fortunate it is possible to create
 * a list with type node and read the output the output is a type of char 
 * (the INPUT_HIGH and INPUT_LOW variants: their input and output is the same)
 * At last the output of a node is feeded to their relevants and act on the output of the
 * current node that is worked on...
 */
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

