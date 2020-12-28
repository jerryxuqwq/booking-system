/*
 * User.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: jerry
 */

#include "User.h"
#include <iostream>
#include <UserPage.h>
#include <LoginPage.h>


User::User()
{
	// TODO Auto-generated constructor stub

}

User::~User()
{

}

int User::Login(Glib::ustring Username, Glib::ustring Password)
{

	mysqlpp::Connection conn(false);

	if(conn.connect(db, server, user, password))
	{

		mysqlpp::Query query = conn.query("SELECT * FROM user");

		if(mysqlpp::StoreQueryResult res = query.store())
		{

			mysqlpp::StoreQueryResult::const_iterator it;

			for(it = res.begin(); it != res.end(); ++it)
			{
				mysqlpp::Row row = *it;

				if(row[2] == Username && row[3] == Password)
				{
					//std::cout <<"Userid in User"<< row[0] << std::endl;
					user_id=row[0];
					Update();
					is_login = true;

					return 1;
				}

				else if(it == res.end()-1)
				{

					is_login = false;
					return 0;
				}
			}
		}

	}

	else
	{
		return 2;
	}

}

int User::Update()
{

	mysqlpp::Connection conn(false);

	if(conn.connect(db, server, user, password))
	{

		mysqlpp::Query query = conn.query(
		                           "SELECT * FROM `user` WHERE `user_id`="
		                           + std::to_string(user_id));
		//std::cout<<"in_user_id in User"<<user_id<<std::endl;

		if(mysqlpp::StoreQueryResult res = query.store())
		{

			mysqlpp::StoreQueryResult::const_iterator it;

			for(it = res.begin(); it != res.end(); ++it)
			{
				mysqlpp::Row row = *it;
				user_name.assign(row[1]);
				user_loginname.assign(row[2]);
				user_password.assign(row[3]);
				user_email.assign(row[4]);
				user_level = row[5];
				user_status = row[6];
				//std::cout << " " << row[0] << row[1] << row[2] << row[3]
				//          << row[4] << row[5] << row[6] << std::endl;
				//std::cout <<"user_id in User.Update"<< user_id << std::endl;
			}

		}

		return 0;

	}

	else
		return -1;

}
