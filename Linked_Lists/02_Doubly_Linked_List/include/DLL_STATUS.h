#ifndef DLL_STATUS
#define DLL_STATUS

typedef enum DLL_Status {
    DLL_OK = 0,
    DLL_NULL_PARAM_ERROR
} DLL_Status;

const char* dll_status_get_message(DLL_Status status);

#define DLL_TRY(status)\
    do {\
        if ((status) != DLL_OK) {\
            fprintf(stderr, "[DLL ERROR]: %s, FILE: %s, LINE: %d",\
            dll_status_get_message((status)), __FILE__, __LINE__);\
            return (status);\
        }\
    } while (0);

#endif