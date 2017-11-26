#ifndef CIRCLE_H
#define CIRCLE_H

#include "Area.h"
#include "Point.h"
#include "Figure.h"
#include <vector>
using namespace std;

class Circle: public Figure, public Area
{
public:
	Circle();
	Circle(Point center, int radius);
	~Circle();

	void draw(); //画轮廓点，若被填充，则也画填充点
	void clear(); //删除轮廓点，若被填充，也删除填充点

	Point getCenter();
	void setRadius(int r);
	void fillColor();

private:
	Point center; //圆心
	int radius; //半径

	void calculatePoints(); //计算轮廓点位置
	void calculateFillPoints(); //计算填充点位置
};

#endif // !CIRCLE_H