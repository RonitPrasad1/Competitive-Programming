//Accepted!

/*
    Competition: Codeforces Round #835 (Div. 4)
    Problem: "C: Advantage"
    Date: 11/22/2022
*/

// Header Files:
#include <iostream>
#include <vector>
#include <set>

//Driver Function:
auto main (int argc, const char** argv) -> decltype (0)
{
	std::ios::sync_with_stdio (NULL);
	std::cin.tie (nullptr);
	
	int64_t t, n;
	std::cin >> t;
	
	while (t--)
	{
		std::cin >> n;
		
		std::vector <int64_t> Strength;
		std::multiset <int64_t> Advantage;
		for (int64_t i = 0; i < n; ++i)
		{
		    int64_t x;
			std::cin >> x;
			Strength.push_back(x);
			
			Advantage.insert(x);
		}
	    
	   // std::cout << "Vector values are: ";
	   // for (auto i : Strength)
	   //     std::cout << i << " ";
	        
	   // std::cout << '\n';	   
	    
	   // std::cout << "Multiset values are: ";
	   // for (auto i : Advantage)
	   //     std::cout << i << " ";
	        
	    // std::cout << '\n';
	    
        for (int64_t i = 0; i < n; ++i)
        {
            Advantage.erase(Advantage.find(Strength[i]));
    		//for (std::multiset <int64_t>::reverse_iterator rItr = Advantage.rbegin(); rItr != Advantage.rend(); ++rItr)
    		//{
    		    //std::cout << (Strength[i] - (*rItr)) << " ";
    		//}
    		
    		int64_t ReverseValue = (*Advantage.rbegin());
			
		    std::cout << (Strength[i] - ReverseValue) << " ";
			
		    Advantage.insert(Strength[i]);
        }
		
		std::cout << '\n';
		
		// Clear Memory:
		Strength.clear();
		Advantage.clear();
	}
	
	return 0;
}
