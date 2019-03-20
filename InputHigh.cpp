#include "InputHigh.h"
  
#include <stdio.h>

InputHigh InputHigh::m_INPUT_HIGH("INPUT_HIGH");

InputHigh::InputHigh(std::string uValue) : Node(uValue, 1) {}

InputHigh::InputHigh() {} 

void InputHigh::action()
{
        this->draw();
        printf("This node has %lu input pins: ", IN.size());
        for(auto& node : this->IN) {
                 printf("[%s: %d] ", node.lock()->id.c_str(), node.lock()->output);
        }
 	printf("\n\n");
}

std::string InputHigh::getType() {
	return this->type;
}

void InputHigh::draw() const
{
        printf("This is %s an %s node!\n", id.c_str(), type.c_str());
}

Node* InputHigh::clone() const
{
    return new InputHigh;
}
