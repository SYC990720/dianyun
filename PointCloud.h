// CPointCloud.h : main header file for the CPOINTCLOUD application
//

#if !defined(AFX_CPOINTCLOUD_H__733FE858_DAF6_46C4_877E_57EFF9635C93__INCLUDED_)
#define AFX_CPOINTCLOUD_H__733FE858_DAF6_46C4_877E_57EFF9635C93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPointCloudApp:
// See CPointCloud.cpp for the implementation of this class
//

class CPointCloudApp : public CWinApp
{
public:
	CPointCloudApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointCloudApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPointCloudApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPOINTCLOUD_H__733FE858_DAF6_46C4_877E_57EFF9635C93__INCLUDED_)
