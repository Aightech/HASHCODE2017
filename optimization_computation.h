#ifndef __OPT_COMPUT_H__
#define __OPT_COMPUT_H__

void compute_video_weights(CacheServer** cache_servers, Video** videos, int videos_nb, int cache_servers_nb, int endpoints_nb);

void print_video_weights(CacheServer* cache_server, int videos_nb);

#endif
