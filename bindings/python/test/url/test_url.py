################################################################################################################################################################

# @project        Open Space Toolkit ▸ I/O
# @file           bindings/python/test/url/test_url.py
# @author         Remy Derollez <remy@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

import pytest

import ostk.io as io

from ostk.core.types import String

################################################################################################################################################################

URL = io.URL

################################################################################################################################################################

def test_url_constructors ():

    # default constructor
    scheme = 'https'
    host = 'domain.org'
    path = '/path/to/page'
    port = 443
    user = 'user'
    password = 'password'
    query = URL.Query.undefined()
    fragment = 'fragment'
    url = URL(scheme, host, path, port, user, password, query, fragment)
    assert isinstance(url, URL)

    # undefined url constructor
    url = URL.undefined()
    assert isinstance(url, URL)

    # parsing url constructor
    url = URL.parse('https://www.google.com')
    assert isinstance(url, URL)

def test_url_getter_functions ():

    scheme = 'https'
    host = 'domain.org'
    path = '/path/to/page'
    port = 443
    user = 'user'
    password = 'password'
    query = URL.Query.undefined()
    fragment = 'fragment'
    url = URL(scheme, host, path, port, user, password, query, fragment)

    assert url.get_scheme() == scheme
    assert url.get_host() == host
    assert url.get_path() == path
    assert url.get_port() == port
    assert url.get_user() == user
    assert url.get_password() == password
    assert url.get_query() == query
    assert url.get_fragment() == fragment

def test_url_setter_functions ():

    url = URL.parse('https://www.google.com')

    url.set_scheme('http')
    url.set_host('youtube.com')
    url.set_path('/path/to/page')
    url.set_port(443)
    url.set_user('Bob')
    url.set_password('Sponge')
    url.set_query(URL.Query.undefined())
    url.set_fragment('frag')

    assert url.get_scheme() == 'http'
    assert url.get_host() == 'youtube.com'
    assert url.get_path() == '/path/to/page'
    assert url.get_port() == 443
    assert url.get_user() == 'Bob'
    assert url.get_password() == 'Sponge'
    assert url.get_query().is_defined() is False
    assert url.get_fragment() == 'frag'

def test_url_comparators ():

    url_1 = URL.parse('https://www.google.com')
    url_2 = URL.parse('https://www.youtube.com')

    assert url_1 == url_1
    assert url_1 != url_2

def test_url_to_string ():

    url = URL.parse('https://www.google.com')

    assert isinstance(url.to_string(), String)
    assert url.to_string() == 'https://www.google.com'
    assert url.to_string(False) == url.to_string()
    # assert url.to_string(True) == 'https://%20www.google.com'

def test_url_operators ():

    url_1 = URL.parse('https://www.google.com')
    url_2 = url_1 + '/stuff'

    assert url_2.to_string() == 'https://www.google.com/stuff'
    assert isinstance(url_2, URL)

def test_url_query ():

    parameter_1 = URL.Query.Parameter('name1', 'value1')
    parameter_2 = URL.Query.Parameter('name2', 'value2')

    list_parameters = [parameter_1, parameter_2, parameter_1, parameter_2]
    tuple_parameters = (parameter_1, parameter_2)

    assert parameter_1 == parameter_1
    assert parameter_1 != parameter_2
    assert parameter_1.is_defined()
    assert parameter_2.is_defined()

    assert parameter_1.get_name() == 'name1'
    assert parameter_1.get_value() == 'value1'

    assert parameter_2.get_name() == 'name2'
    assert parameter_2.get_value() == 'value2'

    query_1 = URL.Query(list_parameters)
    query_2 = URL.Query(tuple_parameters)
    query_3 = URL.Query((parameter_1,))

    assert isinstance(query_1, URL.Query)
    assert isinstance(query_2, URL.Query)
    assert isinstance(query_3, URL.Query)

    assert query_1.is_defined()
    assert query_2.is_defined()
    assert query_3.is_defined()
    assert URL.Query.undefined().is_defined() is False

    assert query_1.has_parameter_with_name('name1')
    assert query_1.has_parameter_with_name('name2')
    assert query_2.has_parameter_with_name('name1')
    assert query_2.has_parameter_with_name('name2')
    assert query_3.has_parameter_with_name('name1') is True
    assert query_3.has_parameter_with_name('name2') is False

    assert query_1.to_string() == 'name1=value1&name2=value2&name1=value1&name2=value2'
    assert query_2.to_string() == 'name1=value1&name2=value2'
    assert query_3.to_string() == 'name1=value1'

    query_3.add_parameter(parameter_2)
    assert query_3.to_string() == 'name1=value1&name2=value2'

    assert query_3 == query_2
    assert query_3 != query_1
    assert query_2 != query_1

    param_1 = query_1.get_parameter_with_name('name1')
    param_2 = query_2.get_parameter_with_name('name2')

    assert isinstance(param_1, String)
    assert isinstance(param_2, String)
    assert param_1 == 'value1'
    assert param_2 == 'value2'

################################################################################################################################################################
