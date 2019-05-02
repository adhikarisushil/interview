#pragma once
#include "Services.h"

class RWGPSServices : public Services
{
public:
	RWGPSServices();
	~RWGPSServices();

	vector<string> GetFixedRoutes();
	vector<string> GetUserRoute(int userId);
	string GetServiceName();

private:
	const vector<string> mFixedRoutes = { "CVT", "Perkiomen", "Welsh Mountain" };
	const string mServiceName = "RWGPS";

};

