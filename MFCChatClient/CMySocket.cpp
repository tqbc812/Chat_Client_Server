#include "pch.h"
#include "CMySocket.h"
#include "MFCChatClient.h"
#include "MFCChatClientDlg.h"

CMySocket::CMySocket() {

}
CMySocket::~CMySocket()
{

}

void CMySocket::OnConnect(int nErrorCode)
{
	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();
	CString str;
	//��ȡ��ǰʱ��
	dlg->m_tm = CTime::GetCurrentTime();
	str = dlg->m_tm.Format("%X ");
	str += _T("����������ӳɹ�");
	dlg->m_list.AddString(str);
	   
	CAsyncSocket::OnConnect(nErrorCode);
}

void CMySocket::OnReceive(int nErrorCode)
{
	

	

}