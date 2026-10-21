# Apache License 2.0

import ostk.io as io

URL = io.URL
Response = io.ip.tcp.http.Response
StatusCode = Response.StatusCode


def test_http_response():
    enum_members = Response.StatusCode.__members__

    list_keys = [
        "Continue",
        "SwitchingProtocols",
        "Processing",
        "EarlyHints",
        "Ok",
        "Created",
        "Accepted",
        "NonAuthoritativeInformation",
        "NoContent",
        "ResetContent",
        "PartialContent",
        "MultiStatus",
        "AlreadyReported",
        "IMUsed",
        "MultipleChoices",
        "MovedPermanently",
        "Found",
        "SeeOther",
        "NotModified",
        "UseProxy",
        "SwitchProxy",
        "TemporaryRedirect",
        "PermanentRedirect",
        "BadRequest",
        "Unauthorized",
        "PaymentRequired",
        "Forbidden",
        "NotFound",
        "MethodNotAllowed",
        "NotAcceptable",
        "ProxyAuthenticationRequired",
        "RequestTimeout",
        "Conflict",
        "Gone",
        "LengthRequired",
        "PreconditionFailed",
        "PayloadTooLarge",
        "URITooLong",
        "UnsupportedMediaType",
        "RangeNotSatisfiable",
        "ExpectationFailed",
        "ImATeapot",
        "MisdirectedRequest",
        "UnprocessableEntity",
        "Locked",
        "FailedDependency",
        "UpgradeRequired",
        "PreconditionRequired",
        "TooManyRequests",
        "RequestHeaderFieldsTooLarge",
        "UnavailableForLegalReasons",
        "InternalServerError",
        "NotImplemented",
        "BadGateway",
        "ServiceUnavailable",
        "GatewayTimeout",
        "HTTPVersionNotSupported",
        "VariantAlsoNegotiates",
        "InsufficientStorage",
        "LoopDetected",
        "NotExtended",
        "NetworkAuthenticationRequire",
    ]

    list_values = [
        StatusCode.Continue,
        StatusCode.SwitchingProtocols,
        StatusCode.Processing,
        StatusCode.EarlyHints,
        StatusCode.Ok,
        StatusCode.Created,
        StatusCode.Accepted,
        StatusCode.NonAuthoritativeInformation,
        StatusCode.NoContent,
        StatusCode.ResetContent,
        StatusCode.PartialContent,
        StatusCode.MultiStatus,
        StatusCode.AlreadyReported,
        StatusCode.IMUsed,
        StatusCode.MultipleChoices,
        StatusCode.MovedPermanently,
        StatusCode.Found,
        StatusCode.SeeOther,
        StatusCode.NotModified,
        StatusCode.UseProxy,
        StatusCode.SwitchProxy,
        StatusCode.TemporaryRedirect,
        StatusCode.PermanentRedirect,
        StatusCode.BadRequest,
        StatusCode.Unauthorized,
        StatusCode.PaymentRequired,
        StatusCode.Forbidden,
        StatusCode.NotFound,
        StatusCode.MethodNotAllowed,
        StatusCode.NotAcceptable,
        StatusCode.ProxyAuthenticationRequired,
        StatusCode.RequestTimeout,
        StatusCode.Conflict,
        StatusCode.Gone,
        StatusCode.LengthRequired,
        StatusCode.PreconditionFailed,
        StatusCode.PayloadTooLarge,
        StatusCode.URITooLong,
        StatusCode.UnsupportedMediaType,
        StatusCode.RangeNotSatisfiable,
        StatusCode.ExpectationFailed,
        StatusCode.ImATeapot,
        StatusCode.MisdirectedRequest,
        StatusCode.UnprocessableEntity,
        StatusCode.Locked,
        StatusCode.FailedDependency,
        StatusCode.UpgradeRequired,
        StatusCode.PreconditionRequired,
        StatusCode.TooManyRequests,
        StatusCode.RequestHeaderFieldsTooLarge,
        StatusCode.UnavailableForLegalReasons,
        StatusCode.InternalServerError,
        StatusCode.NotImplemented,
        StatusCode.BadGateway,
        StatusCode.ServiceUnavailable,
        StatusCode.GatewayTimeout,
        StatusCode.HTTPVersionNotSupported,
        StatusCode.VariantAlsoNegotiates,
        StatusCode.InsufficientStorage,
        StatusCode.LoopDetected,
        StatusCode.NotExtended,
        StatusCode.NetworkAuthenticationRequire,
    ]

    assert list(enum_members.keys()) == list_keys
    assert list(enum_members.values()) == list_values

    responses = []
    for i in range(len(list_values)):
        statuscode = list_values[i]
        response = Response(statuscode, f"body{i}")
        assert isinstance(response, Response)
        responses.append(response)

        assert Response.string_from_status_code(statuscode) == list_keys[i]

    response_1 = responses[1]
    response_2 = responses[2]
    response_3 = responses[3]
    response_4 = responses[4]

    assert response_1.get_body() == "body1"
    assert response_2.get_body() == "body2"
    assert response_3.get_body() == "body3"

    assert response_1.is_ok() is False
    assert response_2.is_ok() is False
    assert response_3.is_ok() is False

    assert response_1.get_status_code() == StatusCode.SwitchingProtocols
    assert response_2.get_status_code() == StatusCode.Processing
    assert response_3.get_status_code() == StatusCode.EarlyHints

    assert response_4.is_ok() is True
    assert response_4.get_status_code() == StatusCode.Ok
    assert response_4.get_body() == "body4"
