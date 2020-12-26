/*
 * LoginPage.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: jerry
 */

#include "LoginPage.h"
#include <iostream>



LoginPage::LoginPage() :
	m_Button_Login("Login"), m_Label_Username("Username:"), m_Label_Password(
	    "Password:")
//,m_VBox(Gtk::ORIENTATION_VERTICAL)
{
	set_size_request(250, 100);
	set_title("Login");

	add(m_grid);

	m_Entry_Username.set_max_length(30);
	m_Entry_Username.set_text("jerry");
	m_Entry_Username.select_region(0, m_Entry_Username.get_text_length());

	m_grid.attach(m_Label_Username, 0, 1);
	m_grid.attach(m_Entry_Username, 1, 1);

	m_Entry_Password.set_max_length(30);
	m_Entry_Password.set_text("jerry");
	m_Entry_Password.select_region(0, m_Entry_Password.get_text_length());
	m_Entry_Password.set_visibility(false);

	m_grid.attach(m_Label_Password, 0, 2);
	m_grid.attach_next_to(m_Entry_Password, m_Label_Password, Gtk::POS_RIGHT);

	m_Button_Login.set_can_default();
	m_Button_Login.grab_default();
	m_grid.attach_next_to(m_Button_Login, m_Entry_Password, Gtk::POS_BOTTOM, 2,
	                      1);

	show_all_children();

	m_Button_Login.signal_clicked().connect(
	    sigc::mem_fun(*this,&LoginPage::on_Buttom_Login_A));


}

LoginPage::~LoginPage()
{
}

void LoginPage::on_Buttom_Login_A()
{


	switch(LoginUser.Login(m_Entry_Username.get_text(),
	                       m_Entry_Password.get_text()))
	{

	case 1:
	{
		//LoginUser.Update(LoginUserData.user_id);
		LoginUser.Update();

		//std::cout<<"username in LoginPage="<<LoginUser.GetUserName()<<std::endl;

		if(win!=NULL)
		{
			delete win;
		}
		
		win= new UserPage();
		//User NewUser;
		win->Update();
		win->show();

		break;
	}

	case 0:
	{
		Gtk::MessageDialog dialog(*this, "Error");
		dialog.set_secondary_text("Error");
		dialog.run();
		break;
	}

	case 2:
	{
		Gtk::MessageDialog dialog(*this, "Error");
		dialog.set_secondary_text("No DataBase");
		dialog.run();
		break;
	}

	}



}
