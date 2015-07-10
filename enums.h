#pragma once
#include <cstdint>
#include <tuple>

enum Enum_old
{
    First = 0
};

enum Enum_old_u8: std::uint8_t
{

};

enum class Enum
{

};

enum class Enum_old_u64: std::int64_t
{

};

enum class Person
{
    Id,
    Name,
    Surname,
    Address
};

enum Person_old
{
    Id,
    Name,
    Surname,
    Address
};

using PersonTuple = std::tuple<int, std::string, std::string, std::string>;

template<typename E>
constexpr auto toU(E enumerator) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

void enums()
{
    std::cout << "size of old enum: " << sizeof(Enum_old) << std::endl;
    std::cout << "size of old enum: " << sizeof(Enum) << std::endl;
    std::cout << "size of old enum: " << sizeof(Enum_old_u8) << std::endl;
    std::cout << "size of old enum: " << sizeof(Enum_old_u64) << std::endl;

    PersonTuple p1 = std::make_tuple(1, "Krystian", "Gwozdz", "Ilowa");
    std::cout << "Id: "       << std::get<Id>(p1)
              << " name: "    << std::get<Name>(p1)
              << " surname: " << std::get<Surname>(p1)
              << " address: " << std::get<Address>(p1)
              << std::endl;

    std::cout << "Id: "       << std::get<static_cast<std::size_t>(Person::Id)>(p1)
              << " name: "    << std::get<static_cast<std::size_t>(Person::Name)>(p1)
              << " surname: " << std::get<static_cast<std::size_t>(Person::Surname)>(p1)
              << " address: " << std::get<static_cast<std::size_t>(Person::Address)>(p1)
              << std::endl;

    std::cout << "Id: "       << std::get<toU(Person::Id)>(p1)
              << " name: "    << std::get<toU(Person::Name)>(p1)
              << " surname: " << std::get<toU(Person::Surname)>(p1)
              << " address: " << std::get<toU(Person::Address)>(p1)
              << std::endl;
}
