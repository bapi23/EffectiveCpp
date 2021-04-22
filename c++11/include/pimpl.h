#pragma once
#include <memory>

class PimplTest
{
public:
    PimplTest();
    void test();
    PimplTest(PimplTest&& test);
    ~PimplTest();
    PimplTest& operator=(PimplTest&& test);

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};


inline void pimpl()
{
    PimplTest t;
    t.test();

    PimplTest z(std::move(t));
}
