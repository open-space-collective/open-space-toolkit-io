# import imp

# imp.load_dynamic('libssl', '/usr/lib/x86_64-linux-gnu/libssl.so.1.1')

import os

# os.environ['LD_LIBRARY_PATH'] = '/usr/lib/x86_64-linux-gnu'
# os.environ['PYTHONHOME'] = '/usr/lib/x86_64-linux-gnu'
# os.environ['PYTHONPATH'] = '/usr/lib/x86_64-linux-gnu'
# os.environ['RUN_LD_PATH'] = '/usr/lib/x86_64-linux-gnu'

print(os.environ)

import Library.Core as Core

Integer = Core.Types.Integer

a = Integer(123)

# print(a)

from ctypes.util import find_library

print(find_library('ssl'))

import Library.IO as IO

URL = IO.URL
Client = IO.IP.TCP.HTTP.Client

url = URL.Parse('https://www.google.com')

response = Client.Get(url)

print(response.getStatusCode())