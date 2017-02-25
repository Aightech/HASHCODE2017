def generate_output(filename, cache_servers):
    # open file in writing mode
    f = open(filename, 'w')

    # get number of used cache servers
    f.write(str(len(cache_servers)) + '\n')

    # go through cache servers, write list of videos uid
    for cache_server in cache_servers[:-1]:
        f.write(' '.join([str(x) for x in cache_server.video_list]) + '\n')
    # (treat last line in separate case for the linebreak problem)
    f.write(' '.join([str(x) for x in cache_server.video_list]))

    # close file
    f.close()
