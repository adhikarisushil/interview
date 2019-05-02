#include "RWGPSServices.h"



RWGPSServices::RWGPSServices()
{
}


RWGPSServices::~RWGPSServices()
{
}

vector<string> RWGPSServices::GetFixedRoutes()
{
	return mFixedRoutes;
}

vector<string> RWGPSServices::GetUserRoute(int userId)
{
	return AppendUserId(userId, mFixedRoutes);
}

string RWGPSServices::GetServiceName()
{
	return mServiceName;
}
