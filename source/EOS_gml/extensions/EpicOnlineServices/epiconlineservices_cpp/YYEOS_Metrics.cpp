
//Metrics Interface
//Interface to record play sessions for game usage data collection.

//EOS_Metrics_BeginPlayerSession
//EOS_Metrics_EndPlayerSession

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_metrics.h>

EOS_HMetrics HMetrics;
void EpicGames_Metrics_Init()
{
	HMetrics = EOS_Platform_GetMetricsInterface(PlatformHandle);
}


YYEXPORT void EpicGames_Metrics_BeginPlayerSession(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	const char* account = YYGetString(arg, 0);
	const char* DisplayName = YYGetString(arg, 1);
	double AccountIdType = YYGetReal(arg, 2);
	double ControllerType = YYGetReal(arg, 3);
	const char* ServerIp = YYGetString(arg, 4);
	const char* GameSessionId = YYGetString(arg, 5);

	// Begin Player Session Metrics
	EOS_Metrics_BeginPlayerSessionOptions MetricsOptions = {};
	MetricsOptions.ApiVersion = EOS_METRICS_BEGINPLAYERSESSION_API_LATEST;
	MetricsOptions.AccountIdType = (EOS_EMetricsAccountIdType)AccountIdType;//EOS_EMetricsAccountIdType::EOS_MAIT_Epic;
	MetricsOptions.AccountId.Epic = EOS_EpicAccountId_FromString(account);
	MetricsOptions.DisplayName = DisplayName;
	MetricsOptions.ControllerType = (EOS_EUserControllerType)ControllerType;//EOS_EUserControllerType::EOS_UCT_MouseKeyboard;
	MetricsOptions.ServerIp = ServerIp;
	MetricsOptions.GameSessionId = GameSessionId;

	EOS_EResult EpicResult = EOS_Metrics_BeginPlayerSession(HMetrics, &MetricsOptions);

	return_EOS_EResult(&Result,EpicResult);
}

YYEXPORT void EpicGames_Metrics_EndPlayerSession(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	const char* account = YYGetString(arg, 0);
	double AccountIdType = YYGetReal(arg, 1);

	EOS_Metrics_EndPlayerSessionOptions MetricsOptions = {};
	MetricsOptions.ApiVersion = EOS_METRICS_ENDPLAYERSESSION_API_LATEST;
	MetricsOptions.AccountId.Epic = EOS_EpicAccountId_FromString(account);
	MetricsOptions.AccountIdType = (EOS_EMetricsAccountIdType)AccountIdType;//EOS_EMetricsAccountIdType::EOS_MAIT_Epic;

	const EOS_EResult EpicResult = EOS_Metrics_EndPlayerSession(HMetrics, &MetricsOptions);

	return_EOS_EResult(&Result, EpicResult);
}

