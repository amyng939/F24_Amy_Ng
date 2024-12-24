#include "Counter.h"

Counter::Counter()
{
	for (int i = 0; i <= 9; i++) // filenames are named from 0.png to 9.png
	{
		std::string filename = "../MyGame/Assets/" + std::to_string(i) + ".png";
		numbers.emplace_back(filename);
	}
}

void Counter::AddPoint()
{
	count++;
}

void Counter::DrawCounter()
{
	std::string string_count = std::to_string(count);
	int x = 1800;
	int y = 900; // top right corner

	for (int i = string_count.size() - 1; i >= 0; i--)
	{
		Avo::Renderer::Draw(numbers[string_count[i] - '0'], x, y);
		
		if (i > 0)
			x = x - numbers[string_count[i - 1] - '0'].GetWidth() - 5; // leave gap of 5 pixels between digits
	}
}

int Counter::GetCount() const
{
	return count;
}
