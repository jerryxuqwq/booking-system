/*
 * UserPage.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: jerry
 */

#include "UserPage.h"

UserPage::~UserPage()
{
	// TODO Auto-generated destructor stub
}

UserPage::UserPage(User_data LoginUser) :
		m_VBox(Gtk::ORIENTATION_VERTICAL), m_Button_Quit("Quit"), m_Label_Username(
				"test", true)
{
	set_title("Meeting system GUI");
	set_border_width(5);
	set_default_size(400, 200);

	add(m_VBox);

	//Add the TreeView, inside a ScrolledWindow, with the button underneath:
	m_ScrolledWindow.add(m_TreeView);

	//Only show the scrollbars when they are necessary:
	m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	m_VBox.pack_start(m_ScrolledWindow);
	m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

	m_ButtonBox.pack_start(m_Label_Username);
	m_Label_Username.set_text("欢迎 "+ LoginUser.user_name);
	m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
	m_ButtonBox.set_border_width(5);
	m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);
	m_Button_Quit.signal_clicked().connect(
			sigc::mem_fun(*this, &UserPage::on_button_quit));

	show_all_children();

}

void UserPage::on_button_quit()
{
	hide();
}
