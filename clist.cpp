
#include <iostream>
#include <list>
#include "clist.h"
#include <iterator>

#ifndef USE_STRUCT_HANDLE
	#include <map>
	std::map<int, std::list<int>> lists;	
#endif

std::list<int>& get_list(clist list)
{
#ifdef USE_STRUCT_HANDLE
		return *reinterpret_cast<std::list<int>*>(list);
#else
		return lists[list];
#endif
}

clist create_list()
{
#ifdef USE_STRUCT_HANDLE
		return reinterpret_cast<clist>(new std::list<int>());
#else
		static int count = 0;
		lists[count++];
		return count-1;
#endif
}

void push_back(clist list,int data)
{
		get_list(list).push_back(data);
}

void push_front(clist list,int data)
{
		get_list(list).push_front(data);
}

void print(clist list)
{
		for(auto const & item: get_list(list))
				std::cout<<item<<" ";
}

int size(clist list)
{
		return get_list(list).size();
}

int element_at(clist list,int i)
{
		auto & mylist = get_list(list);
		if ( i >= 0 )
		{
			auto it=mylist.begin();
			std::advance(it,i);
			return *it;
		}
		else
		{
			return element_at(list, (int) mylist.size() + i); 
		}
}
