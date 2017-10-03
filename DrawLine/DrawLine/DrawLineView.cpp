
// DrawLineView.cpp : CDrawLineView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DrawLine.h"
#endif

#include "DrawLineDoc.h"
#include "DrawLineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawLineView

IMPLEMENT_DYNCREATE(CDrawLineView, CView)

BEGIN_MESSAGE_MAP(CDrawLineView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawLineView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CDrawLineView 构造/析构

CDrawLineView::CDrawLineView()
{
	// TODO:  在此处添加构造代码

}

CDrawLineView::~CDrawLineView()
{
}

BOOL CDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawLineView 绘制

void CDrawLineView::OnDraw(CDC* /*pDC*/)
{
	CDrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CDrawLineView 打印


void CDrawLineView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CDrawLineView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawLineView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawLineView 诊断

#ifdef _DEBUG
void CDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawLineDoc* CDrawLineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawLineDoc)));
	return (CDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawLineView 消息处理程序


void CDrawLineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//MessageBox(L"View Clicked!");     //用于单击窗口客户区时的测试
	m_ptOrigin = point;

	CView::OnLButtonDown(nFlags, point);
}

void CDrawLineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*
	//获得窗口的设备描述表
	HDC hdc;
	hdc = ::GetDC(m_hWnd);
	//移动到线条的起点
	MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	//画线
	LineTo(hdc, point.x, point.y);
	//释放设备描述表
	::ReleaseDC(m_hWnd, hdc);
	*/
	//使用CDC类实现
	CDC *pDC = GetDC();
	pDC->MoveTo(m_ptOrigin);
	pDC->LineTo(point);
	ReleaseDC(pDC);


	CView::OnLButtonUp(nFlags, point);
}
