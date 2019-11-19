#ifndef _FEMALE_RABBIT__HPP_
#define _FEMALE_RABBIT__HPP_

#include "Rabbit.hpp"
#include <iostream>
#include <list>

extern "C" {
	#include "rand.h"
}

typedef std::list<Rabbit> rabbit_list;

class FemaleRabbit : public Rabbit {
	private:
		int nb_litters;
	public:
		FemaleRabbit();
		FemaleRabbit(int age, bool maturity);
		rabbit_list give_birth();
};

#endif