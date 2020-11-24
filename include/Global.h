#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <gtkmm.h>
#include <vector>
#include "User.h"
#include <iostream>
#include "mysql++.h"
#include "Rooms.h"

struct rooms_data
{
	int room_id, room_level, room_status;
	Glib::ustring room_name, room_dsp;
};

std::vector<rooms_data> roomlist;

extern User LoginUser;
//Glib::ustring Username, Password; //input by User, use for check login


#endif /* GLOBAL_H_ */
