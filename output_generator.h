#ifndef __OUTPUT_GENERATOR_H__
#define __OUTPUT_GENERATOR_H__

int count_used_cache_servers(int cache_servers_nb, CacheServer** cache_servers);
		
void generate_output(char* outputname, int cache_servers_nb, CacheServer** cache_servers, int count);

#endif
