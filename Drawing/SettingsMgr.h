#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed
struct settingsData
{
	int color;
	ShapeEnum shape;
};
class SettingsMgr
{
private:
	Color curColor;
	ShapeEnum curShape;
	settingsData data;
public:
	// this is to set starting color and save it to data, it needs the starting color and shape
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		curColor = startingColor;
		curShape = startingShape;

		data.color = startingColor.toInteger();
		data.shape = startingShape;
	}
	//this is to set the color to the current color, it takes the new color
	void setCurColor(Color newColor)
	{
		curColor = newColor;
		
		data.color = newColor.toInteger();
	}
	// this is to set the shape to the current shape, it takes the new shape
	void setCurShape(ShapeEnum newshape)
	{
		curShape = newshape;

		data.shape = newshape;
	}
	// this returns the current color
	Color getCurColor()
	{
		return curColor;
	}
	// this returns the current shape
	ShapeEnum getCurShape()
	{
		return curShape;
	}
	// this reads the binary file and liads it into the settings data struct
	void loadFile(fstream& binFile)
	{
		settingsData temp;
		binFile.read(reinterpret_cast<char *>(&temp), sizeof(settingsData));
		setCurColor(Color(temp.color));
		setCurShape(temp.shape);
	}
	// this saves the data in the struct, it takes the file we opened
	void saveFile(fstream& binFile)
	{
		binFile.write(reinterpret_cast<char *>(&data), sizeof(data));
	}
};
