#ifndef _FEMALE_RABBIT__HPP_
#define _FEMALE_RABBIT__HPP_

#include "Rabbit.hpp"
#include "MaleRabbit.hpp"
#include <list>
#include "rand.h"

extern "C" {
	#include "rand.h"
};

class FemaleRabbit : public Rabbit {
	private:
		int nb_litters;
	public:
		FemaleRabbit();
		FemaleRabbit(int age, bool maturity);
		bool live_one_more_month() override;
		void give_birth(std::list<FemaleRabbit> &females, std::list<MaleRabbit> &males);
};

#endif