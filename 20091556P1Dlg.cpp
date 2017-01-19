
// 20091556P1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "20091556P1.h"
#include "20091556P1Dlg.h"
#include "afxdialogex.h"
#define min(a,b)        ((a) < (b) ? (a) : (b)) // ���� �����ڸ� �̿��� �� ���� �˻� ����
#define max(a,b)        ((a) > (b) ? (a) : (b))

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy20091556P1Dlg ��ȭ ����




CMy20091556P1Dlg::CMy20091556P1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy20091556P1Dlg::IDD, pParent)
	, m_strPathName(_T(""))
	, H(NULL)
	, E(NULL)
	, nY(NULL)
	, nCb(NULL)
	, nCr(NULL)
	, EqualY(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20091556P1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy20091556P1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOAD, &CMy20091556P1Dlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_EQUAL, &CMy20091556P1Dlg::OnBnClickedEqual)
END_MESSAGE_MAP()


// CMy20091556P1Dlg �޽��� ó����

BOOL CMy20091556P1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMy20091556P1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMy20091556P1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMy20091556P1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy20091556P1Dlg::OnBnClickedLoad()
{
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	HDC hDC = dc.GetSafeHdc();
	Graphics G(hDC);
	
	for(int i = 0; i < 256; i++)  // ��ϵ� �󵵼� �ʱ�ȭ
		 m_Hist[i] = 0;    

	CFileDialog Load(TRUE,NULL,NULL,OFN_FILEMUSTEXIST); // �̹������� �ε���� Ȯ�� 
	if(IDOK == Load.DoModal())
	{
        CString strPathName = Load.GetPathName(); 
	}
	CFile file;
	file.Open(Load.GetPathName(), CFile::modeRead | CFile::typeBinary); // �̹������� �ε�
	m_strPathName = file.GetFilePath();   // ��ο����� �̹����� �־���
	file.Close();

	Bitmap dlg(m_strPathName);
	G.DrawImage(&dlg,35,55,300,190); // �̹��� ���


	H = (Color**)calloc(dlg.GetWidth(),sizeof(Color*)); // �ҷ��� �̹����� ���� ���� ������ �迭  // H ��ϵ��� �������ִ� ����
	for(int i = 0; i < dlg.GetWidth(); i++)
			H[i] = (Color*)calloc(sizeof(Color),dlg.GetHeight());
		

	for(int i = 0; i < dlg.GetWidth(); i++)
	{
		for(int j = 0; j < dlg.GetHeight(); j++)
		{
			dlg.GetPixel(i,j,&H[i][j]); // �ҷ��� �̹����� �ȼ� ���� H �迭�� �־���
			Hist(H[i][j]); // �׸� �ȼ��� ��ϵ��� ���� �󵵼� ��� �Լ�  // Ư�� ��ϵ��� �󵵼��� �����ϴ� �迭
		}
	}

	int m_topHist = 0; // ������׷� �׷����� Y�� ����ȭ : �׸��� ��ϵ��� ���� �ִ� �� �ȼ����� �������� �������ν� ���� ���� �׷����� ��ǥ�ϱ����� ����
	for(int i = 0; i < 256; i++) // �ȼ��� �ִ밪�� ���ϴ� �ݺ���
	{
		if(m_Hist[i] > m_topHist)
			m_topHist = m_Hist[i];
	}

	Bitmap graph(256,m_topHist);
	if(graph.GetLastStatus() != Ok)
		return;

	for(int i = 0; i < 256; i++) // ����
	{
		for(int j = 0; j < m_topHist; j++) // ����
			graph.SetPixel(i,j,Color(255,255,255)); // �׷��� ��� ������� �ʱ�ȭ
	}

	for(int x = 0; x < 256; x++)
	{
		for(int y = 0; y < m_Hist[x]; y++) // Y���� ��ϵ� �󵵼��� ��´�.
			graph.SetPixel(x,m_topHist-y,Color(0,0,0)); // �׸��� �󵵼��� ���� �׷��� ��� �ݺ���(MFC�� ��ǥ�� �������� 0,0 �̱⶧���� �ִ밪���� �󵵼��� ����� �ùٸ� ������� ����)
	}
	G.DrawImage(&graph,35,285,300,190); // �׷��� ���
}


void CMy20091556P1Dlg::OnBnClickedEqual()
{
	// TODO: Add your control notification handler code here
	int sum=0, total_pixels=0, k=0;
	int sum_of_hist[256];     // ����������׷� ����
	
	CClientDC dc(this);
	HDC hDC = dc.GetSafeHdc();
	Graphics G(hDC);
	
	Bitmap dlg(m_strPathName);
	
	E = (Color**)calloc(dlg.GetWidth(),sizeof(Color*)); // �ҷ��� �̹����� ���� ���� ������ �迭
	for(int i = 0; i< dlg.GetWidth(); i++)
		E[i] = (Color*)calloc(sizeof(Color),dlg.GetHeight());

	nY = (int**)calloc( dlg.GetWidth(),sizeof(int*)); // �Է� ���� Y�� ���� ���� ������ �迭
	for(int i = 0; i< dlg.GetWidth(); i++)
		nY[i] = (int*)calloc(sizeof(int),dlg.GetHeight());

	nCb = (int**)calloc( dlg.GetWidth(),sizeof(int*)); // �Է� ���� Cb�� ���� ���� ������ �迭
	for(int i = 0; i< dlg.GetWidth(); i++)
		nCb[i] = (int*)calloc(sizeof(int),dlg.GetHeight());

	nCr = (int**)calloc(dlg.GetWidth(),sizeof(int*)); // �Է� ���� Cr�� ���� ���� ������ �迭
	for(int i = 0; i< dlg.GetWidth(); i++)
		nCr[i] = (int*)calloc(sizeof(int),dlg.GetHeight());

	EqualY = (int**)calloc(dlg.GetWidth(),sizeof(int*)); // ����ȭ ��Ų ���� ���� ���� ������ �迭
	for(int i = 0; i< dlg.GetWidth(); i++)
		EqualY[i] = (int*)calloc(sizeof(int),dlg.GetHeight());

	for(int i=0; i<256; i++) // ��ϵ� ��ô ������׷�!
	{
		sum=sum+m_Hist[i];  // �����󵵼�
		sum_of_hist[i]=sum;
	}

	total_pixels=dlg.GetWidth()*dlg.GetHeight();
	Bitmap m_ResultImg(dlg.GetWidth(), dlg.GetHeight());
	for(int i = 0; i < dlg.GetWidth(); i++) // ����
	{
		for(int j = 0; j < dlg.GetHeight(); j++)
		{
			dlg.GetPixel(i,j,&E[i][j]); // �ҷ��� �̹����� �ȼ� ���� E �迭�� �־���
			nY[i][j]=SaveY(E[i][j]);
			nCb[i][j]=SaveCb(E[i][j]);
			nCr[i][j]=SaveCr(E[i][j]);

			EqualY[i][j] = sum_of_hist[nY[i][j]]*(255.0/total_pixels); // ���� ������׷��� ����ȭ    ����������׷�* �����ִ밪/���ȼ��ǰ���
			m_ResultImg.SetPixel(i,j,SetRGB(EqualY[i][j],nCb[i][j],nCr[i][j]));
		}
	}

	G.DrawImage(&m_ResultImg,545,55,300,190); // ��Ȱȭ�� �̹��� ���
	

	for(int i = 0; i < 256; i++) // ��ϵ� �󵵼� �ʱ�ȭ
		 m_Hist[i] = 0;

	for(int i = 0; i < dlg.GetWidth(); i++) // ����ȭ�� ��ϵ��� �󵵼��� ����ϱ����� �ݺ���
	{
		for(int j = 0; j < dlg.GetHeight(); j++)
		{
			EqualHist(EqualY[i][j]); // �׸� �ȼ��� ��ϵ��� ���� �󵵼� ��� �Լ�
		}
	}

	int m_EqualtopHist = 0; // ������׷� �׷����� Y�� ����ȭ : �׸��� ��ϵ��� ���� �ִ� �� �ȼ����� �������� �����Ƿν� ���� ���� �׷����� ��ǥ�ϱ����� ����
	
	for(int i = 0; i < 256; i++) // �ȼ��� �ִ밪�� ���ϴ� �ݺ���
	{
		if(m_Hist[i] > m_EqualtopHist)
			m_EqualtopHist = m_Hist[i];
	}
	Bitmap Equalgraph(256,m_EqualtopHist);
	if(Equalgraph.GetLastStatus() != Ok)
		return;
	
	
	for(int i = 0; i < 256; i++) // ����		
	{
		for(int j = 0; j < m_EqualtopHist; j++) // ����
			Equalgraph.SetPixel(i,j,Color(255,255,255)); // �׷��� ��� ������� �ʱ�ȭ
	}
	
	for(int x = 0; x < 256; x++)
	{
		for(int y = 0; y < m_Hist[x]; y++) // Y���� ��ϵ� �󵵼��� ��´�.
			Equalgraph.SetPixel(x,m_EqualtopHist-y,Color(0,0,0)); 
	}
	G.DrawImage(&Equalgraph,545,285,300,190);
}


void CMy20091556P1Dlg::Hist(Color a) // ������ ���� �󵵼��� �����ϴ� �Լ�
{
	int R, G, B, L;

	R = a.GetR();
	G = a.GetG();
	B = a.GetB();
	L = 0.30*R + 0.59*G + 0.11*B; // RGB���� �� ���� ����
	m_Hist[L]++; // �󵵼� ����
}


double CMy20091556P1Dlg::SaveY(Color a) // ������ Y�� ���� �Լ�
{
	int Y;
	Y = 0.29900*a.GetR() + 0.58700*a.GetG() + 0.11400*a.GetB();
	Y = min(255,max(0,Y));
	return Y;
}


double CMy20091556P1Dlg::SaveCb(Color a) // ������ Cb�� ���� �Լ�
{
	int Cb;
	Cb = -0.16874*a.GetR() - 0.33126*a.GetG() + 0.50000*a.GetB();
	Cb = min(255,max(0,Cb));
	return Cb;
}


double CMy20091556P1Dlg::SaveCr(Color a) // ������ Cr�� ���� �Լ�
{
	int Cr;
	Cr = 0.50000*a.GetR() - 0.41869*a.GetG() - 0.08131*a.GetB();
	Cr = min(255,max(0,Cr));
	return Cr;
}


Color CMy20091556P1Dlg::SetRGB(int Y, int Cb, int Cr) // Y, Cb, Cr���� RGB�� �ٲ��ִ� �Լ�
{
	Color a;
	int R, G, B;

	R = 1.00000*Y + 1.40200*Cr;
	G = 1.00000*Y - 0.34414*Cb - 0.71414*Cr;
	B = 1.00000*Y + 1.77200*Cb;

	//R = min(255,max(0,R));
	//G = min(255,max(0,G));
	//B = min(255,max(0,B));

	a.SetFromCOLORREF(RGB(R,G,B));
	return a;
}


void CMy20091556P1Dlg::EqualHist(int EqualY)
{
	m_Hist[EqualY]++;
}