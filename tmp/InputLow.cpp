#include "InputLow.h"
  
#include <stdio.h>

InputLow InputLow::m_INPUT_LOW("INPUT_LOW");

InputLow::InputLow(const char* uValue) : Node(uValue) {}

InputLow::InputLow() {}

void InputLow::action() const
{
        printf("This is an action method from node %s\n", type);
}

void InputLow::draw() const
{
        printf("This is an %s node!\n", type);
}

Node* InputLow::clone() const
{
    return new InputLow;
}
