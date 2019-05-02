#include "StarvaServices.h"

StarvaServices::StarvaServices()
{
}

StarvaServices::~StarvaServices()
{
}

vector<string> StarvaServices::GetFixedRoutes()
{
	return mFixedRoutes;
}

vector<string> StarvaServices::GetUserRoute(int userId)
{
	return PrependUserId(userId, mFixedRoutes);
}

string StarvaServices::GetServiceName()
{
	return mServiceName;
}
