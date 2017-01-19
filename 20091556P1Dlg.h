
// 20091556P1Dlg.h : ��� ����
//

#pragma once


// CMy20091556P1Dlg ��ȭ ����
class CMy20091556P1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20091556P1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MY20091556P1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strPathName;
	int m_Hist[256]; // �̹����� ��ϵ� �󵵼��� �����ϴ� ���� 
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedEqual();
	Color** H; // ��ȯ�� �̹����� ���� ������ �迭
	Color** E; // ��ȯ�� �̹����� ���� ������ �迭
	void Hist(Color a);
	double SaveY(Color a); // ������ Y�� ���� �Լ�
	double SaveCb(Color a); // ������ Cb�� ���� �Լ�
	double SaveCr(Color a); // ������ Cr�� ���� �Լ�
	int **nY;
	int **nCb;
	int **nCr;
	Color SetRGB(int Y, int Cb, int Cr);
	int **EqualY;
	void EqualHist(int EqualY);
};
