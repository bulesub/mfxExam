﻿
// GProjectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "GProject.h"
#include "GProjectDlg.h"
#include "afxdialogex.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
using namespace std;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CGProjectDlg 대화 상자



CGProjectDlg::CGProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GPROJECT_DIALOG, pParent)
	, m_nSize(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SIZE, m_nSize);
}

BEGIN_MESSAGE_MAP(CGProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
//	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_TEST, &CGProjectDlg::OnBnClickedBtnTest)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_PROCESS, &CGProjectDlg::OnBnClickedBtnProcess)
	ON_BN_CLICKED(IDC_BTN_MAKE_PATTERN, &CGProjectDlg::OnBnClickedBtnMakePattern)
	ON_BN_CLICKED(IDC_BTN_GET_DATA, &CGProjectDlg::OnBnClickedBtnGetData)
	ON_EN_CHANGE(IDC_EDIT_SIZE, &CGProjectDlg::OnEnChangeEditSize)
	ON_BN_CLICKED(IDC_BTN_THREAD, &CGProjectDlg::OnBnClickedBtnThread)
//	ON_WM_MOUSEMOVE()
//ON_WM_MOUSEACTIVATE()
END_MESSAGE_MAP()


// CGProjectDlg 메시지 처리기

BOOL CGProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 1280, 800);
	m_pDlgImage = new CDlgImage;
	// Create시에 this 넣는 이유
	// -> 자식 Dialog에서 부모 Dialog를 참조할 수 있게(모달리스가 가능하도록)
	m_pDlgImage->Create(IDD_CDlgImage, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0, 0, 640, 480);
	m_pDlgImageResult = new CDlgImage;
	m_pDlgImageResult->Create(IDD_CDlgImage, this);
	m_pDlgImageResult->ShowWindow(SW_SHOW);
	m_pDlgImageResult->MoveWindow(640, 0, 640, 480);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGProjectDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_pDlgImage)		delete m_pDlgImage;
	if (m_pDlgImageResult)	delete m_pDlgImageResult;
}

void CGProjectDlg::CallFunc(int n)
{
	//int nData = n;
	std::cout << n << std::endl;
}

void CGProjectDlg::OnBnClickedBtnTest()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	memset(fm, 0, nWidth * nHeight);

	for (int k = 0; k < MAX_POINT; k++)
	{
		int x = rand() % nWidth;
		int y = rand() % nHeight;
		fm[y * nPitch + x] = rand() % 0xff;
	}

	//memset(fm, 0, 320 * 240);

	int nIndex = 0;
	// Threshold : 한계점
	int nTh = 100;
	for (int j = 0; j < nHeight; j++)
	{
		for (int i = 0; i < nWidth; i++)
		{
			if (fm[j * nPitch + i] > nTh)
			{
				if (m_pDlgImageResult->m_nDataCount < MAX_POINT)
				{
					//cout << nIndex << ":" << i << ", " << j << endl;
					m_pDlgImageResult->m_pointData[nIndex].x = i;
					m_pDlgImageResult->m_pointData[nIndex].y = j;
					m_pDlgImageResult->m_nDataCount = ++nIndex;
				}
			}
		}
	}

	m_pDlgImage->Invalidate();
	m_pDlgImageResult->Invalidate();
}

#include "CProcess.h"
#include <chrono>
void CGProjectDlg::OnBnClickedBtnProcess()
{
	CProcess process;

	auto start = chrono::system_clock::now();
	int nReturn = process.GetStarInfo(&m_pDlgImage->m_image, 100);
	auto end = chrono::system_clock::now();
	auto millisec = chrono::duration_cast<chrono::milliseconds>(end - start);

	cout << nReturn << "\t" << millisec.count() << "ms" << endl;
}

void CGProjectDlg::OnBnClickedBtnMakePattern()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	memset(fm, 0, nWidth * nHeight);

	CRect rect(100, 100, 200, 200);
	for (int j = rect.top; j < rect.bottom; j++)
	{
		for (int i = rect.left; i < rect.right; i++)
		{
			fm[j * nPitch + i] = rand() % 0xff;
		}
	}
	m_pDlgImage->Invalidate();
}

void CGProjectDlg::OnBnClickedBtnGetData()
{
	const CImage& image = m_pDlgImage->m_image;
	unsigned char* fm = (unsigned char*)image.GetBits();
	int nWidth = image.GetWidth();
	int nHeight = image.GetHeight();
	int nPitch = image.GetPitch();

	int nTh = 0x80;
	CRect rect(0, 0, nWidth, nHeight);
	int nSumX = 0, nSumY = 0, nCount = 0;
	for (int j = rect.top; j < rect.bottom; j++)
	{
		for (int i = rect.left; i < rect.right; i++)
		{
			if (fm[j * nPitch + i] > nTh)
			{
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
	}

	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	cout << dCenterX << "\t" << dCenterY << endl;
}

void CGProjectDlg::OnEnChangeEditSize()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

#include <thread>
#include <vector>
void ThreadProcess(CWnd* pParent, CRect rect, int* nRect)
{
	CGProjectDlg* pWnd = (CGProjectDlg*)pParent;
	*nRect = pWnd->ProcessImage(rect);
}

void CGProjectDlg::OnBnClickedBtnThread()
{
	auto start = chrono::system_clock::now();

	int nImageSize = 4096 * 4;
	CRect rect(0, 0, nImageSize, nImageSize);
	CRect rt[4];
	int nRect[4];
	for (int k = 0; k < 4; k++)
	{
		rt[k] = rect;
		rt[k].OffsetRect(nImageSize * (k % 2), nImageSize * int(k / 2));
	}
	
	vector<thread> _threads;
	for (int i = 0; i < 4; i++)
		_threads.push_back(thread(ThreadProcess, this, rt[i], &nRect[i]));

	for (thread& thr : _threads) thr.join();

	//thread _thread0(ThreadProcess, this, rt[0], &nRect[0]);
	//thread _thread1(ThreadProcess, this, rt[1], &nRect[1]);
	//thread _thread2(ThreadProcess, this, rt[2], &nRect[2]);
	//thread _thread3(ThreadProcess, this, rt[3], &nRect[3]);

	//_thread0.join();
	//_thread1.join();
	//_thread2.join();
	//_thread3.join();

	int nSum = 0;
	for (int i = 0; i < 4; i++)
		nSum += nRect[i];

	auto end = chrono::system_clock::now();
	auto millisec = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "main : " << nSum << "\t" << millisec.count() * 0.001 << "sec" << endl;
}

int CGProjectDlg::ProcessImage(CRect rect)
{
	auto start = chrono::system_clock::now();

	CProcess process;

	int nRect = process.GetStarInfo(&m_pDlgImage->m_image, 0, rect);

	auto end = chrono::system_clock::now();
	auto millisec = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "thread : " << nRect << "\t" << millisec.count() * 0.001 << "sec" << endl;

	return nRect;
}
