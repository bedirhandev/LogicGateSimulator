#pragma once

#include "NodeFactory.h"
#include "Node.h"

#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

class CircuitReader 
{
	public:
		CircuitReader(std::string);
		~CircuitReader();
		void initialize(std::map<std::string, std::shared_ptr<Node>> &NodeMap, std::vector<std::string> &Path);
	public:
		std::string path;
};
