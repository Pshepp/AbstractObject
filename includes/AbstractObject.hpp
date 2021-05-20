#ifndef ABSTRACTOBJECT_INCLUDES_GENERIC_OBJECT_HPP
#define ABSTRACTOBJECT_INCLUDES_GENERIC_OBJECT_HPP

#include "Labels.hpp"

namespace Abstract
{
/* TODO: Figure out a better name and what data we want to include. Do
 * 			we want/need index counting? This could be a pain when
 * 			deletions and insertions come into play. All my algos (except
 * 			subgraph matching) ignore these signifiers.
 * 			We could name it "generic identifiers" or something of the
 * 			sort.
 */
class AbstractObject
{
public:
	/************************************************
	 *  CONSTRUCTORS/DESTRUCTORS
	 ***********************************************/
	AbstractObject()
	{
	}

	AbstractObject(std::string name)
	{
		this->setName(name);
	}

	AbstractObject(std::string name, std::string label)
	{
		this->setName(name);
		this->setLabels(label);
	}
	AbstractObject(std::string name, std::vector<std::string> labels)
	{
		this->setName(name);
		this->setLabels(labels);
	}

	//copy constructor
	inline AbstractObject(const AbstractObject &rhs) :
			labels(rhs.labels)
	{
	}

	//move constructor
	inline AbstractObject(AbstractObject &&rhs) :
			labels(rhs.labels)
	{
	}

	//copy assignment
	inline AbstractObject& operator=(const AbstractObject &rhs)
	{
		this->labels = rhs.labels;
		return *this;
	}

	//move assignment
	inline AbstractObject& operator=(AbstractObject &&rhs)
	{
		this->labels = rhs.labels;
		return *this;
	}


	virtual ~AbstractObject() = 0;

	/************************************************
	 *  GETTER/SETTER
	 ***********************************************/
	std::string getName()
	{
		return this->labels.getName();
	}
	std::string getLabel()
	{
		return this->labels.getLabel();
	}
	std::vector<std::string> getLabels()
	{
		return this->labels.getLabels();
	}

	void setName(std::string name)
	{
		this->labels.setName(name);
	}

	void setLabels(std::string label)
	{
		this->labels.setLabels(label);
	}
	void setLabels(std::vector<std::string> labels)
	{
		this->labels.setLabels(labels);
	}

	/************************************************
	 *  MUTATORS
	 ***********************************************/
	void addLabel(std::string label)
	{
		this->labels.addLabel(label);
	}

	/************************************************
	 *  FUNCTIONS
	 ***********************************************/
	bool compareLabels(const std::vector<std::string> otherLabels);

private:
	/************************************************
	 *  ATTRIBUTES
	 ***********************************************/
	Labels labels;

};

inline AbstractObject::~AbstractObject()
{
}

}
#endif // ABSTRACT_OBJECT_HPP
