#ifndef __READ_INPUT_H__
#define __READ_INPUT_H__

#include <stdlib.h>
#include <stdio.h>

void read_main_data(char* filename, int* videos_nb, int* cache_servers_nb, int* endpoints_nb, int* requests_desc_nb, int* cache_size);

void read_input(char* filename, Video** videos, CacheServer** cache_servers, Endpoint** endpoints, int videos_nb, int cache_servers_nb, int endpoints_nb, int requests_desc_nb, int cache_size);

void print_video(Video* v);
void print_endpoint(Endpoint* e, int videos_nb);
void print_cache_server(CacheServer* c);

#endif
