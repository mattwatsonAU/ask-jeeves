#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <immintrin.h>

#include "pagerank.h"

void pagerank(node* list, int npages, int nedges, int nthreads, double dampener) 
{
	int outlink_count[npages];
	//int inlink_count[npages];
	int inlinks[npages];
	node* inode = list;

	for (int i=0; i < npages; i++)
	{
		outlink_count[i] = inode->page->noutlinks;
		printf("%s", "Outlink count: ");
		printf("%d\n", outlink_count[i]);
	}

	inode = list;

	for (int i = 0; i < nedges; )
	{
		for (node *inlink = inode->page->inlinks; inlink != NULL; inlink = inlink->next) 
		{
			inlinks[i] = inlink->page->index;
			printf("%s", "Inlinks: ");
			printf("%d\n", inlinks[i]);
			i++; 
		}

		inode = inode->next;
	}

	// for (int i = 0; i<nedges; i++)
	// {
	// 	printf("%s", "Inlinks: ");
	// 	printf("%d\n", inlinks[i]);
	// }

	// for (int i=0; i < npages; i++)
	// {
	// 	printf("%s", "Outlink count: ");
	// 	printf("%d\n", outlink_count[i]);
	// }

	/*
		TODO
		- implement this function
		- implement any other necessary functions
		- implement any other useful data structures
	*/
}

/*
######################################
### DO NOT MODIFY BELOW THIS POINT ###
######################################
*/

int main(int argc, char** argv) {

	/*
	######################################################
	### DO NOT MODIFY THE MAIN FUNCTION OR HEADER FILE ###
	######################################################
	*/

	config conf;

	init(&conf, argc, argv);

	node* list = conf.list;
	int npages = conf.npages;
	int nedges = conf.nedges;
	int nthreads = conf.nthreads;
	double dampener = conf.dampener;

	pagerank(list, npages, nedges, nthreads, dampener);

	release(list);

	return 0;
}
