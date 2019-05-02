#pragma once
#include "Services.h"

class KomootServices : public Services
{
public:
	KomootServices();
	~KomootServices();

	vector<string> GetFixedRoutes();
	vector<string> GetUserRoute(int userId);
	string GetServiceName();

private: 
	const vector<string> mFixedRoutes = { "SRT", "Welsh Mountain", "Oaks to Philly" };
	const string mServiceName = "Komoot";
};

