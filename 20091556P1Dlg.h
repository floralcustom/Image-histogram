
// 20091556P1Dlg.h : 헤더 파일
//

#pragma once


// CMy20091556P1Dlg 대화 상자
class CMy20091556P1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy20091556P1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MY20091556P1_DIALOG };

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
	CString m_strPathName;
	int m_Hist[256]; // 이미지의 명암도 빈도수를 저장하는 변수 
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedEqual();
	Color** H; // 변환전 이미지에 대한 이차원 배열
	Color** E; // 변환후 이미지에 대한 이차원 배열
	void Hist(Color a);
	double SaveY(Color a); // 추출한 Y값 저장 함수
	double SaveCb(Color a); // 추출한 Cb값 저장 함수
	double SaveCr(Color a); // 추출한 Cr값 저장 함수
	int **nY;
	int **nCb;
	int **nCr;
	Color SetRGB(int Y, int Cb, int Cr);
	int **EqualY;
	void EqualHist(int EqualY);
};
