# lockfreedataengine

A small C++ project exploring **lock-free, high throughput message passing** for low-latency systems.

Using C++ 20 for several reasons:
- std::atomic, std::memory_order for lock-free structures 
- std::optional, std::span, std::chrono for clean APIs and timing 
- constexpr improvements for compile-time helpers

Supported across GCC (>=10), Clang (>= 10) & MSVC. 

Don't need bleeding edge C++26 though could expirement with C++23 if the toolchain evolves to support it 