# Apache License 2.0

import ostk.io as io

URL = io.URL
Request = io.ip.tcp.http.Request
Method = Request.Method


def test_http_request():
    enum_members = Request.Method.__members__

    list_keys = [
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

    get_request = requests[0]
    post_request = requests[2]

    converted_methods = []
    for method_value in list_values:
        converted_methods.append(Request.string_from_method(method_value))
    assert converted_methods == list_keys

    assert get_request.get_method() == Method.Get
    assert post_request.get_method() == Method.Post

    assert get_request.get_url() == url
    assert post_request.get_url() == url

    assert get_request.get_body() == "body"
    assert post_request.get_body() == "body"

    new_get_request = Request.get(url)

    assert isinstance(new_get_request, Request)
    assert new_get_request.get_method() == Method.Get
    assert new_get_request.get_url() == url
    assert new_get_request.get_body() == ""
