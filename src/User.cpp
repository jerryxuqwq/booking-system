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
					std::cout << row[0] << std::endl;

					Update(row[0]);
					LoginUserData.is_login = true;

					return 1;


				}

				else if(it >= res.end())
				{

					LoginUserData.is_login = false;
					return 0;
				}
			}
		}

	}

	else
	{
		std::cout<<"cannot connect to the database"<<std::endl;
	}

}

int User::Update(int in_user_id)
{

	mysqlpp::Connection conn(false);

	if(conn.connect(db, server, user, password))
	{

		mysqlpp::Query query = conn.query(
		                           "SELECT * FROM `user` WHERE `user_id`="
		                           + std::to_string(in_user_id));

		if(mysqlpp::StoreQueryResult res = query.store())
		{

			mysqlpp::StoreQueryResult::const_iterator it;

			for(it = res.begin(); it != res.end(); ++it)
			{
				mysqlpp::Row row = *it;
				LoginUserData.user_name.assign(row[1]);
				LoginUserData.user_loginname.assign(row[2]);
				LoginUserData.user_password.assign(row[3]);
				LoginUserData.user_email.assign(row[4]);
				LoginUserData.user_level = row[5];
				LoginUserData.user_status = row[6];
//				std::cout << " " << row[0] << row[1] << row[2] << row[3]
//				          << row[4] << row[5] << row[6] << std::endl;
//				std::cout << LoginUserData.user_id << std::endl;
			}

		}

		return 0;

	}

	else
		return -1;

}
