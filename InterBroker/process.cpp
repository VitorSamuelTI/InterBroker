#include "xmlprocessor/rapidxml.hpp"
#include "xmlprocessor/rapidxml_utils.hpp"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;
using namespace rapidxml;

extern "C" int xmlProcess(char*);


int xmlProcess(char* message)
{
	string str(message);

	//printf(message);

	vector<char> xml_copy(str.begin(), str.end());
	xml_copy.push_back('\0');

	xml_document<> doc;
	doc.parse<parse_declaration_node | parse_no_data_nodes>(&xml_copy[0]);

	//Get first Node example
	//cout << "Name of my first node is: " << doc.first_node()->name() << "\n";

	//Get first attribute example
	//string firstAttibure = doc.first_node()->first_attribute()->value();
	//cout << "Att1: " << firstAttibure << endl;


	//Iteration Nodes Example
	rapidxml::xml_node<>* node = doc.first_node();

	for(node = node -> first_node(); node != NULL; node = node -> next_sibling()){

      if(node->type() == node_element) //chek node type
      {
        cout<<node -> name() <<" 's value is : "<<node->value() <<   endl; //get node value
        
      }
    }

	return 0;
}

