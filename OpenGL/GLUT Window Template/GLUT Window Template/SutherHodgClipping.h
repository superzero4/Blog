#pragma once
class SutherHodgClipping
{
private:
public:
	int x_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	int y_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	void clip(int poly_points[][2], int& poly_size, int x1, int y1, int x2, int y2);
	void suthHodgClip(int poly_points[][2], int poly_size, int clipper_points[][2], int clipper_size);
	void clippingAlgoritm();
};

