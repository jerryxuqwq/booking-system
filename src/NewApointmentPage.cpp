#include "NewApointmentPage.h"
#include <iostream>
#include <string>

NewApointmentPage::NewApointmentPage():
	m_box(Gtk::ORIENTATION_HORIZONTAL, 12),
	m_box1(Gtk::ORIENTATION_HORIZONTAL, 12),
	m_label1("Type text to allow the assistant to continue:"),
	m_label2("Confirmation page"),
	m_label3("Type text to allow the assistant to continue:"),
	m_check("Optional extra information")
{
	set_title("Gtk::Assistant example");
	set_border_width(12);
	set_default_size(400, 300);
//rooms
	m_scrolledWindow.add(m_TreeView_Rooms);
	m_scrolledWindow.set_size_request(300,100);
	m_scrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	m_TreeView_Rooms.append_column("ID", m_Columns_Rooms.m_col_room_id);
	m_TreeView_Rooms.append_column("Name", m_Columns_Rooms.m_col_room_name);
	m_TreeView_Rooms.append_column("Dsp", m_Columns_Rooms.m_col_room_dsp);
	m_TreeView_Rooms.append_column("Status", m_Columns_Rooms.m_col_room_status);

	m_refTreeModel_Rooms = Gtk::ListStore::create(m_Columns_Rooms);
	m_TreeView_Rooms.set_model(m_refTreeModel_Rooms);

	refSelection = m_TreeView_Rooms.get_selection();
	PullRoomData();
//rooms end

//APMs
	m_scrolledWindow_APM.add(m_TreeView_APM);
	m_scrolledWindow_APM.set_size_request(300,100);
	m_scrolledWindow_APM.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
//APMs end
	m_box.pack_start(m_calendar);
	m_box.pack_start(m_scrolledWindow);
	
	append_page(m_box);
	set_page_title(*get_nth_page(0), "Select Date & Room");
	set_page_complete(m_box, false);

	m_box1.pack_start(m_label3);
	m_box1.pack_start(m_scrolledWindow_APM);
	append_page(m_box1);
	set_page_title(*get_nth_page(1), "Select Time");

	append_page(m_label2);
	set_page_title(*get_nth_page(2), "Confirmation");



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

	show_all_children();
}

NewApointmentPage::~NewApointmentPage()
{
}

void NewApointmentPage::on_assistant_apply()
{
	std::cout << "Apply was clicked" << std::endl;
}

void NewApointmentPage::on_assistant_cancel()
{
	std::cout << "Cancel was clicked" << std::endl;

	hide();
}

void NewApointmentPage::on_assistant_close()
{
	std::cout << "Assistant was closed" << std::endl;
	hide();
}

void NewApointmentPage::on_assistant_prepare(Gtk::Widget* /* widget */)
{
	set_title(Glib::ustring::compose("Gtk::Assistant example (Page %1 of %2)",
	                                 get_current_page() + 1, get_n_pages()));



}

void NewApointmentPage::PullRoomData()
{
	std::vector<rooms_data> data = room_list.GetRoomlist();

	//Fill the TreeView's model
	for(int i=0; i< data.size(); i++)
	{
		Gtk::TreeModel::Row row = *(m_refTreeModel_Rooms->append());
		row[m_Columns_Rooms.m_col_room_id] = data[i].room_id;
		row[m_Columns_Rooms.m_col_room_name] = data[i].room_name;
		row[m_Columns_Rooms.m_col_room_dsp] = data[i].room_dsp;
		row[m_Columns_Rooms.m_col_room_status] = data[i].room_status;
	}
}

void NewApointmentPage::on_entry_changed()
{

	Glib::Date date;
	std::tm c_date;

	m_calendar.get_date(date);
	date.to_struct_tm(c_date);

	//std::cout<<<<std::endl;
	if(refSelection)
	{
		Gtk::TreeModel::iterator iter = refSelection->get_selected();

		if(iter)
		{
			int id = (*iter)[m_Columns_Rooms.m_col_room_id];
			m_label2.set_text("You will book "+
			                  (*iter)[m_Columns_Rooms.m_col_room_name]+" at (DD/MM/YYYY) "
			                  +std::to_string(date.get_day())+ "/"
			                  +std::to_string(date.get_month())+ "/"
			                  +std::to_string(date.get_year())
			                 );
		}

		set_page_complete(m_box, true);
		set_page_complete(m_label2, true);
	}
}
