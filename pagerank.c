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
	//node* inode = list;
	//calculate the initial P value - that is, divide 1 by the number of pages
	double initpvalue = 1 / (double)npages;
	
	//check this worked and print the initial P value
	//printf("%f\n", initpvalue);

	//create P value arrays
	double curr[npages];
	double prev[npages];

	//fill the current p value array with the intial p value 'initpvalue'
	for(int i=0; i<npages; i++)
	{
		curr[i] = initpvalue;
	}

	double c = (1 - dampener)/npages;
	double e2 = EPSILON * EPSILON;
	//printf("%f\n", e2);
	
	//Set convergance value to 1 to ensure the while loop starts
	double convergance = 1;

	//Declare a variable pprev which acts as a temp P value for updating
	double pprev;

	while (convergance > e2) 
	{
		//Copy current P values into previous as current will be updated and overwritten upon iteration
		for (int counter = 0; counter < npages; counter++)
		{
			prev[counter] = curr[counter];
		}

		//Loop through each page
		for (node *inlink = list; inlink != NULL; inlink = inlink->next)
		{
			pprev=0.0;

			//Check if there are inlinks, then loop
			if(inlink->page->inlinks != NULL)
			{
				for(node* in=inlink->page->inlinks; in != NULL; in = in->next)
				{
					//Calculate the new P value
					pprev += prev[in->page->index] / in->page->noutlinks;
					//printf("%f\n", pprev);
				}
			}
			//Save the new calculated P value to the current array
			curr[inlink->page->index] = c + dampener*pprev;
		}
		//Calculate the new convergance (epsilon)
		convergance = 0.0;
		for (int i = 0; i < npages; i++)
		{
			//printf("%s %f\n","Current: ", curr[i]);
			//printf("%s %f\n","Previous: ", prev[i]);
			double difference = curr[i] - prev[i];
			convergance += (difference*difference);
		}
		//printf("%f\n", convergance);
	}
	//print the result
	for (node *inlink = list; inlink != NULL; inlink = inlink->next)
	{
		printf("%s %.4lf\n", inlink->page->name, curr[inlink->page->index]);
	}
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
