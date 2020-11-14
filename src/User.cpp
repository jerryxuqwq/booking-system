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
	std::cout << "New User" << std::endl;
	// TODO Auto-generated constructor stub

}

User::~User()
{

}

void User::Login()
{

	mysqlpp::Connection conn(false);

	if (conn.connect(db, server, user, password))
	{

		mysqlpp::Query query = conn.query("SELECT * FROM user");
		if (mysqlpp::StoreQueryResult res = query.store())
		{

			mysqlpp::StoreQueryResult::const_iterator it;
			for (it = res.begin(); it != res.end(); ++it)
			{
				mysqlpp::Row row = *it;
				std::cout << "1:" << row[2] << std::endl;
				std::cout << "2:" << row[3] << std::endl;
				if (row[2] == Username && row[3] == Password)
				{
					std::cout << row[0] << std::endl;

					Update(row[0]);
					LoginUser.is_login = true;

				}
				else if (it >= res.end())
				{
					//return 0;
					LoginUser.is_login = false;
				}
			}
		}

	}

}
int User::Update(int in_user_id)
{

	mysqlpp::Connection conn(false);

	if (conn.connect(db, server, user, password))
	{

		mysqlpp::Query query = conn.query(
				"SELECT * FROM `user` WHERE `user_id`="
						+ std::to_string(in_user_id));
		if (mysqlpp::StoreQueryResult res = query.store())
		{
			std::cout << "updateing" << std::endl;

			mysqlpp::StoreQueryResult::const_iterator it;
			for (it = res.begin(); it != res.end(); ++it)
			{
				mysqlpp::Row row = *it;
				LoginUser.user_name.assign(row[1]);
				LoginUser.user_loginname.assign(row[2]);
				LoginUser.user_password.assign(row[3]);
				LoginUser.user_email.assign(row[4]);
				LoginUser.user_level = row[5];
				LoginUser.user_status = row[6];
				std::cout << " " << row[0] << row[1] << row[2] << row[3]
						<< row[4] << row[5] << row[6] << std::endl;
				std::cout << LoginUser.user_id << std::endl;
			}

		}
		return 0;

	}
	else
		return -1;

}

const User_data& User::GetLoginUser() const
{
	return LoginUser;
}

void User::SetLoginUser(const User_data &loginUser)
{
	LoginUser = loginUser;
}
