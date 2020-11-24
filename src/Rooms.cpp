/*
 * Rooms.cpp
 *
 *  Created on: Oct 29, 2020
 *      Author: jerry
 */

#include "Rooms.h"
#include <iostream>
using namespace std;
Rooms::Rooms()
{
	// TODO Auto-generated constructor stub
	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	conn.connect(db, server, user, password);
	mysqlpp::Query query = conn.query("SELECT * FROM `rooms` ");

	if(mysqlpp::StoreQueryResult res = query.store())
	{
		cout.setf(ios::left);

		mysqlpp::StoreQueryResult::const_iterator it;

		for(it = res.begin(); it != res.end(); ++it)
		{
			rooms_data data;
			mysqlpp::Row row = *it;
			data.room_id =row[0];
			data.room_level=row[1];
			data.room_name.assign(row[2]);
			data.room_dsp.assign(row[3]);
			data.room_status=row[4];
			roomlist.push_back(data);
			
			//std::cout << " " << row[0] << row[1] <<row[2]<< row[3] << row[4]  << endl;
		}
	}
	else
		std::cout<<"out"<<std::endl;


}

Rooms::~Rooms()
{
	// TODO Auto-generated destructor stub
}
rooms_data Rooms::GetRoom(int in_id)
{
	return roomlist[in_id-1]; // vector start at 0, so -1 to match the ID in database
}


