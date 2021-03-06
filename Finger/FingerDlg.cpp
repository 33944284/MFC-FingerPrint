
// FingerDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Finger.h"
#include "FingerDlg.h"
#include "afxdialogex.h"
#include "step.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CFingerDlg 对话框



CFingerDlg::CFingerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFingerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_srcIMG1, m_picCtrl1);
	DDX_Control(pDX, IDC_srcIMG2, m_picCtrl2);
	DDX_Control(pDX, IDC_srcIMG3, m_picCtrl3);
	DDX_Control(pDX, IDC_srcIMG4, m_picCtrl4);
	DDX_Control(pDX, IDC_srcIMG5, m_picCtrl5);
	DDX_Control(pDX, IDC_srcIMG6, m_picCtrl6);
	DDX_Control(pDX, IDC_srcIMG7, m_picCtrl7);
	DDX_Control(pDX, IDC_srcIMG8, m_picCtrl8);
	DDX_Control(pDX, IDC_srcIMG9, m_picCtrl9);
	DDX_Control(pDX, IDC_srcIMG10, m_picCtrl10);
	DDX_Control(pDX, IDC_srcIMG11, m_picCtrl11);
	DDX_Text(pDX, IDC_EDIT1,m_name);
}

BEGIN_MESSAGE_MAP(CFingerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CFingerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CFingerDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK3, &CFingerDlg::OnBnClickedOk3) 
	ON_BN_CLICKED(IDOK4, &CFingerDlg::OnBnClickedOk4)
	ON_BN_CLICKED(IDOK6, &CFingerDlg::OnBnClickedOk6)
	ON_BN_CLICKED(IDOK9, &CFingerDlg::OnBnClickedOk9)
	ON_BN_CLICKED(IDOK7, &CFingerDlg::OnBnClickedOk7)
	ON_BN_CLICKED(IDOK12, &CFingerDlg::OnBnClickedOk12)
	ON_BN_CLICKED(IDOK5, &CFingerDlg::OnBnClickedOk5)
	ON_BN_CLICKED(IDOK10, &CFingerDlg::OnBnClickedOk10)
	ON_BN_CLICKED(IDOK11, &CFingerDlg::OnBnClickedOk11)
	ON_BN_CLICKED(IDOK13, &CFingerDlg::OnBnClickedOk13)
	ON_BN_CLICKED(IDOK8, &CFingerDlg::OnBnClickedOk8)
	ON_BN_CLICKED(IDOK14, &CFingerDlg::OnBnClickedOk14)
END_MESSAGE_MAP()


// CFingerDlg 消息处理程序

BOOL CFingerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFingerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFingerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFingerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFingerDlg::OnBnClickedOk()
{
	char *info = "";
	//Step1_LoadBmpImage(info);
	//Step2_MidFilter(info);
	//Step3_HistoNormalize(info);
	//Step4_Direction(info);
	//Step5_Frequency(info);
	//Step6_GetMask(info);
	//Step7_GaborEnhance(info);
	//Step8_Binary(info);
	//Step9_Thinning(info);
	//Step10_MinuExtract(info);
	//Step11_MinuFilter(info);
	//Step12_Enroll("wxh",info);
	
	//Step12_Match(info);
	//Step12_Identify(info);
	::MessageBox(NULL, _T("执行完成"), _T("OK"), MB_OK);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

CString strFile = _T("");

void CFingerDlg::OnBnClickedOk2()
{
	CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.bmp)|*.bmp|All Files (*.*)|*.*||"), NULL);

	if (dlgFile.DoModal())
	{
		strFile = dlgFile.GetPathName();
	}
	char *info = "";

	USES_CONVERSION;
	char * beginfilename = T2A(strFile);
	Step1_LoadBmpImage(beginfilename,info);

	ShowImageInCtrl(m_picCtrl1, beginfilename);

	// TODO: 在此添加控件通知处理程序代码
}


void CFingerDlg::OnBnClickedOk3()
{
	// TODO: 在此添加控件通知处理程序代码
	char *info = "";
	USES_CONVERSION;
	char * beginfilename = T2A(strFile);
	Step2_MidFilter(beginfilename,info);
	ShowImageInCtrl(m_picCtrl2, STEP_IMG_2);
}


void CFingerDlg::OnBnClickedOk4()
{
	// TODO: 在此添加控件通知处理程序代
	char *info = "";
	Step3_HistoNormalize(info);
	ShowImageInCtrl(m_picCtrl3, STEP_IMG_3);
}


void CFingerDlg::OnBnClickedOk6()
{
	// TODO: 在此添加控件通知处理程序代码
	char *info = "";
	Step4_Direction(info);
	ShowImageInCtrl(m_picCtrl4, STEP_IMG_4);
}


void CFingerDlg::OnBnClickedOk9()
{
	// TODO: 在此添加控件通知处理程序代码
	char *info = "";
	Step5_Frequency(info);
	ShowImageInCtrl(m_picCtrl5, STEP_IMG_5);
}


void CFingerDlg::OnBnClickedOk7()
{
	// TODO: 在此添加控件通知处理程序代码
	char *info = "";
	Step6_GetMask(info);
	ShowImageInCtrl(m_picCtrl6, STEP_IMG_6);
}


void CFingerDlg::OnBnClickedOk12()
{
	// TODO: 在此添加控件通知处理程序代码
	char *info = "";
	Step7_GaborEnhance(info);
	ShowImageInCtrl(m_picCtrl7, STEP_IMG_7);
}


void CFingerDlg::OnBnClickedOk5()
{
	// TODO: 在此添加控件通知处理程序代码
	char *info = "";
	Step8_Binary(info);
	ShowImageInCtrl(m_picCtrl8, STEP_IMG_8);
}


void CFingerDlg::OnBnClickedOk10()
{
	// TODO: 在此添加控件通知处理程序代码
	char *info = "";
	Step9_Thinning(info);
	ShowImageInCtrl(m_picCtrl9, STEP_IMG_9);
}


void CFingerDlg::OnBnClickedOk11()
{
	// TODO: 在此添加控件通知处理程序代码
	char *info = "";
	Step10_MinuExtract(info);
	ShowImageInCtrl(m_picCtrl10, STEP_IMG_10);
}


void CFingerDlg::OnBnClickedOk13()
{
	// TODO: 在此添加控件通知处理程序代码
	char *info = "";
	Step11_MinuFilter(info);
	ShowImageInCtrl(m_picCtrl11, STEP_IMG_11);
}


void CFingerDlg::OnBnClickedOk8()
{
	// TODO: 在此添加控件通知处理程序代码
	char *info = "";
	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString str;
	pBoxOne->GetWindowText(str);
	USES_CONVERSION;
	char * name = T2A(str);
	char * beginfilename = T2A(strFile);
	Step12_Enroll(beginfilename,name,info);
	::MessageBox(NULL, _T("指纹完成入库!"), _T("执行完成"), MB_OK);
}


void CFingerDlg::OnBnClickedOk14()
{
	char *info = "";
	USES_CONVERSION;
	char * beginfilename = T2A(strFile);
	Step12_Identify(beginfilename,info);
}
