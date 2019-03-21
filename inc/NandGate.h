#pragma once
  
#include "Node.h"

class NandGate : public Node
{
        private:
                NandGate(std::string);
                NandGate();

                void action();
                void draw() const;
                Node *clone() const;
                std::string getType();
        private:
                static NandGate m_nandGate;
};
