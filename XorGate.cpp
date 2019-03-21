#include "XorGate.h"

XorGate XorGate::m_XorGate("XOR");

XorGate::XorGate(std::string uValue) : Node(uValue) {}

XorGate::XorGate() {}

void XorGate::action()
{
        this->draw();
        printf("This node has %lu input pins: ", IN.size());

	this->output = 0;
        for(auto& node : this->IN) {
                if(node.lock()->output == 1) {
                        this->output = 1;
                        break;
		}
        }

        for(auto& node : this->IN) {
                printf("[%s: %d] ", node.lock()->id.c_str(), node.lock()->output);
        }
        printf("\n\n");
}

std::string XorGate::getType() {
        return this->type;
}

void XorGate::draw() const
{
        printf("This is %s an %s gate!\n", id.c_str(), type.c_str());
}

Node* XorGate::clone() const
{
    return new XorGate;
}
