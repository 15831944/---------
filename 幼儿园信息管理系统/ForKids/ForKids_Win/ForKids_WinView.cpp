
// ForKids_WinView.cpp : CForKids_WinView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ForKids_Win.h"
#endif

#include "ForKids_WinDoc.h"
#include "ForKids_WinView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CForKids_WinView

IMPLEMENT_DYNCREATE(CForKids_WinView, CView)

BEGIN_MESSAGE_MAP(CForKids_WinView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CForKids_WinView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CForKids_WinView ����/����

CForKids_WinView::CForKids_WinView()
{
	// TODO: �ڴ˴���ӹ������

}

CForKids_WinView::~CForKids_WinView()
{
}

BOOL CForKids_WinView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CForKids_WinView ����

void CForKids_WinView::OnDraw(CDC* /*pDC*/)
{
	CForKids_WinDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CForKids_WinView ��ӡ


void CForKids_WinView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CForKids_WinView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CForKids_WinView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CForKids_WinView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CForKids_WinView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CForKids_WinView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CForKids_WinView ���

#ifdef _DEBUG
void CForKids_WinView::AssertValid() const
{
	CView::AssertValid();
}

void CForKids_WinView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CForKids_WinDoc* CForKids_WinView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CForKids_WinDoc)));
	return (CForKids_WinDoc*)m_pDocument;
}
#endif //_DEBUG


// CForKids_WinView ��Ϣ�������
