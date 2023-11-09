#pragma once

#include <cstdlib> 

namespace nm_algo {

	double pow(double number, int pow) {
		if (pow < 0) {
			number = 1 / number;
		}
		long int power = std::labs(power);

		double powNumber = 1;

		while (power) {
			if ((power & 1) != 0) {
				powNumber *= number;
			}

			number *= number;
			power >>= 1;
		}
		return powNumber;
	}
}
