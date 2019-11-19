#include "Rabbit.hpp"

static double sexual_maturity_tab[] = { 0, 0, 0, 0, 0, 0.25, 0.50, 0.75, 1};


Rabbit::Rabbit() :
	age_month(0),
	sexual_maturity(false),
	death_rate(80)
{
}

Rabbit::Rabbit(int age, bool mature) :
	age_month(age),
	sexual_maturity(mature)
{
	if(age > 8 && !mature)
		throw std::invalid_argument("The rabbit can't be immature and older than 8 months");
	else if(age < 5 && mature)
		throw std::invalid_argument("The rabbit can't be younger than 5 months and be mature");
	death_rate = (mature) ? 50 : 80;
}


bool Rabbit::live_one_more_month()
{
	bool i_will_survive = true;
	if(!sexual_maturity)
	{
		if(genrand_real1() - sexual_maturity_tab[age_month] <= 0)
		{
			sexual_maturity = true;
			death_rate = 50;
		}
	} else {
		if(age_month > 132 && (age_month%12 == 0))
			death_rate += 10;
	}
	if(genrand_real1() - (double) death_rate/1200 <= 0)
	{
		i_will_survive = false;
	}
	age_month++;
	return i_will_survive;
}

bool Rabbit::is_mature()
{
	return sexual_maturity;
}