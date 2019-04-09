#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

// this is to bail out when we need to, it takes the message we want to say
void die(string message)
{
	cout << message << endl;
	exit(-1);
}
class SettingsUI
{
private:
	SettingsMgr * m;
	Font font;
	Text colorLabel, shapeLabel;
	CircleShape cyanBtn, blueBtn, magBtn, cirBtn;
	RectangleShape sqBtn;
	const int RAD = 10;
	const float SIZE = 20;
public:
	SettingsUI(SettingsMgr *mgr)
	{
		m = mgr;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\Comicbd.ttf"))
		{
			die("couldnt load font");
		}
		
		colorLabel.setFont(font);
		colorLabel.setString("Color");
		colorLabel.setPosition(Vector2f(100, 100));
		
		shapeLabel.setFont(font);
		shapeLabel.setString("Shape");
		shapeLabel.setPosition(Vector2f(100, 300));
		
		cyanBtn.setPosition(Vector2f(100, 150));
		cyanBtn.setRadius(RAD);
		cyanBtn.setOutlineThickness(2);
		cyanBtn.setOutlineColor(Color::Cyan);
		cyanBtn.setFillColor(Color::Transparent);

		blueBtn.setPosition(Vector2f(100, 200));
		blueBtn.setRadius(RAD);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		blueBtn.setFillColor(Color::Transparent);

		magBtn.setPosition(Vector2f(100, 250));
		magBtn.setRadius(RAD);
		magBtn.setOutlineThickness(2);
		magBtn.setOutlineColor(Color::Magenta);
		magBtn.setFillColor(Color::Transparent);

		cirBtn.setPosition(Vector2f(100, 350));
		cirBtn.setRadius(RAD);
		cirBtn.setOutlineThickness(2);
		cirBtn.setOutlineColor(Color::White);
		cirBtn.setFillColor(Color::Transparent);

		sqBtn.setPosition(Vector2f(100, 400));
		sqBtn.setSize(Vector2f(SIZE,SIZE));
		sqBtn.setOutlineThickness(2);
		sqBtn.setOutlineColor(Color::White);
		sqBtn.setFillColor(Color::Transparent);
	}
	//this is to see if the user clicked on a button, it takes the position of the mouse
	void handleMouseUp(Vector2f mouse)
	{
		if (cyanBtn.getGlobalBounds().contains(mouse))
		{
			m->setCurColor(Color::Cyan);
		}
		else if (blueBtn.getGlobalBounds().contains(mouse))
		{
			m->setCurColor(Color::Blue);
		}
		else if (magBtn.getGlobalBounds().contains(mouse))
		{
			m->setCurColor(Color::Magenta);
		}
		if (cirBtn.getGlobalBounds().contains(mouse))
		{
			m->setCurShape(CIRCLE);
		}
		else if (sqBtn.getGlobalBounds().contains(mouse))
		{
			m->setCurShape(SQUARE);
		}
	}
	// This is to draw and fill in current settings, it takes the window
	void draw(RenderWindow& win)
	{
		if (m->getCurColor() == Color::Cyan)
		{
			cyanBtn.setFillColor(Color::Cyan);
			blueBtn.setFillColor(Color::Transparent);
			magBtn.setFillColor(Color::Transparent);
		}
		else if (m->getCurColor() == Color::Blue)
		{
			cyanBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Blue);
			magBtn.setFillColor(Color::Transparent);
		}
		else if (m->getCurColor() == Color::Magenta)
		{
			cyanBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Transparent);
			magBtn.setFillColor(Color::Magenta);
		}
		if (m->getCurShape() == SQUARE)
		{
			sqBtn.setFillColor(Color::White);
			cirBtn.setFillColor(Color::Transparent);
		}
		else if (m->getCurShape() == CIRCLE)
		{
			sqBtn.setFillColor(Color::Transparent);
			cirBtn.setFillColor(Color::White);
		}

		//drawing all the settings and buttons
		win.draw(colorLabel);
		win.draw(shapeLabel);
		win.draw(cyanBtn);
		win.draw(blueBtn);
		win.draw(magBtn);
		win.draw(cirBtn);
		win.draw(sqBtn);
	}



};
