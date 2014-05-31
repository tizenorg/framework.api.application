/*
 * Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. 
 */



#include <tet_api.h>
#include <stdio.h>
#include <stdlib.h>
#include <app.h>

static void startup(void);
static void cleanup(void);


void (*tet_startup)(void) = startup;
void (*tet_cleanup)(void) = cleanup;

static void utc_service_create_positive(void);
static void utc_service_create_negative(void);

static void utc_service_destroy_positive(void);
static void utc_service_destroy_negative(void);

static void utc_service_set_operation_positive1(void);
static void utc_service_set_operation_positive2(void);
static void utc_service_set_operation_negative(void);

static void utc_service_get_operation_positive(void);
static void utc_service_get_operation_negative1(void);
static void utc_service_get_operation_negative2(void);
static void utc_service_get_operation_negative3(void);

static void utc_service_set_uri_positive1(void);
static void utc_service_set_uri_positive2(void);
static void utc_service_set_uri_negative(void);

static void utc_service_get_uri_positive(void);
static void utc_service_get_uri_negative1(void);
static void utc_service_get_uri_negative2(void);
static void utc_service_get_uri_negative3(void);

static void utc_service_set_mime_positive1(void);
static void utc_service_set_mime_positive2(void);
static void utc_service_set_mime_negative(void);

static void utc_service_get_mime_positive(void);
static void utc_service_get_mime_negative1(void);
static void utc_service_get_mime_negative2(void);
static void utc_service_get_mime_negative3(void);

static void utc_service_set_package_positive(void);
static void utc_service_set_package_negative1(void);
static void utc_service_set_package_negative2(void);

static void utc_service_get_package_positive(void);
static void utc_service_get_package_negative1(void);
static void utc_service_get_package_negative2(void);
static void utc_service_get_package_negative3(void);

static void utc_service_add_extra_data_positive(void);
static void utc_service_add_extra_data_negative1(void);
static void utc_service_add_extra_data_negative2(void);

static void utc_service_remove_extra_data_positive(void);
static void utc_service_remove_extra_data_negative1(void);
static void utc_service_remove_extra_data_negative2(void);
static void utc_service_remove_extra_data_negative3(void);

static void utc_service_get_extra_data_positive(void);
static void utc_service_get_extra_data_negative1(void);
static void utc_service_get_extra_data_negative2(void);
static void utc_service_get_extra_data_negative3(void);
static void utc_service_get_extra_data_negative4(void);

static void utc_service_foreach_extra_data_positive(void);
static void utc_service_foreach_extra_data_negative1(void);
static void utc_service_foreach_extra_data_negative2(void);

static void utc_service_clone_positive(void);
static void utc_service_clone_negative1(void);
static void utc_service_clone_negative2(void);

static void utc_service_send_launch_request_positive1(void);
static void utc_service_send_launch_request_positive2(void);
static void utc_service_send_launch_request_positive3(void);
static void utc_service_send_launch_request_negative1(void);
static void utc_service_send_launch_request_negative2(void);

static void utc_service_reply_to_launch_request_negative1(void);
static void utc_service_reply_to_launch_request_negative2(void);

static void utc_service_foreach_app_matched_positive(void);
static void utc_service_foreach_app_matched_negative1(void);
static void utc_service_foreach_app_matched_negative2(void);

static void utc_service_add_extra_data_array_positive(void);
static void utc_service_add_extra_data_array_negative1(void);
static void utc_service_add_extra_data_array_negative2(void);
static void utc_service_add_extra_data_array_negative3(void);

static void utc_service_get_extra_data_array_positive(void);
static void utc_service_get_extra_data_array_negative1(void);
static void utc_service_get_extra_data_array_negative2(void);
static void utc_service_get_extra_data_array_negative3(void);
static void utc_service_get_extra_data_array_negative4(void);
static void utc_service_get_extra_data_array_negative5(void);

static void utc_service_is_extra_data_array_positive(void);
static void utc_service_is_extra_data_array_negative1(void);
static void utc_service_is_extra_data_array_negative2(void);
static void utc_service_is_extra_data_array_negative3(void);
static void utc_service_is_extra_data_array_negative4(void);


static void utc_service_is_reply_requested_positive1(void);
static void utc_service_is_reply_requested_negative1(void);
static void utc_service_is_reply_requested_negative2(void);
static void utc_service_is_reply_requested_negative3(void);

static void utc_service_get_caller_positive1(void);
static void utc_service_get_caller_negative1(void);
static void utc_service_get_caller_negative2(void);
static void utc_service_get_caller_negative3(void);


struct tet_testlist tet_testlist[] = {
	{ utc_service_create_positive, 1 },
	{ utc_service_create_negative, 1 },
	{ utc_service_destroy_positive, 1 },
	{ utc_service_destroy_negative, 1 },
	{ utc_service_set_operation_positive1, 1 },
	{ utc_service_set_operation_positive2, 1 },
	{ utc_service_set_operation_negative, 1 },
	{ utc_service_get_operation_positive, 1 },
	{ utc_service_get_operation_negative1, 1 },
	{ utc_service_get_operation_negative2, 1 },
	{ utc_service_get_operation_negative3, 1 },
	{ utc_service_set_uri_positive1, 1 },
	{ utc_service_set_uri_positive2, 1 },	
	{ utc_service_set_uri_negative, 1 },
	{ utc_service_get_uri_positive, 1 },
	{ utc_service_get_uri_negative1, 1 },
	{ utc_service_get_uri_negative2, 1 },
	{ utc_service_get_uri_negative3, 1 },
	{ utc_service_set_mime_positive1, 1 },
	{ utc_service_set_mime_positive2, 1 },
	{ utc_service_set_mime_negative, 1 },
	{ utc_service_get_mime_positive, 1 },
	{ utc_service_get_mime_negative1, 1 },
	{ utc_service_get_mime_negative2, 1 },
	{ utc_service_get_mime_negative3, 1 },
	{ utc_service_set_package_positive, 1 },
	{ utc_service_set_package_negative1, 1 },
	{ utc_service_set_package_negative2, 1 },
	{ utc_service_get_package_positive, 1 },
	{ utc_service_get_package_negative1, 1 },
	{ utc_service_get_package_negative2, 1 },
	{ utc_service_get_package_negative3, 1 },
	{ utc_service_add_extra_data_positive, 1 },
	{ utc_service_add_extra_data_negative1, 1 },
	{ utc_service_add_extra_data_negative2, 1 },
	{ utc_service_remove_extra_data_positive, 1 },
	{ utc_service_remove_extra_data_negative1, 1 },
	{ utc_service_remove_extra_data_negative2, 1 },
	{ utc_service_remove_extra_data_negative3, 1 },
	{ utc_service_get_extra_data_positive, 1 },
	{ utc_service_get_extra_data_negative1, 1 },
	{ utc_service_get_extra_data_negative2, 1 },
	{ utc_service_get_extra_data_negative3, 1 },
	{ utc_service_get_extra_data_negative4, 1 },
	{ utc_service_foreach_extra_data_positive, 1 },
	{ utc_service_foreach_extra_data_negative1, 1 },
	{ utc_service_foreach_extra_data_negative2, 1 },
	{ utc_service_clone_positive, 1 },
	{ utc_service_clone_negative1, 1 },
	{ utc_service_clone_negative2, 1 },
	{ utc_service_send_launch_request_positive1, 1 },
	{ utc_service_send_launch_request_positive2, 1 },
	{ utc_service_send_launch_request_positive3, 1 },
	{ utc_service_send_launch_request_negative1, 1 },
	{ utc_service_send_launch_request_negative2, 1 },
	{ utc_service_reply_to_launch_request_negative1, 1 },
	{ utc_service_reply_to_launch_request_negative2, 1 },
	{ utc_service_foreach_app_matched_positive, 1 },
	{ utc_service_foreach_app_matched_negative1, 1 },
	{ utc_service_foreach_app_matched_negative2, 1 },
	{ utc_service_add_extra_data_array_positive, 1 },
	{ utc_service_add_extra_data_array_negative1, 1 },
	{ utc_service_add_extra_data_array_negative2, 1 },
	{ utc_service_add_extra_data_array_negative3, 1 },
	{ utc_service_get_extra_data_array_positive, 1 },
	{ utc_service_get_extra_data_array_negative1, 1 },
	{ utc_service_get_extra_data_array_negative2, 1 },
	{ utc_service_get_extra_data_array_negative3, 1 },
	{ utc_service_get_extra_data_array_negative4, 1 },
	{ utc_service_get_extra_data_array_negative5, 1 },
	{ utc_service_is_extra_data_array_positive, 1 },
	{ utc_service_is_extra_data_array_negative1, 1 },
	{ utc_service_is_extra_data_array_negative2, 1 },
	{ utc_service_is_extra_data_array_negative3, 1 },
	{ utc_service_is_extra_data_array_negative4, 1 },
	{ utc_service_is_reply_requested_positive1, 1 },
	{ utc_service_is_reply_requested_negative1, 1 },
	{ utc_service_is_reply_requested_negative2, 1 },
	{ utc_service_is_reply_requested_negative3, 1 },
	{ utc_service_get_caller_positive1, 1 },
	{ utc_service_get_caller_negative1, 1 },
	{ utc_service_get_caller_negative2, 1 },
	{ utc_service_get_caller_negative3, 1 },
	{ NULL, 0 },
};

static void startup(void)
{
	/* start of TC */
}

static void cleanup(void)
{
	/* end of TC */
}


static void utc_service_create_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	ret = service_create(&service);

	dts_message(API_NAME, "ret(%d)", ret);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_create_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = service_create(NULL);

	dts_message(API_NAME, "ret(%d)", ret);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}


static void utc_service_destroy_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_destroy(service);
	
	dts_message(API_NAME, "ret(%d)", ret);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}


static void utc_service_destroy_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = service_destroy(NULL);
	
	dts_message(API_NAME, "ret(%d)", ret);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}


static void utc_service_set_operation_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *input_value = "INPUT_VALUE";

	service_h service;

	service_create(&service);

	ret = service_set_operation(service, input_value);

	dts_message(API_NAME, "ret(%d)", ret);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);

}

static void utc_service_set_operation_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_set_operation(service, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_set_operation_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	ret = service_set_operation(NULL, input_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}



static void utc_service_get_operation_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";
	char *output_value;

	service_h service;

	service_create(&service);

	service_set_operation(service, input_value);

	ret = service_get_operation(service, &output_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		if(!strcmp(input_value, output_value))
		{
			dts_pass(API_NAME, "passed");
		}
		else
		{
			dts_fail(API_NAME, "failed");
		}
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);

}

static void utc_service_get_operation_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = service_get_operation(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_get_operation_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_get_operation(service, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_operation_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	service_h service;

	service_create(&service);

	ret = service_get_operation(service, &output_value);

	if(ret == SERVICE_ERROR_NONE && output_value == NULL)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_set_uri_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	service_h service;

	service_create(&service);

	ret = service_set_uri(service, input_value);
	
	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);

}

static void utc_service_set_uri_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_set_uri(service, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);

}

static void utc_service_set_uri_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	ret = service_get_uri(NULL, input_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_get_uri_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";
	char *output_value;

	service_h service;

	service_create(&service);

	service_set_uri(service, input_value);

	service_get_uri(service, &output_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		if(!strcmp(input_value, output_value))
		{
			dts_pass(API_NAME, "passed");
		}
		else
		{
			dts_fail(API_NAME, "failed");
		}
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);

}

static void utc_service_get_uri_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	service_h service;

	service_create(&service);

	ret = service_get_uri(service, &output_value);

	if(ret == SERVICE_ERROR_NONE && output_value == NULL)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);

}

static void utc_service_get_uri_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = service_get_uri(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

}

static void utc_service_get_uri_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_get_uri(service, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);

}

static void utc_service_set_mime_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	service_h service;

	service_create(&service);

	ret = service_set_mime(service, input_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");		
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_set_mime_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_set_mime(service, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}


static void utc_service_set_mime_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	ret = service_set_mime(NULL, input_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_get_mime_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";
	char *output_value;

	service_h service;

	service_create(&service);

	service_set_mime(service, input_value);

	ret = service_get_mime(service, &output_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		if(!strcmp(input_value, output_value))
		{
			dts_pass(API_NAME, "passed");
		}
		else
		{
			dts_fail(API_NAME, "failed");
		}
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_mime_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	service_h service;

	service_create(&service);

	ret = service_get_mime(service, &output_value);

	if(ret == SERVICE_ERROR_NONE && output_value == NULL)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_mime_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = service_get_mime(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_get_mime_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_get_mime(service, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_set_package_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	service_h service;

	service_create(&service);

	ret = service_set_package(service, input_value);
	
	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_set_package_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = service_get_package(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_set_package_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_get_package(service, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_package_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";
	char *output_value;

	service_h service;

	service_create(&service);

	service_set_package(service, input_value);

	ret = service_get_package(service, &output_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		if(!strcmp(input_value, output_value))
		{
			dts_pass(API_NAME, "passed");
		}
		else
		{
			dts_fail(API_NAME, "failed");
		}
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_package_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	service_h service;

	service_create(&service);

	ret = service_get_package(service, &output_value);

	if(ret == SERVICE_ERROR_NONE && output_value == NULL)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_package_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = service_get_package(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_get_package_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_get_package(service, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_add_extra_data_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *value = "EXTRA_VALUE";

	service_h service;

	service_create(&service);

	ret = service_add_extra_data(service, key, value);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_add_extra_data_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int passed = 0;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *value = "EXTRA_VALUE";

	service_h service;

	service_create(&service);


	// key : unll
	ret = service_add_extra_data(service, NULL, value);

	if(ret != SERVICE_ERROR_NONE)
	{
		passed++;
	}

	// key : zero-length
	ret = service_add_extra_data(service, "", value);

	if(ret != SERVICE_ERROR_NONE)
	{
		passed++;
	}

	// value : null
	ret = service_add_extra_data(service, key, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		passed++;
	}

	// value : zero-length
	ret = service_add_extra_data(service, key, "");

	if(ret != SERVICE_ERROR_NONE)
	{
		passed++;
	}

	if(passed == 4)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_add_extra_data_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *value = "EXTRA_VALUE";

	ret = service_add_extra_data(NULL, key, value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_remove_extra_data_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *value = "EXTRA_VALUE";

	service_h service;

	service_create(&service);

	service_add_extra_data(service, key, value);

	ret = service_remove_extra_data(service, key);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_remove_extra_data_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";

	service_h service;

	service_create(&service);

	ret = service_remove_extra_data(service, key);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_remove_extra_data_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";

	ret = service_remove_extra_data(NULL, key);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_remove_extra_data_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_remove_extra_data(service, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_extra_data_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *value = "EXTRA_VALUE";
	char *ret_value;

	service_h service;

	service_create(&service);

	service_add_extra_data(service, key, value);

	ret = service_get_extra_data(service, key, &ret_value);

	if(ret == SERVICE_ERROR_NONE && !strcmp(ret_value, value))
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_extra_data_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *ret_value;

	service_h service;

	service_create(&service);

	ret = service_get_extra_data(service, key, &ret_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_extra_data_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *ret_value;

	ret = service_get_extra_data(NULL, key, &ret_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

}

static void utc_service_get_extra_data_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	char *ret_value;

	service_h service;

	service_create(&service);

	ret = service_get_extra_data(service, NULL, &ret_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_extra_data_negative4(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";

	service_h service;

	service_create(&service);

	ret = service_get_extra_data(service, key, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

#define NUM_EXTRA_DATA 32

bool service_extra_data(service_h service, const char *key, void *user_data)
{
	bool *passed = (bool*)user_data;
	char *value;

	service_get_extra_data(service, key, &value);

	if (!strcmp(key, value))
	{
		int index = atoi(key);
		passed[index] = true;
	}

	return true;
}

static void utc_service_foreach_extra_data_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	int i;
	bool passed[NUM_EXTRA_DATA] = {0, };
	int num_passed = 0;
	char buf[32] = {0, };

	service_h service;

	service_create(&service);

	for (i=0; i<NUM_EXTRA_DATA; i++)
	{
		snprintf(buf, sizeof(buf), "%d", i);
		service_add_extra_data(service, buf, buf);
	}

	ret = service_foreach_extra_data(service, service_extra_data, &passed);

	for (i=0; i<NUM_EXTRA_DATA; i++)
	{
		if (passed[i] == true)
		{
			num_passed++;
		}
	}

	if(ret == SERVICE_ERROR_NONE && num_passed == NUM_EXTRA_DATA)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_foreach_extra_data_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_foreach_extra_data(service, NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_foreach_extra_data_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = service_foreach_extra_data(NULL, service_extra_data, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_clone_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	char *operation = "OPERATION_VALUE";
	char *operation_clone;

	char *uri = "URI_VALUE";
	char *uri_clone;

	char *mime = "MIME_VALUE";
	char *mime_clone;

	char *package = "PACKAGE_VALUE";
	char *package_clone;

	char *extra_key = "EXTRA_KEY";
	
	char *extra_value = "EXTRA_VALUE";
	char *extra_value_clone;

	service_h service;
	service_h service_cloned;

	service_create(&service);
	service_set_operation(service, operation);
	service_set_uri(service, uri);
	service_set_mime(service, mime);
	service_set_package(service, package);
	service_add_extra_data(service, extra_key, extra_value);

	ret = service_clone(&service_cloned, service);

	service_get_operation(service_cloned, &operation_clone);
	service_get_uri(service_cloned, &uri_clone);
	service_get_mime(service_cloned, &mime_clone);
	service_get_package(service_cloned, &package_clone);
	service_get_extra_data(service_cloned, extra_key, &extra_value_clone);


	if(ret == SERVICE_ERROR_NONE
		&& !strcmp(operation, operation_clone)
		&& !strcmp(uri, uri_clone)
		&& !strcmp(mime, mime_clone)
		&& !strcmp(package, package_clone)
		&& !strcmp(extra_value, extra_value_clone))
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
	service_destroy(service_cloned);
}

static void utc_service_clone_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service_cloned;

	ret = service_clone(&service_cloned, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_clone_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_clone(NULL, service);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}


void dts_service_reply_cb(service_h request, service_h reply, service_result_e result, void *user_data)
{

}

static void utc_service_send_launch_request_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	service_set_operation(service, SERVICE_OPERATION_DEFAULT);

	service_set_package(service, "com.samsung.calculator");

	// explicit launch without reply callback
	ret = service_send_launch_request(service, NULL, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);

}

static void utc_service_send_launch_request_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	service_set_operation(service, SERVICE_OPERATION_DEFAULT);

	service_set_package(service, "com.samsung.calculator");

	// explicit launch with reply callback
	ret = service_send_launch_request(service, dts_service_reply_cb, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_send_launch_request_positive3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	service_set_operation(service, SERVICE_OPERATION_VIEW);

	service_set_mime(service, "type/custom");

	ret = service_send_launch_request(service, dts_service_reply_cb, NULL);

	if(ret == SERVICE_ERROR_APP_NOT_FOUND)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_send_launch_request_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = service_send_launch_request(NULL, NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_send_launch_request_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	service_set_operation(service, SERVICE_OPERATION_DEFAULT);

	ret = service_send_launch_request(service, NULL, NULL);

	if(ret == SERVICE_ERROR_APP_NOT_FOUND)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
	
	service_destroy(service);
}

static void utc_service_reply_to_launch_request_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h request;

	service_create(&request);

	ret = service_reply_to_launch_request(NULL, request, SERVICE_RESULT_CANCELED);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_reply_to_launch_request_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_reply_to_launch_request(service, NULL, SERVICE_RESULT_CANCELED);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

bool dts_service_app_matched_cb(service_h service, const char *package, void *user_data)
{
	return true;
}

static void utc_service_foreach_app_matched_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	service_set_operation(service, SERVICE_OPERATION_VIEW);

	ret = service_foreach_app_matched(service, dts_service_app_matched_cb, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_foreach_app_matched_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = service_foreach_app_matched(NULL, dts_service_app_matched_cb, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_foreach_app_matched_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_foreach_app_matched(service, NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_add_extra_data_array_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;

	service_h service;

	service_create(&service);

	ret = service_add_extra_data_array(service, array_key, array_value, array_length);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_add_extra_data_array_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};

	service_h service;

	service_create(&service);

	ret = service_add_extra_data_array(service, NULL, array_value, 4);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}


static void utc_service_add_extra_data_array_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";

	service_h service;

	service_create(&service);

	ret = service_add_extra_data_array(service, array_key, NULL, 4);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_add_extra_data_array_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};

	service_h service;

	service_create(&service);

	ret = service_add_extra_data_array(service, array_key, array_value, -1);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_extra_data_array_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;

	char** array_value_out;
	int array_length_out;

	service_h service;

	service_create(&service);

	service_add_extra_data_array(service, array_key, array_value, array_length);

	ret = service_get_extra_data_array(service, array_key, &array_value_out, &array_length_out);

	if(ret == SERVICE_ERROR_NONE && array_length_out == array_length)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_extra_data_array_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	char** array_value_out;
	int array_length_out;

	service_h service;

	service_create(&service);

	ret = service_get_extra_data_array(service, array_key, &array_value_out, &array_length_out);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_extra_data_array_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;
	char** array_value_out;
	int array_length_out;

	service_h service;

	service_create(&service);

	service_add_extra_data_array(service, array_key, array_value, array_length);

	ret = service_get_extra_data_array(NULL, array_key, &array_value_out, &array_length_out);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_extra_data_array_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;
	char** array_value_out;
	int array_length_out;

	service_h service;

	service_create(&service);

	service_add_extra_data_array(service, array_key, array_value, array_length);

	ret = service_get_extra_data_array(service, NULL, &array_value_out, &array_length_out);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_extra_data_array_negative4(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;
	int array_length_out;

	service_h service;

	service_create(&service);

	service_add_extra_data_array(service, array_key, array_value, array_length);

	ret = service_get_extra_data_array(service, array_key, NULL, &array_length_out);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_get_extra_data_array_negative5(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;
	char** array_value_out;

	service_h service;

	service_create(&service);

	service_add_extra_data_array(service, array_key, array_value, array_length);

	ret = service_get_extra_data_array(service, array_key, &array_value_out, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

}

static void utc_service_is_extra_data_array_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;
	bool is_array;

	service_h service;

	service_create(&service);

	service_add_extra_data_array(service, array_key, array_value, array_length);

	ret = service_is_extra_data_array(service, array_key, &is_array);

	if(ret == SERVICE_ERROR_NONE && is_array == true)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_is_extra_data_array_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *key = "key";

	bool is_array;

	service_h service;

	service_create(&service);

	ret = service_is_extra_data_array(service, key, &is_array);

	if(ret == SERVICE_ERROR_NONE && is_array == false)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_is_extra_data_array_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *key = "key";

	bool is_array;

	service_h service;

	service_create(&service);

	ret = service_is_extra_data_array(NULL, key, &is_array);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_is_extra_data_array_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	bool is_array;

	service_h service;

	service_create(&service);

	ret = service_is_extra_data_array(service, NULL, &is_array);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}

static void utc_service_is_extra_data_array_negative4(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *key = "key";

	service_h service;

	service_create(&service);

	ret = service_is_extra_data_array(service, key, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}


static void utc_service_is_reply_requested_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;
	bool requested;

	service_create(&service);

	ret = service_is_reply_requested(service, &requested);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}


static void utc_service_is_reply_requested_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_is_reply_requested(service, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}


static void utc_service_is_reply_requested_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	bool requsted = false;

	ret = service_is_reply_requested(NULL, &requsted);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_is_reply_requested_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = service_is_reply_requested(NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}


static void utc_service_get_caller_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;
	char *caller;

	service_create(&service);

	ret = service_get_caller(service, &caller);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}


static void utc_service_get_caller_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	service_h service;

	service_create(&service);

	ret = service_get_caller(service, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	service_destroy(service);
}


static void utc_service_get_caller_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	char *caller = NULL;

	ret = service_get_caller(NULL, &caller);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_service_get_caller_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = service_get_caller(NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

