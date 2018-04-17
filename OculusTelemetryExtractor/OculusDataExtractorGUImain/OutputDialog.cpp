#include "stdafx.h"
#include "OutputDialog.h"

// This method is responsible for inputting telemetry data into the live table
// mainDlg - the main dialog of the application
// addTxt - the telemetry data for input to live table
// dataType - determines the type of telemetry data that is being dealt with
// rowItem - the current row within the live table
void addToColumn(CWnd* mainDlg, const std::string addTxt,const CString dataType,LVITEMW rowItem) {
	//Get live table and then get the base columns
	CListCtrl* list = (CListCtrl*)mainDlg->GetDlgItem(IDC_TDLIST);
	CHeaderCtrl* pHeader = (CHeaderCtrl*)list->GetHeaderCtrl();
	int length = pHeader->GetItemCount();
	const INT SIZE = 0x100;
	TCHAR hdInfo[255];
	LVCOLUMNW listItem;
	ZeroMemory(&hdInfo, sizeof(hdInfo));
	ZeroMemory(&listItem, sizeof(listItem));
	listItem.cchTextMax = SIZE;
	listItem.mask = LVCF_TEXT;
	listItem.pszText = hdInfo;
	for (int i = 1; i <length; i++) {
		list->GetColumn(i, &listItem);
		//If the datatype is the same as the header then continue to add to the live table
		if (dataType == CString(listItem.pszText)) {
			rowItem.iSubItem = i;
			ZeroMemory(&hdInfo, sizeof(hdInfo));
			mbstowcs(hdInfo, addTxt.c_str(), addTxt.length() + 1);
			rowItem.pszText = hdInfo;
			list->SetItem(&rowItem);
			i += length;
		}
	}
}
// This method is responsible for inputting content into a content window
// mainDlg - the main dialog of the application
// addTxt - the desired text to add
// txtId - the content window that there is a desire to change
// exNewLine - how many extra newlines are required
// statPos - the width of the desired text
void addToOutput(CWnd* mainDlg, const std::string addTxt,const int txtId,int exNewLine,const int statPos) {
	// Get the content window 
	std::string str_;
	CWnd* dlg_ = mainDlg->GetDlgItem(txtId);
	CString tempOutput;
	int oldPos = 0, counter = 0;
	dlg_->GetWindowTextW(tempOutput);
	// Place the desired new lines prior to the input of the message
	for (; exNewLine != -1; exNewLine--)
		tempOutput += "\r\n";
	// Determines how the text should be devised based on the desired width
	float mod = (float)addTxt.length() / (float)60;
	if (mod >= 1) {
		for (int i = (int)mod; i != 0 && mod >= 0; i--) {
			if (mod <= 1) {
				tempOutput += "\r\n";
				str_ = addTxt.substr(oldPos, statPos);
				tempOutput += str_.c_str();
			}
			else {
				if ((statPos + oldPos + counter) < addTxt.length()) {
					str_ = addTxt.at(statPos + oldPos + counter);
					if (str_ == " ") {
						if (i == 1)
							i += 1;
						if (oldPos != 0)
							tempOutput += "\r\n";
						str_ = addTxt.substr(oldPos, (statPos + counter));
						tempOutput += str_.c_str();
						oldPos = oldPos + statPos + counter + 1;
						mod -= 1;
						counter = 0;
					}
					else {
						i += 1;
						counter += 1;
					}
				}
				else {
					str_ = addTxt.substr(oldPos, addTxt.length());
					tempOutput += str_.c_str();
				}
			}
		}
	}
	else {
		str_ = addTxt.substr(oldPos, statPos);
		tempOutput += str_.c_str();
	}
	// Set the content window with the tempOutput content
	dlg_->SetWindowTextW(tempOutput);
	CEdit* tempEdit = (CEdit*)dlg_;
	// Scroll to the bottom of the live table
	tempEdit->LineScroll(tempEdit->GetLineCount());
}