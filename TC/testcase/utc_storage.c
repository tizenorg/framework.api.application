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

static void utc_storage_foreach_device_supported_positive(void);
static void utc_storage_foreach_device_supported_negative(void);
static void utc_storage_get_root_directory_positive(void);
static void utc_storage_get_root_directory_negative1(void);
static void utc_storage_get_root_directory_negative2(void);
static void utc_storage_get_type_positive(void);
static void utc_storage_get_type_negative1(void);
static void utc_storage_get_type_negative2(void);
static void utc_storage_get_state_positive(void);
static void utc_storage_get_state_negative1(void);
static void utc_storage_get_state_negative2(void);
static void utc_storage_get_total_space_positive(void);
static void utc_storage_get_total_space_negative1(void);
static void utc_storage_get_total_space_negative2(void);
static void utc_storage_get_available_space_positive(void);
static void utc_storage_get_available_space_negative1(void);
static void utc_storage_get_available_space_negative2(void);

static void utc_storage_set_state_changed_cb_positive(void);
static void utc_storage_set_state_changed_cb_negative1(void);
static void utc_storage_set_state_changed_cb_negative2(void);

static void utc_storage_unset_state_changed_cb_positive(void);
static void utc_storage_unset_state_changed_cb_negative(void);

struct tet_testlist tet_testlist[] = {
	{utc_storage_foreach_device_supported_positive, 1},
	{utc_storage_foreach_device_supported_negative, 2},
	{utc_storage_get_root_directory_positive, 1},
	{utc_storage_get_root_directory_negative1, 2},
	{utc_storage_get_root_directory_negative2, 2},
	{utc_storage_get_type_positive, 1},
	{utc_storage_get_type_negative1, 2},
	{utc_storage_get_type_negative2, 2},
	{utc_storage_get_state_positive, 1},
	{utc_storage_get_state_negative1, 2},
	{utc_storage_get_state_negative2, 2},
	{utc_storage_get_total_space_positive, 1},
	{utc_storage_get_total_space_negative1, 2},
	{utc_storage_get_total_space_negative2, 2},
	{utc_storage_get_available_space_positive, 1},
	{utc_storage_get_available_space_negative1, 2},
	{utc_storage_get_available_space_negative2, 2},
	{utc_storage_set_state_changed_cb_positive, 1},
	{utc_storage_set_state_changed_cb_negative1, 2},
	{utc_storage_set_state_changed_cb_negative2, 2},
	{utc_storage_unset_state_changed_cb_positive, 1},
	{utc_storage_unset_state_changed_cb_negative, 2},
	{NULL, 0},
};

static int internal_storage_id;

bool get_internal_storage(int storage, storage_type_e type,  storage_state_e state, const char *path, void *user_data)
{
	if (type == STORAGE_TYPE_INTERNAL) {
		internal_storage_id = storage;
		return false;
	}

	return true;
}

static void startup(void)
{
	storage_foreach_device_supported(get_internal_storage, NULL);
}


static void cleanup(void)
{
	/* end of TC */

}

bool get_storage_device(int storage, storage_type_e type, storage_state_e state,
			const char *path, void *user_data)
{
	return true;
}

static void utc_storage_foreach_device_supported_positive(void)
{
	int err;

	err = storage_foreach_device_supported(get_storage_device, NULL);

	if (err == STORAGE_ERROR_NONE) {
		dts_pass("utc_storage_foreach_device_supported_positive", "passed");
	} else {
		dts_fail("utc_storage_foreach_device_supported_positive", "failed");
	}

}

static void utc_storage_foreach_device_supported_negative(void)
{
	int err;

	err = storage_foreach_device_supported(NULL, NULL);

	if (err == STORAGE_ERROR_INVALID_PARAMETER) {
		dts_pass("utc_storage_foreach_device_supported_positive", "passed");
	} else {
		dts_fail("utc_storage_foreach_device_supported_positive", "failed");
	}
}

static void utc_storage_get_root_directory_positive(void)
{
	int err;
	char* path;
	err = storage_get_root_directory(internal_storage_id, &path);

	if ((err == STORAGE_ERROR_NONE) && (path != NULL)) {
		dts_pass("utc_storage_get_root_directory_positive", "passed");
	} else {
		dts_fail("utc_storage_get_root_directory_positive", "failed");
	}
}

static void utc_storage_get_root_directory_negative1(void)
{
	int err;
	char* path;
	err = storage_get_root_directory(10, &path);

	if (err == STORAGE_ERROR_NOT_SUPPORTED) {
		dts_pass("utc_storage_get_root_directory_negative1", "passed");
	} else {
		dts_fail("utc_storage_get_root_directory_negative1", "failed");
	}
}

static void utc_storage_get_root_directory_negative2(void)
{
	int err;
	
	err = storage_get_root_directory(internal_storage_id, NULL);

	if (err == STORAGE_ERROR_INVALID_PARAMETER) {
		dts_pass("utc_storage_get_root_directory_negative2", "passed");
	} else {
		dts_fail("utc_storage_get_root_directory_negative2", "failed");
	}
}

static void utc_storage_get_type_positive(void)
{
	int err;
	storage_type_e type;

	err = storage_get_type(internal_storage_id, &type);

	if ((err == STORAGE_ERROR_NONE) && (type == STORAGE_TYPE_INTERNAL)) {
		dts_pass("utc_storage_get_type_positive", "passed");
	} else {
		dts_fail("utc_storage_get_type_positive", "failed");
	}
}

static void utc_storage_get_type_negative1(void)
{
	int err;
	storage_type_e type;
	err = storage_get_type(10, &type);

	if (err == STORAGE_ERROR_NOT_SUPPORTED) {
		dts_pass("utc_storage_get_type_negative1", "passed");
	} else {
		dts_fail("utc_storage_get_type_negative1", "failed");
	}
}

static void utc_storage_get_type_negative2(void)
{
	int err;
	err = storage_get_type(internal_storage_id, NULL);

	if (err == STORAGE_ERROR_INVALID_PARAMETER) {
		dts_pass("utc_storage_get_type_negative2", "passed");
	} else {
		dts_fail("utc_storage_get_type_negative2", "failed");
	}
}


static void utc_storage_get_state_positive(void)
{
	int err;
	storage_state_e state;

	err = storage_get_state(internal_storage_id, &state);

	if ((err == STORAGE_ERROR_NONE) && (state == STORAGE_STATE_MOUNTED)) {
		dts_pass("utc_storage_get_state_positive", "passed");
	} else {
		dts_fail("utc_storage_get_state_positive", "failed");
	}
}

static void utc_storage_get_state_negative1(void)
{
	int err;
	storage_state_e state;
	err = storage_get_state(10, &state);

	if (err == STORAGE_ERROR_NOT_SUPPORTED) {
		dts_pass("utc_storage_get_state_negative1", "passed");
	} else {
		dts_fail("utc_storage_get_state_negative1", "failed");
	}
}

static void utc_storage_get_state_negative2(void)
{
	int err;
	err = storage_get_state(internal_storage_id, NULL);

	if (err == STORAGE_ERROR_INVALID_PARAMETER) {
		dts_pass("utc_storage_get_state_negative2", "passed");
	} else {
		dts_fail("utc_storage_get_state_negative2", "failed");
	}
}


static void utc_storage_get_total_space_positive(void)
{
	int err;
	unsigned long long size;

	err = storage_get_total_space(internal_storage_id, &size);

	if (err == STORAGE_ERROR_NONE) {
		dts_pass("utc_storage_get_total_space_positive", "passed");
	} else {
		dts_fail("utc_storage_get_total_space_positive", "failed");
	}
}

static void utc_storage_get_total_space_negative1(void)
{
	int err;
	unsigned long long size;
	err = storage_get_total_space(10, &size);

	if (err == STORAGE_ERROR_NOT_SUPPORTED) {
		dts_pass("utc_storage_get_total_space_negative1", "passed");
	} else {
		dts_fail("utc_storage_get_total_space_negative1", "failed");
	}
}

static void utc_storage_get_total_space_negative2(void)
{
	int err;
	err = storage_get_total_space(internal_storage_id, NULL);

	if (err == STORAGE_ERROR_INVALID_PARAMETER) {
		dts_pass("utc_storage_get_total_space_negative2", "passed");
	} else {
		dts_fail("utc_storage_get_total_space_negative2", "failed");
	}
}


static void utc_storage_get_available_space_positive(void)
{
	int err;
	unsigned long long size;

	err = storage_get_available_space(internal_storage_id, &size);

	if (err == STORAGE_ERROR_NONE) {
		dts_pass("utc_storage_get_available_space_positive", "passed");
	} else {
		dts_fail("utc_storage_get_available_space_positive", "failed");
	}
}

static void utc_storage_get_available_space_negative1(void)
{
	int err;
	unsigned long long size;
	err = storage_get_available_space(10, &size);

	if (err == STORAGE_ERROR_NOT_SUPPORTED) {
		dts_pass("utc_storage_get_available_space_negative1", "passed");
	} else {
		dts_fail("utc_storage_get_available_space_negative1", "failed");
	}
}

static void utc_storage_get_available_space_negative2(void)
{
	int err;
	err = storage_get_available_space(internal_storage_id, NULL);

	if (err == STORAGE_ERROR_INVALID_PARAMETER) {
		dts_pass("utc_storage_get_available_space_negative2", "passed");
	} else {
		dts_fail("utc_storage_get_available_space_negative2", "failed");
	}
}

static void dts_storage_state_changed_cb(int storage, storage_state_e state, void *user_data)
{

}

static void utc_storage_set_state_changed_cb_positive(void)
{
	int err;

	err = storage_set_state_changed_cb(0, dts_storage_state_changed_cb, NULL);

	if (err == STORAGE_ERROR_NONE) {
		dts_pass("utc_storage_set_state_changed_cb_positive", "passed");
	} else {
		dts_fail("utc_storage_set_state_changed_cb_positive", "failed");
	}
}

static void utc_storage_set_state_changed_cb_negative1(void)
{
	int err;

	err = storage_set_state_changed_cb(-1, dts_storage_state_changed_cb, NULL);

	if (err == STORAGE_ERROR_NOT_SUPPORTED) {
		dts_pass("utc_storage_set_state_changed_cb_negative1", "passed");
	} else {
		dts_fail("utc_storage_set_state_changed_cb_negative1", "failed");
	}
}

static void utc_storage_set_state_changed_cb_negative2(void)
{
	int err;

	err = storage_set_state_changed_cb(0, NULL, NULL);

	if (err == STORAGE_ERROR_INVALID_PARAMETER) {
		dts_pass("utc_storage_set_state_changed_cb_negative2", "passed");
	} else {
		dts_fail("utc_storage_set_state_changed_cb_negative2", "failed");
	}
}

static void utc_storage_unset_state_changed_cb_positive(void)
{
	int err;

	storage_set_state_changed_cb(0, dts_storage_state_changed_cb, NULL);

	err = storage_unset_state_changed_cb(0);

	if (err == STORAGE_ERROR_NONE) {
		dts_pass("utc_storage_unset_state_changed_cb_positive", "passed");
	} else {
		dts_fail("utc_storage_unset_state_changed_cb_positive", "failed");
	}
}

static void utc_storage_unset_state_changed_cb_negative(void)
{
	int err;

	err = storage_unset_state_changed_cb(-1);

	if (err == STORAGE_ERROR_NOT_SUPPORTED) {
		dts_pass("utc_storage_unset_state_changed_cb_negative", "passed");
	} else {
		dts_fail("utc_storage_unset_state_changed_cb_negative", "failed");
	}
}

