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
std::vector<appointment_data> Appointment::Update()
{
//	const char *db = "meetingsystem", *server = "127.0.0.1", *user = "library",
//			*password = "jtO3ngAeISZKFH0O";
	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	mysqlpp::Query query = conn.query("SELECT * FROM `appointment`");

	std::cout << conn.connect(db, server, user, password) << std::endl;
	//appointment_data *data = new appointment_data[query.end];
	int temp = query.end+1;
	std::vector<appointment_data> data;
	appointment_data apm_data;

	if(mysqlpp::StoreQueryResult res = query.store())
	{
		int i = 0;
		std::cout << "connect to the database" << std::endl;

		mysqlpp::StoreQueryResult::const_iterator it;

		for(it = res.begin(); it != res.end(); ++it)
		{

			mysqlpp::Row row = *it;

			apm_data.apm_id = row[0];
			apm_data.apm_room_id = row[1];
			apm_data.apm_user_id = row[2];
			apm_data.apm_end_date = row[3];
			apm_data.apm_begin_date = row[4];
			apm_data.apm_approve_status = row[5];
			apm_data.apm_reason.assign((row[6]));
			data.push_back(apm_data);
//			std::cout << " " << row[0] << row[1] << row[3] << row[4] << row[5]
//					<< row[6] << std::endl;
//			std::string test = apm_data.apm_reason.assign((row[6]));
//			std::cout << "in apm_data  " << apm_data.apm_id << "  "
//					<< apm_data.apm_room_id << "  " << apm_data.apm_user_id
//					<< "  " << "  " << apm_data.apm_end_date << "  "
//					<< apm_data.apm_begin_date << "  "
//					<< apm_data.apm_approve_status << std::endl;
			i++;
			std::cout << "const_iterator"<< i << std::endl;
		}

		std::cout << "finish1" << std::endl;
	}

	std::cout << "finish2" << std::endl;


	return data;
}
