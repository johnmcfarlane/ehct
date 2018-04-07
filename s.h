extern int x;

struct S {
    ~S() noexcept { x = 0; }
    void operator()();
};
