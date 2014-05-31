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

static void utc_notification_create_positive(void);
static void utc_notification_create_negative(void);

static void utc_notification_create_ongoing_positive(void);
static void utc_notification_create_ongoing_negative(void);

static void utc_notification_destroy_positive(void);
static void utc_notification_destroy_negative(void);

static void utc_notification_is_ongoing_positive1(void);
static void utc_notification_is_ongoing_positive2(void);
static void utc_notification_is_ongoing_negative1(void);
static void utc_notification_is_ongoing_negative2(void);

static void utc_notification_set_icon_positive1(void);
static void utc_notification_set_icon_positive2(void);
static void utc_notification_set_icon_negative1(void);

static void utc_notification_get_icon_positive(void);
static void utc_notification_get_icon_negative1(void);
static void utc_notification_get_icon_negative2(void);

static void utc_notification_set_time_positive1(void);
static void utc_notification_set_time_positive2(void);
static void utc_notification_set_time_negative1(void);

static void utc_notification_get_time_positive(void);
static void utc_notification_get_time_negative1(void);
static void utc_notification_get_time_negative2(void);

static void utc_notification_set_title_positive1(void);
static void utc_notification_set_title_positive2(void);
static void utc_notification_set_title_negative1(void);

static void utc_notification_get_title_positive(void);
static void utc_notification_get_title_negative1(void);
static void utc_notification_get_title_negative2(void);

static void utc_notification_set_content_positive1(void);
static void utc_notification_set_content_positive2(void);
static void utc_notification_set_content_negative1(void);

static void utc_notification_get_content_positive(void);
static void utc_notification_get_content_negative1(void);
static void utc_notification_get_content_negative2(void);

static void utc_notification_set_service_positive1(void);
static void utc_notification_set_service_positive2(void);
static void utc_notification_set_service_negative1(void);

static void utc_notification_get_service_positive(void);
static void utc_notification_get_service_negative1(void);
static void utc_notification_get_service_negative2(void);

static void utc_notification_set_sound_positive1(void);
static void utc_notification_set_sound_positive2(void);
static void utc_notification_set_sound_negative1(void);

static void utc_notification_get_sound_positive(void);
static void utc_notification_get_sound_negative1(void);
static void utc_notification_get_sound_negative2(void);

static void utc_notification_set_vibration_positive1(void);
static void utc_notification_set_vibration_positive2(void);
static void utc_notification_set_vibration_negative1(void);

static void utc_notification_get_vibration_positive(void);
static void utc_notification_get_vibration_negative1(void);
static void utc_notification_get_vibration_negative2(void);

static void utc_notification_post_negative1(void);

static void utc_notification_cancel_negative1(void);

static void utc_notification_cancel_all_positive(void);

static void utc_notification_cancel_all_by_type_positive1(void);
static void utc_notification_cancel_all_by_type_positive2(void);

static void utc_notification_update_negative1(void);

static void utc_notification_update_progress_negative1(void);

static void utc_notification_foreach_notification_posted_positive1(void);
static void utc_notification_foreach_notification_posted_positive2(void);
static void utc_notification_foreach_notification_posted_negative1(void);
static void utc_notification_foreach_notification_posted_negative2(void);

static void utc_notification_clone_positive1(void);
static void utc_notification_clone_positive2(void);
static void utc_notification_clone_positive3(void);
static void utc_notification_clone_positive4(void);
static void utc_notification_clone_negative1(void);
static void utc_notification_clone_negative2(void);

struct tet_testlist tet_testlist[] = {
	{utc_notification_create_positive, 1},
	{utc_notification_create_negative, 1},
	{utc_notification_create_ongoing_positive, 1},
	{utc_notification_create_ongoing_negative, 1},
	{utc_notification_destroy_positive, 1},
	{utc_notification_destroy_negative, 1},
	{utc_notification_is_ongoing_positive1, 1},
	{utc_notification_is_ongoing_positive2, 1},
	{utc_notification_is_ongoing_negative1, 1},
	{utc_notification_is_ongoing_negative2, 1},
	{utc_notification_set_icon_positive1, 1},
	{utc_notification_set_icon_positive2, 1},
	{utc_notification_set_icon_negative1, 1},
	{utc_notification_get_icon_positive, 1},
	{utc_notification_get_icon_negative1, 1},
	{utc_notification_get_icon_negative2, 1},
	{utc_notification_set_time_positive1, 1},
	{utc_notification_set_time_positive2, 1},
	{utc_notification_set_time_negative1, 1},
	{utc_notification_get_time_positive, 1},
	{utc_notification_get_time_negative1, 1},
	{utc_notification_get_time_negative2, 1},
	{utc_notification_set_title_positive1, 1},
	{utc_notification_set_title_positive2, 1},
	{utc_notification_set_title_negative1, 1},
	{utc_notification_get_title_positive, 1},
	{utc_notification_get_title_negative1, 1},
	{utc_notification_get_title_negative2, 1},
	{utc_notification_set_content_positive1, 1},
	{utc_notification_set_content_positive2, 1},
	{utc_notification_set_content_negative1, 1},
	{utc_notification_get_content_positive, 1},
	{utc_notification_get_content_negative1, 1},
	{utc_notification_get_content_negative2, 1},
	{utc_notification_set_service_positive1, 1},
	{utc_notification_set_service_positive2, 1},
	{utc_notification_set_service_negative1, 1},
	{utc_notification_get_service_positive, 1},
	{utc_notification_get_service_negative1, 1},
	{utc_notification_get_service_negative2, 1},
	{utc_notification_set_sound_positive1, 1},
	{utc_notification_set_sound_positive2, 1},
	{utc_notification_set_sound_negative1, 1},
	{utc_notification_get_sound_positive, 1},
	{utc_notification_get_sound_negative1, 1},
	{utc_notification_get_sound_negative2, 1},
	{utc_notification_set_vibration_positive1, 1},
	{utc_notification_set_vibration_positive2, 1},
	{utc_notification_set_vibration_negative1, 1},
	{utc_notification_get_vibration_positive, 1},
	{utc_notification_get_vibration_negative1, 1},
	{utc_notification_get_vibration_negative2, 1},
	{utc_notification_post_negative1, 1},
	{utc_notification_cancel_negative1, 1},
	{utc_notification_cancel_all_positive, 1},
	{utc_notification_cancel_all_by_type_positive1, 1},
	{utc_notification_cancel_all_by_type_positive2, 1},
	{utc_notification_update_negative1, 1},
	{utc_notification_update_progress_negative1, 1},
	{utc_notification_foreach_notification_posted_positive1, 1},
	{utc_notification_foreach_notification_posted_positive2, 1},
	{utc_notification_foreach_notification_posted_negative1, 1},
	{utc_notification_foreach_notification_posted_negative2, 1},
	{utc_notification_clone_positive1, 1},
	{utc_notification_clone_positive2, 1},
	{utc_notification_clone_positive3, 1},
	{utc_notification_clone_positive4, 1},
	{utc_notification_clone_negative1, 1},
	{utc_notification_clone_negative2, 1},
	{NULL, 0},
};

static void startup(void)
{

}


static void cleanup(void)
{
	/* end of TC */
}

static void utc_notification_create_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	retcode = ui_notification_create(false, &notification);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_create_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_create(false, NULL);

	if (retcode != UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_create_ongoing_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	retcode = ui_notification_create(true, &notification);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_create_ongoing_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_create(true, NULL);

	if (retcode != UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_destroy_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(true, &notification);

	retcode = ui_notification_destroy(notification);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_destroy_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_destroy(NULL);

	if (retcode != UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_is_ongoing_positive1()
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	bool value = false;

	ui_notification_create(true, &notification);

	retcode = ui_notification_is_ongoing(notification, &value);

	if (retcode == UI_NOTIFICATION_ERROR_NONE && value == true) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_is_ongoing_positive2()
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	bool value = false;

	ui_notification_create(false, &notification);

	retcode = ui_notification_is_ongoing(notification, &value);

	if (retcode == UI_NOTIFICATION_ERROR_NONE && value == false) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_is_ongoing_negative1()
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(true, &notification);

	retcode = ui_notification_is_ongoing(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_is_ongoing_negative2()
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	bool value;

	retcode = ui_notification_is_ongoing(NULL, &value);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_icon_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	retcode = ui_notification_set_icon(notification, "ICON");

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_icon_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	ui_notification_set_icon(notification, "ICON");

	retcode = ui_notification_set_icon(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_icon_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_set_icon(NULL, "ICON");

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_icon_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	char *value;

	ui_notification_create(false, &notification);

	ui_notification_set_icon(notification, "ICON");

	retcode = ui_notification_get_icon(notification, &value);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_icon_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	char *value;

	retcode = ui_notification_get_icon(NULL, &value);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_icon_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	ui_notification_set_icon(notification, "ICON");

	retcode = ui_notification_get_icon(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_time_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	time_t t;
	struct tm tm_t;

	ui_notification_create(false, &notification);

	time(&t);
	localtime_r(&t, &tm_t);

	retcode = ui_notification_set_time(notification, &tm_t);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_time_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	time_t t;
	struct tm tm_t;

	ui_notification_create(false, &notification);

	time(&t);
	localtime_r(&t, &tm_t);

	ui_notification_set_time(notification, &tm_t);

	retcode = ui_notification_set_time(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_time_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	time_t t;
	struct tm tm_t;

	time(&t);
	localtime_r(&t, &tm_t);

	retcode = ui_notification_set_time(NULL, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_time_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	time_t t;
	struct tm tm_t;
	struct tm *value;

	ui_notification_create(false, &notification);

	time(&t);
	localtime_r(&t, &tm_t);

	ui_notification_set_time(notification, &tm_t);

	retcode = ui_notification_get_time(notification, &value);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_time_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	struct tm *value;

	retcode = ui_notification_get_time(NULL, &value);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_time_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	time_t t;
	struct tm tm_t;

	ui_notification_create(false, &notification);

	time(&t);
	localtime_r(&t, &tm_t);

	ui_notification_set_time(notification, &tm_t);

	retcode = ui_notification_get_time(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_title_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	retcode = ui_notification_set_title(notification, "TITLE");

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_title_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	ui_notification_set_title(notification, "TITLE");

	retcode = ui_notification_set_title(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_title_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_set_title(NULL, "TITLE");

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_title_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	char *value;

	ui_notification_create(false, &notification);

	ui_notification_set_title(notification, "TITLE");

	retcode = ui_notification_get_title(notification, &value);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_title_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	char *value;

	retcode = ui_notification_get_title(NULL, &value);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_title_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	ui_notification_set_title(notification, "TITLE");

	retcode = ui_notification_get_title(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_content_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	retcode = ui_notification_set_content(notification, "CONTENT");

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_content_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	ui_notification_set_content(notification, "CONTENT");

	retcode = ui_notification_set_content(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_content_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_set_content(NULL, "CONTENT");

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_content_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	char *value;

	ui_notification_create(false, &notification);

	ui_notification_set_content(notification, "CONTENT");

	retcode = ui_notification_get_content(notification, &value);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_content_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	char *value;

	retcode = ui_notification_get_content(NULL, &value);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_content_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	ui_notification_set_content(notification, "CONTENT");

	retcode = ui_notification_get_content(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_service_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	service_h service;

	ui_notification_create(false, &notification);

	service_create(&service);

	retcode = ui_notification_set_service(notification, service);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_service_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	service_h service;

	ui_notification_create(false, &notification);

	service_create(&service);

	ui_notification_set_service(notification, service);

	retcode = ui_notification_set_service(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_service_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	service_h service;
	service_create(&service);

	retcode = ui_notification_set_service(NULL, service);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_service_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	service_h service;
	service_h value;

	ui_notification_create(false, &notification);

	service_create(&service);

	ui_notification_set_service(notification, service);

	retcode = ui_notification_get_service(notification, &value);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_service_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	service_h value;

	retcode = ui_notification_get_service(NULL, &value);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_service_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	service_h service;

	ui_notification_create(false, &notification);

	service_create(&service);

	ui_notification_set_service(notification, service);

	retcode = ui_notification_get_service(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_sound_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	retcode = ui_notification_set_sound(notification, "/usr/share/svi/sound/operation/new_chat.wav");

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_sound_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	ui_notification_set_sound(notification, "/usr/share/svi/sound/operation/new_chat.wav");

	retcode = ui_notification_set_sound(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_sound_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_set_sound(NULL, "/usr/share/svi/sound/operation/new_chat.wav");

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_sound_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	char *value;

	ui_notification_create(false, &notification);

	ui_notification_set_sound(notification, "/usr/share/svi/sound/operation/new_chat.wav");

	retcode = ui_notification_get_sound(notification, &value);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_sound_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	char *value;

	retcode = ui_notification_get_sound(NULL, &value);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_sound_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	ui_notification_set_sound(notification, "/usr/share/svi/sound/operation/new_chat.wav");

	retcode = ui_notification_get_sound(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_vibration_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	retcode = ui_notification_set_vibration(notification, true);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_vibration_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	ui_notification_set_vibration(notification, true);

	retcode = ui_notification_set_vibration(notification, false);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_set_vibration_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_set_vibration(NULL, false);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_vibration_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	bool value;

	ui_notification_create(false, &notification);

	ui_notification_set_vibration(notification, true);

	retcode = ui_notification_get_vibration(notification, &value);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_vibration_negative1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	bool value;

	retcode = ui_notification_get_vibration(NULL, &value);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_get_vibration_negative2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;

	ui_notification_create(false, &notification);

	ui_notification_set_vibration(notification, true);

	retcode = ui_notification_get_vibration(notification, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_post_negative1(void)
{
	const const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_post(NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_cancel_negative1(void)
{
	const const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_cancel(NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_cancel_all_positive(void)
{
	const const char *API_NAME = __FUNCTION__;

	ui_notification_cancel_all();

	dts_pass(API_NAME, "passed");
}

static void utc_notification_cancel_all_by_type_positive1(void)
{
	const const char *API_NAME = __FUNCTION__;

	ui_notification_cancel_all_by_type(false);

	dts_pass(API_NAME, "passed");
}

static void utc_notification_cancel_all_by_type_positive2(void)
{
	const const char *API_NAME = __FUNCTION__;

	ui_notification_cancel_all_by_type(true);

	dts_pass(API_NAME, "passed");
}

static void utc_notification_update_negative1(void)
{
	const const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_update(NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_update_progress_negative1(void)
{
	const const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_update_progress(NULL, UI_NOTIFICATION_PROGRESS_TYPE_PERCENTAGE, 0);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static bool utc_ui_notification_cb(ui_notification_h notification, void *user_data)
{
	return true;
}

static void utc_notification_foreach_notification_posted_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_foreach_notification_posted(true, utc_ui_notification_cb, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_foreach_notification_posted_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_foreach_notification_posted(false, utc_ui_notification_cb, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_foreach_notification_posted_negative1(void)
{
	const const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_foreach_notification_posted(true, NULL, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_foreach_notification_posted_negative2(void)
{
	const const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	retcode = ui_notification_foreach_notification_posted(true, NULL, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_clone_positive1(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	ui_notification_h clone;

	ui_notification_create(true, &notification);

	retcode = ui_notification_clone(&clone, notification);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_clone_positive2(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	ui_notification_h clone;

	ui_notification_create(false, &notification);

	retcode = ui_notification_clone(&clone, notification);

	if (retcode == UI_NOTIFICATION_ERROR_NONE) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_clone_positive3(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	ui_notification_h clone;
	bool ongoing = true;
	bool ongoing_clone = false;
	char *title = "TITLE";
	char *content = "CONTENT";
	char *icon = "ICON_PATH";
	char *title_clone = NULL;
	char *content_clone  = NULL;
	char *icon_clone  = NULL;
	int equal = 0;

	ui_notification_create(ongoing, &notification);

	ui_notification_set_title(notification, title);
	ui_notification_set_content(notification, content);
	ui_notification_set_icon(notification, icon);

	retcode = ui_notification_clone(&clone, notification);

	if (!ui_notification_is_ongoing(clone, &ongoing_clone))
	{
		if (ongoing == ongoing_clone)
		{
			equal++;
		}
	}

	if (!ui_notification_get_title(clone, &title_clone))
	{
		if (!strcmp(title, title_clone))
		{
			equal++;
		}
	}

	if (!ui_notification_get_content(clone, &content_clone))
	{
		if (!strcmp(content, content_clone))
		{
			equal++;
		}
	}

	if (!ui_notification_get_icon(clone, &icon_clone))
	{
		if (!strcmp(icon, icon_clone))
		{
			equal++;
		}
	}

	if (retcode == UI_NOTIFICATION_ERROR_NONE && equal == 4) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_clone_positive4(void)
{
	const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	ui_notification_h clone;
	bool ongoing = false;
	bool ongoing_clone = false;
	char *title = "TITLE";
	char *content = "CONTENT";
	char *icon = "ICON_PATH";
	char *title_clone = NULL;
	char *content_clone  = NULL;
	char *icon_clone  = NULL;
	int equal = 0;

	ui_notification_create(ongoing, &notification);

	ui_notification_set_title(notification, title);
	ui_notification_set_content(notification, content);
	ui_notification_set_icon(notification, icon);

	retcode = ui_notification_clone(&clone, notification);

	if (!ui_notification_is_ongoing(clone, &ongoing_clone))
	{
		if (ongoing == ongoing_clone)
		{
			equal++;
		}
	}

	if (!ui_notification_get_title(clone, &title_clone))
	{
		if (!strcmp(title, title_clone))
		{
			equal++;
		}
	}

	if (!ui_notification_get_content(clone, &content_clone))
	{
		if (!strcmp(content, content_clone))
		{
			equal++;
		}
	}

	if (!ui_notification_get_icon(clone, &icon_clone))
	{
		if (!strcmp(icon, icon_clone))
		{
			equal++;
		}
	}

	if (retcode == UI_NOTIFICATION_ERROR_NONE && equal == 4) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}

}

static void utc_notification_clone_negative1(void)
{
	const const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h notification;
	ui_notification_create(true, &notification);

	retcode = ui_notification_clone(NULL, notification);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_notification_clone_negative2(void)
{
	const const char *API_NAME = __FUNCTION__;
	int retcode = UI_NOTIFICATION_ERROR_NONE;

	ui_notification_h clone;

	retcode = ui_notification_clone(&clone, NULL);

	if (retcode == UI_NOTIFICATION_ERROR_INVALID_PARAMETER) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}
