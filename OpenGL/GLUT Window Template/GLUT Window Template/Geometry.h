#pragma once
#include <vector>
#include <tuple>
#include <vec2.hpp>
class Geometry
{
private:
	std::vector<glm::vec<2,glm::vec2>> lines;
public:
	int AddLine(glm::vec2 begin, glm::vec2 end) {
		lines.push_back(glm::vec<2,glm::vec2>(begin, end));
		return lines.size()-1;
	}
	const std::vector<glm::vec<2, glm::vec2>> getLines() { return lines; }
};

