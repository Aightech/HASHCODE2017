# import resources
from input_reader import *
from data_processor import *
from output_generator import *
import time

# select working file
filename = 'kittens.in'
# prepare output file name
output_filename = filename.split('.')[0] + '_out.txt'

# get global process time for computation optimization purposes
global_start_time = time.time()

# get data set input
print(':: getting input', flush=True)
start_time = time.time()
videos, cache_servers = read_input(filename)
print(':: got input (%.2fs)' % (time.time() - start_time), flush=True)

# select the number of cache servers to treat
used_cache_servers = 5
# process data
print('-------------------', flush=True)
print(':: processing data', flush=True)
start_time = time.time()
compute_video_lists(cache_servers[:used_cache_servers], videos)
print(':: processed data (%.2fs)' % (time.time() - start_time), flush=True)

# create output data
print('-------------------', flush=True)
print(':: generating output', flush=True)
start_time = time.time()
generate_output(output_filename, cache_servers[:used_cache_servers])
print(':: generated output (%.2fs)' % (time.time() - start_time), flush=True)

print('\n-------------------', flush=True)
print('Global process time: %.2fs' % (time.time() - global_start_time), flush=True)
