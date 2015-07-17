#include <functional>
#include <iostream>


void unique_ptr_()
{
    std::unique_ptr<int> ptr(new int(6));
    std::cout << "size of unique_ptr<int> :" << sizeof(ptr) <<std::endl;

    auto deleter = [](int* it)
    {
        delete it;
    };

    std::unique_ptr<int, std::function<void(int*)>> ptr2(new int, deleter);
    std::cout << "size of unique_ptr<int, deleter> :" << sizeof(ptr2) << std::endl;

    std::cout << "unique before move:" << *ptr << std::endl;
    std::shared_ptr<int> shared(std::move(ptr));
    std::cout << "unique aftert move:" << bool(ptr) << std::endl;
    std::cout << "shared after move from unique initialised?:" << bool(shared) << std::endl;
    std::cout << "shared after move from unique:" << *shared << std::endl;

}
