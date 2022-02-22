import pySYCL

'''
Vector addition example with a single GPU
'''

##########################################################################
### Device setup
##########################################################################
device = pySYCL.Device("gpu")
queue = pySYCL.Queue(device)
pySYCL.printProperties(queue)


##########################################################################
### Data initialization
##########################################################################
N = 2**28

## Input
dataIn = range(0, N)
gpuIn = pySYCL.mallocDevice(N, queue)

## Output
dataOut = [0 for _ in range(0, N)]
gpuOut = pySYCL.mallocDevice(N, queue)


pySYCL.free(gpuIn, queue)
pySYCL.free(gpuOut, queue)


###