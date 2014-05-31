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

static void utc_app_get_package_negative1(void);
static void utc_app_get_package_negative2(void);
static void utc_app_get_name_negative1(void);
static void utc_app_get_name_negative2(void);
static void utc_app_get_version_negative1(void);
static void utc_app_get_version_negative2(void);
static void utc_app_get_resource_negative1(void);
static void utc_app_get_resource_negative2(void);
static void utc_app_get_data_directory_negative1(void);
static void utc_app_get_data_directory_negative2(void);
static void utc_app_get_device_orientation_positive(void);
static void utc_app_set_reclaiming_system_cache_on_pause_positive1(void);
static void utc_app_set_reclaiming_system_cache_on_pause_positive2(void);

struct tet_testlist tet_testlist[] = {
	{ utc_app_get_package_negative1, 1 },
	{ utc_app_get_package_negative2, 1 },
	{ utc_app_get_name_negative1, 1 },
	{ utc_app_get_name_negative2, 1 },
	{ utc_app_get_version_negative1, 1 },
	{ utc_app_get_version_negative2, 1 },
	{ utc_app_get_resource_negative1, 1 },
	{ utc_app_get_resource_negative2, 1 },
	{ utc_app_get_data_directory_negative1, 1 },
	{ utc_app_get_data_directory_negative2, 1 },
	{ utc_app_get_device_orientation_positive, 1 },
	{ utc_app_set_reclaiming_system_cache_on_pause_positive1, 1 },
	{ utc_app_set_reclaiming_system_cache_on_pause_positive2, 1 },
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

static void utc_app_get_package_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = APP_ERROR_NONE;

	char *package = NULL;

	ret = app_get_package(&package);

	dts_message(API_NAME, "ret(%d), package(%s)", ret, package);

	if(ret == APP_ERROR_NONE)
	{
		dts_fail(API_NAME, "failed");
	}
	else
	{
		dts_pass(API_NAME, "passed");
	}
}


static void utc_app_get_package_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = APP_ERROR_NONE;

	ret = app_get_package(NULL);

	dts_message(API_NAME, "ret(%d)", ret);

	if(ret == APP_ERROR_NONE)
	{
		dts_fail(API_NAME, "failed");
	}
	else
	{
		dts_pass(API_NAME, "passed");
	}
}


static void utc_app_get_name_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = APP_ERROR_NONE;
	char *name = NULL;

	ret = app_get_name(&name);

	dts_message(API_NAME, "ret(%d), name(%s)", ret, name);

	if(ret == APP_ERROR_NONE)
	{
		dts_fail(API_NAME, "failed");
	}
	else
	{
		dts_pass(API_NAME, "passed");
	}
}

static void utc_app_get_name_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = APP_ERROR_NONE;

	ret = app_get_name(NULL);

	dts_message(API_NAME, "ret(%d)", ret);

	if(ret == APP_ERROR_NONE)
	{
		dts_fail(API_NAME, "failed");
	}
	else
	{
		dts_pass(API_NAME, "passed");
	}
}


static void utc_app_get_version_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = APP_ERROR_NONE;
	char *version = NULL;

	ret = app_get_version(&version);

	dts_message(API_NAME, "ret(%d), version(%s)", ret, version);

	if(ret == APP_ERROR_NONE)
	{
		dts_fail(API_NAME, "failed");
	}
	else
	{
		dts_pass(API_NAME, "passed");
	}
}


static void utc_app_get_version_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int ret = APP_ERROR_NONE;

	ret = app_get_version(NULL);

	dts_message(API_NAME, "ret(%d)", ret);

	if(ret == APP_ERROR_NONE)
	{
		dts_fail(API_NAME, "failed");
	}
	else
	{
		dts_pass(API_NAME, "passed");
	}
}


static void utc_app_get_resource_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	char *ret = NULL;
	char *path = NULL;
	int size = 0;

	ret = app_get_resource("res/image.jpg", path, size);

	dts_message(API_NAME, "ret(%s), path(%s)", ret, path);

	if(path != NULL)
	{
		dts_fail(API_NAME, "failed");
	}
	else
	{
		dts_pass(API_NAME, "passed");
	}
}


static void utc_app_get_resource_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	char *ret = NULL;
	int size = 0;

	ret = app_get_resource("res/image.jpg", NULL, size);

	dts_message(API_NAME, "ret(%s)", ret);

	if(ret != NULL)
	{
		dts_fail(API_NAME, "failed");
	}
	else
	{
		dts_pass(API_NAME, "passed");
	}
}


static void utc_app_get_data_directory_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	char *ret = NULL;
	char *path = NULL;
	int size =0;

	ret = app_get_data_directory(path, size);

	dts_message(API_NAME, "ret(%s), path(%s)", ret, path);

	if(ret != NULL)
	{
		dts_fail(API_NAME, "failed");
	}
	else
	{
		dts_pass(API_NAME, "passed");
	}
}


static void utc_app_get_data_directory_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	char *ret = NULL;
	int size = 0;

	ret = app_get_data_directory(NULL, size);

	dts_message(API_NAME, "ret(%s)", ret);

	if(ret != NULL)
	{
		dts_fail(API_NAME, "failed");
	}
	else
	{
		dts_pass(API_NAME, "passed");
	}
}

static void utc_app_get_device_orientation_positive(void)
{
	const char *API_NAME = __FUNCTION__;

	app_device_orientation_e orientation = APP_DEVICE_ORIENTATION_0;

	orientation = app_get_device_orientation();

	dts_message(API_NAME, "orientation(%d)", orientation);

	dts_pass(__FUNCTION__, "passed");
}

static void utc_app_set_reclaiming_system_cache_on_pause_positive1(void)
{
	const char *API_NAME = __FUNCTION__;

	app_set_reclaiming_system_cache_on_pause(true);

	dts_pass(API_NAME, "passed");
}

static void utc_app_set_reclaiming_system_cache_on_pause_positive2(void)
{
	const char *API_NAME = __FUNCTION__;

	app_set_reclaiming_system_cache_on_pause(false);

	dts_pass(API_NAME, "passed");
}

