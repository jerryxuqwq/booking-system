/*
 * Appointment.cpp
 *
 *  Created on: Oct 29, 2020
 *      Author: jerry
 */

#include "Appointment.h"

Appointment::Appointment()
{
	// TODO Auto-generated constructor stub

}

Appointment::~Appointment()
{
	// TODO Auto-generated destructor stub
}
appointment_data* Appointment::Update()
{
	const char *db = "meetingsystem", *server = "127.0.0.1", *user = "library",
			*password = "jtO3ngAeISZKFH0O";
	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	mysqlpp::Query query = conn.query("SELECT * FROM `appointment`");

	std::cout << conn.connect(db, server, user, password) << std::endl;
	//appointment_data *data = new appointment_data[query.end];
	int temp = query.end+1;
	appointment_data* data = new appointment_data[temp];
	if (mysqlpp::StoreQueryResult res = query.store())
	{
		int i = 0;
		std::cout << "connect to the database" << std::endl;

		mysqlpp::StoreQueryResult::const_iterator it;
		for (it = res.begin(); it != res.end(); ++it)
		{

			mysqlpp::Row row = *it;
			data[i].apm_id = row[0];
			data[i].apm_room_id = row[1];
			data[i].apm_user_id = row[2];
			data[i].apm_end_date = row[3];
			data[i].apm_begin_date = row[4];
			data[i].apm_approve_status = row[5];
			data[i].apm_reason.assign((row[6]));
//			std::cout << " " << row[0] << row[1] << row[3] << row[4] << row[5]
//					<< row[6] << std::endl;
//			std::string test = data[i].apm_reason.assign((row[6]));
//			std::cout << "in data[i]  " << data[i].apm_id << "  "
//					<< data[i].apm_room_id << "  " << data[i].apm_user_id
//					<< "  " << "  " << data[i].apm_end_date << "  "
//					<< data[i].apm_begin_date << "  "
//					<< data[i].apm_approve_status << std::endl;
			i++;
			std::cout << "const_iterator"<< i << std::endl;
		}
		std::cout << "finish1" << std::endl;
	}
	std::cout << "finish2" << std::endl;


	return data;
}
