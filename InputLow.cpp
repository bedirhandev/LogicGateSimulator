#include "InputLow.h"
  
#include <stdio.h>

InputLow InputLow::m_INPUT_LOW("INPUT_LOW");

InputLow::InputLow(std::string uValue) : Node(uValue) {}

InputLow::InputLow() {}

void InputLow::action()
{
        this->draw();
        printf("This node has 0 input pins.");
        for(auto& node : this->IN) {
                 printf("[%s: %d] ", node.lock()->id.c_str(), node.lock()->output);
        }
        printf("\n\n");
}

std::string InputLow::getType() {
	return type;
}

void InputLow::draw() const
{
        printf("This is %s an %s node!\n", id.c_str(), type.c_str());
}

Node* InputLow::clone() const
{
    return new InputLow;
}
