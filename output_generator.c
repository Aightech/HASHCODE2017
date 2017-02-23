#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "output_generator.h"

int count_used_cache_servers(int cache_servers_nb, CacheServer** cache_servers){
	int i;
	int count=0;
	for (i=0;i<cache_servers_nb;i++){
		if (cache_servers[i]->listVideo!=NULL)
			count++;
	}
	return count;
}
		

void generate_output(char* outputname, int cache_servers_nb, CacheServer** cache_servers, int count) {
	FILE *f = fopen(outputname, "r");
	
	fprintf(f, "%d\n", count);
	int i,j;
	for (i=0;i<cache_servers_nb;i++){
		if (cache_servers_nb->listVideo_nb!=0){
			fprintf(f, "%d ", i);
			for (j=0;j<cache_servers_nb->listVideo_nb;j++){
				fprintf(f, "%d ",cache_servers_nb->listVideo_nb[j]->uid );
				}
			fprintf(f, "\n");	
			}
		}
		
	fclose(f);
	}
	
	


