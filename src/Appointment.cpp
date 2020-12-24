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

int Appointment::add(int apm_room_id, int apm_user_id,
                     Glib::ustring apm_reason, mysqlpp::sql_datetime apm_begin_date)
{
	mysqlpp::sql_date date(apm_begin_date);
	mysqlpp::sql_time time(apm_begin_date);

	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	conn.connect(db, server, user, password);
	// Form the query to insert the row into the stock table.
	mysqlpp::Query query = conn.query();
	query << "INSERT INTO `appointment`"<<
	      "(`apm_room_id`,`apm_user_id`,`apm_reason`,`apm_begin_date`,`apm_begin_time`)"
	      <<"VALUES("+
	      std::to_string(apm_room_id)+","+std::to_string(apm_user_id)+
	      ",\""+apm_reason+"\",'"+date.str()+"','"+time.str()+
	      "')";
	//std::cout<<query<<std::endl;
	query.execute();

	return 1;
}

std::vector<appointment_data> Appointment::UserUpdate(int user_id)
{
//	const char *db = "meetingsystem", *server = "127.0.0.1", *user = "library",
//			*password = "jtO3ngAeISZKFH0O";
	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	conn.connect(db, server, user, password);
	//appointment_data *data = new appointment_data[query.end];
	mysqlpp::Query query =
	    conn.query("SELECT * FROM `appointment` WHERE apm_user_id="+std::to_string(
	                   user_id));
	std::vector<appointment_data> data;
	appointment_data apm_data;

	if(mysqlpp::StoreQueryResult res = query.store())
	{


		mysqlpp::StoreQueryResult::const_iterator it;

		for(it = res.begin(); it != res.end(); ++it)
		{

			mysqlpp::Row row = *it;

			apm_data.apm_id = row[0];
			apm_data.apm_room_id = row[1];
			apm_data.apm_user_id = row[2];
			apm_data.apm_begin_date = row[3];
			apm_data.apm_begin_time = row[4];
			apm_data.apm_end_date = row[5];
			apm_data.apm_end_time = row[6];
			apm_data.apm_approve_status = row[7];
			apm_data.apm_reason.assign((row[8]));
			apm_data.apm_period=ConvertToPeriod(row[4]);
			data.push_back(apm_data);
//			std::cout << " " << row[0] << row[1] << row[2]<<row[3] << row[4] << row[5]
//			          << row[6] << std::endl;
//			std::string test = apm_data.apm_reason.assign((row[6]));
//			std::cout << "in apm_data  " << apm_data.apm_id << "  "
//					<< apm_data.apm_room_id << "  " << apm_data.apm_user_id
//					<< "  " << "  " << apm_data.apm_end_time << "  "
//					<< apm_data.apm_begin_time << "  "
//					<< apm_data.apm_approve_status << std::endl;
		}

	}

	return data;
}

std::vector<appointment_data> Appointment::DateUpdate(mysqlpp::sql_date
        apm_begin_date)
{
//	const char *db = "meetingsystem", *server = "127.0.0.1", *user = "library",
//			*password = "jtO3ngAeISZKFH0O";
	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	conn.connect(db, server, user, password);

	mysqlpp::Query query =
	    conn.query("SELECT * FROM `appointment` WHERE `apm_begin_date` ='"+
	               apm_begin_date.str()+"'");
	//std::cout<<query<<std::endl;
	std::vector<appointment_data> data;
	appointment_data apm_data;

	if(mysqlpp::StoreQueryResult res = query.store())
	{

		mysqlpp::StoreQueryResult::const_iterator it;

		for(it = res.begin(); it != res.end(); ++it)
		{

			mysqlpp::Row row = *it;

			apm_data.apm_id = row[0];
			apm_data.apm_room_id = row[1];
			apm_data.apm_user_id = row[2];
			apm_data.apm_begin_date = row[3];
			apm_data.apm_begin_time = row[4];
			apm_data.apm_end_date = row[5];
			apm_data.apm_end_time = row[6];
			apm_data.apm_approve_status = row[7];
			apm_data.apm_reason.assign((row[8]));
			apm_data.apm_period=ConvertToPeriod(row[4]);
			data.push_back(apm_data);
//			std::cout << " " << row[0] << row[1] << row[2]<<row[3] << row[4] << row[5]
//			          << row[6] << std::endl;
//			std::string test = apm_data.apm_reason.assign((row[6]));
//			std::cout << "in apm_data  " << apm_data.apm_id << "  "
//					<< apm_data.apm_room_id << "  " << apm_data.apm_user_id
//					<< "  " << "  " << apm_data.apm_end_date << "  "
//					<< apm_data.apm_begin_date << "  "
//					<< apm_data.apm_approve_status << std::endl;
		}

	}

	return data;
}

int Appointment::change_approve(int apm_id, int state)
{
	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	conn.connect(db, server, user, password);
	// Form the query to insert the row into the stock table.
	mysqlpp::Query query = conn.query();
//	query << "INSERT INTO `appointment`"<<
//	      "(`apm_room_id`,`apm_user_id`,`apm_reason`,`apm_begin_date`,`apm_begin_time`)"
//	      <<"VALUES("+
//	      std::to_string(apm_room_id)+","+std::to_string(apm_user_id)+
//	      ",\""+apm_reason+"\",'"+date.str()+"','"+time.str()+
//	      "')";
	query << "UPDATE appointment SET apm_approve_status=\'"<<std::to_string(state)<<"\' WHERE apm_id="<<std::to_string(apm_id);
	      //std::cout<<query<<std::endl;
	query.execute();

	return 1;
}

int Appointment::ConvertToPeriod(mysqlpp::sql_time apm_begin_time)
{

	int hour = apm_begin_time.hour(), minute = apm_begin_time.minute();

	//std::cout<<"hour"<<hour<<" "<<minute <<std::endl;

	if(hour == 7 && minute == 30) return 1;

	else if(hour ==  8 && minute == 25) return 2;

	else if(hour ==  9 && minute == 20) return 3;

	else if(hour == 10 && minute == 20) return 4;

	else if(hour == 11 && minute == 15) return 5;

	else if(hour == 13 && minute == 30) return 6;

	else if(hour == 14 && minute == 25) return 7;

	else if(hour == 15 && minute == 25) return 8;

	else if(hour == 16 && minute == 20) return 9;

	else if(hour == 18 && minute == 30) return 10;

	else if(hour == 20 && minute ==  0) return 11;

	else if(hour == 21 && minute == 30) return 12;

	else return -1;
}

mysqlpp::Time Appointment::ConvertToBeginTime(int period)
{
	mysqlpp::Time time;

	switch(period)
	{

	case 1:
		time.hour(7);
		time.minute(30);
		break;

	case 2:
		time.hour(8);
		time.minute(25);
		break;

	case 3:
		time.hour(9);
		time.minute(20);
		break;

	case 4:
		time.hour(10);
		time.minute(20);
		break;

	case 5:
		time.hour(11);
		time.minute(15);
		break;

	case 6:
		time.hour(13);
		time.minute(30);
		break;

	case 7:
		time.hour(14);
		time.minute(30);
		break;

	case 8:
		time.hour(15);
		time.minute(25);
		break;

	case 9:
		time.hour(16);
		time.minute(20);
		break;

	case 10:
		time.hour(18);
		time.minute(30);
		break;

	case 11:
		time.hour(20);
		time.minute(0);
		break;

	case 12:
		time.hour(21);
		time.minute(12);
		break;

	}

	return time;
}

int Appointment::del(int apm_id)
{
	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	conn.connect(db, server, user, password);
	// Form the query to insert the row into the stock table.
	mysqlpp::Query query = conn.query();
	query << "DELETE FROM `appointment` WHERE apm_id="<<apm_id;
	//std::cout<<query<<std::endl;
	query.execute();
	return 1;
}

mysqlpp::Time Appointment::ConvertToEndTime(int period)
{
	mysqlpp::Time time;
	return time;
}

std::vector<appointment_data> Appointment::DateUpdate(int apm_room_id,
        mysqlpp::sql_date apm_begin_date)
{
	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
	conn.connect(db, server, user, password);

	mysqlpp::Query query =
	    conn.query("SELECT * FROM `appointment` WHERE `apm_begin_date` ='"+
	               apm_begin_date.str()+"' AND `apm_room_id` = '"+std::to_string(
	                   apm_room_id)+"'");
	//std::cout<<query<<std::endl;
	std::vector<appointment_data> data;
	appointment_data apm_data;

	if(mysqlpp::StoreQueryResult res = query.store())
	{

		mysqlpp::StoreQueryResult::const_iterator it;

		for(it = res.begin(); it != res.end(); ++it)
		{

			mysqlpp::Row row = *it;

			apm_data.apm_id = row[0];
			apm_data.apm_room_id = row[1];
			apm_data.apm_user_id = row[2];
			apm_data.apm_begin_date = row[3];
			apm_data.apm_begin_time = row[4];
			apm_data.apm_end_date = row[5];
			apm_data.apm_end_time = row[6];
			apm_data.apm_approve_status = row[7];
			apm_data.apm_reason.assign((row[8]));
			apm_data.apm_period=ConvertToPeriod(row[4]);
			data.push_back(apm_data);
//			std::cout << " " << row[0] << row[1] << row[2]<<row[3] << row[4] << row[5]
//			          << row[6] << std::endl;
//			std::string test = apm_data.apm_reason.assign((row[6]));
//			std::cout << "in apm_data  " << apm_data.apm_id << "  "
//					<< apm_data.apm_room_id << "  " << apm_data.apm_user_id
//					<< "  " << "  " << apm_data.apm_end_date << "  "
//					<< apm_data.apm_begin_date << "  "
//					<< apm_data.apm_approve_status << std::endl;
		}

	}

	return data;
}
