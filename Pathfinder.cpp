/*
 * Pathfinder.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: jjfeddock
 */

#include "Pathfinder.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

Pathfinder::Pathfinder()
{
	stringstream maze;
	maze << "1 ";
	for (int a=0; a<3; a++)
		maze << "1 ";
	maze << "1";
	maze << "\n";
	for (int n=0; n<4; n++)
	{
		for (int k=0; k<4; k++)
		{
			maze << "1 ";
		}
		maze << "1";
		maze << "\n";
	}
	maze << "\n";
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<5; j++)
		{
			for (int k=0; k<4; k++)
			{
				maze << "1 ";
			}
			maze << "1";
			maze << "\n";
		}
		maze << "\n";
	}
	for (int j=0; j<4; j++)
	{
		for (int k=0; k<4; k++)
		{
			maze << "1 ";
		}
		maze << "1";
		maze << "\n";
	}
	for (int k=0; k<4; k++)
	{
		maze << "1 ";
	}
	maze << "1";

	my_maze = maze.str();
    x = 0;
}

bool exists(string file)
{
    ifstream infile(file);
    return infile.good();
}

string Pathfinder::getMaze()
{
	return my_maze;
}

void Pathfinder::createRandomMaze()
{
    srand(x);
	stringstream maze;
	maze << "1 ";
	for (int a=0; a<3; a++)
		maze << to_string(rand() % 2) << " ";
	maze << to_string(rand() % 2);
	maze << "\n";
	for (int n=0; n<4; n++)
	{
		for (int k=0; k<4; k++)
		{
			maze << to_string(rand() % 2) << " ";
		}
		maze << to_string(rand() % 2);
		maze << "\n";
	}
	maze << "\n";
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<5; j++)
		{
			for (int k=0; k<4; k++)
			{
				maze << to_string(rand() % 2) << " ";
			}
			maze << to_string(rand() % 2);
			maze << "\n";
		}
		maze << "\n";
	}
	for (int j=0; j<4; j++)
	{
		for (int k=0; k<4; k++)
		{
			maze << to_string(rand() % 2) << " ";
		}
		maze << to_string(rand() % 2);
		maze << "\n";
	}
	for (int k=0; k<4; k++)
	{
		maze << to_string(rand() % 2) << " ";
	}
	maze << "1";

    x++;
	my_maze = maze.str();
}

bool Pathfinder::importMaze(string file_name)
{
    if (exists(file_name))
    {
        ifstream file(file_name);
        string file_maze;
        string temp;

        while (getline(file, temp))
        {
            file_maze = file_maze + temp;
        }

        int test;
        int counter = 0;
        stringstream ss;
        ss << file_maze;

        while (ss >> test)
        {
            if (test == 0 || test == 1)
                counter++;
        }

        if (file_maze.at(0) == '1')
        {
            if (file_maze.length() == 253)
            {
                if (file_maze.at(252) == '1')
                {
                    if (counter == 125)
                    {
                        my_maze = file_maze;
                        file.close();
                        return true;
                    }
                }
            }
        }
    }

	return false;
}

vector<string> Pathfinder::solveMaze()
{
    solution.clear();

	stringstream transfer;
	transfer << my_maze;

	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5; j++)
		{
			for (int k=0; k<5; k++)
			{
				transfer >> maze[k][j][i];
			}
		}
	}


	if (solve(0, 0, 0) == true)
    {
		return solution;
	}

	return solution;
}

bool Pathfinder::solve(int x, int y, int z)
{
	solution.push_back("(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")");

	if (x < 0 || y < 0 || z < 0 || x > 4 || y > 4 || z > 4)
	{
		solution.pop_back();
		return false;
	}

	if (maze[x][y][z] == 0)
	{
		solution.pop_back();
		return false;
	}

	if (maze[x][y][z] == 5)
	{
		solution.pop_back();
		return false;
	}

	if (maze[x][y][z] == 3)
	{
		solution.pop_back();
		return false;
	}

	if (x == 4 && y == 4 && z == 4)
		return true;

	maze[x][y][z] = 5;


	if (solve(x+1, y, z) == true)
		return true;

	if (solve(x, y+1, z) == true)
		return true;

	if (solve(x, y, z+1) == true)
		return true;

	if (solve(x, y, z-1) == true)
		return true;

	if (solve(x-1, y, z) == true)
		return true;

	if (solve(x, y-1, z) == true)
		return true;

	solution.pop_back();

	maze[x][y][z] = 3;

	return false;
}



