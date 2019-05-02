#pragma once
#include<memory>

#include "StarvaServices.h"
#include "RWGPSServices.h"
#include "KomootServices.h"

class ServiceProvider
{
public:
	ServiceProvider();
	~ServiceProvider();

	vector<string> GetAllRoutes();
	vector<string> GetUniqueRoutes();
	vector<string> GetAllUserRoute(int userId);
	vector<string> GetUserRouteForListOfServices(int userId, vector<string> services);

private:
	vector<shared_ptr<Services>> mListOfServices;

};

