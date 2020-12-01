/*
 * Appointment.h
 *
 *  Created on: Oct 29, 2020
 *      Author: jerry
 */

#ifndef APPOINTMENT_H_
#define APPOINTMENT_H_
#include <gtkmm.h>
#include <mysql++.h>
#include <vector>
#include <datetime.h>
#include "Global.h"
#include "Database.h"
#include <string>
struct appointment_data
{
	int apm_id, apm_room_id, apm_user_id, apm_approve_status;
	Glib::ustring apm_reason;
	mysqlpp::sql_date apm_begin_date, apm_end_date;
	mysqlpp::sql_time apm_begin_time, apm_end_time;
	int apm_period;
};

class Appointment
{
public:
	std::vector<appointment_data> Update(int user_id);
	std::vector<appointment_data> Update();


	Appointment();
	int add(int apm_room_id, int apm_user_id,
	        Glib::ustring apm_reason, mysqlpp::sql_datetime apm_begin_date,
	        mysqlpp::sql_datetime apm_end_date);
	virtual ~Appointment();

private:
	int ConvertToPeriod(mysqlpp::sql_time apm_begin_time,
	                    mysqlpp::sql_time apm_end_time);


};

#endif /* APPOINTMENT_H_ */
