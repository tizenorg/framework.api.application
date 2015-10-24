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


#include <appcore-efl.h>
#include <aul.h>

#include "app_extension.h"

//#ifdef _APPFW_FEATURE_PROCESS_POOL
void* app_get_preinitialized_window(const char *win_name)
{
#ifdef _APPFW_FEATURE_PROCESS_POOL
	appcore_set_preinit_window_name(win_name);
	return aul_get_preinit_window(win_name);
#else
	return NULL;
#endif
}

void* app_get_preinitialized_background(void)
{
#ifdef _APPFW_FEATURE_PROCESS_POOL
	return aul_get_preinit_background();
#else
	return NULL;
#endif
}

void* app_get_preinitialized_conformant(void)
{
#ifdef _APPFW_FEATURE_PROCESS_POOL
	return aul_get_preinit_conformant();
#else
	return NULL;
#endif
}
//#endif
