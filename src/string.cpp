#include <EASTL/internal/config.h>
#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>

// Disable EASTL_EASTDC_VSNPRINTF in config.h if you want to use this and not EAStdC
int Vsnprintf8 (char*  pDestination, size_t n, const char*  pFormat, va_list arguments) {
    return vsnprintf(pDestination, n, pFormat, arguments);
}
//int Vsnprintf16(char16_t* pDestination, size_t n, const char16_t* pFormat, va_list arguments);
//int Vsnprintf32(char32_t* pDestination, size_t n, const char32_t* pFormat, va_list arguments);
#if EA_CHAR8_UNIQUE
	int Vsnprintf8 (char8_t*  pDestination, size_t n, const char8_t*  pFormat, va_list arguments) {
        return vsnprintf(pDestination, n, pFormat, arguments);
    }
#endif
#if defined(EA_WCHAR_UNIQUE) && EA_WCHAR_UNIQUE
	int VsnprintfW(wchar_t* pDestination, size_t n, const wchar_t* pFormat, va_list arguments) {
        return vswprintf(pDestination, n, pFormat, arguments);
    }
#endif

