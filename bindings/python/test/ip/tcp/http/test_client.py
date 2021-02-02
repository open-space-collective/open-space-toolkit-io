################################################################################################################################################################

# @project        Open Space Toolkit ▸ I/O
# @file           bindings/python/test/ip/tcp/http/test_client.py
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

import pytest

import ostk.io as io

################################################################################################################################################################

URL = io.URL
Request = io.ip.tcp.http.Request
Response = io.ip.tcp.http.Response
Client = io.ip.tcp.http.Client

################################################################################################################################################################

def test_http_client ():

    response = Client.get(URL.parse("https://www.google.com"))

    assert response is not None
    assert response.is_defined() is True
    assert response.is_ok() is True
    assert response.get_status_code() == Response.StatusCode.Ok

    # response = Client.send()

    # response = Client.fetch()

    # response = Client.list()

################################################################################################################################################################
