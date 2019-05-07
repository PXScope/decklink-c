#include <memory>

#include "types.h"
#include "include/util.h"

void cdecklink_free_string(const char *str) {
    free((void *) str);
}

HRESULT cdecklink_api_version(cdecklink_iterator_t* it, const char** str) {
    IDeckLinkAPIInformation *info;
    HRESULT result = it->QueryInterface(IID_IDeckLinkAPIInformation, reinterpret_cast<void**>(&info));
    if (FAILED(result)) return result;

    return info->GetString(BMDDeckLinkAPIVersion, str);
}