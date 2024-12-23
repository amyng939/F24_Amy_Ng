#pragma once

#include "Avo.h"
#include <vector>

class Counter
{
public:
	Counter();

	void AddPoint();
	void DrawCounter();
	int GetCount() const;

private:
	int count = 0;
	std::vector<Avo::Image> numbers{};
};