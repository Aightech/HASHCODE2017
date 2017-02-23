#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "optimization_computation.h"

void compute_video_weights(CacheServer** cache_servers, Video** videos, int videos_nb, int cache_servers_nb, int endpoints_nb) {
	int i, j, k;
	for (i = 0; i < cache_servers_nb; i++) {
		for (j = 0; j < endpoints_nb; j++) {
			// if it is in the connectedEndpoints list
			Endpoint* e = cache_servers[i]->connectedEndpoints[j];
			if (e != NULL) {
				int latencyDifference = e->datacenterLatency - e->cacheServersLatencies[i];
				for (k = 0; k < videos_nb; k++) {
					VideoWeight vw = cache_servers[i]->video_weights[k];
					vw.weight = e->video_requests[k] * latencyDifference;
					vw.video = videos[k];
					vw.ratio = vw.weight / vw.video->size;
					cache_servers[i]->video_weights[k] = vw;
				}
			}
		}
	}
}

void print_video_weights(CacheServer* cache_server, int videos_nb) {
	printf("Cache #%d, video weights:\n", cache_server->uid);
	int i;
	for (i = 0; i < videos_nb; i++) {
		printf("Video #%d (size: %dMB): weight = %d, ratio = %d\n", cache_server->video_weights[i].video->uid, cache_server->video_weights[i].video->size, cache_server->video_weights[i].weight, cache_server->video_weights[i].ratio);
	}
}