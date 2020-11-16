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
	Rooms(int in_room_id);
	virtual ~Rooms();


	Rooms& SetRoomDsp(const Glib::ustring& room_dsp)
	{
		this->room_dsp = room_dsp;
		return *this;
	}
	Rooms& SetRoomId(int room_id)
	{
		this->room_id = room_id;
		return *this;
	}
	Rooms& SetRoomLevel(int room_level)
	{
		this->room_level = room_level;
		return *this;
	}
	Rooms& SetRoomName(const Glib::ustring& room_name)
	{
		this->room_name = room_name;
		return *this;
	}
	Rooms& SetRoomStatus(int room_status)
	{
		this->room_status = room_status;
		return *this;
	}
	const Glib::ustring& GetRoomDsp() const
	{
		return room_dsp;
	}
	int GetRoomId() const
	{
		return room_id;
	}
	int GetRoomLevel() const
	{
		return room_level;
	}
	const Glib::ustring& GetRoomName() const
	{
		return room_name;
	}
	int GetRoomStatus() const
	{
		return room_status;
	}

private:
	int room_id, room_level, room_status;
	Glib::ustring room_name, room_dsp;
};

#endif /* INCLUDE_ROOMS_H_ */
