
// MfcProblemDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MfcProblem.h"
#include "MfcProblemDlg.h"
#include "afxdialogex.h"
#include<iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

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
END_MESSAGE_MAP()


// CMfcProblemDlg 대화 상자



CMfcProblemDlg::CMfcProblemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROBLEM_DIALOG, pParent)
	, InputSize(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcProblemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, InputSize);
}

BEGIN_MESSAGE_MAP(CMfcProblemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_PRESS, &CMfcProblemDlg::OnBnClickedBtnPress)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_CROSS_OUTLINE, &CMfcProblemDlg::OnBnClickedBtnCrossOutline)
END_MESSAGE_MAP()


// CMfcProblemDlg 메시지 처리기

BOOL CMfcProblemDlg::OnInitDialog()
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


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMfcProblemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMfcProblemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMfcProblemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMfcProblemDlg::OnBnClickedBtnPress()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	OnDestroy();

	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0, nWidth * nHeight);


	UpdateDisplay();

	UpdateData(TRUE);

	InputSize;

	UpdateData(false);

	static int nSttX = 0;
	static int nSttY = 0;
	int nGray = 80;
	/*int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();*/
	int nRadius = InputSize;
	//unsigned char* fm = (unsigned char*)m_image.GetBits();

	//memset(fm, 0xff, nWidth*nHeight);


	int WidthR = rand() % nWidth;
	int HeightR = rand() % nHeight;

	if (nWidth-50 < WidthR + InputSize) {
		WidthR = WidthR - (InputSize * 2.5);
	}
	if (0 > WidthR - InputSize) {
		WidthR = WidthR + (InputSize * 2.5);
	}

	if (nHeight-50 < HeightR + InputSize) {
		HeightR = HeightR - (InputSize * 2.5);
	}
	if (0 > HeightR - InputSize) {
		HeightR = HeightR + (InputSize * 2.5);
	}

	MakeCircle(fm, nSttX + WidthR , nSttY + HeightR, nRadius, nGray);
	
}



void CMfcProblemDlg::MakeCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++)
		{
			if (isInCircle(i, j, nCenterX, nCenterY, nRadius)) {
				if (nHeight > j && nWidth > i && i > 0 && j>0) {
					fm[j * nPitch + i] = nGray;
				}
			}


		}
	}

	UpdateDisplay();
}
bool CMfcProblemDlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}

	return bRet;
}

void CMfcProblemDlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

void CMfcProblemDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	
	if (m_image != NULL) {
		m_image.Destroy();
	}

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CMfcProblemDlg::OnBnClickedBtnCrossOutline()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nGray = 80;

	int nTh = nGray - 1;
	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;
	CRect rect(0, 0, nWidth, nHeight);

	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j * nPitch + i] > nTh) {
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
	}
	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	std::cout << dCenterX << "\t" << dCenterY << std::endl;

	int CrossLine = 5;

	MakeCross_line(dCenterX,dCenterY, CrossLine);
	MakeOutline(dCenterX, dCenterY);

	UpdateDisplay();
}

void CMfcProblemDlg::MakeCross_line(double dCenterX, double dCenterY, int size)
{
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();

	int CenterX = dCenterX;
	int CenterY = dCenterY;
	int i = CenterX - size;
	int j = CenterY - size;
	int k = CenterX + size;
	int l = CenterY + size;

	for (i; i < CenterX; i++) {
		if (CenterY < nHeight && CenterX < nWidth) {
			fm[CenterY * nPitch + i] = RGB(0xff, 0, 0);
		}
	}

	for (j; j < CenterY; j++){
		if (CenterY < nHeight && CenterX < nWidth) {
			fm[j * nPitch + CenterX] = RGB(0xff, 0, 0);
		}
	}

	for (k; k > CenterX; k--) {
		if (CenterY < nHeight && CenterX < nWidth) {
			fm[CenterY * nPitch + k] = RGB(0xff, 0, 0);
		}
	}

	for (l; l > CenterY; l--) {
		if (CenterY < nHeight && CenterX < nWidth) {
			fm[l * nPitch + CenterX] = RGB(0xff, 0, 0);
		}
	}

}
void CMfcProblemDlg::MakeOutline(double dCenterX, double dCenterY)
{
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int rgb = RGB(0xff, 0xff,0);

	double pi = 3.1415926535897932384626433832795; // PI
	double radius = InputSize; // 반지름
	int vertex = 365; // 꼭지점

	// 중심점위치
	double cen_x = dCenterY;
	double cen_y = dCenterX;

	double x = radius * cos(0.0) + cen_x;
	double y = radius * sin(0.0) + cen_y;


	for (int i = 0; i <= vertex; i++)
	{
		double radian = i * 2 * pi / vertex;
		int x = radius * cos(radian) + cen_x;
		int y = radius * sin(radian) + cen_y;
		if(nWidth > y && nHeight > x){
			fm[x * nPitch + y] = rgb;
			}

	}


}
