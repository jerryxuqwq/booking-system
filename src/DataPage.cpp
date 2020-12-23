/*
 * DataPage.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: jerry
 */

#include "DataPage.h"
#include <iostream>
#include <string>

using namespace std;

DataPage::DataPage()
{


//		row = *(m_refTreeModel->append());
//		row[m_Columns.m_col_apm_id] = i;
//		row[m_Columns.m_col_room_name] = "测试房间2";


//Add the TreeView's view columns:
	append_column("APID", m_Columns.m_col_apm_id);
	append_column("ROOM", m_Columns.m_col_room_name);
	append_column("BEGIN DATA", m_Columns.m_col_begin_date);
	append_column("BEGIN TIME", m_Columns.m_col_begin_time);
	append_column("REASON",m_Columns.m_col_reason);
	append_column("APPROVE",m_Columns.m_col_approve_status);

	m_assistant_new.signal_apply().connect(
	    sigc::mem_fun(*this, &DataPage::Update));
//Fill popup menu:
	auto item = Gtk::make_managed<Gtk::MenuItem>("_New", true);
	item->signal_activate().connect(sigc::mem_fun(*this,
	                                &DataPage::on_menu_file_popup_new));
	m_Menu_Popup.append(*item);

//	item = Gtk::make_managed<Gtk::MenuItem>("_Process", true);
//	item->signal_activate().connect(
//	    sigc::mem_fun(*this, &DataPage::on_menu_file_popup_generic));
//	m_Menu_Popup.append(*item);

	item = Gtk::make_managed<Gtk::MenuItem>("_Delete", true);
	item->signal_activate().connect(
	    sigc::mem_fun(*this,&DataPage::on_menu_file_popup_delete));
	m_Menu_Popup.append(*item);

	m_Menu_Popup.accelerate(*this);
	m_Menu_Popup.show_all(); //Show all menu items when the menu pops up
}

DataPage::~DataPage()
{
}

bool DataPage::on_button_press_event(GdkEventButton *button_event)
{
	bool return_value = false;

	//Call base class, to allow normal handling,
	//such as allowing the row to be selected by the right-click:
	return_value = TreeView::on_button_press_event(button_event);

	//Then do our custom stuff:
	if((button_event->type == GDK_BUTTON_PRESS) && (button_event->button == 3))
	{
		m_Menu_Popup.popup_at_pointer((GdkEvent*) button_event);

		// Menu::popup_at_pointer() is new in gtkmm 3.22.
		// If you have an older revision, try this:
		//m_Menu_Popup.popup(button_event->button, button_event->time);
	}

	return return_value;
}

void DataPage::on_menu_file_popup_delete()
{
	auto refSelection = get_selection();

	if(refSelection)
	{
		Gtk::TreeModel::iterator iter = refSelection->get_selected();

		if(iter)
		{
			int id = (*iter)[m_Columns.m_col_apm_id];
			//std::cout << "  Delete ID=" << id << std::endl;
			DelAppointment.del(id);
			Update();
		}

	}


}
void DataPage::on_menu_file_popup_generic()
{
	//std::cout << "A popup menu item was selected." << std::endl;

	auto refSelection = get_selection();

	if(refSelection)
	{
		Gtk::TreeModel::iterator iter = refSelection->get_selected();

		if(iter)
		{
			int id = (*iter)[m_Columns.m_col_apm_id];
			std::cout << "  Selected ID=" << id << std::endl;
		}
	}
}

void DataPage::on_menu_file_popup_new()
{
	m_assistant_new.show();
	std::cout<<"show new page"<<std::endl;
	Update();
}

void DataPage::Update()
{
	std::vector<appointment_data> data;
	Appointment apm_data;

	data = apm_data.UserUpdate(LoginUser.GetUserId());
	//std::cout<<"UserID in DataPage"<<LoginUser.GetUserId()<<std::endl;


	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	set_model(m_refTreeModel);
	//Fill the TreeView's model
	Gtk::TreeModel::Row row; //= *(m_refTreeModel->append());
//	row[m_Columns.m_col_apm_id] = 0;
//	row[m_Columns.m_col_room_name] = "Name of the room";
//	row[m_Columns.m_col_reason] = "Here is Reasons";
//	row[m_Columns.m_col_approve_status] ="Status";

	for(int i = 0; i < data.size(); i++)
	{
		rooms_data room_data = room_list.GetRoom(data[i].apm_room_id);

		std::string Bdate=data[i].apm_begin_date, Btime=data[i].apm_begin_time;

		row = *(m_refTreeModel->append());
		row[m_Columns.m_col_apm_id] = data[i].apm_id;
		row[m_Columns.m_col_room_name] = room_data.room_name;
		row[m_Columns.m_col_begin_date] = Bdate;
		row[m_Columns.m_col_begin_time] = Btime;
		row[m_Columns.m_col_reason] = data[i].apm_reason;

		switch(data[i].apm_approve_status)
		{
		case 1:
			row[m_Columns.m_col_approve_status] = "Approved";
			break;

		case 0:
			row[m_Columns.m_col_approve_status] = "Waiting";
			break;

		case -1:
			row[m_Columns.m_col_approve_status] = "Reject";
			break;

		default:
			row[m_Columns.m_col_approve_status]=std::to_string(data[i].apm_approve_status);
		}

	}


}
