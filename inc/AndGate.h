#pragma once

#include "Node.h"

class AndGate : public Node
{
	private:
		AndGate(std::string);
		AndGate();

		void action();
		void draw() const;
		Node *clone() const;
		std::string getType();
	private:
		static AndGate m_andGate;
};
