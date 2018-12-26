#pragma once

#include "types.h"

namespace std
{
    namespace __l
    {
        template<typename T, typename T2>
        class __tree_node;
        
        template<typename T, typename T2>
        class list
        {
            public:
            list(T const &);
        };

        template<typename T, typename T2>
        class pair
        {
            public:
            ~pair();
        };  

        template<typename T, typename T2>
        class vector
        {
            public:
            void reserve(u64);
            void __push_back_slow_path<T const &>(T const &);
        };

        template<typename T, typename T2, typename T3>
        class __tree
        {
            public:
            void destroy(std::__l::__tree_node<T, void *> *);
        };
    }; 
};