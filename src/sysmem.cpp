#include <cerrno>
#include <cstdint>
#include <cstddef>

extern "C" {

/**
 * Pointer to the current high watermark of the heap usage
 */
static std::uint8_t* __sbrk_heap_end = nullptr;

/**
 * @brief _sbrk() allocates memory to the newlib heap and is used by malloc
 *        and others from the C library
 *
 * @verbatim
 * ############################################################################
 * #  .data  #  .bss  #       newlib heap       #          MSP stack          #
 * #         #        #                         # Reserved by _Min_Stack_Size #
 * ############################################################################
 * ^-- RAM start      ^-- _end                             _estack, RAM end --^
 * @endverbatim
 *
 * This implementation starts allocating at the '_end' linker symbol
 * The '_Min_Stack_Size' linker symbol reserves a memory for the MSP stack
 * The implementation considers '_estack' linker symbol to be RAM end
 * NOTE: If the MSP stack, at any point during execution, grows larger than the
 * reserved size, please increase the '_Min_Stack_Size'.
 *
 * @param incr Memory size
 * @return Pointer to allocated memory
 */
void* _sbrk(std::ptrdiff_t incr) {
    extern std::uint8_t _end; // Symbol defined in the linker script
    extern std::uint8_t _estack; // Symbol defined in the linker script
    extern std::uint32_t _Min_Stack_Size; // Symbol defined in the linker script
    const std::uint32_t stack_limit = (std::uint32_t)&_estack - (std::uint32_t)&_Min_Stack_Size;
    const std::uint8_t* max_heap = (std::uint8_t*)stack_limit;
    std::uint8_t* prev_heap_end;

    // Initialize heap end at first call
    if (!__sbrk_heap_end) {
        __sbrk_heap_end = &_end;
    }

    // Protect heap from growing into the reserved MSP stack
    if (__sbrk_heap_end + incr > max_heap) {
        errno = ENOMEM;
        return (void*) -1;
    }

    prev_heap_end = __sbrk_heap_end;
    __sbrk_heap_end += incr;

    return (void*) prev_heap_end;
}

#ifdef __PICOLIBC__
    // Picolibc expects syscalls without the leading underscore.
    // This creates a strong alias so that
    // calls to `sbrk()` are resolved to our `_sbrk()` implementation.
    __strong_reference(_sbrk, sbrk);
#endif

}