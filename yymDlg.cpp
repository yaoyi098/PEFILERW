// yymDlg.cpp : implementation file
//

#include "stdafx.h"
#include "yym.h"
#include "yymDlg.h"
#include "WINNT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	

	

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYymDlg dialog

CYymDlg::CYymDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CYymDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CYymDlg)
	m_JM = _T("");
	m_JQS = _T("");
	m_RYCD = _T("");
	m_RYQS = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYymDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CYymDlg)
	DDX_Control(pDX, IDC_EDIT2, m_Text2);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
	DDX_Control(pDX, IDC_EDIT1, m_Text);
	DDX_Text(pDX, IDC_JM, m_JM);
	DDX_Text(pDX, IDC_JQS, m_JQS);
	DDX_Text(pDX, IDC_RYCD, m_RYCD);
	DDX_Text(pDX, IDC_RYQS, m_RYQS);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CYymDlg, CDialog)
	//{{AFX_MSG_MAP(CYymDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_OPEN, OnMenuOpen)
	ON_COMMAND(ID_MENU_QUIT, OnMenuQuit)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_COMMAND(ID_MENUITEM_yincangwenjian, OnMENUITEMyincangwenjian)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYymDlg message handlers

BOOL CYymDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CYymDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CYymDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CYymDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CYymDlg::OnMenuOpen() 
{	
	CString fileName;


	//设置文件类型过滤
	char filter[] = "执行文件 (*.exe)|*.exe|DLL文件 (*.dll)|*.dll|All Files (*.*)|*.*||";
	
	//声明文件对话框
	CFileDialog fdlg(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,filter);
	fdlg.m_ofn.lpstrInitialDir = "d:\\";
	if(fdlg.DoModal() == IDOK)
	{
		fileName = fdlg.GetPathName();
	}
	//声明文件异常
	CFileException fileException;
	
	//打开文件，处理异常
	if(!file.Open(fileName,CFile::modeReadWrite|CFile::typeBinary,&fileException))
	{
		CString errorInfo;
		errorInfo.Format("不能打开文件%S，错误：%u\n",fileName,fileException.m_cause);
		MessageBox(errorInfo, "错误", MB_OK | MB_ICONERROR);
		return;
	}
	



	
	file.Seek(0,CFile::begin);
	file.Read(&myPeFile.dosHeader,sizeof(myPeFile.dosHeader));
	
	file.Seek(myPeFile.dosHeader.e_lfanew,CFile::begin);
	file.Read(&myPeFile.ntHeader,sizeof(myPeFile.ntHeader));
	

	if(!(myPeFile.dosHeader.e_magic == IMAGE_DOS_SIGNATURE) && !(myPeFile.ntHeader.Signature == IMAGE_NT_SIGNATURE))
	{
		MessageBox("不是有效的PE文件！","错误",MB_OK|MB_ICONERROR);
		return;
	}
	
	myPeFile.numSection = myPeFile.ntHeader.FileHeader.NumberOfSections;

	long p;
	p = myPeFile.dosHeader.e_lfanew + sizeof(myPeFile.ntHeader.Signature) + sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_OPTIONAL_HEADER);
	for(int i=0;i<myPeFile.numSection;i++)
	{
		file.Seek(p+(i * (sizeof(myPeFile.secHeader))),CFile::begin);
		file.Read(&myPeFile.secHeader,sizeof(myPeFile.secHeader));
		myPeFile.secname[i].name = myPeFile.secHeader.Name;
		myPeFile.secname[i].rYStart = myPeFile.secHeader.PointerToRawData + myPeFile.secHeader.Misc.VirtualSize;
		myPeFile.secname[i].ryLen = (myPeFile.secHeader.SizeOfRawData - myPeFile.secHeader.Misc.VirtualSize);
		m_listBox.AddString(myPeFile.secname[i].name);
		myPeFile.secname[i].jieStart = myPeFile.secHeader.PointerToRawData;
		
//		CString buff;
//		buff.Format("start: %x  ,len:%d",myPeFile.secname[i].rYStart,myPeFile.secname[i].ryLen);
//		MessageBox(buff);
	}




	
//	MessageBox(buff);
	

	//file.Close();
	
}



void CYymDlg::OnMenuQuit() 
{
	OnCancel();
	
}

void CYymDlg::OnSelchangeList1() 
{
	int curSel;
	int len;
	char *readbuff;
	CString abuff;
	curSel = m_listBox.GetCurSel();

	file.Seek(myPeFile.secname[curSel].rYStart,CFile::begin);
	len = myPeFile.secname[curSel].ryLen;
	
	readbuff = new char[len];

	file.Read(readbuff,len);
	//选择编辑框中全部文本并删除

	m_Text.SetSel(-1,0);
	m_Text.Clear();
	m_Text.SetWindowText(readbuff);
	delete readbuff;

	m_JM = myPeFile.secname[curSel].name;
	m_JQS.Format("0x%x",myPeFile.secname[curSel].jieStart);
	m_RYQS.Format("0x%x",myPeFile.secname[curSel].rYStart);
	m_RYCD.Format("%d",myPeFile.secname[curSel].ryLen);


	UpdateData(false);
}

void CYymDlg::OnButton1() 
{
	CString writebuff;
	int len;
	int i;
	int sel;
	char *buff;
	CListBox *listBox = (CListBox *)GetDlgItem(IDC_LIST1);
	sel = listBox->GetCurSel();
	if(sel == -1)
	{
		MessageBox("请选择一个节！");
		return;
	}
	m_Text2.GetWindowText(writebuff);
	len = writebuff.GetLength();
	if(len > (myPeFile.secname[sel].ryLen))
	{
		CString buff1;
		buff1.Format("文本长度超出限制（%d）",myPeFile.secname[sel].ryLen);
		MessageBox(buff1,"错误",MB_OK|MB_ICONERROR);
		return;
	}
	buff = new char[myPeFile.secname[sel].ryLen];
	for(i=0;i<myPeFile.secname[sel].ryLen;i++)
	{
		buff[i] = '\0';
	}
	file.Seek(myPeFile.secname[sel].rYStart,CFile::begin);
	file.Write(buff,myPeFile.secname[sel].ryLen);
	file.Seek(myPeFile.secname[sel].rYStart,CFile::begin);
	file.Write(writebuff.GetBuffer(len),len);
	UpdateData(false);
	OnSelchangeList1();
	delete buff;
}	

void CYymDlg::OnButton2() 
{
	int len;
	int sel;
	char *buff2;
	CListBox *listBox = (CListBox *)GetDlgItem(IDC_LIST1);

	sel = listBox->GetCurSel();


	if(sel == -1)
	{
		MessageBox("请选择一个节！");

		return;
	}
	len = myPeFile.secname[sel].ryLen;
	file.Seek(myPeFile.secname[sel].rYStart,CFile::begin);
	buff2 = new char [len];
	for(int i = 0;i<len;i++)
		buff2[i] = '\0';
	file.Write(buff2,len);
	OnSelchangeList1();
	
	
	delete buff2;
  
	
}

void CYymDlg::OnMENUITEMyincangwenjian() 
{
	// TODO: Add your command handler code here
	CString fileName1;
	CFile file1;
	long filelen;
	int ryzlen;
	CString buff;
	char *buff2;
	char *readbuff;
	int i;
	ryzlen = 0;

	//设置文件类型过滤
	for(i=0;i < myPeFile.numSection; i++)
	{

		ryzlen = ryzlen + myPeFile.secname[i].ryLen;
//		buff.Format("%d   %l    %d",i,ryzlen,myPeFile.secname[i].ryLen);
//		MessageBox(buff);

	}
	buff.Format("现有冗余长度为：%d",ryzlen);
	MessageBox(buff);

	//声明文件对话框
	CFileDialog fdlg(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT);
	fdlg.m_ofn.lpstrInitialDir = "d:\\";
	if(fdlg.DoModal() == IDOK)
	{
		fileName1 = fdlg.GetPathName();
	}
	//声明文件异常
	CFileException fileException;
	
	//打开文件，处理异常
	if(!file1.Open(fileName1,CFile::modeReadWrite|CFile::typeBinary,&fileException))
	{
		CString errorInfo;
		errorInfo.Format("不能打开文件%S，错误：%u\n",fileName1,fileException.m_cause);
		MessageBox(errorInfo, "错误", MB_OK | MB_ICONERROR);
		return;
	}
	filelen = file1.GetLength();
	if(ryzlen <= filelen)
	{
		CString errorInfo;
		errorInfo.Format("文件大小超出限制%d",ryzlen);
		MessageBox(errorInfo,"出错啦！",MB_OK|MB_ICONERROR);
		file1.Close();
		return;
	}
	fileName1 = file1.GetFileName();
	long p;
	p = myPeFile.dosHeader.e_lfanew + sizeof(myPeFile.ntHeader.Signature) + sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_OPTIONAL_HEADER) + (myPeFile.numSection + 1)*40;
	if(fileName1.GetLength() < 20)
	{
		buff2 = new char[40];
		for(i=0;i<40;i++)
		{
			buff2[i] = '\0';
		}
		file.Seek(p,CFile::begin);
		file.Write(buff2,40);
		file.Seek(p,CFile::begin);
		file.Write(fileName1.GetBuffer(fileName1.GetLength()),fileName1.GetLength());
		file.Seek(p + 20,CFile::begin);
		buff.Format("%d",filelen);
		file.Write(buff.GetBuffer(20),buff.GetLength());
	}
	else 
	{
		MessageBox("文件名长度超过20字节，请修改文件名","出错啦!",MB_OK|MB_ICONERROR);
		return;
	}
	int alreadywrite = 0;
	for(i=0;;i++)
	{
		file.Seek(myPeFile.secname[i].rYStart,CFile::begin);
		file1.Seek((long)alreadywrite,CFile::begin);
		readbuff = new char[myPeFile.secname[i].ryLen];
		file1.Read(readbuff,myPeFile.secname[i].ryLen);
		file.Write(readbuff,myPeFile.secname[i].ryLen);
		alreadywrite = alreadywrite + myPeFile.secname[i].ryLen;
		if(alreadywrite>=filelen)
			break;
	}
	delete readbuff;
	delete buff2;
			
    file1.Close();
}
