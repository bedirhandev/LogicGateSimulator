#pragma once

#include "Node.h"

class NotGate : public Node
{
	private:
		NotGate(std::string);
		NotGate();

		void action();
		void draw() const;
		Node *clone() const;
		std::string getType();	
	private:
		static NotGate m_notGate;
};
