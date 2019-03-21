#pragma once
  
#include "Node.h"

class XorGate : public Node
{
        private:
                XorGate(std::string);
                XorGate();

                void action();
                void draw() const;
                Node *clone() const;
                std::string getType();
        private:
                static XorGate m_XorGate;
};
