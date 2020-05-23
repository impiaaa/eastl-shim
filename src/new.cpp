#include <stdlib.h>
#include <malloc.h>
void* operator new(size_t count, void* ptr) {
    return ptr;
}
void* operator new(size_t size) {
    return malloc(size);
}
void* operator new[](size_t size) {
    return malloc(size);
}
void operator delete[](void* ptr) noexcept {
    free(ptr);
}
void operator delete(void* ptr, size_t size) noexcept {
    free(ptr);
}
// EASTL includes an allocator_malloc, but I can't figure out how to use it as default.
void* operator new[](size_t size, const char* pName, int flags, unsigned debugFlags, const char* file, int line) {
    return malloc(size);
}
void* operator new[](size_t size, size_t alignment, size_t alignmentOffset, const char* pName, int flags, unsigned debugFlags, const char* file, int line) {
	if((alignmentOffset % alignment) == 0)
		return memalign(alignment, size);
	return NULL;
}

