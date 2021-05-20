#ifndef ABSTRACTOBJECT_INCLUDES_INDEX_HPP
#define ABSTRACTOBJECT_INCLUDES_INDEX_HPP

#include <string>
#include <vector>

namespace Abstract
{
class Index
{
public:
	//////////////////////////////////////////////////////////
	//                       CONSTRUCTOR                    //
	//////////////////////////////////////////////////////////
	Index()
	{
		this->SetIndex(this->GenerateIndex());
	}
	Index(unsigned long long index)
	{
		this->SetIndex(index);
	}

	//copy constructor
	inline Index(const Index &rhs) :
			index_(rhs.index_)
	{
	}

	//move constructor
	inline Index(Index &&rhs) :
			index_(rhs.index_)
	{
	}

	//copy assignment
	inline Index& operator=(const Index &rhs)
	{
		this->index_ = rhs.index_;
		return *this;
	}

	//move assignment
	inline Index& operator=(Index &&rhs)
	{
		this->index_ = rhs.index_;
			return *this;
	}

	//////////////////////////////////////////////////////////
	//                       ACCESSOR                       //
	//////////////////////////////////////////////////////////
	inline unsigned long long GetIndex()
	{
		return index_;
	}
	//////////////////////////////////////////////////////////
	//                       MUTATOR                        //
	//////////////////////////////////////////////////////////
	inline void SetIndex(unsigned long long index)
	{
		index_ = index;
	}
private:
	//////////////////////////////////////////////////////////
	//                       FUNCTIONS                      //
	//////////////////////////////////////////////////////////
	inline unsigned long long GenerateIndex()
	{
		static unsigned long long s_NodeIndex = 0; // static keyword means it is created only once and persists beyond scope of code block.
		return s_NodeIndex++; // makes copy of index, increments the real index, then returns the value in the copy
	}
	//////////////////////////////////////////////////////////
	//                       ATTRIBUTES                     //
	//////////////////////////////////////////////////////////
	unsigned long long index_;
};

}
#endif // INDEX_HPP
