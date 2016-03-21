/*
 * Pathfinder.h
 *
 *  Created on: Feb 24, 2016
 *      Author: jjfeddock
 */
#pragma once

#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include "PathfinderInterface.h"

class Pathfinder : public PathfinderInterface
{
public:
	Pathfinder();
	virtual ~Pathfinder() {}

	string getMaze();
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
	bool solve(int x, int y, int z);

private:
	string my_maze;
	int maze[5][5][5];
	vector<string> solution;
        int x;

};


#endif /* PATHFINDER_H_ */
