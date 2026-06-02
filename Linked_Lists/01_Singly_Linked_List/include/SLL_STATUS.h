#ifndef SLL_STATUS
#define SLL_STATUS

typedef enum SLL_Status {
    SLL_OK = 0,
    SLL_NULL_PARAM_ERROR
} SLL_Status;

const char* sll_status_get_message(SLL_Status status);

#define SLL_TRY(status)\
    do {\
        if ((status) != SLL_OK ){\
            fprintf(stderr, "[SLL ERROR]: %s, FILE: %s, LINE: %d",\
            sll_status_get_message((status)), __FILE__, __LINE__);\
        }\
        return ((status));\
    } while (0);


#endif