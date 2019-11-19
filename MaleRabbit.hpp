#ifndef _MALE_RABBIT__HPP_
#define _MALE_RABBIT__HPP_

#include "Rabbit.hpp"

class MaleRabbit : public Rabbit {
	private:
		static int number_mature;
	public:
		MaleRabbit();
		MaleRabbit(int age, bool maturity);
		~MaleRabbit();
		bool live_one_more_month() override;
		static bool is_there_mature_male();
};

#endif