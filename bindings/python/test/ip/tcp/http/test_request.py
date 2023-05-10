# Apache License 2.0

import pytest

import ostk.io as io

URL = io.URL
Request = io.ip.tcp.http.Request
Method = Request.Method


def test_http_request():
    enum_members = Request.Method.__members__

    list_keys = [
        "Undefined",
        "Get",
        "Head",
        "Post",
        "Put",
        "Delete",
        "Trace",
        "Options",
        "Connect",
        "Patch",
    ]

    list_values = [
        Method.Undefined,
        Method.Get,
        Method.Head,
        Method.Post,
        Method.Put,
        Method.Delete,
        Method.Trace,
        Method.Options,
        Method.Connect,
        Method.Patch,
    ]

    assert list(enum_members.keys()) == list_keys
    assert list(enum_members.values()) == list_values

    requests = []
    url = URL.parse("https://www.google.com")

    for request_method in list_values:
        request = Request(request_method, url, "body")
        assert isinstance(request, Request)
        requests.append(request)

    undef_request = requests[0]
    get_request = requests[1]
    post_request = requests[3]

    assert undef_request.is_defined() is False
    assert Request.undefined().is_defined() is False
    assert get_request.is_defined()
    assert post_request.is_defined()

    converted_methods = []
    for method_value in list_values:
        converted_methods.append(Request.string_from_method(method_value))
    assert converted_methods == list_keys

    assert get_request.get_method() == Method.Get
    assert post_request.get_method() == Method.Post

    with pytest.raises(RuntimeError):
        undef_request.get_method()

    assert get_request.get_url() == url
    assert post_request.get_url() == url

    with pytest.raises(RuntimeError):
        undef_request.get_url()

    assert get_request.get_body() == "body"
    assert post_request.get_body() == "body"

    with pytest.raises(RuntimeError):
        undef_request.get_body()

    new_get_request = Request.get(url)

    assert isinstance(new_get_request, Request)
    assert new_get_request.is_defined()
    assert new_get_request.get_method() == Method.Get
    assert new_get_request.get_url() == url
    assert new_get_request.get_body() == ""
