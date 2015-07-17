#include <string>
#include "pimpl.h"
#include <iostream>

struct PimplTest::Impl
{
    std::string m_string;
};

PimplTest::PimplTest():
    m_impl(new Impl)
{

}

void PimplTest::test()
{
    std::cout << "TEST pimpl";
}

PimplTest::PimplTest(PimplTest &&test) = default;

PimplTest::~PimplTest()
{

}

PimplTest& PimplTest::operator=(PimplTest &&test) = default;



