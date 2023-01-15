
// MfcProblemDlg.h: 헤더 파일
//

#pragma once


// CMfcProblemDlg 대화 상자
class CMfcProblemDlg : public CDialogEx
{
// 생성입니다.
public:
	CMfcProblemDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CImage m_image;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROBLEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int InputSize;
	afx_msg void OnBnClickedBtnPress();
	void UpdateDisplay();
	void MakeCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	afx_msg void OnDestroy();
	bool isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	afx_msg void OnBnClickedBtnCrossOutline();
	void MakeCross_line(double dCenterX, double dCenterY, int size);
	void MakeOutline(double dCenterX, double dCenterY);
};
