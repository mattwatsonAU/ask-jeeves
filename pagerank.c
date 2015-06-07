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
	//calculate initial P value
	double init = 1 / (double)npages;
	//printf("%f\n", init);

	//create P value arrays
	double curr[npages];
	//double prev[npages];

	//fill the current p value array with the intial p value 'init'
	for(int i=0; i<npages; i++)
	{
		curr[i] = init;
	}

	//double c = (1 - dampener)/npages;
	//double e2 = EPSILON * EPSILON; 
	/* Initialise convergance as 1 so while loop begins */
	//double convergance = 1;	
	//double pprev;

	// while (convergance > e2) 
	// {
	// 	// copy current P values into previous as current will be updated and overwritten upon iteration
	// 	for (int i = 0; i < npages; i++)
	// 	{
	// 		prev[i] = curr[i];
	// 	}
	// }	







	//convert the linked list to arrays for performance boost
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

	//print the result
	//printf("%s %.4lf\n");
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
