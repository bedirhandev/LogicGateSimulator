#pragma once

#include "Node.h"

class OrGate : public Node
{
	private:
		OrGate(std::string);
		OrGate();

		void action();
		void draw() const;
		Node *clone() const;
		std::string getType();
	private:
		static OrGate m_orGate;
};
