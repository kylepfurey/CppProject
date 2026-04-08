// .hpp
// TODO Error Logging Macros
// by Kyle Furey

#pragma once
#include <Types.hpp>

namespace TODO {
    /** TODO success code. */
    constexpr Int SUCCESS = 0x0;

    /** TODO error code. */
    constexpr Int ERROR = 0xBAD;

    /** Logs the given message for TODO. */
    template<typename... T>
    void print(T &&... msg) {
#ifdef TODO_DEBUG
        std::cout << "TODO LOG:\t";
        (..., (std::cout << msg << ' '));
        std::cout << std::endl;
#endif
    }

    /** Logs the given error message for TODO. */
    template<typename... T>
    void error(T &&... msg) {
#ifdef TODO_DEBUG
        std::cerr << "TODO ERROR:\t";
        (..., (std::cerr << msg << ' '));
        std::cerr << std::endl;
#endif
    }

    /** Crashes TODO with the given message <msg> if <cond> is false. */
    template<typename... T>
    void assert(Bool cond, T &&... msg) {
#ifdef TODO_DEBUG
        if (!cond) {
            std::cerr << "TODO ASSERTION FAILED: ";
            (..., (std::cerr << msg << ' '));
            std::cerr << std::endl;
            std::exit(ERROR);
        }
#endif
    }
}
