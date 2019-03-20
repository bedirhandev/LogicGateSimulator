#pragma once
  
#include "Node.h"

class Probe : public Node
{
        private:
                Probe(std::string);
                Probe();

                void action();
                void draw() const;
                Node *clone() const;
		std::string getType();
	private:
                static Probe m_PROBE;
};
