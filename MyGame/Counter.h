#pragma once

#include "Avo.h"
#include <vector>

class Counter
{
public:
	Counter();

	void AddPoint();
	void DrawCounter();
	int GetCount();

private:
	int count = 0;

	Avo::Image zero{ "../MyGame/Assets/0.png" };
	Avo::Image one{ "../MyGame/Assets/1.png" };
	Avo::Image two{ "../MyGame/Assets/2.png" };
	Avo::Image three{ "../MyGame/Assets/3.png" };
	Avo::Image four{ "../MyGame/Assets/4.png" };
	Avo::Image five{ "../MyGame/Assets/5.png" };
	Avo::Image six{ "../MyGame/Assets/6.png" };
	Avo::Image seven{ "../MyGame/Assets/7.png" };
	Avo::Image eight{ "../MyGame/Assets/8.png" };
	Avo::Image nine{ "../MyGame/Assets/9.png" };

	std::vector<Avo::Image> numbers{};
};