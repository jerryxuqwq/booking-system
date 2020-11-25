#include "NewApointmentPage.h"
#include <iostream>

NewApointmentPage::NewApointmentPage():
	m_box(Gtk::ORIENTATION_HORIZONTAL, 12),
	m_label1("Type text to allow the assistant to continue:"),
	m_label2("Confirmation page"),
	m_check("Optional extra information")
{
	set_title("Gtk::Assistant example");
	set_border_width(12);
	set_default_size(400, 300);

	m_scrolledWindow.add(m_TreeView);

	m_box.pack_start(m_calendar);
	m_box.pack_start(m_scrolledWindow);
	m_scrolledWindow.set_size_request(300,100);
	m_scrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_TreeView.append_column("ID", m_Columns.m_col_room_id);
	m_TreeView.append_column("Name", m_Columns.m_col_room_name);
	m_TreeView.append_column("Dsp", m_Columns.m_col_room_dsp);
	m_TreeView.append_column("Status", m_Columns.m_col_room_status);

	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	m_TreeView.set_model(m_refTreeModel);

	PullRoomData();

	//append_page(m_box);
	append_page(m_box);
	set_page_title(*get_nth_page(0), "Select Date & Room");

	append_page(m_label1);
	set_page_title(*get_nth_page(1), "Select Time");

	append_page(m_label2);
	set_page_title(*get_nth_page(2), "Confirmation");
	//set_page_title(*get_nth_page(0), "Page 1");


	set_page_complete(m_box, true);
	//set_page_complete(m_label1, true);

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
		Gtk::TreeModel::Row row = *(m_refTreeModel->append());
		row[m_Columns.m_col_room_id] = data[i].room_id;
		row[m_Columns.m_col_room_name] = data[i].room_name;
		row[m_Columns.m_col_room_dsp] = data[i].room_dsp;
		row[m_Columns.m_col_room_status] = data[i].room_status;
	}
}
