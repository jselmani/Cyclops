#ifndef _OUTPUTDIALOG_H_
#define _OUTPUTDIALOG_H_

#include "stdafx.h"
//Add message to a control box
void addToOutput(CWnd*, const std::string,const int, int = 0,const int = 60);
//Add item to a specific column of a specific row number
void addToColumn(CWnd*, const std::string,const CString, LVITEMW);

#endif