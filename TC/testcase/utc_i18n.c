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

static void utc_i18n_get_test_positive(void);
static void utc_i18n_get_test_negative(void);

struct tet_testlist tet_testlist[] = {
	{utc_i18n_get_test_positive, 1},
	{utc_i18n_get_test_negative, 1},
	{NULL, 0},
};

static void startup(void)
{

}


static void cleanup(void)
{
	/* end of TC */
}

static void utc_i18n_get_test_positive(void)
{
	const char *API_NAME = __FUNCTION__;
	const char *msg_id = "HELLO";
	char *msg;

	msg = i18n_get_text(msg_id);

	if (!strcmp(msg_id, msg)) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

static void utc_i18n_get_test_negative(void)
{
	const char *API_NAME = __FUNCTION__;
	char *msg;

	msg = i18n_get_text(NULL);

	if (msg == NULL) {
		dts_pass(API_NAME, "passed");
	} else {
		dts_fail(API_NAME, "failed");
	}
}

