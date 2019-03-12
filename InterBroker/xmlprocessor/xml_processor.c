// gcc -Wall -lxml2 -I/usr/include/libxml2 -o ex1 ex1.c

#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>

int read(int argc, char **argv)
{
	xmlDoc *document;
	xmlNode *root, *first_child, *node;
	char *filename;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename.xml\n", argv[0]);
		return 1;
	}
	filename = argv[1];

	document = xmlReadFile(filename, NULL, 0);
	root = xmlDocGetRootElement(document);
	fprintf(stdout, "Root is <%s> (%i)\n", root->name, root->type);
	first_child = root->children;

	for (node = first_child; node; node = node->next)
	{
		fprintf(stdout, "\t Child is <%s> (%i)\n", node->name, node->type);
	}
	fprintf(stdout, "...\n");
	return 0;
}