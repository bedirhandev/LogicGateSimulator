#pragma once

#pragma disable(warning: 4786)

#include <map>

class Node;

class NodeFactory
{
	private:
		typedef std::map<std::string, const Node*> NodeMap;
	private:
		static void assign(std::string, const Node*);
	public:
		static Node* create(std::string);
	private:
		friend class Node;
		static inline NodeMap nMap;
};
