#include "ApprovalPage.h"

ApprovalPage::ApprovalPage()
{
	append_column("Name",m_Columns.m_col_user_name);
	Pop_menu();
}

ApprovalPage::~ApprovalPage()
{
}
void ApprovalPage::Pop_menu()
{

	auto item = Gtk::make_managed<Gtk::MenuItem>("_New", true);
	item->signal_activate().connect(sigc::mem_fun(*this,
	                                &ApprovalPage::on_menu_file_popup_new));
	m_Menu_Popup.append(*item);

	item = Gtk::make_managed<Gtk::MenuItem>("_Delete", true);
	item->signal_activate().connect(
	    sigc::mem_fun(*this,&ApprovalPage::on_menu_file_popup_delete));
	m_Menu_Popup.append(*item);

	item = Gtk::make_managed<Gtk::MenuItem>("_Approve", true);
	item->signal_activate().connect(
	    sigc::mem_fun(*this,&ApprovalPage::on_menu_file_popup_approve));
	m_Menu_Popup.append(*item);

	item = Gtk::make_managed<Gtk::MenuItem>("_Reject", true);
	item->signal_activate().connect(
	    sigc::mem_fun(*this,&ApprovalPage::on_menu_file_popup_reject));
	m_Menu_Popup.append(*item);

	m_Menu_Popup.accelerate(*this);
	m_Menu_Popup.show_all(); //Show all menu items when the menu pops up

	m_assistant_new.signal_apply().connect(
	    sigc::mem_fun(*this,
	                  &ApprovalPage::Update));// overwrite the update signal in Datapage
}

void ApprovalPage::on_menu_file_popup_approve()
{

	auto refSelection = get_selection();

	if(refSelection)
	{
		Gtk::TreeModel::iterator iter = refSelection->get_selected();

		if(iter)
		{
			int id = (*iter)[m_Columns.m_col_apm_id];
			//std::cout << "  Delete ID=" << id << std::endl;
			MyAppointment.change_approve(id,1);
			this->Update();
		}

	}
}
void ApprovalPage::on_menu_file_popup_reject()
{
	auto refSelection = get_selection();

	if(refSelection)
	{
		Gtk::TreeModel::iterator iter = refSelection->get_selected();

		if(iter)
		{
			int id = (*iter)[m_Columns.m_col_apm_id];
			//std::cout << "  Delete ID=" << id << std::endl;
			MyAppointment.change_approve(id,-1);
			this->Update();
		}

	}

}

void ApprovalPage::Update()
{
	std::vector<appointment_data> data;
	Appointment apm_data;

	data = apm_data.Update();
	//std::cout<<"UserID in DataPage"<<LoginUser.GetUserId()<<std::endl;


	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	set_model(m_refTreeModel);
	//Fill the TreeView's model
	Gtk::TreeModel::Row row;

	for(int i = 0; i < data.size(); i++)
	{
		rooms_data room_data = room_list.GetRoom(data[i].apm_room_id);

		std::string Bdate=data[i].apm_begin_date, Btime=data[i].apm_begin_time;
		User ApplyUser;
		ApplyUser.SetUserId(data[i].apm_user_id);
		ApplyUser.Update();


		row = *(m_refTreeModel->append());
		row[m_Columns.m_col_apm_id] = data[i].apm_id;
		row[m_Columns.m_col_room_name] = room_data.room_name;
		row[m_Columns.m_col_begin_date] = Bdate;
		row[m_Columns.m_col_begin_time] = Btime;
		row[m_Columns.m_col_reason] = data[i].apm_reason;
		row[m_Columns.m_col_user_name] = ApplyUser.GetUserName();

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

void ApprovalPage::on_menu_file_popup_new()
{
	m_assistant_new.show();
	Update();
}

void ApprovalPage::on_menu_file_popup_delete()
{
	auto refSelection = get_selection();

	if(refSelection)
	{
		Gtk::TreeModel::iterator iter = refSelection->get_selected();

		if(iter)
		{
			int id = (*iter)[m_Columns.m_col_apm_id];
			//std::cout << "  Delete ID=" << id << std::endl;
			MyAppointment.del(id);
			Update();
		}

	}

}
