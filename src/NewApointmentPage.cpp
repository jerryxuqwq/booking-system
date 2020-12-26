#include "NewApointmentPage.h"
#include <iostream>
#include <string>

NewApointmentPage::NewApointmentPage():
	m_box(Gtk::ORIENTATION_HORIZONTAL, 12),
	m_box1(Gtk::ORIENTATION_HORIZONTAL, 12),
	m_label1("Type text to allow the assistant to continue:"),
	m_label2("Confirmation page"),
	m_label3("Choose A time:"),
	m_check("Optional extra information")
{

	set_title("Gtk::Assistant example");
	set_border_width(12);
	set_default_size(400, 300);
//rooms
	m_scrolledWindow.add(m_TreeView_Rooms);
	m_scrolledWindow.set_size_request(300,100);
	m_scrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	m_TreeView_Rooms.append_column("ID", m_Columns.m_col_room_id);
	m_TreeView_Rooms.append_column("Name", m_Columns.m_col_room_name);
	m_TreeView_Rooms.append_column("Dsp", m_Columns.m_col_room_dsp);
	m_TreeView_Rooms.append_column("Status", m_Columns.m_col_room_status);

	m_refTreeModel_Rooms = Gtk::ListStore::create(m_Columns);
	m_TreeView_Rooms.set_model(m_refTreeModel_Rooms);

	refSelection = m_TreeView_Rooms.get_selection();

//rooms end

//APMs
	m_scrolledWindow_APM.add(m_TreeView_APM);
	m_scrolledWindow_APM.set_size_request(300,100);
	m_scrolledWindow_APM.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	m_TreeView_APM.append_column("Period", m_Columns.m_col_period);
	m_TreeView_APM.append_column("Begin Time", m_Columns.m_col_begin_time);
	//m_TreeView_APM.append_column("End Time", m_Columns.m_col_end_time);
	m_TreeView_APM.append_column("Status", m_Columns.m_col_approve_status);



	m_refTreeModel_APM = Gtk::ListStore::create(m_Columns);
	m_TreeView_APM.set_model(m_refTreeModel_APM);

	refSelection_APM = m_TreeView_APM.get_selection();

	//Fill the TreeView's model


//APMs end

	PullRoomData();

	m_box.pack_start(m_calendar);
	//m_calendar.select_day(20);
	m_box.pack_start(m_scrolledWindow);

	append_page(m_box);
	set_page_title(*get_nth_page(0), "Select Date & Room");
	set_page_complete(m_box, false);

	m_box1.pack_start(m_label3);
	m_box1.pack_start(m_scrolledWindow_APM);
	append_page(m_box1);
	set_page_title(*get_nth_page(1), "Select Time");

	append_page(m_TextView);
	set_page_complete(m_TextView, true);
	set_page_title(*get_nth_page(2), "Reason");

	append_page(m_label2);
	set_page_title(*get_nth_page(3), "Confirmation");



	set_page_type(m_box, Gtk::ASSISTANT_PAGE_INTRO);
	set_page_type(m_label2, Gtk::ASSISTANT_PAGE_CONFIRM);

	signal_apply().connect(
	    sigc::mem_fun(*this,&NewApointmentPage::on_assistant_apply));
	signal_cancel().connect(
	    sigc::mem_fun(*this,&NewApointmentPage::on_assistant_cancel));
	signal_close().connect(
	    sigc::mem_fun(*this,&NewApointmentPage::on_assistant_close));
	signal_prepare().connect(
	    sigc::mem_fun(*this,&NewApointmentPage::on_assistant_prepare));

	refSelection->signal_changed().connect(
	    sigc::mem_fun(*this,&NewApointmentPage::on_entry_changed));
	refSelection_APM->signal_changed().connect(
	    sigc::mem_fun(*this,&NewApointmentPage::on_entry_changed_APM));

	show_all_children();
}

NewApointmentPage::~NewApointmentPage()
{
}

void NewApointmentPage::on_assistant_apply()
{
	mysqlpp::sql_datetime datetime;
	time_t rawtime;
	std::tm *info;
	time(&rawtime);
	info = localtime(&rawtime);
	mysqlpp::Date date;
	datetime.hour(NewAppointment.ConvertToBeginTime(C_period).hour());
	datetime.minute(NewAppointment.ConvertToBeginTime(C_period).minute());
	datetime.year(1900+info->tm_year);
	datetime.month(info->tm_mon+1);
	datetime.day(info->tm_mday);
	Glib::RefPtr<Gtk::TextBuffer> buffer =  m_TextView.get_buffer();

	NewAppointment.add(C_room,
	                   LoginUser.GetUserId(),
	                   buffer->get_text(),
	                   datetime
	                  );
}

void NewApointmentPage::on_assistant_cancel()
{

	hide();
}

void NewApointmentPage::on_assistant_close()
{
	hide();
}

void NewApointmentPage::on_assistant_prepare(Gtk::Widget* /* widget */)
{
	set_title(Glib::ustring::compose("Gtk::Assistant example (Page %1 of %2)",
	                                 get_current_page() + 1, get_n_pages()));


	if(get_current_page()==1)
	{
		PullAPMData();
	}



}
void NewApointmentPage::PullAPMData()
{
	Gtk::TreeModel::Row row;
	User ApplyUser;

	std::vector<appointment_data> apms = NewAppointment.DateUpdate(C_room,Sdate);



	m_refTreeModel_APM->clear();


	for(int i=1; i<=11; i++)
	{
		row= *(m_refTreeModel_APM->append());
		row[m_Columns.m_col_period] = i;
		row[m_Columns.m_col_begin_time] = NewAppointment.ConvertToBeginTime(
		                                      i).str();
		row[m_Columns.m_col_approve_status] = "Empty";

		for(int j=0; j<apms.size(); j++)
		{
			if(i==apms[j].apm_period)
			{
				ApplyUser.SetUserId(apms[j].apm_user_id);
				ApplyUser.Update();
				row[m_Columns.m_col_approve_status] = ApplyUser.GetUserName();
				exist_period.push_back(i);
			}
		}
	}

}
void NewApointmentPage::PullRoomData()
{
	std::vector<rooms_data> rooms = room_list.GetRoomlist();

	//Fill the TreeView's model
	for(int i=0; i< rooms.size(); i++)
	{
		Gtk::TreeModel::Row row = *(m_refTreeModel_Rooms->append());
		row[m_Columns.m_col_room_id] = rooms[i].room_id;
		row[m_Columns.m_col_room_name] = rooms[i].room_name;
		row[m_Columns.m_col_room_dsp] = rooms[i].room_dsp;

		switch(rooms[i].room_status)
		{
		case 0:
			row[m_Columns.m_col_room_status] = "OFS";
			broken_room.push_back(rooms[i].room_id);
			break;

		case 1:
			row[m_Columns.m_col_room_status] = "In service";
			break;
		}

	}

}



void NewApointmentPage::on_entry_changed()
{

	Glib::Date date;
	unsigned int year, month, day;

	//std::cout<<<<std::endl;
	if(refSelection)
	{

		m_calendar.get_date(year, month, day);
		month++;
		//std::cout<<"choose1:"<<year<<" "<<month<<" "<<day<<std::endl;
		Sdate.month(month);
		Sdate.year(year);
		Sdate.day(day);
		Gtk::TreeModel::iterator iter = refSelection->get_selected();
		
		set_page_complete(m_box, true);
		set_page_complete(m_label2, true);

		if(iter)
		{
			C_room = (*iter)[m_Columns.m_col_room_id];

			for(int i=0; i<broken_room.size(); i++)
			{
				if(C_room==broken_room[i])
				{
					set_page_complete(m_box, false);
					Gtk::MessageDialog dialog(*this, "Note");
					dialog.set_secondary_text("This room is out of service");
					dialog.run();
				}

			}

			text="You will book "+
			     (*iter)[m_Columns.m_col_room_name]+
			     " at "
			     +std::to_string(day)+ "/"
			     +std::to_string(month)+ "/"
			     +std::to_string(year)+" ";
		}



	}
}

void NewApointmentPage::on_entry_changed_APM()
{
	if(refSelection_APM)
	{
		Gtk::TreeModel::iterator iter = refSelection_APM->get_selected();


		if(iter)
		{
			C_period = (*iter)[m_Columns.m_col_period];
			m_label2.set_text(text+(*iter)[m_Columns.m_col_begin_time]);
			set_page_complete(m_box1, true);

			for(int i=0; i<exist_period.size(); i++)
			{
				if(C_period==exist_period[i])
				{
					set_page_complete(m_box1, false);
					Gtk::MessageDialog dialog(*this, "Note");
					dialog.set_secondary_text("This room is reserved");
					dialog.run();
				}

			}
		}
	}

}
