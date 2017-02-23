#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "input_reader.h"
#include "optimization_computation.h"

int main() {
	// general variables
	Video** videos = NULL;
	CacheServer** cache_servers = NULL;
	Endpoint** endpoints = NULL;
	int videos_nb, cache_servers_nb, endpoints_nb, requests_desc_nb, cache_size;
	// file to load
	char* filename = "trending_today.in";

	// get the main data: the size of the different structures arrays
	read_main_data(filename, &videos_nb, &cache_servers_nb, &endpoints_nb, &requests_desc_nb, &cache_size);
	
	// allocate memory
	videos = (Video**)malloc(sizeof(Video*) * videos_nb);
	cache_servers = (CacheServer**)malloc(sizeof(CacheServer*) * cache_servers_nb);
	endpoints = (Endpoint**)malloc(sizeof(Endpoint*) * endpoints_nb);
	
	// get file data
	read_input(filename, videos, cache_servers, endpoints, videos_nb, cache_servers_nb, endpoints_nb, requests_desc_nb, cache_size);
	
	// compute all video weights
	compute_video_weights(cache_servers, videos, videos_nb, cache_servers_nb, endpoints_nb);
	
	return 1;
}