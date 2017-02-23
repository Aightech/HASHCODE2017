
typedef struct _video {
	int uid;
	int size;
} Video;

typedef struct _videoWeight {
	Video* video;
	int weight;
	int ratio;
} VideoWeight;

typedef struct _endpoint {
	int uid;
	int datacenterLatency;
	int nbOfCacheServers;
	int* cacheServersLatencies;
	int* video_requests;
} Endpoint;

typedef struct _cacheServer {
	int uid;
	int size;
	Endpoint** connectedEndpoints;
	VideoWeight* video_weights;
	int listVideo_nb;
	Video* listVideo;
} CacheServer;
