//Accepted!

/*
    Competition: Codeforces Round #835 (Div. 4)
    Problem: "B: Atilla's Favorite Number"
    Date: 11/22/2022
*/

// Header Files:
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cassert>
#include <algorithm>

//Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
	std::ios::sync_with_stdio (NULL);
	std::cin.tie (nullptr);
	
	int64_t t, n;
	std::cin >> t;
	
	std::map <int64_t, char> AFP;
	AFP =   {{1, 'a'}, 
		    {2, 'b'},
		    {3, 'c'},
		   	{4, 'd'},
		   	{5, 'e'},
		   	{6, 'f'},
		   	{7, 'g'},
		   	{8, 'h'},
		   	{9, 'i'},
		   	{10, 'j'},
		   	{11, 'k'},
		   	{12, 'l'},
		    {13, 'm'},
		   	{14, 'n'},
		   	{15, 'o'},
		   	{16, 'p'},
		   	{17, 'q'},
		   	{18, 'r'},
		   	{19, 's'},
		   	{20, 't'},
		   	{21, 'u'},
		   	{22, 'v'},
		   	{23, 'w'},
		   	{24, 'x'},
		   	{25, 'y'},
		    {26, 'z'}};

    std::vector <int64_t> StoredValues;
	while (t--)
	{
		std::cin >> n;
		
		std::string Atilla;
		std::cin >> Atilla;
		
		for (int64_t i = 0; i < n; ++i)
		{
		    char Find = (Atilla[i]);
		    
			for (auto itr = AFP.begin(); itr != AFP.end(); ++itr)
			{
			    if (itr -> second == Find)
		            StoredValues.push_back (itr -> first);
			}  
		}
		
		int64_t MaxValue = *std::max_element(StoredValues.begin(), StoredValues.end());
		std::cout << MaxValue << '\n';
		
		// Clear Vector:
		StoredValues.clear();
	}
	
	return 0;
}
