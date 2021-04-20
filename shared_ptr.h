#pragma once
#include <memory>


class Test_Shared_Without_Duplication : public std::enable_shared_from_this<Test_Shared_Without_Duplication>
{
public:
    std::shared_ptr<Test_Shared_Without_Duplication> get()
    {
        return std::shared_ptr<Test_Shared_Without_Duplication>(shared_from_this());
    }
};

class Test_Shared
{
public:
    std::shared_ptr<Test_Shared> get()
    {
        return std::shared_ptr<Test_Shared>(this);
    }
};

void shared_ptr_()
{
    std::shared_ptr<int> ptr_s;
    std::cout << "size of shared_ptr<int> :" << sizeof(ptr_s) << std::endl;

    auto deleter = [](int* it)
    {
        delete it;
    };

    std::shared_ptr<int> ptr_s_cd(new int(5), deleter);
    std::cout << "size of shared_ptr<int> with deleter:" << sizeof(ptr_s_cd) << std::endl;

    std::shared_ptr<Test_Shared_Without_Duplication> test = std::make_shared<Test_Shared_Without_Duplication>();
    auto testGet = test->get();
    std::cout << "shared count without duplication:" << testGet.use_count() << std::endl;

    Test_Shared_Without_Duplication bad;
    //auto really_bad = bad.get(); crash
}
