#include "NodeFactory.h"
#include "Node.h"

void NodeFactory::assign(std::string uValue, const Node* pNode)
{
   	 nMap[uValue] = pNode;
};

Node* NodeFactory::create(std::string uValue)
{
    	NodeMap::const_iterator cFind = nMap.find(uValue);
    	Node* node = cFind->second->clone();
	node->setOutput(cFind->second->output); 
	node->setType(uValue);
    	return (cFind == nMap.end()) ? 0 : node;
};
