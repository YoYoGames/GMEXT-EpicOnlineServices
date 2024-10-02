
//Reports Interface
//Query user reports to view the details of reported user behaviors, for example, cheating, verbal abuse, offensive profiles, and so on.

//EOS_Reports_SendPlayerBehaviorReport

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_reports.h>

EOS_HReports HReports;
void EpicGames_Reports_Init()
{
	HReports = EOS_Platform_GetReportsInterface(PlatformHandle);
}

void EOS_CALL SendPlayerBehaviorReportCallbackFn(const EOS_Reports_SendPlayerBehaviorReportCompleteCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Reports_SendPlayerBehaviorReport");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Reports_SendPlayerBehaviorReport(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* ReporterUserId = YYGetString(arg, 0);
	const char* ReportedUserId = YYGetString(arg, 1);
	int category = (int)YYGetReal(arg, 2);
	const char* Message = YYGetString(arg, 3);

	EOS_Reports_SendPlayerBehaviorReportOptions SendPlayerBehaviorReportOptions = {};
	SendPlayerBehaviorReportOptions.ApiVersion = EOS_REPORTS_SENDPLAYERBEHAVIORREPORT_API_LATEST;
	SendPlayerBehaviorReportOptions.Category = (EOS_EPlayerReportsCategory)category; EOS_EPlayerReportsCategory::EOS_PRC_Cheating;
	SendPlayerBehaviorReportOptions.Message = Message;
	SendPlayerBehaviorReportOptions.ReportedUserId = EOS_ProductUserId_FromString(ReportedUserId);
	SendPlayerBehaviorReportOptions.ReporterUserId = EOS_ProductUserId_FromString(ReporterUserId);
	
	callback* mcallback = getCallbackData();

	EOS_Reports_SendPlayerBehaviorReport(HReports, &SendPlayerBehaviorReportOptions, mcallback, SendPlayerBehaviorReportCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
