#include "NorGate.h"

NorGate NorGate::m_norGate("NOR");

NorGate::NorGate(std::string uValue) : Node(uValue) {}

NorGate::NorGate() {}

void NorGate::action()
{
        this->draw();
        printf("This node has %lu input pins: ", IN.size());

	this->output = 1;
        for(auto& node : this->IN) {
                if(node.lock()->output == 1) {
                        this->output = 0;
                        break;
		}
        }

        for(auto& node : this->IN) {
                printf("[%s: %d] ", node.lock()->id.c_str(), node.lock()->output);
        }
        printf("\n\n");
}

std::string NorGate::getType() {
        return this->type;
}

void NorGate::draw() const
{
        printf("This is %s an %s gate!\n", id.c_str(), type.c_str());
}

Node* NorGate::clone() const
{
    return new NorGate;
}
