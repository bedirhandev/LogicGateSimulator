#pragma once

#include <vector>
#include <string>

class Node
{
	typedef std::weak_ptr<Node> pin_t;
	protected:
		Node(std::string);
		Node(std::string, char OUT);
		Node();
	public:
		virtual void action() = 0;
		void setType(std::string);
		void setOutput(char);
		void addInput(pin_t);
		virtual ~Node();
		virtual Node *clone() const = 0;
		virtual void draw() const = 0;
		virtual std::string getType() = 0;
	public:
		std::string id;
		std::string type;
		std::vector<pin_t> IN;
		char output;
};
