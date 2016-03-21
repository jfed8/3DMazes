/*
 * Factory.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: jjfeddock
 */

#include "Factory.h"
#include "Pathfinder.h"
#include "PathfinderInterface.h"

using namespace std;

/*
	createPathfinder()
*/
PathfinderInterface* Factory::createPathfinder()
{
    return new Pathfinder();
}
//=======================================================================================
