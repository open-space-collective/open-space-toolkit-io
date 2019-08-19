////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library ▸ I/O
/// @file           Library/IO/IP/Address.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_IO_IP_Address__
#define __Library_IO_IP_Address__

#include <Library/Core/Types/String.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace io
{
namespace ip
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using String = library::core::types::String ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Internet Protocol (IP) address
///
/// @ref                        https://en.wikipedia.org/wiki/IP_address

class Address
{

    public:

        enum class Type
        {

            Undefined,
            IPv4,
            IPv6

        } ;

        /// @brief              Default constructor (disabled)

                                Address                                     ( ) = delete ;

        /// @brief              Copy constructor
        ///
        /// @param              [in] anAddress An IP address

                                Address                                     (   const   Address&                    anAddress                                   ) ;

        /// @brief              Destructor

                                ~Address                                    ( ) ;

        /// @brief              Assignment operator
        ///
        /// @param              [in] anAddress An IP address
        /// @return             Address

        Address&                operator =                                  (   const   Address&                    anAddress                                   ) ;

        /// @brief              Equal to operator
        ///
        /// @code
        ///                     Address::Parse("0.0.0.0") == Address::Parse("0.0.0.0") ; // True
        /// @endcode
        ///
        /// @param              [in] anAddress An IP address
        /// @return             True if addresses are equal

        bool                    operator ==                                 (   const   Address&                    anAddress                                   ) const ;

        /// @brief              Not equal to operator
        ///
        /// @code
        ///                     Address::Parse("0.0.0.0") != Address::Parse("0.0.0.1") ; // True
        /// @endcode
        ///
        /// @param              [in] anAddress An IP address
        /// @return             True if addresses are not equal

        bool                    operator !=                                 (   const   Address&                    anAddress                                   ) const ;

        /// @brief              Output stream operator
        ///
        /// @code
        ///                     Address address = Address::Parse("0.0.0.0") ;
        ///                     std::cout << address ;
        /// @endcode
        ///
        /// @param              [in] anOutputStream An output stream
        /// @param              [in] anAddress An IP address
        /// @return             An output stream

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Address&                    anAddress                                   ) ;

        /// @brief              Check if address is defined
        ///
        /// @code
        ///                     Address address = Address::Parse("0.0.0.0") ;
        ///                     address.isDefined() ; // True
        /// @endcode
        ///
        /// @return             True if address is defined

        bool                    isDefined                                   ( ) const ;

        /// @brief              Returns true if address is loopback
        ///
        /// @code
        ///                     Address::Parse("127.0.0.1").isLoopback() ; // True
        ///                     Address::Parse("::1").isLoopback() ; // True
        /// @endcode
        ///
        /// @return             True if address is loopback

        bool                    isLoopback                                  ( ) const ;

        /// @brief              Returns true if address is wildcard (all zero)
        ///
        /// @code
        ///                     Address::Parse("0.0.0.0").isWildcard() ; // True
        ///                     Address::Parse("::").isWildcard() ; // True
        /// @endcode
        ///
        /// @return             True if address is wildcard

        bool                    isWildcard                                  ( ) const ;

        /// @brief              Returns true if address is link local unicast
        ///
        ///                     IPv4 link local addresses are in the 169.254.0.0/16 range, according to RFC 3927.
        ///                     IPv6 link local addresses have 1111 1110 10 as the first 10 bits, followed by 54 zeros.
        ///
        /// @return             True if address is link local unicast

        bool                    isLinkLocal                                 ( ) const ;

        /// @brief              Returns true if IP address is broadcast
        ///
        ///                     Only IPv4 addresses can be broadcast addresses. In a broadcast address, all bits are one.
        ///                     For an IPv6 address, returns always false.
        ///
        /// @code
        ///                     Address::Parse("255.255.255.255").isBroadcast() ; // True
        ///                     Address::Parse("::").isBroadcast() ; // False
        /// @endcode
        ///
        /// @return             True if address is broadcast

        bool                    isBroadcast                                 ( ) const ;

        /// @brief              Returns true if address is unicast
        ///
        ///                     An address is unicast if it is neither a wildcard, broadcast or multicast address.
        ///
        /// @return             True if address is unicast

        bool                    isUnicast                                   ( ) const ;

        /// @brief              Returns true if address is multicast
        ///
        ///                     IPv4 multicast addresses are in the 224.0.0.0 to 239.255.255.255 range (the first four bits have the value 1110).
        ///                     IPv6 multicast addresses are in the FFxx:x:x:x:x:x:x:x range.
        ///
        /// @return             True if address is multicast

        bool                    isMulticast                                 ( ) const ;

        /// @brief              Returns true if address is global multicast
        ///
        ///                     For IPv4, global multicast addresses are in the 224.0.1.0 to 238.255.255.255 range.
        ///                     For IPv6, global multicast addresses are in the FFxF:x:x:x:x:x:x:x range.
        ///
        /// @return             True if address is global multicast

        bool                    isGlobalMulticast                           ( ) const ;

        /// @brief              Returns true if address is link-local multicast
        ///
        ///                     For IPv4, link-local multicast addresses are in the 224.0.0.0/24 range.
        ///                     For IPv6, link-local multicast addresses are in the FFx2:x:x:x:x:x:x:x range.
        ///
        /// @return             True if address is link-local multicast

        bool                    isLinkLocalMulticast                        ( ) const ;

        /// @brief              Returns true if address is node-local multicast
        ///
        ///                     IPv4 does not support node-local addresses, thus the result is always false for an IPv4 address.
        ///                     For IPv6, node-local multicast addresses are in the FFx1:x:x:x:x:x:x:x range.
        ///
        /// @return             True if address is node-local multicast

        bool                    isNodeLocalMulticast                        ( ) const ;

        /// @brief              Returns true if address is organization-local multicast
        ///
        ///                     For IPv4, organization-local multicast addresses are in the 239.192.0.0/16 range.
        ///                     For IPv6, organization-local multicast addresses are in the FFx8:x:x:x:x:x:x:x range.
        ///
        /// @return             True if address is organization-local multicast

        bool                    isOrgLocalMulticast                         ( ) const ;

        /// @brief              Returns true if address is site local unicast
        ///
        ///                     IPv4 site local addresses are in on of the 10.0.0.0/24, 192.168.0.0/16 or 172.16.0.0 to 172.31.255.255 ranges.
        ///                     Originally, IPv6 site-local addresses had FEC0/10 (1111 1110 11) prefix (RFC 4291), followed by 38 zeros.
        ///                     Interfaces using this mask are supported, but obsolete; RFC 4193 prescribes fc00::/7 (1111 110) as local unicast prefix.
        ///
        /// @return             True if address is site local unicast

        bool                    isSiteLocal                                 ( ) const ;

        /// @brief              Returns true if address is site-local multicast
        ///
        ///                     For IPv4, site local multicast addresses are in the 239.255.0.0/16 range.
        ///                     For IPv6, site-local multicast addresses are in the FFx5:x:x:x:x:x:x:x range.
        ///
        /// @return             True if address is site-local multicast

        bool                    isSiteLocalMulticast                        ( ) const ;

        /// @brief              Returns true if address is well-known multicast
        ///
        ///                     For IPv4, well-known multicast addresses are in the 224.0.0.0/8 range.
        ///                     For IPv6, well-known multicast addresses are in the FF0x:x:x:x:x:x:x:x range.
        ///
        /// @return             True if address is well-known multicast

        bool                    isWellKnownMulticast                        ( ) const ;

        /// @brief              Returns true if address is IPv4 compatible
        ///
        ///                     For IPv4 addresses, this is always true.
        ///                     For IPv6, the address must be in the ::x:x range (the first 96 bits are zero).
        ///
        /// @return             True if address is IPv4 compatible

        bool                    isIPv4Compatible                            ( ) const ;

        /// @brief              Returns true if address is an IPv4 mapped IPv6 address
        ///
        ///                     For IPv4 addresses, this is always true.
        ///                     For IPv6, the address must be in the ::FFFF:x:x range.
        ///
        /// @return             True if address is an IPv4 mapped IPv6 address.

        bool                    isIPv4Mapped                                ( ) const ;

        /// @brief              Get address type
        ///
        /// @code
        ///                     Address::Parse("0.0.0.0").getType() ; // Address::Type::IPv4
        ///                     Address::Parse("::").getType() ; // Address::Type::IPv6
        /// @endcode
        ///
        /// @return             Address type

        Address::Type           getType                                     ( ) const ;

        /// @brief              Get address string representation
        ///
        /// @code
        ///                     Address::Parse("1.2.3.4").getString() ; // "1.2.3.4"
        ///                     Address::Parse("::").getString() ; // "::"
        /// @endcode
        ///
        /// @return             Address string representation

        String                  getString                                   ( ) const ;

        /// @brief              Constructs an undefined address
        ///
        /// @code
        ///                     Address address = Address::Undefined() ;
        ///                     address.isDefined() ; // False
        /// @endcode
        ///
        /// @return             Undefined address

        static Address          Undefined                                   ( ) ;

        /// @brief              Constructs a loopback address
        ///
        /// @code
        ///                     Address address = Address::Loopback(Address::Type::IPv4) ;
        ///                     address.getString() ; // "127.0.0.1"
        /// @endcode
        ///
        /// @return             Loopback address

        static Address          Loopback                                    (   const   Address::Type&              aType                                       ) ;

        /// @brief              Constructs a broadcast address
        ///
        /// @code
        ///                     Address address = Address::Broadcast() ;
        ///                     address.getString() ; // "255.255.255.255"
        /// @endcode
        ///
        /// @return             Broadcast address

        static Address          Broadcast                                   ( ) ;

        /// @brief              Constructs an IPv4 address
        ///
        /// @code
        ///                     Address address = Address::IPv4(1, 2, 3, 4) ;
        ///                     address.getString() ; // "1.2.3.4"
        /// @endcode
        ///
        /// @return             IPv4 address

        static Address          IPv4                                        (   const   uint8_t&                    aFirstGroup,
                                                                                const   uint8_t&                    aSecondGroup,
                                                                                const   uint8_t&                    aThirdGroup,
                                                                                const   uint8_t&                    aFourthGroup                                ) ;

        /// @brief              Constructs an IPv4 address
        ///
        /// @code
        ///                     Address address = Address::IPv4(0) ;
        ///                     address.getString() ; // "0.0.0.0"
        /// @endcode
        ///
        /// @return             IPv4 address

        static Address          IPv4                                        (   const   uint32_t&                   anAddress                                   ) ;

        /// @brief              Constructs an IPv6 address
        ///
        /// @code
        ///                     Address address = Address::IPv6(0, 0, 0, 0, 0, 0, 0, 0) ;
        ///                     address.getString() ; // "::"
        /// @endcode
        ///
        /// @return             IPv6 address

        static Address          IPv6                                        (   const   uint16_t&                   aFirstGroup,
                                                                                const   uint16_t&                   aSecondGroup,
                                                                                const   uint16_t&                   aThirdGroup,
                                                                                const   uint16_t&                   aFourthGroup,
                                                                                const   uint16_t&                   aFifthGroup,
                                                                                const   uint16_t&                   aSixthGroup,
                                                                                const   uint16_t&                   aSeventhGroup,
                                                                                const   uint16_t&                   anEighthGroup                               ) ;

        /// @brief              Constructs an address from a given string
        ///
        /// @code
        ///                     Address address = Address::Parse("1.2.3.4") ; // IPv4
        ///                     Address address = Address::Parse("::") ; // IPv6
        /// @endcode
        ///
        /// @param              [in] aString A string
        /// @return             Address

        static Address          Parse                                       (   const   String&                     aString                                     ) ;

    private:

        // [TBI]

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
