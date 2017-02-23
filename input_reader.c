#include "structs.h"
#include "input_reader.h"

void read_main_data(char* filename, int* videos_nb, int* cache_servers_nb, int* endpoints_nb, int* requests_desc_nb, int* cache_size) {
	FILE *f = fopen(filename, "r");
	
	// read input nbs
	fscanf(f, "%d %d %d %d %d", videos_nb, endpoints_nb, requests_desc_nb, cache_servers_nb, cache_size);
	
	fclose(f);
}

void read_input(char* filename, Video** videos, CacheServer** cache_servers, Endpoint** endpoints, int videos_nb, int cache_servers_nb, int endpoints_nb, int requests_desc_nb, int cache_size) {
	FILE *f = fopen(filename, "r");

	// pass first line
	char ignore[255];
	fgets(ignore, 255, f);
	
	// fill in video data
	int i;
	for (i = 0; i < videos_nb; i++) {
		Video* v = (Video*)malloc(sizeof(Video));
		v->uid = i;
		fscanf(f, "%d", &(v->size));
		videos[i] = v;
	}
	
	// fill in cache servers data
	for (i = 0; i < cache_servers_nb; i++) {
		CacheServer* c = (CacheServer*)malloc(sizeof(CacheServer));
		c->uid = i;
		c->size = cache_size;
		c->connectedEndpoints = (Endpoint**)calloc(endpoints_nb, sizeof(Endpoint));
		cache_servers[i] = c;
	}
	
	// fill in endpoints data
	for (i = 0; i < endpoints_nb; i++) {
		Endpoint* e = (Endpoint*)malloc(sizeof(Endpoint));
		e->uid = i;
		fscanf(f, "%d %d", &(e->datacenterLatency), &(e->nbOfCacheServers));
		e->cacheServersLatencies = (int*)malloc(sizeof(int) * cache_servers_nb);
		int j = 0;
		for (j = 0; j < cache_servers_nb; j++) {
			e->cacheServersLatencies[j] = -1;
		}
		for (j = 0; j < e->nbOfCacheServers; j++) {
			int index, value;
			fscanf(f, "%d %d", &index, &value);
			e->cacheServersLatencies[index] = value;
			cache_servers[index]->connectedEndpoints[e->uid] = e;
		}
		e->video_requests = (int*)calloc(videos_nb, sizeof(int));
		endpoints[i] = e;
	}
	
	// get request descriptions data
	for (i = 0; i < requests_desc_nb; i++) {
		int endpoint, video, requests_nb;
		fscanf(f, "%d %d %d", &video, &endpoint, &requests_nb);
		endpoints[endpoint]->video_requests[video] = requests_nb;
	}
	
	fclose(f);
}

void print_video(Video* v) {
	printf("Video #%d: %dMB\n", v->uid, v->size);
}

void print_endpoint(Endpoint* e, int videos_nb) {
	printf("Endpoint #%d: %dms datacenter latency, connected to %d cache servers:\n", e->uid, e->datacenterLatency, e->nbOfCacheServers);
	int i;
	for (i = 0; i < e->nbOfCacheServers; i++) {
		printf("Cache %d: latency = %dms\n", i, e->cacheServersLatencies[i]);
	}
	for (i = 0; i < videos_nb; i++) {
		if (e->video_requests[i] == 0) continue;
		printf("%d video requests from video %d to endpoint %d\n", e->video_requests[i], i, e->uid);
	}
}

void print_cache_server(CacheServer* c) {
	printf("Cache server #%d: %dMB\n", c->uid, c->size);
}
