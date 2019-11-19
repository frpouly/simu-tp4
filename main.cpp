#include "Rabbit.hpp"
#include "FemaleRabbit.hpp"
#include "MaleRabbit.hpp"
#include <iostream>
#include <list>
#include "rand.h"

extern "C" {
	#include "rand.h"
};

int main(int, char **)
{
	unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);
    std::list<MaleRabbit> males;
    std::list<FemaleRabbit> females;
    for(int i = 0; i < 100; i++)
    {
        if(genrand_real1() < 0.5)
    	   females.push_back(FemaleRabbit(12, true));
        else
            males.push_back(MaleRabbit(12, true));
    }
    while(!males.empty() && !females.empty())
    {
    	std::cout << males.size();
        std::cout << "\t";
        std::cout << females.size() << std::endl;
    	std::list<MaleRabbit>::iterator it = males.begin();
        std::list<MaleRabbit>::iterator end = males.end();
    	while (it != end)
    	{
    		bool survive = (*it).live_one_more_month();
    		if(!survive)
    		{
    			males.erase(it++);
    		}
    		else
    		{
    			++it;
    		}
    	}
        std::list<FemaleRabbit>::iterator it2 = females.begin();
        std::list<FemaleRabbit>::iterator end2 = females.end();
        while(it2 != end2)
        {
            bool survive = (*it2).live_one_more_month();
            if(!survive)
            {
                females.erase(it2++);
            }
            else
            {
                (*it2).give_birth(females, males);   
                ++it2;
            }
        }
    }
	return 0;
}