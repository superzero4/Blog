#pragma once
#include <vector>
#include <tuple>
#include <vec2.hpp>
#include "ClosedLineSequence.h"
class Geometry
{
private:
	std::vector<glm::vec<2,glm::vec2>> freeLines;
	std::vector<ClosedLineSequence*> polygons;
public:
	int AddLine(glm::vec2 begin, glm::vec2 end) {
		freeLines.push_back(glm::vec<2,glm::vec2>(begin, end));
		return freeLines.size()-1;
	}
	int AddPoly(ClosedLineSequence* p) {
		polygons.push_back(p);
		return polygons.size() - 1;
	}
	const std::vector<glm::vec<2, glm::vec2>> getFreeLines() { return freeLines; }
	const std::vector<ClosedLineSequence*> getPolygons() { return polygons; }
};

