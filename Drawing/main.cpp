//================================================
// YOUR NAME GOES HERE <-----------------  
//================================================
#include <iostream>
#include <fstream>
using namespace std;
#include <SFML\Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
#include "SettingsUI.h"
#include "DrawingUI.h"
using namespace sf;

// Finish this code. Other than where it has comments telling you to 
// add code, you shouldn't need to add any logic to main to satisfy
// the requirements of this programming assignment

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");
	window.setFramerateLimit(60);

	SettingsMgr settingsMgr(Color::Blue, ShapeEnum::CIRCLE);
	SettingsUI  settingsUI(&settingsMgr); 
	ShapeMgr    shapeMgr;
	DrawingUI   drawingUI(Vector2f(200, 50));
	
	// ********* Add code here to make the managers read from shapes file (if the file exists)
	fstream binFile;
	binFile.open("shapes.bin", ios::in | ios::binary);
	if (binFile)
	{
		settingsMgr.loadFile(binFile);
		shapeMgr.loadFile(binFile);
	}

	binFile.close();
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();

				binFile.open("shapes.bin", ios::out | ios::binary);
				if (binFile)
				{
					settingsMgr.saveFile(binFile);
					shapeMgr.saveFile(binFile);
				}
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				settingsUI.handleMouseUp(mousePos);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left))
			{

				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (drawingUI.isMouseInCanvas(mousePos))
				{
					shapeMgr.addShape(mousePos, settingsMgr.getCurShape(), settingsMgr.getCurColor());
				}
			}
		}
	
	

		// The remainder of the body of the loop draws one frame of the animation
		window.clear();

		// this should draw the left hand side of the window (all of the settings info)
		settingsUI.draw(window);

		// this should draw the rectangle that encloses the drawing area, then draw the
		// shapes. This is passed the shapeMgr so that the drawingUI can get the shapes
		// in order to draw them. This redraws *all* of the shapes every frame.
		drawingUI.draw(window, &shapeMgr);

		window.display();
	} // end body of animation loop

	return 0;
}