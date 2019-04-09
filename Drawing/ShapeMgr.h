#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape *> listOfShapes;
public:
	ShapeMgr()
	{
		
	}
	// this reads the binary file and sends it to add shape, it needs the file we opened in main
	void loadFile(fstream &binFile)
	{
		drawingData temp;

		while (binFile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			addShape(temp.position, temp.shape, Color(temp.col));
		}
	}
	// this is to save the data we have in our struct, it needs the file we opened in main
	void saveFile(fstream &binFile)
	{
		for (int i = 0; i < listOfShapes.size(); i++)
		{
			binFile.write(reinterpret_cast<char *>(&listOfShapes[i]->getData()), sizeof(drawingData));
		}
	}
	// this is to add a new shape to our vector, it needs what shape, the position, and the color
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			listOfShapes.push_back(new Circle(pos, color));
		}
		else if (whichShape == SQUARE)
		{
			listOfShapes.push_back(new Square(pos, color));
		}
	}
		// this is to return all the shapes we created
	const vector<DrawingShape *>* getShapes()
	{
		return &listOfShapes;
	}
	

};
