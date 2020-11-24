/*
 * Rooms.h
 *
 *  Created on: Oct 29, 2020
 *      Author: jerry
 */

#ifndef INCLUDE_ROOMS_H_
#define INCLUDE_ROOMS_H_
#include <gtkmm-3.0/gtkmm.h>
#include <vector>
#include "Global.h"
class Rooms
{
public:
	Rooms();

	virtual ~Rooms();
	rooms_data GetRoom(int in_id);

};

#endif /* INCLUDE_ROOMS_H_ */
