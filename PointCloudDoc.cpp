// CPointCloudDoc.cpp : implementation of the CPointCloudDoc class
//

#include "stdafx.h"
#include "PointCloud.h"

#include "PointCloudDoc.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPointCloudDoc

IMPLEMENT_DYNCREATE(CPointCloudDoc, CDocument)

BEGIN_MESSAGE_MAP(CPointCloudDoc, CDocument)
	//{{AFX_MSG_MAP(CPointCloudDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPointCloudDoc construction/destruction

CPointCloudDoc::CPointCloudDoc()
{
	// TODO: add one-time construction code here

	m_ptMax.x = -10000000.0;
	m_ptMax.y = -10000000.0;
	m_ptMax.z = -10000000.0;
	m_ptMin.x = 10000000.0;
	m_ptMin.y = 10000000.0;
	m_ptMin.z = 10000000.0;

}

CPointCloudDoc::~CPointCloudDoc()
{
}

BOOL CPointCloudDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPointCloudDoc serialization

void CPointCloudDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPointCloudDoc diagnostics

#ifdef _DEBUG
void CPointCloudDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPointCloudDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPointCloudDoc commands

void CPointCloudDoc::OnFileOpen() 
{

	CString m_strPathname;
	CString m_strFilename;
	CString m_strFileTitle;
	CString m_strFileext;//文件的扩展名

	LPTSTR lpszFilter = "点云文件(*.txt , *TXT)|*.txt|All Files(*.*)|*.*||";
	CFileDialog p_dlg(true,".txt",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,lpszFilter,NULL);
	if (p_dlg.DoModal() == IDOK)
	{
		m_strPathname = p_dlg.GetPathName();
		m_strFilename = p_dlg.GetFileName();
		m_strFileTitle = p_dlg.GetFileTitle();
		m_strFileext = p_dlg.GetFileExt();//文件扩展名对话框
		
	}
	else 
		return ;
	

	m_strFileext.MakeLower();
	if (m_strFileext!="txt")
	{
		return ;
	}




	FILE *p_txt= fopen(m_strPathname,"r");
	if (p_txt == NULL)
	{
	   fclose(p_txt);
	   return ;
	}

//////////////////////////////////////////////////////////////////////////
	m_ptVertexList.clear();


	m_ptMax.x = -10000000.0;
	m_ptMax.y = -10000000.0;
	m_ptMax.z = -10000000.0;
	m_ptMin.x = 10000000.0;
	m_ptMin.y = 10000000.0;
	m_ptMin.z = 10000000.0;

//////////////////////////////////////////////////////////////////////////
   	Point3D ptXYZ;
	while (fscanf(p_txt,"%f %f %f",&ptXYZ.x,&ptXYZ.y,&ptXYZ.z) != EOF)
	{
		
		m_ptMax.x=max(m_ptMax.x,ptXYZ.x);
		m_ptMax.y=max(m_ptMax.y,ptXYZ.y);
		m_ptMax.z=max(m_ptMax.z,ptXYZ.z);
		m_ptMin.x=min(m_ptMin.x,ptXYZ.x);
		m_ptMin.y=min(m_ptMin.y,ptXYZ.y);
		m_ptMin.z=min(m_ptMin.z,ptXYZ.z);
		m_ptVertexList.push_back(ptXYZ);
		  	   
	}
	fclose(p_txt);


	m_ptBoxCenter = (m_ptMax+m_ptMin) / 2;
	m_ptBoxSize = (m_ptMax-m_ptMin)/2;
	m_dbDistance=sqrt(m_ptBoxSize.x*m_ptBoxSize.x+
		m_ptBoxSize.y*m_ptBoxSize.y+
		m_ptBoxSize.z*m_ptBoxSize.z);
	
	UpdateAllViews(NULL,0,0);
	
}
