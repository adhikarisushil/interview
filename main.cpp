#include <iostream>
#include <string>

#include "ServiceProvider.h"

using namespace std;

void PrintHelp()
{
	cout << "Uses: Arguments are case sensitive" << endl;
	cout << "\t To get all routes, Run the program without argument." << endl;
	cout << "\t \t for eg. 'InterviewProject.exe'" << endl;
	cout << "\t To get unique routes, Run the program with 'Unique' string as argument" << endl;
	cout << "\t \t for eg. 'InterviewProject.exe Unique'" << endl;
	cout << "\t To get all user routes, Run the program with 'UserId xx' where xx is userId" << endl;
	cout << "\t \t for eg. 'InterviewProject.exe UserId 42'" << endl;
	cout << "\t To get user routes by services, Run the program with 'UserId xx ...' where ... is list of services separated by space" << endl;
	cout << "\t \t for eg. 'InterviewProject.exe UserId 42 Strava Komoot'" << endl;;

}

int main(int argc, char** argv)
{
	ServiceProvider agent = ServiceProvider();
	vector<string> listOfRoutesToPrint = vector<string>();

	//since there is no argument get all the routes. 
	if (argc == 1)
	{
		listOfRoutesToPrint = agent.GetAllRoutes();
	}
	// there is one arguments check if its asking for unique routes. if not print help
	else if (argc == 2)
	{
		if (string(argv[1]) == "Unique")
		{
			listOfRoutesToPrint = agent.GetUniqueRoutes();
		}
		else
		{
			PrintHelp();
		}
	}
	// there are two arguments check if its asking for user routes. If not print help.
	else if (argc == 3)
	{
		if (string(argv[1]) == "UserId")
		{
			try
			{
				// This can throw if its not integer
				int userId = stoi(string(argv[2]));
				listOfRoutesToPrint = agent.GetAllUserRoute(userId);
			}
			catch (...)
			{
				PrintHelp();
			}
		}
		else
		{
			PrintHelp();
		}
	}
	else
	{
		// If second argument is "UserId" and thrid argument value of userId and the rest list of services.
		if (string(argv[1]) == "UserId")
		{
			try
			{
				// This can throw if its not integer
				int userId = stoi(string(argv[2]));

				vector<string> listOfServices;
				for (int i = 3; i < argc; i++)
				{
					listOfServices.push_back(argv[i]);
				}

				listOfRoutesToPrint = agent.GetUserRouteForListOfServices(userId, listOfServices);

				if (listOfRoutesToPrint.size() == 0)
				{
					PrintHelp();
				}
			}
			catch (...)
			{
				PrintHelp();
			}
		}
		else
		{
			PrintHelp();
		}
	}

	cout << "Requested routes are: ";

	for(unsigned int index = 0; index < listOfRoutesToPrint.size(); index++)
	{
		cout << listOfRoutesToPrint[index];
		
		// If it is not the last route, need to put comma separator.
		if (index != (listOfRoutesToPrint.size() - 1))
		{
			cout << ", ";
		}
	}
	cout << endl;

	return 0;
}
