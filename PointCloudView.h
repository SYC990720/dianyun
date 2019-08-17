// CPointCloudView.h : interface of the CPointCloudView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPOINTCLOUDVIEW_H__3E7295D2_35B8_42BB_9682_9A0E697BC6B3__INCLUDED_)
#define AFX_CPOINTCLOUDVIEW_H__3E7295D2_35B8_42BB_9682_9A0E697BC6B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPointCloudView : public CView
{
protected: // create from serialization only
	CPointCloudView();
	DECLARE_DYNCREATE(CPointCloudView)

// Attributes
public:
	CPointCloudDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointCloudView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void InitOpenGL();
	void ResetViewport();

	BOOL bInitOpenGL;
	float ModelViewMatrix[16];
	float ProMatrix[16];
	CPoint m_ptCenter;
	CPoint ptDown;		//记录鼠标按下时的点
	CPoint m_ptCur;
	int ProcessID;
	GLfloat glDownX,glDownY,glDownZ;		//按下时坐标
	GLfloat glTransX,glTransY,glTransZ;			//当前平移参数
	GLfloat glRotX,glRotY,glRotZ;
	GLfloat glScaleX,glScaleY,glScaleZ;		
	GLfloat glCurRotX,glCurRotY,glCurRotZ;
	GLfloat glCurTransX,glCurTransY,glCurTransZ;
	

	BOOL m_bScale;							//缩放
	BOOL m_bRotation;						//旋转
	BOOL m_bMoving;							//平移
	HGLRC m_hRC;
	BOOL m_bShowPointCloud;
	void InitRC();							//渲染描述表
	BOOL PiexlFormat();						//像素格式
	void mydraw();							//图形绘制
	CRect m_rectOld;						//保存窗口大小，对于窗口变换后的操作有用
	CClientDC *m_pDC;
	BOOL m_bToolbar;
	BOOL m_bStatusbar;
	virtual ~CPointCloudView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPointCloudView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CPointCloudView.cpp
inline CPointCloudDoc* CPointCloudView::GetDocument()
   { return (CPointCloudDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPOINTCLOUDVIEW_H__3E7295D2_35B8_42BB_9682_9A0E697BC6B3__INCLUDED_)
