/*
 * plist.h
 * contains structures and the like for plists
 *
 * Copyright (c) 2008 Zach C. All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA 
 */

#ifndef PLIST_H
#define PLIST_H

#include "plist/plist.h"

#include <stdint.h>
#include <wchar.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glib.h>





struct plist_data_s {
	union {
		char boolval;
		uint64_t intval;
		double realval;
		char *strval;
		wchar_t *unicodeval;
		char *buff;
	};
	uint64_t length;
	plist_type type;
};

typedef struct plist_data_s *plist_data_t;

plist_t plist_new_node(plist_data_t data);
plist_data_t plist_get_data(const plist_t node);
plist_data_t plist_new_plist_data();
void plist_free_plist_data(plist_data_t node);


#endif
