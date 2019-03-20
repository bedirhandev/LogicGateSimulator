#pragma once
  
#include "Node.h"

class InputLow : public Node
{
        private:
                InputLow(std::string);
                InputLow();

                void action();
                void draw() const;
                Node *clone() const;
        	std::string getType();
	private:
                static InputLow m_INPUT_LOW;
};
