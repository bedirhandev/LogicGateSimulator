#pragma once

#include "Node.h"

#include <map>
#include <iostream>

class Circuit {
	public:
		Circuit();
		~Circuit();
		void calculate();
	public:
		std::map<std::string, std::shared_ptr<Node>> NodeMap;
		std::vector<std::string> Path;
};
