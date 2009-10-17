/*
 * Date.cpp
 *
 * Copyright (c) 2009 Jonathan Beck All Rights Reserved.
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

#include <stdlib.h>
#include <plist/Date.h>

namespace PList
{

Date::Date() : Node(PLIST_DATE)
{
}

Date::Date(plist_t node) : Node(node)
{
}

Date::Date(PList::Date& d) : Node(PLIST_DATE)
{
    timeval t = d.GetValue();
    plist_set_date_val(_node, t.tv_sec, t.tv_usec);
}

Date& Date::operator=(PList::Date& d)
{
    plist_free(_node);
    _node = plist_copy(d.GetPlist());
}

Date::Date(timeval t) : Node(PLIST_DATE)
{
    plist_set_date_val(_node, t.tv_sec, t.tv_usec);
}

Date::~Date()
{
}

Node* Date::Clone()
{
    return new Date(*this);
}

void Date::SetValue(timeval t)
{
    plist_set_date_val(_node, t.tv_sec, t.tv_usec);
}

timeval Date::GetValue()
{
    int32_t tv_sec = 0;
    int32_t tv_usec = 0;
    plist_get_date_val(_node, &tv_sec, &tv_usec);
    return {tv_sec, tv_usec};
}

};
