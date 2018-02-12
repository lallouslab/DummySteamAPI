#ifndef CALLBACKS_H
#define CALLBACKS_H 1

#include "CCallback.h"
#include "list.h"
#include "steam.h"


void callbacks_init(void);
void callbacks_register_callback(struct CCallbackBase *callback, enum steam_callback_type type);
void callbacks_unregister_callback(struct CCallbackBase *callback);
void callbacks_register_api_call_result(struct CCallbackBase *callback, steam_api_call_t api_call);
void callbacks_unregister_api_call_result(struct CCallbackBase *callback, steam_api_call_t api_call);
void callbacks_dispatch_callback_output(enum steam_callback_type type, void *data, size_t data_size);
steam_api_call_t callbacks_dispatch_api_call_result_output(enum steam_callback_type type, steam_bool_t io_failure, void *data, size_t data_size);
steam_bool_t callbacks_api_call_result_is_output_available(steam_api_call_t api_call, steam_bool_t *io_failure);
steam_bool_t callbacks_api_call_result_get_output(steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *io_failure);
void callbacks_run(void);

#endif /* CALLBACKS_H */
