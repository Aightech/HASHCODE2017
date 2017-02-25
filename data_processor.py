from structures import VideoWeight


def compute_video_lists(cache_servers, videos):
    # remember cache servers size
    cache_servers_size = cache_servers[0].size

    # go through cache servers
    for i in range(len(cache_servers)):
        for endpoint in cache_servers[i].connected_endpoints:
            latency_difference = endpoint.datacenter_latency - endpoint.cache_server_latencies[i][1]
            for video_uid, request_nb in endpoint.video_requests:
                weight = latency_difference * request_nb
                cache_servers[i].video_weights.append(VideoWeight(videos[video_uid], weight))

        # sort video weight in descending order
        cache_servers[i].video_weights.sort(reverse=True)

        # select best videos
        free_memory = cache_servers_size
        j = 0
        while j < len(cache_servers[i].video_weights) and free_memory - cache_servers[i].video_weights[j].video.size > 0:
            free_memory -= cache_servers[i].video_weights[j].video.size
            cache_servers[i].video_list.append(cache_servers[i].video_weights[j].video.uid)
            j += 1
