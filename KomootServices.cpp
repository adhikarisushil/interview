#include "KomootServices.h"



KomootServices::KomootServices()
{
}

KomootServices::~KomootServices()
{
}

vector<string> KomootServices::GetFixedRoutes()
{
	return mFixedRoutes;
}

vector<string> KomootServices::GetUserRoute(int userId)
{
	// First prepend the route names with userId
	vector<string> prependedRoutes = PrependUserId(userId, mFixedRoutes);

	// Now append the returned route names with userId and return
	return AppendUserId(userId, prependedRoutes);
}

string KomootServices::GetServiceName()
{
	return mServiceName;
}
