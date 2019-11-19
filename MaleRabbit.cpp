#include "MaleRabbit.hpp"

int MaleRabbit::number_mature = 0;

MaleRabbit::MaleRabbit() :
	Rabbit()
{
} 

MaleRabbit::MaleRabbit(int age, bool mature) :
	Rabbit(age, mature)
{
	if(mature)
		++number_mature;
}

bool MaleRabbit::live_one_more_month()
{
	bool mature_before = is_mature();
	bool alive = Rabbit::live_one_more_month();
	if(!mature_before && is_mature())
	{
		++number_mature;
	}
	return alive;
}

MaleRabbit::~MaleRabbit()
{
	if(is_mature())
		--number_mature;
}


bool MaleRabbit::is_there_mature_male()
{
	bool ret = true;
	if(number_mature == 0)
		ret = false;
	return ret;
}
