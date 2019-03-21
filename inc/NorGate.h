#pragma once
  
#include "Node.h"

class NorGate : public Node
{
        private:
                NorGate(std::string);
                NorGate();

                void action();
                void draw() const;
                Node *clone() const;
                std::string getType();
        private:
                static NorGate m_norGate;
};
