# coding=utf-8

################################################################################################################################################################

# @project        Library/IO
# @file           LibraryIOPy/IP.test.py
# @author         Lucas Brémond <lucas.bremond@gmail.com>
# @license        Apache License 2.0

################################################################################################################################################################

# IP

import Library.Core as Core
import LibraryIOPy as IO

URL = IO.URL
Request = IO.IP.TCP.HTTP.Request
Response = IO.IP.TCP.HTTP.Response
Client = IO.IP.TCP.HTTP.Client

response = Client.Get(URL.Parse("https://www.google.com"))

################################################################################################################################################################