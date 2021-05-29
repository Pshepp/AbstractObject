#ifndef ABSTRACTOBJECT_INCLUDES_LABELS_HPP
#define ABSTRACTOBJECT_INCLUDES_LABELS_HPP

#include <string>
#include <vector>
#include <algorithm>

//TODO: Pick a better namespace name for this, figure out what we should use instead of `unsigned int`
namespace Abstract {
class Labels {
public:
	/************************************************
	 *  CONSTRUCTORS/DESTRUCTORS
	 ***********************************************/
	inline Labels() :
			name("INCORRECT LABEL CONSTRUCTOR")
	{
	}

	inline Labels(std::string name) :
			name(name)
	{
	}

	inline Labels(std::vector<std::string> labels) :
			name("NO_NAME"), labels(labels)
	{
	}

	inline Labels(std::string name, std::string label) :
			name(name), labels(
			{ label })
	{
	}

	inline Labels(std::string name, std::vector<std::string> labels) :
			name(name), labels(labels)
	{
	}

	inline ~Labels()
	{
	}

	//copy constructor
	inline Labels(const Labels &rhs) :
			name(rhs.name), labels(rhs.labels)
	{

	}
	//move constructor
	inline Labels(Labels &&rhs) :
			name(rhs.name), labels(rhs.labels)
	{
	}
	//copy assignment
	inline Labels& operator =(const Labels &rhs)
	{
		this->name = rhs.name;
		this->labels = rhs.labels;
		return *this;
	}
	//move assignment
	Labels& operator =(Labels &&rhs)
	{
		this->name = rhs.name;
		this->labels = rhs.labels;
		return *this;
	}

	/************************************************
	 *  GETTER/SETTER
	 ***********************************************/
	inline std::string getName() const
	{
		return this->name;
	}

	inline std::string getLabel() const
	{
		if (this->labels.empty())
			return "";
		return this->labels.back();
	}

	inline std::vector<std::string> getLabels() const
	{
		return this->labels;
	}

	inline void setName(std::string name)
	{
		this->name = name;
	}

	inline void setLabels(std::string label)
	{
		this->labels.clear();
		this->addLabel(label);
	}

	inline void setLabels(std::vector<std::string> labels)
	{
		this->labels = labels;
	}

	/************************************************
	 *  MUTATORS
	 ***********************************************/
	inline void addLabel(std::string label)
	{
		this->labels.push_back(label);
	}

	inline void addLabels(std::vector<std::string> labels)
	{
		this->labels.insert(this->labels.end(), labels.begin(), labels.end());
	}


	/************************************************
	 *  FUNCTIONS
	 ***********************************************/
	inline bool containsLabel(const std::string query)
	{
		for (std::string currLabel : this->labels)
		{
			//TODO: Why was regex used in your version?
			if (currLabel == query)
				return true;
		}
		return false;
	}
	bool compareLabels(const std::vector<std::string> otherLabels)
	{
		return this->compareLabels(otherLabels, 1);
	}
	inline bool compareLabels(const std::vector<std::string> otherLabels,
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

private:
	/************************************************
	 *  ATTRIBUTES
	 ***********************************************/
	std::string name;
	std::vector<std::string> labels;

};
}

#endif // LABELS_HPP


