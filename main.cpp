#include "NodeFactory.h"
#include "Node.h"

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

#define GATE "NODE"

typedef std::map<std::string, std::shared_ptr<Node>> _NodeMap;
typedef std::vector<std::string> _Path;

_NodeMap NodeMap;
_Path Path;

// circuit behaviour this calls the draw() method 
// from all nodes existing in the circuit
inline void draw(_NodeMap map, _Path path) 
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CALCULATING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
	for(auto const& id : path) 
	{
		if(id.find(GATE) != std::string::npos) {	
			map[id]->action();
		}
	} 
}

int main(void) {
	// File Reader
	std::ifstream file("circuits/circuit3.txt");

	std::istreambuf_iterator<char> i_file(file);
	std::istreambuf_iterator<char> eof;

	std::string id;
	std::string type;

	bool lock;

	while(i_file != eof)
    	{
		if(*i_file == '\n') {
			id.clear();
		}

		if(*i_file == ':') 
			lock = true;

		if(*i_file == '\t') {
			type.clear();
		}

		if(*i_file == ';') {
			id.erase(std::remove(id.begin(), id.end(), '\n'), id.end());
			id.erase(std::remove(id.begin(), id.end(), '\t'), id.end());
			id.erase(std::remove(id.begin(), id.end(), ' '), id.end());
			
			type.erase(std::remove(type.begin(), type.end(), '\t'), type.end());
			type.erase(std::remove(type.begin(), type.end(), ' '), type.end());	

			if(NodeMap.count(id) == 0) {
				//std::cout << "ID: " << id << " TYPE: " << type << std::endl;
				NodeMap.insert(std::make_pair(id, NodeFactory::create(type)));
				Path.emplace_back(id);
				NodeMap[id]->id = id;
			} else {
				// Refactor the names and tidy the code
				//
				// the comma seperated string is the id of the node
				// and the id itself is what the nodemap should find
				std::stringstream ss(type);
				while(ss.good()) {
					std::string substr;
					std::getline(ss, substr, ',');
					//std::cout << substr << std::endl;
					_NodeMap::const_iterator cFind = NodeMap.find(id);
					NodeMap[substr]->addInput(cFind->second);	
				}
				//std::cout << std::endl;
			}

			lock = !lock;
		}

		if(!lock) {
			id += *i_file;
		}
		
		type += *i_file;
		
		++i_file;
    	}

	//NodeMap["A"]->output = 0;
	draw(NodeMap, Path);

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FINAL RESULTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
	
	for(auto const& probe : NodeMap) {
		if(probe.second->getType() == "PROBE") {
			probe.second->action();	
		}
	}
	
	return 0;
}
