#include "Commerce.h"
// 商业贷款



void Commerce::GetHousPrice(HWND hWnd)
{
	HWND hEdit = GetDlgItem(hWnd, IDC_EDIT1);
	TCHAR Buffer[1024] = { 0 };
	GetWindowText(hEdit, Buffer, 50);
	char t_szBuffer[1024] = { 0 };
	WideCharToMultiByte(CP_OEMCP, 0, Buffer, -1, t_szBuffer, 256, NULL, FALSE);
	HousPrice = atof(t_szBuffer);
}

void Commerce::GetHousArea(HWND hWnd)
{
	HWND hEdit = GetDlgItem(hWnd, IDC_EDIT3);
	TCHAR Buffer[1024] = { 0 };
	GetWindowText(hEdit, Buffer, 50);
	char t_szBuffer[1024] = { 0 };
	WideCharToMultiByte(CP_OEMCP, 0, Buffer, -1, t_szBuffer, 256, NULL, FALSE);
	HousArea = atof(t_szBuffer);
}

void Commerce::GetMortYears(HWND hWnd)
{
	HWND hEdit = GetDlgItem(hWnd, IDC_EDIT4);
	TCHAR Buffer[1024] = { 0 };
	GetWindowText(hEdit, Buffer, 50);
	char t_szBuffer[1024] = { 0 };
	WideCharToMultiByte(CP_OEMCP, 0, Buffer, -1, t_szBuffer, 256, NULL, FALSE);
	MortYears = atof(t_szBuffer);
}

void Commerce::GetloanRate(HWND hWnd)
{
	HWND hEdit = GetDlgItem(hWnd, IDC_EDIT6);
	TCHAR Buffer[1024] = { 0 };
	GetWindowText(hEdit, Buffer, 50);
	char t_szBuffer[1024] = { 0 };
	WideCharToMultiByte(CP_OEMCP, 0, Buffer, -1, t_szBuffer, 256, NULL, FALSE);
	loanRate = atof(t_szBuffer);
}

void Commerce::GetRental(HWND hWnd)
{
	HWND hEdit = GetDlgItem(hWnd, IDC_EDIT2);
	TCHAR Buffer[1024] = { 0 };
	GetWindowText(hEdit, Buffer, 50);
	char t_szBuffer[1024] = { 0 };
	WideCharToMultiByte(CP_OEMCP, 0, Buffer, -1, t_szBuffer, 256, NULL, FALSE);
	Rental = atof(t_szBuffer);
}

void Commerce::GetCommerceData(HWND hWnd)
{
	HousPrice = 0;
	HousArea = 0;
	MortYears = 0;
	loanRate = 0;
	Rental = 0;
	GetHousPrice( hWnd);
	GetHousArea( hWnd);
	GetMortYears( hWnd);
	GetloanRate( hWnd);
	GetRental( hWnd);
	GetCommerSele(hWnd);
}

void Commerce::CountFund()
{
	
	if (Capital == 1)	// 等额本金计算
	{
		ResData.Down = (HousArea * HousPrice) / (MortYears * 12) + (HousArea * HousPrice) * 0.002708;
		ResData.FirstMonth = (HousArea * HousPrice) / (MortYears * 12) + (HousArea * HousPrice) * 0.002708;
		ResData.TotalLoan = (HousArea * HousPrice);
		ResData.Payment = (MortYears * 12 + 1) * (HousArea * HousPrice) * 0.002708 / 2;
		ResData.Amount = (MortYears * 12 + 1) * (HousArea * HousPrice) * 0.002708 / 2 + (HousArea * HousPrice);
		ResData.MentMonths = MortYears * 12;
	}
	if (Interest == 1)	// 等额本息计算
	{
		ResData.Down = (HousArea * HousPrice) * 0.2708 * pow(1.2708, ResData.MentMonths )/(pow(1.2708,ResData.MentMonths )- 1);
		ResData.FirstMonth = (HousArea * HousPrice) * 0.2708 * pow(1.2708, ResData.MentMonths) / (pow(1.2708, ResData.MentMonths) - 1);
		ResData.TotalLoan = (HousArea * HousPrice);
		ResData.Payment = ResData.FirstMonth * (MortYears * 12) - (HousArea * HousPrice);
		ResData.Amount = ResData.FirstMonth * (MortYears * 12);
		ResData.MentMonths = MortYears * 12;
	}
}

void Commerce::CountCommerce()
{
	
	if (Capital == 1)	// 等额本金计算
	{
		ResData.Down = (HousArea * HousPrice) / (MortYears * 12) + (HousArea * HousPrice) * 0.03958;
		ResData.FirstMonth = (HousArea * HousPrice) / (MortYears * 12) + (HousArea * HousPrice) * 0.03958;
		ResData.TotalLoan = (HousArea * HousPrice);
		ResData.Payment = (MortYears * 12 + 1) * (HousArea * HousPrice) * 0.03958 / 2;
		ResData.Amount = (MortYears * 12 + 1) * (HousArea * HousPrice) * 0.03958 / 2 + (HousArea * HousPrice);
		ResData.MentMonths = MortYears * 12;
	}
	if (Interest == 1)	// 等额本息计算
	{
		ResData.Down = (HousArea * HousPrice) * 0.3958 * pow(1.3958, ResData.MentMonths) / (pow(1.3958, ResData.MentMonths) - 1);
		ResData.FirstMonth = (HousArea * HousPrice) * 0.3958 * pow(1.3958, ResData.MentMonths) / (pow(1.3958, ResData.MentMonths) - 1);
		ResData.TotalLoan = (HousArea * HousPrice);
		ResData.Payment = ResData.FirstMonth * (MortYears * 12) - (HousArea * HousPrice);
		ResData.Amount = ResData.FirstMonth * (MortYears*12);
		ResData.MentMonths = MortYears * 12;
	}
}

void Commerce::SetResult(HWND hWnd)
{
	
	// 首付
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.Down);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT12), Buffer);
	}
	// 每月月供
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.FirstMonth);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT13), Buffer);
	}
	// 贷款总额
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.TotalLoan);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT19), Buffer);
	}
	// 支付利息
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.Payment);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT16), Buffer);
	}
	// 还款总额
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.Amount);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT17), Buffer);
	}
	// 还款月数
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.MentMonths);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT18), Buffer);
	}

	if (1) // 重置 结果数据 缓冲区
	{
		ResData.Down = 0;
		ResData.FirstMonth = 0;
		ResData.TotalLoan = 0;
		ResData.Payment = 0;
		ResData.Amount = 0;
		ResData.MentMonths = 0;
	}
	
}

void Commerce::CommerceAllCall(HWND hWnd)
{
	GetCommerceData(hWnd);

	if (Capital == Interest)
	{
		MessageBox(NULL, TEXT("请选择单选框"), TEXT("请选择单选框"), NULL);
		return;
	}

	if (iCommerce == Fund)
	{
		MessageBox(NULL, TEXT("请选择单选框"), TEXT("请选择单选框"), NULL);
		return;
	}

	if (iCommerce == 1)
	{
		CountCommerce();
	}
	if (Fund == 1)
	{
		CountFund();
	}
	SetResult(hWnd);
}

void Commerce::ClearText(HWND hWnd)
{
	SetWindowText(GetDlgItem(hWnd, IDC_EDIT1), TEXT(""));
	SetWindowText(GetDlgItem(hWnd, IDC_EDIT3), TEXT(""));
	SetWindowText(GetDlgItem(hWnd, IDC_EDIT4), TEXT(""));
	SetWindowText(GetDlgItem(hWnd, IDC_EDIT6), TEXT(""));
	SetWindowText(GetDlgItem(hWnd, IDC_EDIT2), TEXT(""));

}

void Commerce::GetCommerSele(HWND hWnd)
{
	Capital = 0;
	Interest = 0;
	iCommerce = 0;
	Fund = 0;
	HWND hCheckBox = GetDlgItem(hWnd, dwCapitalID);
	if (SendMessage(hCheckBox, BM_GETCHECK, 0, 0) == BST_CHECKED) 
	{
		Capital = 1;
	}
	

	hCheckBox = GetDlgItem(hWnd, dwInterestID);
	if (SendMessage(hCheckBox, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		Interest = 1;
	}
	hCheckBox = GetDlgItem(hWnd, dwFundID);
	if (SendMessage(hCheckBox, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		Fund = 1;
	}
	hCheckBox = GetDlgItem(hWnd, dwCommerceID);
	if (SendMessage(hCheckBox, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		iCommerce = 1;
	}
}

void Group::GetComerNum(HWND hWnd)
{
	HWND hEdit = GetDlgItem(hWnd, IDC_EDIT7);
	TCHAR Buffer[1024] = { 0 };
	GetWindowText(hEdit, Buffer, 50);
	char t_szBuffer[1024] = { 0 };
	WideCharToMultiByte(CP_OEMCP, 0, Buffer, -1, t_szBuffer, 256, NULL, FALSE);
	ComerNum = atof(t_szBuffer);
}

void Group::GetComerRate(HWND hWnd)
{
	HWND hEdit = GetDlgItem(hWnd, IDC_EDIT9);
	TCHAR Buffer[1024] = { 0 };
	GetWindowText(hEdit, Buffer, 50);
	char t_szBuffer[1024] = { 0 };
	WideCharToMultiByte(CP_OEMCP, 0, Buffer, -1, t_szBuffer, 256, NULL, FALSE);
	ComerRate = atof(t_szBuffer);
}

void Group::GetFundNum(HWND hWnd)
{
	HWND hEdit = GetDlgItem(hWnd, IDC_EDIT10);
	TCHAR Buffer[1024] = { 0 };
	GetWindowText(hEdit, Buffer, 50);
	char t_szBuffer[1024] = { 0 };
	WideCharToMultiByte(CP_OEMCP, 0, Buffer, -1, t_szBuffer, 256, NULL, FALSE);
	FundNum = atof(t_szBuffer);
}

void Group::GetFundRate(HWND hWnd)
{
	HWND hEdit = GetDlgItem(hWnd, IDC_EDIT8);
	TCHAR Buffer[1024] = { 0 };
	GetWindowText(hEdit, Buffer, 50);
	char t_szBuffer[1024] = { 0 };
	WideCharToMultiByte(CP_OEMCP, 0, Buffer, -1, t_szBuffer, 256, NULL, FALSE);
	FundRate = atof(t_szBuffer);
}

void Group::GetMortYear(HWND hWnd)
{
	HWND hEdit = GetDlgItem(hWnd, IDC_EDIT11);
	TCHAR Buffer[1024] = { 0 };
	GetWindowText(hEdit, Buffer, 50);
	char t_szBuffer[1024] = { 0 };
	WideCharToMultiByte(CP_OEMCP, 0, Buffer, -1, t_szBuffer, 256, NULL, FALSE);
	MortYear = atof(t_szBuffer);
}

void Group::GetGroupSele(HWND hWnd)
{
	Capital = 0;
	Interest = 0;
	
	HWND hCheckBox = GetDlgItem(hWnd, IDC_RADIO6);
	if (SendMessage(hCheckBox, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		Capital = 1;
	}


	hCheckBox = GetDlgItem(hWnd, IDC_RADIO5);
	if (SendMessage(hCheckBox, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		Interest = 1;
	}
}

void Group::GetGroupData(HWND hWnd)
{
	GetComerNum( hWnd);
	GetComerRate( hWnd);
	GetFundNum( hWnd);
	GetFundRate( hWnd);
	GetMortYear( hWnd);
	GetGroupSele( hWnd);
}

void Group::CountGroup()
{
	if (Capital == 1)	// 等额本金计算
	{
		ResData.Down = (ComerNum + FundNum) / (MortYear * 12) + (ComerNum + FundNum) * 0.002708;
		ResData.FirstMonth = ((MortYear * 12 + 1) * (ComerNum + FundNum) * 0.002708 / 2 + ComerNum + FundNum) / (MortYear * 12);
		ResData.TotalLoan = FundNum + ComerNum;
		ResData.Payment = (MortYear * 12 + 1) * (ComerNum + FundNum) * 0.002708 / 2;
		ResData.Amount = (MortYear * 12 + 1) * (ComerNum + FundNum) * 0.002708 / 2 + ComerNum + FundNum;
		ResData.MentMonths = MortYear * 12;
	}
	if (Interest == 1)	// 等额本息计算
	{
		
		ResData.Down = (ComerNum + FundNum) * 0.002708 * pow(0.012708, ResData.MentMonths) / (pow(0.012708, ResData.MentMonths) - 1);
		ResData.FirstMonth = (ComerNum + FundNum) * 0.002708 * pow(0.012708, ResData.MentMonths) / (pow(0.012708, ResData.MentMonths) - 1);
		ResData.TotalLoan = ResData.Down * (MortYear * 12);
		ResData.Payment = (MortYear * 12 + 1) * (ComerNum + FundNum) * 0.002708 / 2 + ComerNum + FundNum - ResData.TotalLoan;
		ResData.Amount = (MortYear * 12 + 1) * (ComerNum + FundNum) * 0.002708 / 2 + ComerNum + FundNum;
		ResData.MentMonths = MortYear * 12;
	}
}

void Group::SetResult(HWND hWnd)
{
	// 首付
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.Down);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT12), Buffer);
	}
	// 每月月供
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.FirstMonth);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT13), Buffer);
	}
	// 贷款总额
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.TotalLoan);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT19), Buffer);
	}
	// 支付利息
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.Payment);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT16), Buffer);
	}
	// 还款总额
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.Amount);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT17), Buffer);
	}
	// 还款月数
	if (1)
	{
		TCHAR Buffer[100] = { 0 };
		_sntprintf_s(Buffer, 100, TEXT("%lf"), ResData.MentMonths);
		SetWindowText(GetDlgItem(hWnd, IDC_EDIT18), Buffer);
	}

	if (1) // 重置 结果数据 缓冲区
	{
		ResData.Down = 0;
		ResData.FirstMonth = 0;
		ResData.TotalLoan = 0;
		ResData.Payment = 0;
		ResData.Amount = 0;
		ResData.MentMonths = 0;
	}
}

void Group::GroupAllCall(HWND hWnd)
{
	GetGroupData(hWnd);
	if (Capital == Interest)
	{
		MessageBox(NULL, TEXT("请选择单选框"), TEXT("请选择单选框"), NULL);
		return;
	}
	CountGroup();
	SetResult(hWnd);		// 显示结果在文本框
}

void Group::ClearText(HWND hWnd)
{
	SetWindowText(GetDlgItem(hWnd, IDC_EDIT7), TEXT(""));
	SetWindowText(GetDlgItem(hWnd, IDC_EDIT9), TEXT(""));
	SetWindowText(GetDlgItem(hWnd, IDC_EDIT10), TEXT(""));
	SetWindowText(GetDlgItem(hWnd, IDC_EDIT8), TEXT(""));
	SetWindowText(GetDlgItem(hWnd, IDC_EDIT11), TEXT(""));
}
