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