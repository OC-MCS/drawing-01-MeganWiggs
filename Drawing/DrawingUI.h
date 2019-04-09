#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape canvas;
public:
	// this is to to creat the canvas setting the user can draw in, its given the position of the canvas
	DrawingUI(Vector2f p)
	{
		canvas.setPosition(p);
		canvas.setOutlineThickness(2);
		canvas.setSize(Vector2f(525, 475));
		canvas.setFillColor(Color::Transparent);
	}
	// this is to draw the canvas and the shapes
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		win.draw(canvas);
		const vector<DrawingShape *> *temp = mgr->getShapes();
		for (int i = 0; i < mgr->getShapes()->size(); i++)
		{
			(*temp)[i]-> draw(win);
		}
	}
	// this checks if the mouse is within canvas
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool mouseIsInCanvas = false;
		if (canvas.getGlobalBounds().contains(mousePos))
		{
			mouseIsInCanvas = true;
		}
		return mouseIsInCanvas;
	}

};

