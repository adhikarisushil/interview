#include "Services.h"
#include <iostream>
#include<memory>


Services::Services()
{
}


Services::~Services()
{
}

vector<string> Services::PrependUserId(int userId, vector<string> inputRoutes)
{
	return GetModifiedRoutes(userId, inputRoutes, Operation::PREPEND);
}

vector<string> Services::AppendUserId(int userId, vector<string> inputRoutes)
{
	return GetModifiedRoutes(userId, inputRoutes, Operation::APPEND);
}

vector<string> Services::GetModifiedRoutes(int userId, vector<string> inputRoutes, Operation op)
{
	vector<string> routesToReturn = vector<string>();
	for each (string route in inputRoutes)
	{
		string modifiedRouteName;
		switch (op)
		{
		case Services::PREPEND:
			modifiedRouteName = to_string(userId) + route;
			break;
		case Services::APPEND:
			modifiedRouteName = route + to_string(userId);
			break;
		default:
			modifiedRouteName = route;
			cout << "No matching operation.";
			break;
		}
		routesToReturn.push_back(modifiedRouteName);
	}

	return routesToReturn;
}
