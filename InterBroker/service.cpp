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
#include <curl/curl.h>

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

        stringstream ss;
        string message;

        while (it != params.end())
        {
            // Accessing KEY from element pointed by it.
            string word = it->first;

            // Accessing VALUE from element pointed by it.
            string count = it->second;

            cout << word << " :: " << count << endl;
            ss << "<" << word << ">" << count << "</" << word << ">";

            // Increment the Iterator to point to next entry
            it++;
        }

        message = ss.str();
        cout << message;
        postMessage(message);
    }

    int postMessage(string message)
    {

        CURL *curl;
        CURLcode res;

        /* In windows, this will init the winsock stuff */
        curl_global_init(CURL_GLOBAL_ALL);

        /* get a curl handle */
        curl = curl_easy_init();
        if (curl)
        {
            /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */
            curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
            /* Now specify the POST data */
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");

            /* Perform the request, res will get the return code */
            res = curl_easy_perform(curl);
            /* Check for errors */
            if (res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res));

            /* always cleanup */
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
        return 0;
    }
};

} 
