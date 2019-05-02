#pragma once
#include"Services.h"
class StarvaServices : public Services
{
public:
	StarvaServices();
	~StarvaServices();

	vector<string> GetFixedRoutes();
	vector<string> GetUserRoute(int userId);
	string GetServiceName();

private:

	const vector<string> mFixedRoutes = { "SRT", "CVT", "Perkiomen" };
	const string mServiceName = "Starva";
};

