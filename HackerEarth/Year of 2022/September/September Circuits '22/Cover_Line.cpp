//90 points

/*
    Competition: HackerEarth
    Problem: Cover Line
    Author: Ron Prasad
    Date: 09/20/2022
*/
 
#include <iostream>
#include <map>

//Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
	std::ios::sync_with_stdio (NULL);
	std::cin.tie (nullptr);
 
	int64_t N, M, Left, Right, Weight;
	std::cin >> N;
	
	std::cin >> M;
	
	std::multimap <int64_t, int64_t> CoverLineMM;
	while (M--)
	{
	    std::cin >> Left >> Right >> Weight;
	    
	    if (Right == N)
	    {
	        CoverLineMM.insert (std::pair <int64_t, int64_t> (Left, (Right + Weight)));
	    }
	}	
	
	int64_t MinimizedMaximumWeight, Smallest;
	for (std::multimap <int64_t, int64_t>::iterator itr = CoverLineMM.begin(); itr != CoverLineMM.end(); ++itr)
    {
        Smallest = (*itr).second;
    }
    
    MinimizedMaximumWeight = (Smallest - Right);
    
    //Debugging:
    //std::cout << MinimizedMaximumWeight << '\n';    
    
    if (CoverLineMM.size() == 0)
    {
        std::cout << "-1" << '\n';
    }
    else
    {
        std::cout << MinimizedMaximumWeight << '\n';
    }
    
 	//Debugging:
    // std::cout << "The Map holds: " << '\n';
    // for (auto itr = CoverLineMM.begin(); itr != CoverLineMM.end(); ++itr)
    // {
    //     std::cout << "[" << itr -> first << ", " << " " << itr -> second << "] " << '\n';
    // }
    
    //Clear Multimap:    
    CoverLineMM.clear();
    
	return 0;
}
