/*
 * Rooms.cpp
 *
 *  Created on: Oct 29, 2020
 *      Author: jerry
 */

#include "Rooms.h"
#include <iostream>
using namespace std;
Rooms::Rooms(int in_room_id)
{
	// TODO Auto-generated constructor stub
	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	conn.connect(db, server, user, password);
	mysqlpp::Query query = conn.query("SELECT * FROM `rooms` WHERE `room_id`="
	                                  + std::to_string(in_room_id));

	if(mysqlpp::StoreQueryResult res = query.store())
	{
		cout.setf(ios::left);

		mysqlpp::StoreQueryResult::const_iterator it;

		for(it = res.begin(); it != res.end(); ++it)
		{
			mysqlpp::Row row = *it;
			room_id =row[0];
			room_level=row[1];
			room_name.assign(row[2]);
			room_dsp.assign(row[3]);
			room_status=row[4];
//			std::cout << " " << row[0] << row[1] <<row[2]<< row[3] << row[4]  << endl;
		}
	}


}

Rooms::~Rooms()
{
	// TODO Auto-generated destructor stub
}


