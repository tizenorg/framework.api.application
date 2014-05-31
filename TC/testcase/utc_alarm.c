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
#include <glib.h>

static int passed =1;
int tid;
GMainLoop *loop;

static void startup(void);
static void cleanup(void);

void (*tet_startup)(void) = startup;
void (*tet_cleanup)(void) = cleanup;

static void utc_alarm_schedule_after_delay_positive(void);
static void utc_alarm_schedule_after_delay_negative(void);
static void utc_alarm_cancel_positive(void);
static void utc_alarm_cancel_negative(void);
static void utc_alarm_cancel_all_positive(void);
static void utc_alarm_foreach_registered_alarm_positive(void);
static void utc_alarm_foreach_registered_alarm_negative(void);
static void utc_alarm_get_scheduled_date_positive(void);
static void utc_alarm_get_scheduled_date_negative(void);
static void utc_alarm_get_scheduled_period_positive(void);
static void utc_alarm_get_scheduled_period_negative(void);
static void utc_alarm_schedule_at_date_positive(void);
static void utc_alarm_schedule_at_date_negative(void);
static void utc_alarm_schedule_with_recurrence_week_flag_positive(void);
static void utc_alarm_schedule_with_recurrence_week_flag_negative(void);
static void utc_alarm_get_scheduled_recurrence_week_flag_positive(void);
static void utc_alarm_get_scheduled_recurrence_week_flag_negative(void);
static void utc_alarm_get_current_time_positive(void);
static void utc_alarm_get_current_time_negative(void);
static void utc_alarm_get_service_positive(void);
static void utc_alarm_get_service_negative(void);



struct tet_testlist tet_testlist[] = {
	{ utc_alarm_schedule_after_delay_positive, 1 },
	{ utc_alarm_schedule_after_delay_negative, 2 },
	{ utc_alarm_cancel_positive, 1 },
	{ utc_alarm_cancel_negative, 2 },
	{ utc_alarm_cancel_all_positive, 1 },
	{ utc_alarm_foreach_registered_alarm_positive, 1 },
	{ utc_alarm_foreach_registered_alarm_negative, 2 },
	{ utc_alarm_get_scheduled_date_positive, 1 },
	{ utc_alarm_get_scheduled_date_negative, 2 },
	{ utc_alarm_get_scheduled_period_positive, 1 },
	{ utc_alarm_get_scheduled_period_negative, 2 },
	{ utc_alarm_schedule_at_date_positive, 1 },
	{ utc_alarm_schedule_at_date_negative, 2 },
	{ utc_alarm_schedule_with_recurrence_week_flag_positive, 1 },
	{ utc_alarm_schedule_with_recurrence_week_flag_negative, 2 },
	{ utc_alarm_get_scheduled_recurrence_week_flag_positive, 1 },
	{ utc_alarm_get_scheduled_recurrence_week_flag_negative, 2 },
	{ utc_alarm_get_current_time_positive, 1 },
	{ utc_alarm_get_current_time_negative, 2 },
	{ utc_alarm_get_service_positive, 1 },
	{ utc_alarm_get_service_negative, 2 },
	{ NULL, 0 },
};

static void startup(void)
{
	/* start of TC */
	g_type_init();
}

static void cleanup(void)
{
	/* end of TC */
	alarm_cancel_all();
}

static bool foreach_alarm_cb(int alarm, void* user_data)
{
	if(alarm == tid)
	{
		dts_pass("utc_alarm_foreach_registered_alarm_positive");
	}

	dts_message("utc_alarm_foreach_registered_alarm_positive", "registered id = %d callback id = %d", alarm, tid);
	
	return true;
}

static gboolean timeout(gpointer data)
{
    printf("timeout called\n");
    g_main_loop_quit(data);
    return FALSE;
}

/**
 * @brief Positive test case of alarm_schedule_after_delay()
 */
static void utc_alarm_schedule_after_delay_positive(void)
{
	time_t current_time;
	struct tm current_tm;
	service_h service;
	int tid;
	GMainLoop *loop;
	int ret = ALARM_ERROR_NONE;

	service_create(&service); 
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);
	service_set_package(service, "com.samsung.memo");
	
	loop = g_main_loop_new(NULL, FALSE);
	g_timeout_add(5000,timeout , loop); 
	
	ret = alarm_schedule_after_delay(service, 1, 1, &tid);
	
	g_main_loop_run(loop);
		
	if(ret == ALARM_ERROR_NONE)
	{
		dts_pass("utc_alarm_schedule_after_delay_positive", "passed");
	}
	else
	{
		dts_fail("utc_alarm_schedule_after_delay_positive", "failed");
	}
	
	service_destory(service);
	alarm_cancel_all();
}

/**
 * @brief Negative test case of alarm_schedule_after_delay()
 */
static void utc_alarm_schedule_after_delay_negative(void)
{
	time_t current_time;
	struct tm current_tm;
	service_h service;
	int ret = ALARM_ERROR_NONE;
	int tid;
	GMainLoop *loop;

	service_create(&service); 
	service_set_package(service, "com.samsung.memo");
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);
                                                            
	ret = alarm_schedule_after_delay(service, 1, 1, NULL);

	g_main_loop_run(loop);

	if(ret == ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_schedule_after_delay_negative", "failed");
	}
	else
	{
		dts_pass("utc_alarm_schedule_after_delay_negative", "passed");
	}
	
	service_destory(service);
	alarm_cancel_all();

}


/**
 * @brief Positive test case of alarm_cancel()
 */
static void utc_alarm_cancel_positive(void)
{
	time_t current_time;
	struct tm current_tm;
	service_h service;
	int ret = ALARM_ERROR_NONE;
	int tid;
	GMainLoop *loop;

	service_create(&service);
	service_set_package(service, "com.samsung.memo");
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);

	loop = g_main_loop_new(NULL, FALSE);
	g_timeout_add(5000,timeout , loop);
	
	ret = alarm_schedule_after_delay(service, 1, 1, &tid);
	ret = alarm_cancel(tid);

	g_main_loop_run(loop);
	
	if(ret == ALARM_ERROR_NONE)
	{
		dts_pass("utc_alarm_cancel_positive", "passed");
	}
	else
	{
		dts_fail("utc_alarm_cancel_positive", "passed");
	}
	
	service_destory(service);
	alarm_cancel_all();
}

/**
 * @brief Negative test case of alarm_cancel()
 */
static void utc_alarm_cancel_negative(void)
{
	int ret = ALARM_ERROR_NONE;
	
	ret = alarm_cancel(NULL);
	if(ret == ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_cancel_negative", "failed");
	}
	else
	{
		dts_pass("utc_alarm_cancel_negative", "passed");
	}
	alarm_cancel_all();
}

/**
 * @brief Positive test case of alarm_cancel_all()
 */
static void utc_alarm_cancel_all_positive(void)
{
	int ret = ALARM_ERROR_NONE;

	ret = alarm_cancel_all();

	if(ret == ALARM_ERROR_NONE)
	{
		dts_pass("utc_alarm_cancel_all_positive", "passed");
	}
	else
	{
		dts_fail("utc_alarm_cancel_all_positive", "failed");
	}

	alarm_cancel_all();

}


/**
 * @brief Positive test case of alarm_foreach_registered_alarm()
 */
static void utc_alarm_foreach_registered_alarm_positive(void)
{
	int ret = ALARM_ERROR_NONE;
	time_t current_time;
	struct tm current_tm;
	service_h service;
	int tid;
	GMainLoop *loop;

	loop = g_main_loop_new(NULL, FALSE);
	g_timeout_add(1000,timeout , loop);
	
	service_create(&service);
	service_set_package(service, "com.samsung.memo");
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);
	alarm_schedule_after_delay(service, 1, 5, &tid);
	
	ret = alarm_foreach_registered_alarm(foreach_alarm_cb,NULL);

	g_main_loop_run(loop);

	if(ret != ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_foreach_registered_alarm_positive", "failed");
	}
	else
	{
		dts_pass("utc_alarm_foreach_registered_alarm_positive" , "passed");
	}
	
	service_destory(service);
	alarm_cancel_all();

}


/**
 * @brief Negative test case of alarm_foreach_registered_alarm()
 */
static void utc_alarm_foreach_registered_alarm_negative(void)
{
	int ret = ALARM_ERROR_NONE;
	
	// do i need to call alarm_init??
	ret = alarm_foreach_registered_alarm(NULL,NULL);

	if(ret == ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_foreach_registered_alarm_negative", "failed");
	}
	else
	{
		dts_pass("utc_alarm_foreach_registered_alarm_negative", "passed");
	}
	alarm_cancel_all();
}


/**
 * @brief Positive test case of alarm_get_scheduled_date()
 */
static void utc_alarm_get_scheduled_date_positive(void)
{
	struct tm date;
	service_h service;
	int ret = ALARM_ERROR_NONE;
	int tid;
	GMainLoop *loop;

	loop = g_main_loop_new(NULL, FALSE);
	g_timeout_add(5000,timeout , loop);

	service_create(&service);
	service_set_package(service, "com.samsung.memo");
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);
	alarm_schedule_after_delay(service, 1, 5, &tid);

	ret = alarm_get_scheduled_date(tid, &date);

	g_main_loop_run(loop);

	if(ret == ALARM_ERROR_NONE)
	{
		dts_pass("utc_alarm_get_date_positive", "passed");
	}
	else
	{
		dts_fail("utc_alarm_get_date_positive", "failed");
	}
	
	service_destory(service);
	alarm_cancel_all();
}

/**
 * @brief Negative test case of alarm_get_scheduled_date()
 */
static void utc_alarm_get_scheduled_date_negative(void)
{
	struct tm date;
	int ret = ALARM_ERROR_NONE;
	
	ret =  alarm_get_scheduled_date(NULL, &date);

	if(ret == ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_get_scheduled_date_negative", "failed");
	}
	else
	{
		dts_pass("utc_alarm_get_scheduled_date_negative", "passed");
	}
	alarm_cancel_all();
}


/**
 * @brief Positive test case of alarm_get_period()
 */
static void utc_alarm_get_scheduled_period_positive(void)
{
	time_t current_time;
	struct tm current_tm;
	service_h service;
	int ret = ALARM_ERROR_NONE;
	int period = 0;
	int tid;
	GMainLoop *loop;

	loop = g_main_loop_new(NULL, FALSE);
	g_timeout_add(1000,timeout , loop);

	service_create(&service);
	service_set_package(service, "com.samsung.memo");
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);
	alarm_schedule_after_delay(service, 1, 1, &tid);	

	ret = alarm_get_scheduled_period(tid, &period);

	g_main_loop_run(loop);

	if(ret != ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_get_scheduled_period_positive", "failed");
	}

	if(period == 1)
	{
		dts_pass("utc_alarm_get_scheduled_period_positive", "passed");
	}
	else
	{
		dts_fail("utc_alarm_get_scheduled_period_positive", "failed");
	}

	service_destory(service);
	alarm_cancel_all();

}

/**
 * @brief Negative test case of alarm_get_scheduled_period()
 */
static void utc_alarm_get_scheduled_period_negative(void)
{
	time_t current_time;
	struct tm current_tm;
	int ret = ALARM_ERROR_NONE;
	int period = 0;
	int tid;
	GMainLoop *loop;

	ret = alarm_get_scheduled_period(NULL,&period);

	if(ret == ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_get_scheduled_period_negative", "failed");
	}
	else
	{
		dts_pass("utc_alarm_get_scheduled_period_negative", "passed");
	}

	alarm_cancel_all();

}

/**
 * @brief Positive test case of alarm_schedule_at_date()
 */
static void utc_alarm_schedule_at_date_positive(void)
{
	time_t current_time;
	struct tm date;
	time_t now;
	service_h service;
	int tid;
	GMainLoop *loop;

	int ret = ALARM_ERROR_NONE;

	loop = g_main_loop_new(NULL, FALSE);
	g_timeout_add(5000,timeout , loop);

	time(&now);
	localtime_r(&now, &date);
	
	date.tm_sec += 3;
	service_create(&service);
	service_set_package(service, "com.samsung.memo");
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);

	ret = alarm_schedule_at_date(service, &date, 2, &tid);

	g_main_loop_run(loop);

	if(ret == ALARM_ERROR_NONE)
	{
		dts_pass("utc_alarm_schedule_at_date_positive", "passed");
		
	}
	else
	{
		dts_fail("utc_alarm_schedule_at_date_positive", "failed");
	}

	service_destory(service);
	alarm_cancel_all();

}


/**
 * @brief Negative test case of alarm_schedule_at_date()
 */
static void utc_alarm_schedule_at_date_negative(void)
{
	time_t current_time;
	struct tm current_tm;
	int ret = ALARM_ERROR_NONE;
	service_h service;
	
	service_create(&service);
	service_set_package(service, "com.samsung.memo");
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);
	ret = alarm_schedule_at_date(service, NULL, 1, &tid);	

	if(ret == ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_schedule_at_date_negative", "failed");
	}
	else
	{
		dts_pass("utc_alarm_schedule_at_date_negative", "passed");
	}

	service_destory(service);
	alarm_cancel_all();

}

/**
 * @brief Negative test case of alarm_schedule_at_date()
 */
static void utc_alarm_schedule_with_recurrence_week_flag_positive(void)
{
	time_t current_time;
	struct tm date;
	time_t now;
	service_h service;
	int tid;
	GMainLoop *loop;

	int ret = ALARM_ERROR_NONE;

	loop = g_main_loop_new(NULL, FALSE);
	g_timeout_add(5000,timeout , loop);

	time(&now);
	localtime_r(&now, &date);
	date.tm_sec += 3;
	service_create(&service);
	service_set_package(service, "com.samsung.memo");
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);

	alarm_schedule_with_recurrence_week_flag(service, &date, ALARM_WEEK_FLAG_MONDAY, &tid);

	g_main_loop_run(loop);

	if(ret == ALARM_ERROR_NONE)
	{
		dts_pass("utc_alarm_schedule_with_recurrence_week_flag_positive", "passed");
	}
	else
	{
		dts_fail("utc_alarm_schedule_with_recurrence_week_flag_positive", "failed");
	}

	service_destory(service);
	alarm_cancel_all();

}

static void utc_alarm_schedule_with_recurrence_week_flag_negative(void)
{

	time_t current_time;
	struct tm date;
	time_t now;

	int ret = ALARM_ERROR_NONE;

	time(&now);
	localtime_r(&now, &date);
	date.tm_sec += 3;

	ret = alarm_schedule_with_recurrence_week_flag(NULL, &date, ALARM_WEEK_FLAG_MONDAY, &tid);

	if(ret == ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_schedule_at_date_negative", "failed");
	}
	else
	{
		dts_pass("utc_alarm_schedule_at_date_negative", "passed");
	}

	alarm_cancel_all();

}


/**
 * @brief Negative test case of alarm_schedule_at_date()
 */
static void utc_alarm_get_scheduled_recurrence_week_flag_positive(void)
{
	time_t current_time;
	struct tm date;
	time_t now;
	service_h service;
	int tid;
	GMainLoop *loop;
	int week_flag = 0;

	int ret = ALARM_ERROR_NONE;

	time(&now);
	localtime_r(&now, &date);
	date.tm_sec += 3;
	service_create(&service);
	service_set_package(service, "com.samsung.memo");
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);

	alarm_schedule_with_recurrence_week_flag(service, &date, ALARM_WEEK_FLAG_MONDAY, &tid);

	alarm_get_scheduled_recurrence_week_flag(tid,  &week_flag);

	
	if(ret != ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_get_scheduled_recurrence_week_flag_positive", "failed");
	}

	if(week_flag == ALARM_WEEK_FLAG_MONDAY)
	{
		dts_pass("utc_alarm_get_scheduled_recurrence_week_flag_positive", "passed");
	}
	else
	{
		dts_fail("utc_alarm_get_scheduled_recurrence_week_flag_positive", "failed");
	}
	service_destory(service);
	alarm_cancel_all();

}

static void utc_alarm_get_scheduled_recurrence_week_flag_negative(void)
{

	time_t current_time;
	struct tm date;
	time_t now;

	int ret = ALARM_ERROR_NONE;

	ret = alarm_get_scheduled_recurrence_week_flag(NULL ,NULL);

	if(ret == ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_get_scheduled_recurrence_week_flag_negative", "failed");
	}
	else
	{
		dts_pass("utc_alarm_get_scheduled_recurrence_week_flag_negative", "passed");
	}

	alarm_cancel_all();

}

static void utc_alarm_get_current_time_positive(void)
{
	struct tm date;
	int ret = ALARM_ERROR_NONE;
	
	ret = alarm_get_current_time(&date);
	if(ret == ALARM_ERROR_NONE)
	{
		dts_pass("utc_alarm_get_current_time_positive", "passed");
	}
	else
	{
		dts_fail("utc_alarm_get_current_time_positive", "failed");
	}
}

static void utc_alarm_get_current_time_negative(void)
{
	int ret = ALARM_ERROR_NONE;

	ret = alarm_get_current_time(NULL);
	if(ret == ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_get_current_time_negative", "failed");
	}
	else
	{
		dts_pass("utc_alarm_get_current_time_negative", "passed");
	}
}

static void utc_alarm_get_service_positive(void)
{
	time_t current_time;
	struct tm current_tm;
	service_h service;
	service_h service_return;

	int ret = ALARM_ERROR_NONE;
	int tid;
	GMainLoop *loop;
	char *package;

	loop = g_main_loop_new(NULL, FALSE);
	g_timeout_add(1000,timeout , loop);

	service_create(&service);
	service_set_package(service, "com.samsung.memo");
	service_set_operation(service, SERVICE_OPERATION_DEFAULT);
	alarm_schedule_after_delay(service, 3, 0, &tid);

	ret = alarm_get_service(tid, &service_return);

	g_main_loop_run(loop);

	if(ret != ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_get_service_positive", "failed");
	}
	
	ret = service_get_package(service_return, &package);
	
	if(ret != SERVICE_ERROR_NONE)
	{
		dts_fail("utc_alarm_get_service_positive", "failed");
	}

	if(!strcmp(package, "com.samsung.memo"))
	{
		dts_pass("utc_alarm_get_service_positive", "passed");
	}
	else
	{
		dts_fail("utc_alarm_get_service_positive", "failed");
	}
	
	if(package != NULL)
	{
		free(package);
	}
	service_destory(service);
	service_destory(service_return);
	alarm_cancel_all();

}
static void utc_alarm_get_service_negative(void)
{
	int ret = ALARM_ERROR_NONE;

	ret = alarm_get_service(NULL,NULL);

	if(ret == ALARM_ERROR_NONE)
	{
		dts_fail("utc_alarm_get_service_negative", "failed");
	}
	else
	{
		dts_pass("utc_alarm_get_service_negative", "passed");
	}
}

