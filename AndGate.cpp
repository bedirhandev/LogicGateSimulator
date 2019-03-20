#include "AndGate.h"

#include <stdio.h>

AndGate AndGate::m_andGate("AND");

AndGate::AndGate(std::string uValue) : Node(uValue) {}
                        
AndGate::AndGate() {}

/* The method action for each type of gate (node)
 * takes other nodes as parameter
 * and links it to their input respectively
 * Eventually, rather fortunate it is possible to create
 * a list with type node and read the output the output is a type of char 
 * (the INPUT_HIGH and INPUT_LOW variants: their input and output is the same)
 * At last the output of a node is feeded to their relevants and act on the output of the
 * current node that is worked on...
 */
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

