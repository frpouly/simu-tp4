#include "FemaleRabbit.hpp"

FemaleRabbit::FemaleRabbit() :
	Rabbit(),
	nb_litters(0)
{

} 

FemaleRabbit::FemaleRabbit(int age, bool mature) :
	Rabbit(age, mature),
	nb_litters(0)
{

}

bool FemaleRabbit::live_one_more_month()
{
	return Rabbit::live_one_more_month();
}

void FemaleRabbit::give_birth(std::list<FemaleRabbit> &females, std::list<MaleRabbit> &males)
{
	double tirage;
	int nb_rabbits;
	if(genrand_real1() > 0.5 && MaleRabbit::is_there_mature_male() && is_mature())
	{
		tirage = genrand_real1();
		if(tirage < 0.25)
			nb_rabbits = 3;
		else if(tirage < 0.5)
			nb_rabbits = 4;
		else if(tirage < 0.75)
			nb_rabbits = 5;
		else nb_rabbits = 6;
		for(int i = 0; i< nb_rabbits; i++)
		{
			if(genrand_real1() < 0.5)
	    	   females.push_back(FemaleRabbit());
	        else
	            males.push_back(MaleRabbit());
		}
	}
}