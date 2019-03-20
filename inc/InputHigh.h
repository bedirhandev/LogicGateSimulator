#pragma once
  
#include "Node.h"

class InputHigh : public Node
{
        private:
                InputHigh(std::string);
                InputHigh();

                void action();
                void draw() const;
                Node *clone() const;
        	std::string getType();
	private:
                static InputHigh m_INPUT_HIGH;
};
