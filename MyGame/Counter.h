#pragma once

#include "Avo.h"
#include <vector>

class Counter
{
public:
	Counter();

	void AddPoint();
	void DrawCounter();

private:
	int count = 0;
	std::vector<Avo::Image> numbers{};
};