#include "Node.h"
#include "NodeFactory.h"

Node::Node(std::string uValue)
{
	NodeFactory::assign(uValue, this);
}

Node::Node(std::string uValue, char output) 
{
	this->output = output;
	NodeFactory::assign(uValue, this);
}

void Node::setType(std::string type)
{
	this->type = type;
}

std::string Node::getType()
{
	return this->type;
}	

void Node::setOutput(char output)
{
	this->output = output;
}

void Node::addInput(std::weak_ptr<Node> node)
{
	IN.emplace_back(node);
}

Node::Node()
{
}

Node::~Node()
{
}

