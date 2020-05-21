#pragma once
#include "resource.h"
#include <windows.h>
#include <tchar.h>
#include <cmath>
// 结果数据
static struct ResultData
{
	double Down = 0;			// 首付
	double FirstMonth = 0;		// 每月月供
	double TotalLoan = 0;		// 贷款总额
	double Payment = 0;			// 支付利息
	double Amount = 0;			// 还款总额
	double MentMonths = 0;		// 还款月数
}ResData;

// 商业/公积金贷款
static class Commerce
{
private:	// 私有
	double HousPrice = 0;			// 用户输入 房屋单价
	double HousArea = 0;			// 用户输入 房屋面积
	double MortYears = 0;			// 用户输入 按揭年数
	double loanRate = 0;			// 用户输入 贷款利率
	double Rental = 0;				// 用户输入 贷款总额
public:		// 共有
	int Capital = 0;				// 等额本金 1==选中 0 == 未选中
	int Interest = 0;				// 等额本息 1==选中 0 == 未选中
	int iCommerce = 0;				// 商业贷款 1==选中 0 == 未选中
	int Fund = 0;					// 公积金贷款 1==选中 0 == 未选中

	


	DWORD dwHousPriceID = IDC_EDIT1;		// 房屋单价ID
	DWORD dwHousAreaID= IDC_EDIT3;			// 房屋面积ID
	DWORD dwMortYearsID = IDC_EDIT4;		// 按揭年数ID
	DWORD dwloanRateID= IDC_EDIT6;			// 贷款利率ID
	DWORD dwRentalID = IDC_EDIT2;			// 贷款总额ID

	DWORD dwCapitalID = IDC_RADIO2;			// 等额本金ID
	DWORD dwInterestID = IDC_RADIO1;		// 等额本息ID
	DWORD dwCommerceID = IDC_RADIO3;		// 商业贷款ID
	DWORD dwFundID = IDC_RADIO4;			// 公积金贷款ID
	
public:		// 共有
	

	void GetHousPrice(HWND hWnd);	// 获取用户输入的房屋单价
	void GetHousArea(HWND hWnd);	// 获取用户输入的房屋面积
	void GetMortYears(HWND hWnd);	// 获取用户输入的按揭年数
	void GetloanRate(HWND hWnd);	// 获取用户输入的贷款利率
	void GetRental(HWND hWnd);		// 获取用户输入的贷款总额
	void GetCommerSele(HWND hWnd);	// 获取用户输入的选择

	void GetCommerceData(HWND hWnd);// 获取所有的数据项

	void CountFund();				// 计算公积金贷款
	void CountCommerce();			// 计算商业贷款

	void SetResult(HWND hWnd);		// 计算结果，并显示在文本框

	void CommerceAllCall(HWND hWnd);// 总调用
	void ClearText(HWND hWnd);		// 清空文本框
}Commer;

// 组合贷款
static class Group
{
private:	// 私有
	double ComerNum = 0;			// 用户输入 商业贷款额
	double ComerRate = 0;			// 用户输入 商贷利率
	double FundNum = 0;				// 用户输入 公积金贷款额
	double FundRate = 0;			// 用户输入 公积金利率
	double MortYear = 0;			// 用户输入 按揭年数


public:		// 共有
	int Capital = 0;				// 等额本金 1==选中 0 == 未选中
	int Interest = 0;				// 等额本息 1==选中 0 == 未选中
	
	DWORD dwComerNumID = IDC_EDIT7;			// 商业贷款额	文本框ID
	DWORD dwComerRateID = IDC_EDIT9;		// 商贷利率		文本框ID
	DWORD dwFundNumID = IDC_EDIT10;			// 公积金贷款额  文本框ID
	DWORD dwFundRateID = IDC_EDIT8;			// 公积金利率	文本框ID
	DWORD dwMortYearsID = IDC_EDIT11;		// 按揭年数		文本框ID
	



public:		// 共有
	void GetComerNum(HWND hWnd);	// 获取 用户输入 商业贷款额
	void GetComerRate(HWND hWnd);	// 获取 用户输入 商贷利率
	void GetFundNum(HWND hWnd);		// 获取 用户输入 公积金贷款额
	void GetFundRate(HWND hWnd);	// 获取 用户输入 公积金利率
	void GetMortYear(HWND hWnd);	// 获取 用户输入 按揭年数
	void GetGroupSele(HWND hWnd);	// 获取用户输入的选择
	void GetGroupData(HWND hWnd);	// 获取所有的数据项

	void CountGroup();				// 计算结果
	void SetResult(HWND hWnd);		// 显示结果在文本框
	void GroupAllCall(HWND hWnd);	// 总调用
	void ClearText(HWND hWnd);		// 清空文本框

}group;

/*
	商贷利率  0.002708  IDC_EDIT9
	公积金利率 0.012708  IDC_EDIT8
	贷款利率 0.003958
*/
