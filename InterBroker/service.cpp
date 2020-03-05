#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

namespace services
{
class Service
{

public:
    string mapProcess(map<string, string> params)
    {
        // Create a map iterator and point to beginning of map
        map<string, string>::iterator it = params.begin();

        while (it != params.end())
        {
            // Accessing KEY from element pointed by it.
            string word = it->first;

            // Accessing VALUE from element pointed by it.
            string count = it->second;

            cout << word << " :: " << count << endl;

            // Increment the Iterator to point to next entry
            it++;
        }
    }
};

}
