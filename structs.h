
typedef struct _video {
	int uid;
	int size;
} Video

typedef struct _endpoint {
	int serverLatence;
	int nbOfCacheServers;
	int* cacheServersLatences;
} Endpoint

typedef struct _server {
	int uid;
	int size;
	int cache;
} Video
