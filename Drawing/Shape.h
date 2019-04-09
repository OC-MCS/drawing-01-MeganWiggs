#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

struct drawingData
{
	Vector2f position;
	int col;
	ShapeEnum shape;
};
// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{

public:
	virtual void draw(RenderWindow &win) = 0;
	virtual drawingData getData() = 0;

};

// add Circle, Square classes below. These are derived from DrawingShape

class Circle : public DrawingShape
{
private:
	CircleShape circle;
public:
	// this sets the parameters of the circle, it takes the current position and the current color. 
	Circle(Vector2f position, Color color)
	{
		const float RADIUS = 4;
		circle.setPosition(position);
		circle.setRadius(RADIUS);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(color);
		circle.setFillColor(color);
	}

	// this is to return the data struct
	drawingData getData()
	{
		drawingData data;
		data.col = circle.getFillColor().toInteger();
		data.position = circle.getPosition();
		data.shape = CIRCLE;
		return data;
	}
	// this is to draw the circle
	void draw(RenderWindow &win)
	{
		win.draw(circle);
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape square;

public:
	// this is to set the parameters of the square
	Square(Vector2f position, Color curcolor)
	{
		square.setPosition(position);
		square.setOutlineThickness(2);
		square.setOutlineColor(curcolor);
		square.setFillColor(curcolor);
		square.setSize(Vector2f(10, 10));

	}
	// this is to return the data struct
	drawingData getData()
	{
		drawingData data;
		data.col = square.getFillColor().toInteger();
		data.position = square.getPosition();
		data.shape = SQUARE;
		return data;
	}
	// this is to draw the square
	void draw(RenderWindow &win)
	{
		win.draw(square);
	}
};

