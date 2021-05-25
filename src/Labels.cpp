#include "../includes/Labels.hpp"

namespace Abstract
{

/************************************************
 *  CONSTRUCTORS/DESTRUCTORS
 ***********************************************/
Labels::Labels() :
		name("INCORRECT LABEL CONSTRUCTOR")
{
}

Labels::Labels(std::string name) :
		name(name)
{
}

Labels::Labels(std::vector<std::string> labels) :
		name("NO_NAME"), labels(labels)
{
}

Labels::Labels(std::string name, std::string label) :
		name(name), labels(
		{ label })
{
}

Labels::Labels(std::string name, std::vector<std::string> labels) :
		name(name), labels(labels)
{
}

Labels::~Labels()
{
}

/************************************************
 *  GETTER/SETTER
 ***********************************************/

std::string Labels::getName() const
{
	return this->name;
}

std::string Labels::getLabel() const
{
	if (this->labels.empty())
		return "";
	return this->labels.back();
}

std::vector<std::string> Labels::getLabels() const
{
	return this->labels;
}

void Labels::setName(std::string name)
{
	this->name = name;
}

void Labels::setLabels(std::string label)
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

void Labels::addLabel(std::string label)
{
	this->labels.push_back(label);
}

void Labels::addLabels(std::vector<std::string> labels)
{
	this->labels.insert(this->labels.end(), labels.begin(), labels.end());
}

/************************************************
 *  FUNCTIONS
 ***********************************************/

bool Labels::containsLabel(const std::string query)
{
	for (std::string currLabel : this->labels)
	{
		//TODO: Why was regex used in your version?
		if (currLabel == query)
			return true;
	}
	return false;
}

bool Labels::compareLabels(const std::vector<std::string> otherLabels)
{
	return this->compareLabels(otherLabels, 1);
}

//copy constructor
Labels::Labels(const Labels &rhs) :
		name(rhs.name), labels(rhs.labels)
{

}
//move constructor
Labels::Labels(Labels &&rhs) :
		name(rhs.name), labels(rhs.labels)
{
}
//copy assignment
Labels& Labels::operator =(const Labels &rhs)
{
	this->name = rhs.name;
	this->labels = rhs.labels;
	return *this;
}
//move assignment
Labels& Labels::operator =(Labels &&rhs)
{
	this->name = rhs.name;
	this->labels = rhs.labels;
	return *this;
}

bool Labels::compareLabels(const std::vector<std::string> otherLabels,
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
