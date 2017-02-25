from structures import *

def read_input(filename):
    # open file in reading mode
    f = open(filename, 'r')

    # get base data
    videos_nb, endpoints_nb, requests_desc_nb, cache_servers_nb, cache_servers_size = [int(x) for x in f.readline().split()]

    # get detailed data
    videos, endpoints, cache_servers = [], [], []
    videos_sizes = [int(x) for x in f.readline().split()]
    # videos
    for i in range(videos_nb):
        videos.append(Video(i, videos_sizes[i]))
    # cache servers
    for i in range(cache_servers_nb):
        cache_servers.append(CacheServer(i, cache_servers_size))
    # endpoints
    for i in range(endpoints_nb):
        datacenter_latency, caches_nb = [int(x) for x in f.readline().split()]
        cache_servers_latencies = []
        for j in range(caches_nb):
            cache_uid, cache_latency = [int(x) for x in f.readline().split()]
            cache_servers_latencies.append((cache_servers[cache_uid], cache_latency))

        e = Endpoint(i, datacenter_latency, cache_servers_latencies)
        endpoints.append(e)
        for cache, _ in cache_servers_latencies:
            cache.connected_endpoints.append(e)
    # video requests
    for i in range(requests_desc_nb):
        video_uid, endpoint_uid, request_nb = [int(x) for x in f.readline().split()]
        endpoints[endpoint_uid].video_requests.append((video_uid, request_nb))

    # close file
    f.close()

    # return data
    return videos, cache_servers
