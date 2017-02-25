class Video:
    def __init__(self, uid, size):
        self.uid = uid
        self.size = size

    def __str__(self):
        return 'Video #%d: %dMB' % (self.uid, self.size)


class VideoWeight:
    def __init__(self, video, weight):
        self.video = video
        self.weight = weight
        self.ratio = self.weight / self.video.size

    def __le__(self, other):
        return self.weight <= other.weight

    def __lt__(self, other):
        return self.weight < other.weight

    def __ge__(self, other):
        return self.weight >= other.weight

    def __gt__(self, other):
        return self.weight > other.weight

    def __str__(self):
        return 'VideoWeight: video #%d (%dMB), weight = %d > ratio = %d' % (self.video.uid,
                                                                            self.video.size,
                                                                            self.weight,
                                                                            self.ratio)


class Endpoint:
    def __init__(self, uid, datacenter_latency, cache_server_latencies):
        self.uid = uid
        self.datacenter_latency = datacenter_latency
        self.cache_server_latencies = cache_server_latencies
        self.video_requests = []

    def __str__(self):
        output = 'Endpoint #%d, datacenter latency of %dms, connected to %d caches:\n' % (self.uid,
                                                                                        self.datacenter_latency,
                                                                                        len(self.cache_server_latencies))
        for cache, latency in self.cache_server_latencies:
            output += 'Cache #%d: latency = %dms\n' % (cache.uid, latency)

        return output


class CacheServer:
    def __init__(self, uid, size):
        self.uid = uid
        self.size = size
        self.connected_endpoints = []
        self.video_weights = []
        self.video_list = []

    def __str__(self):
        return 'Cache server #%d (%dMB)' % (self.uid, self.size)
