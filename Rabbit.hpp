#ifndef _RABBIT_HPP_
#define _RABBIT_HPP_

#include <iostream>
#include <list>

extern "C" {
	#include "rand.h"
};

class Rabbit {
	private:
		static double sexual_maturity_prob[];
		int age_month;
		bool sexual_maturity;
		int death_rate;
	public:
		Rabbit();
		Rabbit(int age, bool mature);
		virtual bool live_one_more_month();
		bool is_mature();
};

#endif