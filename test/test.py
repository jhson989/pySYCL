import pySYCL

device = pySYCL.Device("gpu")
queue = pySYCL.Queue(device)