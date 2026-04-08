// .hpp
// TODO Export Macro
// by Kyle Furey

#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #ifdef TODO_EXPORTS
        /** Windows Export */
        #define TODO_API __declspec(dllexport)
    #else
        /** Windows Import */
        #define TODO_API __declspec(dllimport)
    #endif
#else
    #ifdef TODO_EXPORTS
        /** MacOS / Linux Export */
        #define TODO_API __attribute__((visibility("default")))
    #else
        /** Fallback */
        #define TODO_API
    #endif
#endif

#ifdef _DEBUG
    /** TODO Debugging */
    #define TODO_DEBUG
#endif
