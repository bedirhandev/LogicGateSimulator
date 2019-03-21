#include "CircuitReader.h"

CircuitReader::CircuitReader(std::string path) {
	this->path = path;
}

CircuitReader::~CircuitReader() {}

void CircuitReader::initialize(std::map<std::string, std::shared_ptr<Node>> &NodeMap, std::vector<std::string> &Path) {
	std::ifstream file(path);

	std::istreambuf_iterator<char> i_file(file);
	std::istreambuf_iterator<char> eof;

	std::string id, type;

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
				NodeMap.insert(std::make_pair(id, NodeFactory::create(type)));
				Path.emplace_back(id);
				NodeMap[id]->id = id;
			} else {
				std::stringstream ss(type);
				while(ss.good()) {
					std::string substr;
					std::getline(ss, substr, ',');

					std::map<std::string, std::shared_ptr<Node>>::const_iterator cFind = NodeMap.find(id);
					NodeMap[substr]->addInput(cFind->second);
				}
			}

			lock = !lock;
		}

		if(!lock) {
			id += *i_file;
		}

		type += *i_file;

		++i_file;
	}
}
