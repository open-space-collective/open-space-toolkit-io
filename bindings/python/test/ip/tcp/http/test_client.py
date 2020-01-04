################################################################################################################################################################

# @project        Open Space Toolkit ▸ I/O
# @file           bindings/python/test/ip/tcp/http/test_client.py
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

import Library.IO as IO

################################################################################################################################################################

URL = IO.URL
Request = IO.IP.TCP.HTTP.Request
Response = IO.IP.TCP.HTTP.Response
Client = IO.IP.TCP.HTTP.Client

################################################################################################################################################################

def test_client ():

    response = Client.Get(URL.Parse("https://www.google.com"))

    assert response is not None

    assert response.isDefined() is True
    assert response.isOk() is True
    assert response.getStatusCode() == 200

################################################################################################################################################################
