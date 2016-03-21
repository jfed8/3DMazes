/*
 * Factory.h
 *
 *  Created on: Feb 24, 2016
 *      Author: jjfeddock
 */

#include "PathfinderInterface.h"
#pragma once

/*
	createPathfinder()
*/
class Factory
{
public:
	static PathfinderInterface* createPathfinder();
};

//=======================================================================================
