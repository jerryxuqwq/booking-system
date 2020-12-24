#ifndef APPROVALPAGE_H
#define APPROVALPAGE_H
#include "DataPage.h"

class ApprovalPage : public DataPage
{
public:
	ApprovalPage();
	~ApprovalPage();
	
protected:

	void on_menu_file_popup_approve();
	void on_menu_file_popup_reject();
	
private:
	void Pop_menu();


};

#endif // APPROVALPAGE_H
