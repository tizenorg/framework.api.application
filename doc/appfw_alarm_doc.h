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


#ifndef __TIZEN_APPFW_ALARM_DOC_H__
#define __TIZEN_APPFW_ALARM_DOC_H__

 /**
 * @ingroup CAPI_APPLICATION_MODULE
 * @defgroup CAPI_ALARM_MODULE Alarm
 * @brief The @ref CAPI_ALARM_MODULE API allows setting an "alarm clock" for the delivery of a notification at some point in the future.
 *
 * @section CAPI_ALARM_MODULE_HEADER Required Header
 *   \#include <app_alarm.h>
 *
 * @section CAPI_ALARM_MODULE_OVERVIEW Overview
 * Mobile devices typically give constant access to information from various sources. Some of this information is best delivered
 * through alarms - the most obvious case is a calendar scheduling application which lets you know when a meeting is about to start.
 * Alarms are certainly better than actively waiting in a loop.  They are also better than putting an interface to sleep because they do not
 * block your main UI thread.  Use of alarms helps build smooth user experiences and implements unattended data synchronization tasks.
 * If an application is installed after setting the alarm, your alarm is cancelled automatically.\n
 *
 * There are 3 ways to set an alarm.
 * <table>
 * <tr>
 *    <th>FUNCTION</th>
 *    <th>DESCRIPTION </th>
 * </tr>
 * <tr>
 * 	<td>alarm_schedule_after_delay()</td>
 * 	<td>Sets an alarm to be triggered at specific time(can repeat in seconds)</td>
 * </tr>
 * <tr>
 * 	<td>alarm_schedule_at_date()</td>
 * 	<td>Sets an alarm to be triggered after specific delay(can repeat in seconds)</td>
 * </tr>
  * <tr>
 * 	<td>alarm_schedule_with_recurrence_week_flag()</td>
 * 	<td>Sets an alarm to be triggered at specific time with recurrent days of the week(can repeat on days of the week)</td>
 * </tr>
 * </table>
 * \n
 *
 */

#endif /* __TIZEN_APPFW_ALARM_DOC_H__ */
