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

static void utc_app_control_create_positive(void);
static void utc_app_control_create_negative(void);

static void utc_app_control_destroy_positive(void);
static void utc_app_control_destroy_negative(void);

static void utc_app_control_set_operation_positive1(void);
static void utc_app_control_set_operation_positive2(void);
static void utc_app_control_set_operation_negative(void);

static void utc_app_control_get_operation_positive(void);
static void utc_app_control_get_operation_negative1(void);
static void utc_app_control_get_operation_negative2(void);
static void utc_app_control_get_operation_negative3(void);

static void utc_app_control_set_uri_positive1(void);
static void utc_app_control_set_uri_positive2(void);
static void utc_app_control_set_uri_negative(void);

static void utc_app_control_get_uri_positive(void);
static void utc_app_control_get_uri_negative1(void);
static void utc_app_control_get_uri_negative2(void);
static void utc_app_control_get_uri_negative3(void);

static void utc_app_control_set_mime_positive1(void);
static void utc_app_control_set_mime_positive2(void);
static void utc_app_control_set_mime_negative(void);

static void utc_app_control_get_mime_positive(void);
static void utc_app_control_get_mime_negative1(void);
static void utc_app_control_get_mime_negative2(void);
static void utc_app_control_get_mime_negative3(void);

static void utc_app_control_set_package_positive(void);
static void utc_app_control_set_package_negative1(void);
static void utc_app_control_set_package_negative2(void);

static void utc_app_control_get_package_positive(void);
static void utc_app_control_get_package_negative1(void);
static void utc_app_control_get_package_negative2(void);
static void utc_app_control_get_package_negative3(void);

static void utc_app_control_set_app_id_positive(void);
static void utc_app_control_set_app_id_negative1(void);
static void utc_app_control_set_app_id_negative2(void);

static void utc_app_control_get_app_id_positive(void);
static void utc_app_control_get_app_id_negative1(void);
static void utc_app_control_get_app_id_negative2(void);
static void utc_app_control_get_app_id_negative3(void);

static void utc_app_control_set_category_positive(void);
static void utc_app_control_set_category_negative1(void);
static void utc_app_control_set_category_negative2(void);

static void utc_app_control_get_category_positive(void);
static void utc_app_control_get_category_negative1(void);
static void utc_app_control_get_category_negative2(void);
static void utc_app_control_get_category_negative3(void);

static void utc_app_control_set_window_positive(void);
static void utc_app_control_set_window_negative1(void);
static void utc_app_control_set_window_negative2(void);

static void utc_app_control_get_window_positive(void);
static void utc_app_control_get_window_negative1(void);
static void utc_app_control_get_window_negative2(void);
static void utc_app_control_get_window_negative3(void);

static void utc_app_control_add_extra_data_positive(void);
static void utc_app_control_add_extra_data_negative1(void);
static void utc_app_control_add_extra_data_negative2(void);

static void utc_app_control_remove_extra_data_positive(void);
static void utc_app_control_remove_extra_data_negative1(void);
static void utc_app_control_remove_extra_data_negative2(void);
static void utc_app_control_remove_extra_data_negative3(void);

static void utc_app_control_get_extra_data_positive(void);
static void utc_app_control_get_extra_data_negative1(void);
static void utc_app_control_get_extra_data_negative2(void);
static void utc_app_control_get_extra_data_negative3(void);
static void utc_app_control_get_extra_data_negative4(void);

static void utc_app_control_foreach_extra_data_positive(void);
static void utc_app_control_foreach_extra_data_negative1(void);
static void utc_app_control_foreach_extra_data_negative2(void);

static void utc_app_control_clone_positive(void);
static void utc_app_control_clone_negative1(void);
static void utc_app_control_clone_negative2(void);

static void utc_app_control_send_launch_request_positive1(void);
static void utc_app_control_send_launch_request_positive2(void);
static void utc_app_control_send_launch_request_positive3(void);
static void utc_app_control_send_launch_request_negative1(void);
static void utc_app_control_send_launch_request_negative2(void);

static void utc_app_control_reply_to_launch_request_negative1(void);
static void utc_app_control_reply_to_launch_request_negative2(void);

static void utc_app_control_foreach_app_matched_positive(void);
static void utc_app_control_foreach_app_matched_negative1(void);
static void utc_app_control_foreach_app_matched_negative2(void);

static void utc_app_control_add_extra_data_array_positive(void);
static void utc_app_control_add_extra_data_array_negative1(void);
static void utc_app_control_add_extra_data_array_negative2(void);
static void utc_app_control_add_extra_data_array_negative3(void);

static void utc_app_control_get_extra_data_array_positive(void);
static void utc_app_control_get_extra_data_array_negative1(void);
static void utc_app_control_get_extra_data_array_negative2(void);
static void utc_app_control_get_extra_data_array_negative3(void);
static void utc_app_control_get_extra_data_array_negative4(void);
static void utc_app_control_get_extra_data_array_negative5(void);

static void utc_app_control_is_extra_data_array_positive(void);
static void utc_app_control_is_extra_data_array_negative1(void);
static void utc_app_control_is_extra_data_array_negative2(void);
static void utc_app_control_is_extra_data_array_negative3(void);
static void utc_app_control_is_extra_data_array_negative4(void);


static void utc_app_control_is_reply_requested_positive1(void);
static void utc_app_control_is_reply_requested_negative1(void);
static void utc_app_control_is_reply_requested_negative2(void);
static void utc_app_control_is_reply_requested_negative3(void);

static void utc_app_control_get_caller_positive1(void);
static void utc_app_control_get_caller_negative1(void);
static void utc_app_control_get_caller_negative2(void);
static void utc_app_control_get_caller_negative3(void);

static void utc_app_control_to_bundle_positive1(void);
static void utc_app_control_to_bundle_negative1(void);
static void utc_app_control_to_bundle_negative2(void);
static void utc_app_control_to_bundle_negative3(void);


struct tet_testlist tet_testlist[] = {
	{ utc_app_control_create_positive, 1 },
	{ utc_app_control_create_negative, 1 },
	{ utc_app_control_destroy_positive, 1 },
	{ utc_app_control_destroy_negative, 1 },
	{ utc_app_control_set_operation_positive1, 1 },
	{ utc_app_control_set_operation_positive2, 1 },
	{ utc_app_control_set_operation_negative, 1 },
	{ utc_app_control_get_operation_positive, 1 },
	{ utc_app_control_get_operation_negative1, 1 },
	{ utc_app_control_get_operation_negative2, 1 },
	{ utc_app_control_get_operation_negative3, 1 },
	{ utc_app_control_set_uri_positive1, 1 },
	{ utc_app_control_set_uri_positive2, 1 },
	{ utc_app_control_set_uri_negative, 1 },
	{ utc_app_control_get_uri_positive, 1 },
	{ utc_app_control_get_uri_negative1, 1 },
	{ utc_app_control_get_uri_negative2, 1 },
	{ utc_app_control_get_uri_negative3, 1 },
	{ utc_app_control_set_mime_positive1, 1 },
	{ utc_app_control_set_mime_positive2, 1 },
	{ utc_app_control_set_mime_negative, 1 },
	{ utc_app_control_get_mime_positive, 1 },
	{ utc_app_control_get_mime_negative1, 1 },
	{ utc_app_control_get_mime_negative2, 1 },
	{ utc_app_control_get_mime_negative3, 1 },
	{ utc_app_control_set_package_positive, 1 },
	{ utc_app_control_set_package_negative1, 1 },
	{ utc_app_control_set_package_negative2, 1 },
	{ utc_app_control_get_package_positive, 1 },
	{ utc_app_control_get_package_negative1, 1 },
	{ utc_app_control_get_package_negative2, 1 },
	{ utc_app_control_get_package_negative3, 1 },
	{ utc_app_control_set_app_id_positive, 1 },
	{ utc_app_control_set_app_id_negative1, 1 },
	{ utc_app_control_set_app_id_negative2, 1 },
	{ utc_app_control_get_app_id_positive, 1 },
	{ utc_app_control_get_app_id_negative1, 1 },
	{ utc_app_control_get_app_id_negative2, 1 },
	{ utc_app_control_get_app_id_negative3, 1 },
	{ utc_app_control_set_category_positive, 1 },
	{ utc_app_control_set_category_negative1, 1 },
	{ utc_app_control_set_category_negative2, 1 },
	{ utc_app_control_get_category_positive, 1 },
	{ utc_app_control_get_category_negative1, 1 },
	{ utc_app_control_get_category_negative2, 1 },
	{ utc_app_control_get_category_negative3, 1 },
	{ utc_app_control_set_window_positive, 1 },
	{ utc_app_control_set_window_negative1, 1 },
	{ utc_app_control_set_window_negative2, 1 },
	{ utc_app_control_get_window_positive, 1 },
	{ utc_app_control_get_window_negative1, 1 },
	{ utc_app_control_get_window_negative2, 1 },
	{ utc_app_control_get_window_negative3, 1 },
	{ utc_app_control_add_extra_data_positive, 1 },
	{ utc_app_control_add_extra_data_negative1, 1 },
	{ utc_app_control_add_extra_data_negative2, 1 },
	{ utc_app_control_remove_extra_data_positive, 1 },
	{ utc_app_control_remove_extra_data_negative1, 1 },
	{ utc_app_control_remove_extra_data_negative2, 1 },
	{ utc_app_control_remove_extra_data_negative3, 1 },
	{ utc_app_control_get_extra_data_positive, 1 },
	{ utc_app_control_get_extra_data_negative1, 1 },
	{ utc_app_control_get_extra_data_negative2, 1 },
	{ utc_app_control_get_extra_data_negative3, 1 },
	{ utc_app_control_get_extra_data_negative4, 1 },
	{ utc_app_control_foreach_extra_data_positive, 1 },
	{ utc_app_control_foreach_extra_data_negative1, 1 },
	{ utc_app_control_foreach_extra_data_negative2, 1 },
	{ utc_app_control_clone_positive, 1 },
	{ utc_app_control_clone_negative1, 1 },
	{ utc_app_control_clone_negative2, 1 },
	{ utc_app_control_send_launch_request_positive1, 1 },
	{ utc_app_control_send_launch_request_positive2, 1 },
	{ utc_app_control_send_launch_request_positive3, 1 },
	{ utc_app_control_send_launch_request_negative1, 1 },
	{ utc_app_control_send_launch_request_negative2, 1 },
	{ utc_app_control_reply_to_launch_request_negative1, 1 },
	{ utc_app_control_reply_to_launch_request_negative2, 1 },
	{ utc_app_control_foreach_app_matched_positive, 1 },
	{ utc_app_control_foreach_app_matched_negative1, 1 },
	{ utc_app_control_foreach_app_matched_negative2, 1 },
	{ utc_app_control_add_extra_data_array_positive, 1 },
	{ utc_app_control_add_extra_data_array_negative1, 1 },
	{ utc_app_control_add_extra_data_array_negative2, 1 },
	{ utc_app_control_add_extra_data_array_negative3, 1 },
	{ utc_app_control_get_extra_data_array_positive, 1 },
	{ utc_app_control_get_extra_data_array_negative1, 1 },
	{ utc_app_control_get_extra_data_array_negative2, 1 },
	{ utc_app_control_get_extra_data_array_negative3, 1 },
	{ utc_app_control_get_extra_data_array_negative4, 1 },
	{ utc_app_control_get_extra_data_array_negative5, 1 },
	{ utc_app_control_is_extra_data_array_positive, 1 },
	{ utc_app_control_is_extra_data_array_negative1, 1 },
	{ utc_app_control_is_extra_data_array_negative2, 1 },
	{ utc_app_control_is_extra_data_array_negative3, 1 },
	{ utc_app_control_is_extra_data_array_negative4, 1 },
	{ utc_app_control_is_reply_requested_positive1, 1 },
	{ utc_app_control_is_reply_requested_negative1, 1 },
	{ utc_app_control_is_reply_requested_negative2, 1 },
	{ utc_app_control_is_reply_requested_negative3, 1 },
	{ utc_app_control_get_caller_positive1, 1 },
	{ utc_app_control_get_caller_negative1, 1 },
	{ utc_app_control_get_caller_negative2, 1 },
	{ utc_app_control_get_caller_negative3, 1 },
	{ utc_app_control_to_bundle_positive1, 1 },
	{ utc_app_control_to_bundle_negative1, 1 },
	{ utc_app_control_to_bundle_negative2, 1 },
	{ utc_app_control_to_bundle_negative3, 1 },
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


static void utc_app_control_create_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	ret = app_control_create(&app_control);

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

static void utc_app_control_create_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_create(NULL);

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


static void utc_app_control_destroy_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_destroy(app_control);

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


static void utc_app_control_destroy_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_destroy(NULL);

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


static void utc_app_control_set_operation_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *input_value = "INPUT_VALUE";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_set_operation(app_control, input_value);

	dts_message(API_NAME, "ret(%d)", ret);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);

}

static void utc_app_control_set_operation_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_set_operation(app_control, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_operation_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	ret = app_control_set_operation(NULL, input_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}



static void utc_app_control_get_operation_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_operation(app_control, input_value);

	ret = app_control_get_operation(app_control, &output_value);

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

	app_control_destroy(app_control);

}

static void utc_app_control_get_operation_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = app_control_get_operation(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_operation_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_operation(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_operation_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_operation(app_control, &output_value);

	if(ret == SERVICE_ERROR_NONE && output_value == NULL)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_uri_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_set_uri(app_control, input_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);

}

static void utc_app_control_set_uri_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_set_uri(app_control, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);

}

static void utc_app_control_set_uri_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	ret = app_control_get_uri(NULL, input_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_uri_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_uri(app_control, input_value);

	app_control_get_uri(app_control, &output_value);

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

	app_control_destroy(app_control);

}

static void utc_app_control_get_uri_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_uri(app_control, &output_value);

	if(ret == SERVICE_ERROR_NONE && output_value == NULL)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);

}

static void utc_app_control_get_uri_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = app_control_get_uri(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

}

static void utc_app_control_get_uri_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_uri(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);

}

static void utc_app_control_set_mime_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_set_mime(app_control, input_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_mime_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_set_mime(app_control, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}


static void utc_app_control_set_mime_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	ret = app_control_set_mime(NULL, input_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_mime_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_mime(app_control, input_value);

	ret = app_control_get_mime(app_control, &output_value);

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

	app_control_destroy(app_control);
}

static void utc_app_control_get_mime_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_mime(app_control, &output_value);

	if(ret == SERVICE_ERROR_NONE && output_value == NULL)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_mime_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = app_control_get_mime(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_mime_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_mime(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_package_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_set_package(app_control, input_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_package_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	ret = app_control_set_package(NULL, input_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_set_package_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_set_package(NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_package_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_package(app_control, input_value);

	ret = app_control_get_package(app_control, &output_value);

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

	app_control_destroy(app_control);
}

static void utc_app_control_get_package_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_package(app_control, &output_value);

	if(ret == SERVICE_ERROR_NONE && output_value == NULL)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_package_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = app_control_get_package(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_package_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_package(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_app_id_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_set_app_id(app_control, input_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_app_id_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_set_app_id(NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_set_app_id_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	ret = app_control_set_app_id(NULL, input_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_app_id_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_app_id(app_control, input_value);

	ret = app_control_get_app_id(app_control, &output_value);

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

	app_control_destroy(app_control);
}

static void utc_app_control_get_app_id_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_app_id(app_control, &output_value);

	if(ret == SERVICE_ERROR_NONE && output_value == NULL)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_app_id_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = app_control_get_app_id(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_app_id_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_app_id(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_category_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_set_category(app_control, input_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_category_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_set_category(NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_set_category_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";

	ret = app_control_set_category(NULL, input_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_category_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	const char *input_value = "INPUT_VALUE";
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_category(app_control, input_value);

	ret = app_control_get_category(app_control, &output_value);

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

	app_control_destroy(app_control);
}

static void utc_app_control_get_category_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_category(app_control, &output_value);

	if(ret == SERVICE_ERROR_NONE && output_value == NULL)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_category_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *output_value;

	ret = app_control_get_category(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_category_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_category(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_window_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	unsigned int wid = 5;
	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_set_window(app_control, wid);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_set_window_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_set_window(NULL, -1);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_set_window_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	unsigned int wid = 5;

	ret = app_control_set_window(NULL, wid);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_window_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	unsigned int wid = 5;
	int output_value = 0;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_window(app_control, wid);

	ret = app_control_get_window(app_control, &output_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		if(wid == output_value)
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

	app_control_destroy(app_control);
}

static void utc_app_control_get_window_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	int output_value = 0;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_window(app_control, &output_value);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_window_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	int output_value = 0;

	ret = app_control_get_window(NULL, &output_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_window_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_window(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_add_extra_data_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *value = "EXTRA_VALUE";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_add_extra_data(app_control, key, value);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_add_extra_data_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int passed = 0;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *value = "EXTRA_VALUE";

	app_control_h app_control;

	app_control_create(&app_control);


	// key : unll
	ret = app_control_add_extra_data(app_control, NULL, value);

	if(ret != SERVICE_ERROR_NONE)
	{
		passed++;
	}

	// key : zero-length
	ret = app_control_add_extra_data(app_control, "", value);

	if(ret != SERVICE_ERROR_NONE)
	{
		passed++;
	}

	// value : null
	ret = app_control_add_extra_data(app_control, key, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		passed++;
	}

	// value : zero-length
	ret = app_control_add_extra_data(app_control, key, "");

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

	app_control_destroy(app_control);
}

static void utc_app_control_add_extra_data_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *value = "EXTRA_VALUE";

	ret = app_control_add_extra_data(NULL, key, value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_remove_extra_data_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *value = "EXTRA_VALUE";

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_add_extra_data(app_control, key, value);

	ret = app_control_remove_extra_data(app_control, key);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_remove_extra_data_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_remove_extra_data(app_control, key);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_remove_extra_data_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";

	ret = app_control_remove_extra_data(NULL, key);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_remove_extra_data_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_remove_extra_data(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_extra_data_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *value = "EXTRA_VALUE";
	char *ret_value;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_add_extra_data(app_control, key, value);

	ret = app_control_get_extra_data(app_control, key, &ret_value);

	if(ret == SERVICE_ERROR_NONE && !strcmp(ret_value, value))
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_extra_data_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *ret_value;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_extra_data(app_control, key, &ret_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_extra_data_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";
	char *ret_value;

	ret = app_control_get_extra_data(NULL, key, &ret_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

}

static void utc_app_control_get_extra_data_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	char *ret_value;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_extra_data(app_control, NULL, &ret_value);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_extra_data_negative4(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	char *key = "EXTRA_KEY";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_extra_data(app_control, key, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

#define NUM_EXTRA_DATA 32

bool app_control_extra_data(app_control_h app_control, const char *key, void *user_data)
{
	bool *passed = (bool*)user_data;
	char *value;

	app_control_get_extra_data(app_control, key, &value);

	if (!strcmp(key, value))
	{
		int index = atoi(key);
		passed[index] = true;
	}

	return true;
}

static void utc_app_control_foreach_extra_data_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	int i;
	bool passed[NUM_EXTRA_DATA] = {0, };
	int num_passed = 0;
	char buf[32] = {0, };

	app_control_h app_control;

	app_control_create(&app_control);

	for (i=0; i<NUM_EXTRA_DATA; i++)
	{
		snprintf(buf, sizeof(buf), "%d", i);
		app_control_add_extra_data(app_control, buf, buf);
	}

	ret = app_control_foreach_extra_data(app_control, app_control_extra_data, &passed);

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

	app_control_destroy(app_control);
}

static void utc_app_control_foreach_extra_data_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_foreach_extra_data(app_control, NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_foreach_extra_data_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_foreach_extra_data(NULL, app_control_extra_data, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_clone_positive(void)
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

	app_control_h app_control;
	app_control_h app_control_cloned;

	app_control_create(&app_control);
	app_control_set_operation(app_control, operation);
	app_control_set_uri(app_control, uri);
	app_control_set_mime(app_control, mime);
	app_control_set_package(app_control, package);
	app_control_add_extra_data(app_control, extra_key, extra_value);

	ret = app_control_clone(&app_control_cloned, app_control);

	app_control_get_operation(app_control_cloned, &operation_clone);
	app_control_get_uri(app_control_cloned, &uri_clone);
	app_control_get_mime(app_control_cloned, &mime_clone);
	app_control_get_package(app_control_cloned, &package_clone);
	app_control_get_extra_data(app_control_cloned, extra_key, &extra_value_clone);


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

	app_control_destroy(app_control);
	app_control_destroy(app_control_cloned);
}

static void utc_app_control_clone_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control_cloned;

	ret = app_control_clone(&app_control_cloned, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_clone_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_clone(NULL, app_control);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}


void dts_app_control_reply_cb(app_control_h request, app_control_h reply, app_control_result_e result, void *user_data)
{

}

static void utc_app_control_send_launch_request_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_operation(app_control, SERVICE_OPERATION_DEFAULT);

	app_control_set_package(app_control, "org.tizen.calculator");

	// explicit launch without reply callback
	ret = app_control_send_launch_request(app_control, NULL, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);

}

static void utc_app_control_send_launch_request_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_operation(app_control, SERVICE_OPERATION_DEFAULT);

	app_control_set_package(app_control, "org.tizen.calculator");

	// explicit launch with reply callback
	ret = app_control_send_launch_request(app_control, dts_app_control_reply_cb, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_send_launch_request_positive3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_operation(app_control, SERVICE_OPERATION_VIEW);

	app_control_set_mime(app_control, "type/custom");

	ret = app_control_send_launch_request(app_control, dts_app_control_reply_cb, NULL);

	if(ret == SERVICE_ERROR_APP_NOT_FOUND)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_send_launch_request_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_send_launch_request(NULL, NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_send_launch_request_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_operation(app_control, SERVICE_OPERATION_DEFAULT);

	ret = app_control_send_launch_request(app_control, NULL, NULL);

	if(ret == SERVICE_ERROR_APP_NOT_FOUND)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_reply_to_launch_request_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h request;

	app_control_create(&request);

	ret = app_control_reply_to_launch_request(NULL, request, SERVICE_RESULT_CANCELED);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_reply_to_launch_request_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_reply_to_launch_request(app_control, NULL, SERVICE_RESULT_CANCELED);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

bool dts_app_control_app_matched_cb(app_control_h app_control, const char *package, void *user_data)
{
	return true;
}

static void utc_app_control_foreach_app_matched_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_set_operation(app_control, SERVICE_OPERATION_VIEW);

	ret = app_control_foreach_app_matched(app_control, dts_app_control_app_matched_cb, NULL);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_foreach_app_matched_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_foreach_app_matched(NULL, dts_app_control_app_matched_cb, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_foreach_app_matched_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_foreach_app_matched(app_control, NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_add_extra_data_array_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_add_extra_data_array(app_control, array_key, array_value, array_length);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_add_extra_data_array_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_add_extra_data_array(app_control, NULL, array_value, 4);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}


static void utc_app_control_add_extra_data_array_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_add_extra_data_array(app_control, array_key, NULL, 4);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_add_extra_data_array_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_add_extra_data_array(app_control, array_key, array_value, -1);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_extra_data_array_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;

	char** array_value_out;
	int array_length_out;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_add_extra_data_array(app_control, array_key, array_value, array_length);

	ret = app_control_get_extra_data_array(app_control, array_key, &array_value_out, &array_length_out);

	if(ret == SERVICE_ERROR_NONE && array_length_out == array_length)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_extra_data_array_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	char** array_value_out;
	int array_length_out;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_extra_data_array(app_control, array_key, &array_value_out, &array_length_out);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_extra_data_array_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;
	char** array_value_out;
	int array_length_out;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_add_extra_data_array(app_control, array_key, array_value, array_length);

	ret = app_control_get_extra_data_array(NULL, array_key, &array_value_out, &array_length_out);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_extra_data_array_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;
	char** array_value_out;
	int array_length_out;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_add_extra_data_array(app_control, array_key, array_value, array_length);

	ret = app_control_get_extra_data_array(app_control, NULL, &array_value_out, &array_length_out);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_extra_data_array_negative4(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;
	int array_length_out;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_add_extra_data_array(app_control, array_key, array_value, array_length);

	ret = app_control_get_extra_data_array(app_control, array_key, NULL, &array_length_out);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_get_extra_data_array_negative5(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;
	char** array_value_out;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_add_extra_data_array(app_control, array_key, array_value, array_length);

	ret = app_control_get_extra_data_array(app_control, array_key, &array_value_out, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

}

static void utc_app_control_is_extra_data_array_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *array_key = "array_key";
	const char* array_value[] = {"array_value1", "array_value2", "array_value3", "array_value4"};
	int array_length = 4;
	bool is_array;

	app_control_h app_control;

	app_control_create(&app_control);

	app_control_add_extra_data_array(app_control, array_key, array_value, array_length);

	ret = app_control_is_extra_data_array(app_control, array_key, &is_array);

	if(ret == SERVICE_ERROR_NONE && is_array == true)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_is_extra_data_array_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *key = "key";

	bool is_array;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_is_extra_data_array(app_control, key, &is_array);

	if(ret == SERVICE_ERROR_NONE && is_array == false)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_is_extra_data_array_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *key = "key";

	bool is_array;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_is_extra_data_array(NULL, key, &is_array);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_is_extra_data_array_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	bool is_array;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_is_extra_data_array(app_control, NULL, &is_array);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}

static void utc_app_control_is_extra_data_array_negative4(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	const char *key = "key";

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_is_extra_data_array(app_control, key, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}


static void utc_app_control_is_reply_requested_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;
	bool requested;

	app_control_create(&app_control);

	ret = app_control_is_reply_requested(app_control, &requested);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}


static void utc_app_control_is_reply_requested_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_is_reply_requested(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}


static void utc_app_control_is_reply_requested_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	bool requsted = false;

	ret = app_control_is_reply_requested(NULL, &requsted);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_is_reply_requested_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_is_reply_requested(NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}


static void utc_app_control_get_caller_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;
	char *caller;

	app_control_create(&app_control);

	ret = app_control_get_caller(app_control, &caller);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}


static void utc_app_control_get_caller_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_get_caller(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}


static void utc_app_control_get_caller_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	char *caller = NULL;

	ret = app_control_get_caller(NULL, &caller);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_get_caller_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_get_caller(NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_to_bundle_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;
	app_control_h app_control;
	bundle *data;
	const char *input_value = "INPUT_VALUE";

	app_control_create(&app_control);

	ret = app_control_set_package(app_control, input_value);

	ret = app_control_to_bundle(app_control, &data);

	if(ret == SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}


static void utc_app_control_to_bundle_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	app_control_h app_control;

	app_control_create(&app_control);

	ret = app_control_to_bundle(app_control, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}

	app_control_destroy(app_control);
}


static void utc_app_control_to_bundle_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	bundle *data = NULL;

	ret = app_control_to_bundle(NULL, &data);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}

static void utc_app_control_to_bundle_negative3(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = SERVICE_ERROR_NONE;

	ret = app_control_to_bundle(NULL, NULL);

	if(ret != SERVICE_ERROR_NONE)
	{
		dts_pass(API_NAME, "passed");
	}
	else
	{
		dts_fail(API_NAME, "failed");
	}
}
