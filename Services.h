#pragma once
#include <vector>
#include <string>
using namespace std;

class Services
{
public:
	Services();
	~Services();
	virtual vector<string> GetFixedRoutes() = 0;
	virtual vector<string> GetUserRoute(int userId) = 0;
	virtual string GetServiceName() = 0;

protected:
	vector<string> PrependUserId(int userId, vector<string> inputRoutes);
	vector<string> AppendUserId(int userId, vector<string> inputRoutes);

private:
	enum Operation
	{
		PREPEND,
		APPEND
	};

	vector<string> Services::GetModifiedRoutes(int userId, vector<string> inputRoutes, Operation op);
};

