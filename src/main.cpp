#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "data.h"
#include "hungarian.h"


int main(int argc, char** argv){
	Data *data = new Data(argc, argv[1]);
	data->readData();
	size_t dimension = data->getDimension();
	std::cout << "Starting solving to instance: "<< data->getInstanceName() << std::endl;


	hungarian_problem_t hProblem;

	hungarian_init(
		&hProblem, 
		data->getMatrixCost(), 
		dimension, 
		dimension, 
		HUNGARIAN_MODE_MINIMIZE_COST
	);

	hungarian_solve(&hProblem);
	hungarian_print_status(&hProblem);


	return 0;
}