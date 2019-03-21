#include "NandGate.h"

NandGate NandGate::m_nandGate("NAND");

NandGate::NandGate(std::string uValue) : Node(uValue) {}

NandGate::NandGate() {}

void NandGate::action()
{
        this->draw();
        printf("This node has %lu input pins: ", IN.size());

	this->output = 0;

        for(auto& node : this->IN) {
                if(node.lock()->output == 0) {
                        this->output = 1;
                        break;
		}
        }

        for(auto& node : this->IN) {
                printf("[%s: %d] ", node.lock()->id.c_str(), node.lock()->output);
        }
        printf("\n\n");
}

std::string NandGate::getType() {
        return this->type;
}

void NandGate::draw() const
{
        printf("This is %s an %s gate!\n", id.c_str(), type.c_str());
}

Node* NandGate::clone() const
{
    return new NandGate;
}
