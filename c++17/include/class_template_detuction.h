namespace class_template_deduction{

    template <typename T>
    class Foo{
        public:
        Foo(const T& t):
            _member(t){
        }
        T _member;
    };


void main_(){
    auto f = Foo(5.6);
    std::cout << "Template member: " << f._member << std::endl;
}

}