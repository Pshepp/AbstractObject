#include "../includes/Labels.hpp"

namespace Abstract
{

/************************************************
 *  CONSTRUCTORS/DESTRUCTORS
 ***********************************************/
inline Labels::Labels() :
		name("INCORRECT LABEL CONSTRUCTOR")
{
}

inline Labels::Labels(std::string name) :
		name(name)
{
}

inline Labels::Labels(std::vector<std::string> labels) :
		name("NO_NAME"), labels(labels)
{
}

inline Labels::Labels(std::string name, std::string label) :
		name(name), labels({label})
{
}

inline Labels::Labels(std::string name, std::vector<std::string> labels) :
		name(name), labels(labels)
{
}

Labels::~Labels()
{
}

/************************************************
 *  GETTER/SETTER
 ***********************************************/

inline std::string Labels::getName() const
{
	return this->name;
}

inline std::string Labels::getLabel() const
{
	if (this->labels.empty())
		return "";
	return this->labels.back();
}

inline std::vector<std::string> Labels::getLabels() const
{
	return this->labels;
}

inline void Labels::setName(std::string name)
{
	this->name = name;
}

inline void Labels::setLabels(std::string label)
{
	this->labels.clear();
	this->addLabel(label);
}

inline void Labels::setLabels(std::vector<std::string> labels)
{
	this->labels = labels;
}

/************************************************
 *  MUTATORS
 ***********************************************/

inline void Labels::addLabel(std::string label)
{
	this->labels.push_back(label);
}

inline void Labels::addLabels(std::vector<std::string> labels)
{
	this->labels.insert(this->labels.end(), labels.begin(), labels.end());
}

/************************************************
 *  FUNCTIONS
 ***********************************************/

inline bool Labels::containsLabel(const std::string query)
{
	for (std::string currLabel : this->labels)
	{
		//TODO: Why was regex used in your version?
		if (currLabel == query)
			return true;
	}
	return false;
}

inline bool Labels::compareLabels(const std::vector<std::string> otherLabels)
{
	return this->compareLabels(otherLabels, 1);
}

//copy constructor
inline Labels::Labels(const Labels &rhs) :
		name(rhs.name), labels(rhs.labels)
{

}
//move constructor
inline Labels::Labels(Labels &&rhs) :
		name(rhs.name), labels(rhs.labels)
{
}
//copy assignment
inline Labels& Labels::operator =(const Labels &rhs)
{
	this->name = rhs.name;
	this->labels = rhs.labels;
	return *this;
}
//move assignment
inline Labels& Labels::operator =(Labels &&rhs)
{
	this->name = rhs.name;
	this->labels = rhs.labels;
	return *this;
}

inline bool Labels::compareLabels(const std::vector<std::string> otherLabels,
		unsigned int numMatches)
{
	unsigned int matchCounter = 0;
	for (std::string currLabel : this->labels)
	{
		if (std::find(otherLabels.begin(), otherLabels.end(), currLabel)
				!= otherLabels.end())
		{
			matchCounter++;
			if (matchCounter == numMatches)
				return true;
		}
	}
	return false;
}

}
