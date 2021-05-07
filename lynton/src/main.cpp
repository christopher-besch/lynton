#include <iostream>
#include <emscripten.h>

// needed when using C++
extern "C"
{
    // use from javascript
    int EMSCRIPTEN_KEEPALIVE fib(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        else
            return fib(n - 1) + fib(n - 2);
    }

    int main()
    {
        std::cout << "Hello World" << std::endl;

        int res = fib(5);
        std::cout << "fib(5)=" << res << std::endl;
        // use javascript
        emscripten_run_script("alert('Hello World');");

        // javascript api
        int result = EM_ASM_INT({
            console.log($0);
            console.log($1);
            return $0 + $1;
        },
                                13, 23);
        std::cout << result << std::endl;

        return 0;
    }
}
