# Apache License 2.0

import pytest

import ostk.io as io
from ostk.core.filesystem import Directory, File, Path

URL = io.URL
Request = io.ip.tcp.http.Request
Response = io.ip.tcp.http.Response
Client = io.ip.tcp.http.Client


def test_http_client_get_success():
    url = URL.parse("https://www.google.com")

    response = Client.get(url)

    assert response is not None
    assert response.is_defined() is True
    assert response.is_ok() is True
    assert response.get_status_code() == Response.StatusCode.Ok


def test_http_client_send_success():
    url = URL.parse("https://www.google.com")

    request = Request(Request.Method.Get, url, "")
    response = Client.send(request)

    assert response is not None
    assert response.is_defined() is True
    assert response.is_ok() is True
    assert response.get_status_code() == Response.StatusCode.Ok


def test_http_client_fetch_success():
    url = URL.parse(
        "https://www.google.com/images/branding/googlelogo/2x/googlelogo_color_272x92dp.png"
    )
    directory = Directory.path(Path.parse("/tmp"))

    file_response = Client.fetch(url, directory)

    assert file_response is not None
    assert file_response.exists() is True


# def test_http_client_list_success():

# Disabling similar to the C++ test. The list takes about 1 minute to complete for some reason.

# url = URL.parse("ftp://naif.jpl.nasa.gov/pub/naif/generic_kernels/")
# file_input = File.path(Path.parse("/tmp/listing.txt"))
# response = Client.list(url, file_input, 3)

# assert response is not None
# assert response.is_defined() is True
# assert response.is_ok() is True
# assert response.get_status_code() == Response.StatusCode.Ok
