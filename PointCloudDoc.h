// CPointCloudDoc.h : interface of the CPointCloudDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPOINTCLOUDDOC_H__752C78B7_D7D3_4AB7_ABC8_38E22B0B0872__INCLUDED_)
#define AFX_CPOINTCLOUDDOC_H__752C78B7_D7D3_4AB7_ABC8_38E22B0B0872__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point3D.h"
class CPointCloudDoc : public CDocument
{
protected: // create from serialization only
	CPointCloudDoc();
	DECLARE_DYNCREATE(CPointCloudDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointCloudDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	vector<Point3D> m_ptVertexList;
	double	m_dbDistance;
	Point3D m_ptBoxCenter;
	Point3D m_ptBoxSize;
	Point3D m_ptMax;
	Point3D m_ptMin;
	virtual ~CPointCloudDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPointCloudDoc)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPOINTCLOUDDOC_H__752C78B7_D7D3_4AB7_ABC8_38E22B0B0872__INCLUDED_)
