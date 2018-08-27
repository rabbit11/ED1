#ifndef ACCUMULATOR_H_
#define ACCUMULATOR_H_

typedef struct {
	
	double total;
	int quantidade;
	
} acumulator;

void initialize(acumulator* a);

void addDataValue(acumulator* a, double val);

double	mean(acumulator* a);

double value(acumulator* a);

void toString(acumulator* a, char* str);

#endif
