/*
 * Rooms.h
 *
 *  Created on: Oct 29, 2020
 *      Author: jerry
 */

#ifndef INCLUDE_ROOMS_H_
#define INCLUDE_ROOMS_H_
#include <gtkmm-3.0/gtkmm.h>
#include "Database.h"
#include <mysql++.h>
#include <vector>

struct rooms_data
{
	int room_id, room_level, room_status;
	Glib::ustring room_name, room_dsp;
};

class Rooms
{
public:
	Rooms();

	virtual ~Rooms();
	rooms_data GetRoom(int in_id);

	const std::vector<rooms_data>& GetRoomlist() const
	{
		return roomlist;
	}
	
private:
	std::vector<rooms_data> roomlist;

};

#endif /* INCLUDE_ROOMS_H_ */
