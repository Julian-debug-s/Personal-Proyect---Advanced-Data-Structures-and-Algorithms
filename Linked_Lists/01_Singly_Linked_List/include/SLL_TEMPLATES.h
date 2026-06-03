#ifndef SLL_TEMPLATES
#define SLL_TEMPLATES

#include "SLL_STATUS.h"

#define DEFINE_SLL_FOR_TYPE(NAME, TYPE)\
\
\
    /*NODE*/\
\
    typedef struct NAME##_node {\
        TYPE data;\
        struct NAME##_node* next;\
    } NAME##_node;\
\
    SLL_Status NAME##_create_node(TYPE data, NAME##_node** new_node);\
\
\
    /*LIST*/\
\
    typedef struct NAME {\
        NAME##_node* head;\
        NAME##_node* tail;\
        size_t size;\
    } NAME;\
\
\
    /*FUNCTIONS*/\
\
    SLL_Status NAME##_insert_head(TYPE data, NAME* list);\
    SLL_Status NAME##_insert_tail(TYPE data, NAME* list);\
    SLL_Status NAME##_insert_at(TYPE data, size_t pos, NAME* list);\
\
    SLL_Status NAME##_delete_head(NAME* list, TYPE* out_data);\
    SLL_Status NAME##_delete_tail(NAME* list, TYPE* out_data);\
    SLL_Status NAME##_delete_at(NAME* list, size_t pos, TYPE* out_data);\
\
    SLL_Status NAME##_visualize(NAME* list, void (*view_function)(const TYPE* data));\
    SLL_Status NAME##_filter(NAME* list, int (*filter_function)(const TYPE* data), NAME* filtered_list);\
    SLL_Status NAME##_merge_sort(NAME* list);\
    SLL_Status NAME##_clear_list(NAME* list);

#define NUMBER_COMPARATOR(a, b) (((a)>(b))-((a)<(b)))

#endif