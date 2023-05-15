/// Apache License 2.0

#include <OpenSpaceToolkit/Core/Containers/Map.hpp>
#include <OpenSpaceToolkit/Core/Error.hpp>
#include <OpenSpaceToolkit/Core/Utilities.hpp>

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Request.hpp>

namespace ostk
{
namespace io
{
namespace ip
{
namespace tcp
{
namespace http
{

Request::Request(const Request::Method& aMethod, const URL& aUrl, const String& aBody)
    : method_(aMethod),
      url_(aUrl),
      body_(aBody)
{
}

std::ostream& operator<<(std::ostream& anOutputStream, const Request& aRequest)
{
    ostk::core::utils::Print::Header(anOutputStream, "Request");

    ostk::core::utils::Print::Line(anOutputStream) << "Method:" << Request::StringFromMethod(aRequest.method_);
    ostk::core::utils::Print::Line(anOutputStream)
        << "URL:" << (aRequest.url_.isDefined() ? aRequest.url_.toString() : "Undefined");
    ostk::core::utils::Print::Line(anOutputStream) << "Body:" << aRequest.body_;

    ostk::core::utils::Print::Footer(anOutputStream);

    return anOutputStream;
}

bool Request::isDefined() const
{
    return (method_ != Request::Method::Undefined) && url_.isDefined();
}

Request::Method Request::getMethod() const
{
    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Request");
    }

    return method_;
}

URL Request::getUrl() const
{
    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Request");
    }

    return url_;
}

String Request::getBody() const
{
    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Request");
    }

    return body_;
}

Request Request::Undefined()
{
    return {Request::Method::Undefined, URL::Undefined(), String::Empty()};
}

Request Request::Get(const URL& aUrl)
{
    return {Request::Method::Get, aUrl, String::Empty()};
}

String Request::StringFromMethod(const Request::Method& aMethod)
{
    using ostk::core::ctnr::Map;

    static const Map<Request::Method, String> methodStringMap = {
        {{Request::Method::Undefined, "Undefined"},
         {Request::Method::Get, "Get"},
         {Request::Method::Head, "Head"},
         {Request::Method::Post, "Post"},
         {Request::Method::Put, "Put"},
         {Request::Method::Delete, "Delete"},
         {Request::Method::Trace, "Trace"},
         {Request::Method::Options, "Options"},
         {Request::Method::Connect, "Connect"},
         {Request::Method::Patch, "Patch"}}};

    return methodStringMap.at(aMethod);
}

}  // namespace http
}  // namespace tcp
}  // namespace ip
}  // namespace io
}  // namespace ostk
