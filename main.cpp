#include "Rabbit.hpp"
#include "FemaleRabbit.hpp"
#include "MaleRabbit.hpp"
#include <iostream>
#include <list>

extern "C" {
	#include "rand.h"
};

int main(int, char **)
{
	typedef std::list<Rabbit> rabbit_list;
	unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);
    rabbit_list rabbits;
    for(int i = 0; i < 100; i++)
    {
        if(genrand_real1() < 0.5)
    	   rabbits.push_back(FemaleRabbit(12, true));
        else
            rabbits.push_back(MaleRabbit(12, true));
    }
    while(!rabbits.empty())
    {
    	std::cout << rabbits.size() << std::endl;
    	rabbit_list::iterator it = rabbits.begin();
    	while (it != rabbits.end())
    	{
    		bool survive = (*it).live_one_more_month();
    		if(!survive)
    		{
    			rabbits.erase(it++);
    		}
    		else
    		{
    			++it;
    		}
    	}
    }
	return 0;
}