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
#include <app.h>


static void startup(void);
static void cleanup(void);

void (*tet_startup)(void) = startup;
void (*tet_cleanup)(void) = cleanup;

static void utc_preference_set_int_negative1(void);
static void utc_preference_set_int_negative2(void);

static void utc_preference_set_double_negative1(void);
static void utc_preference_set_double_negative2(void);

static void utc_preference_set_string_negative1(void);
static void utc_preference_set_string_negative2(void);

static void utc_preference_set_boolean_negative1(void);
static void utc_preference_set_boolean_negative2(void);

static void utc_preference_get_int_negative1(void);
static void utc_preference_get_int_negative2(void);

static void utc_preference_get_double_negative1(void);
static void utc_preference_get_double_negative2(void);

static void utc_preference_get_string_negative1(void);
static void utc_preference_get_string_negative2(void);

static void utc_preference_get_boolean_negative1(void);
static void utc_preference_get_boolean_negative2(void);

static void utc_preference_remove_negative1(void);
static void utc_preference_remove_all_negative1(void);

static void utc_preference_is_existing_negative1(void);
static void utc_preference_is_existing_negative2(void);

static void utc_preference_set_changed_cb_negative1(void);
static void utc_preference_set_changed_cb_negative2(void);
static void utc_preference_set_changed_cb_negative3(void);

static void utc_preference_unset_changed_cb_negative1(void);
static void utc_preference_unset_changed_cb_negative2(void);

static void utc_preference_foreach_item_negative1(void);


struct tet_testlist tet_testlist[] = {
	{utc_preference_set_int_negative1, 2},
	{utc_preference_set_int_negative2, 2},

	{utc_preference_set_double_negative1, 2},
	{utc_preference_set_double_negative2, 2},

	{utc_preference_set_string_negative1, 2},
	{utc_preference_set_string_negative2, 2},

	{utc_preference_set_boolean_negative1, 2},
	{utc_preference_set_boolean_negative2, 2},

	{utc_preference_get_int_negative1, 2},
	{utc_preference_get_int_negative2, 2},

	{utc_preference_get_double_negative1, 2},
	{utc_preference_get_double_negative2, 2},

	{utc_preference_get_string_negative1, 2},
	{utc_preference_get_string_negative2, 2},

	{utc_preference_get_boolean_negative1, 2},
	{utc_preference_get_boolean_negative2, 2},

	{utc_preference_remove_negative1, 2},
	{utc_preference_remove_all_negative1, 2},

	{utc_preference_is_existing_negative1, 2},
	{utc_preference_is_existing_negative2, 2},

	{utc_preference_set_changed_cb_negative1, 2},
	{utc_preference_set_changed_cb_negative2, 2},
	{utc_preference_set_changed_cb_negative3, 2},

	{utc_preference_unset_changed_cb_negative1, 2},
	{utc_preference_unset_changed_cb_negative2, 2},

	{utc_preference_foreach_item_negative1, 2},

	{NULL, 0},
};

static void startup(void)
{

}


static void cleanup(void)
{
	/* end of TC */
}

static void utc_preference_set_int_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	const char *key = "preference_key";

	int ret;

	ret = preference_set_int(key, 1);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_set_int_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_set_int(NULL, 1);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_set_double_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	const char *key = "preference_key";

	int ret;

	ret = preference_set_double(key, 1.0);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_set_double_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_set_double(NULL, 1.0);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_set_string_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	const char *key = "preference_key";

	int ret;

	ret = preference_set_string(key, "string");
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_set_string_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_set_string(NULL, "string");
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_set_boolean_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	const char *key = "preference_key";

	int ret;

	ret = preference_set_boolean(key, true);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_set_boolean_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_set_boolean(NULL, true);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}


static void utc_preference_get_int_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	int value;

	int ret;

	ret = preference_get_int(NULL, &value);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_get_int_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	const char *key = "key";

	int ret;

	ret = preference_get_int(key, NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_get_double_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	double value;

	int ret;

	ret = preference_get_double(NULL, &value);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_get_double_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	const char *key = "key";

	int ret;

	ret = preference_get_double(key, NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_get_string_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	char *value;

	int ret;

	ret = preference_get_string(NULL, &value);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_get_string_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	const char *key = "key";

	int ret;

	ret = preference_get_string(key, NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_get_boolean_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	bool value;

	int ret;

	ret = preference_get_boolean(NULL, &value);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_get_boolean_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	const char *key = "key";

	int ret;

	ret = preference_get_boolean(key, NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_remove_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_remove(NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_remove_all_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_remove_all();
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_is_existing_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	bool is_exist;

	int ret;

	ret = preference_is_existing(NULL,&is_exist);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_is_existing_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_is_existing("key", NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void dts_preference_changed_cb(const char *key, void *user_data)
{

}

static void utc_preference_set_changed_cb_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_set_changed_cb(NULL, dts_preference_changed_cb, NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_set_changed_cb_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_set_changed_cb("key", NULL, NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_set_changed_cb_negative3(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_set_changed_cb("key", dts_preference_changed_cb, NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_unset_changed_cb_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_unset_changed_cb(NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_unset_changed_cb_negative2(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_unset_changed_cb("key");
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_preference_foreach_item_negative1(void)
{
	const char *API_NAME = __FUNCTION__;

	int ret;

	ret = preference_foreach_item(NULL, NULL);
	
	if (ret != PREFERENCE_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

