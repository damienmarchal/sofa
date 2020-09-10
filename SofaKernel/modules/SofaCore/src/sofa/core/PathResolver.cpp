/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#pragma once

#include "PathResolver.h"
#include <sofa/core/objectmodel/Base.h>

namespace sofa::core
{

using sofa::core::objectmodel::Base;
using sofa::core::objectmodel::BaseData;
using sofa::core::objectmodel::BaseClass;

Base* PathResolver::FindBaseFromPath(Base* context, const std::string& path)
{
    return context->findBaseFromPath(path);
}

BaseData* PathResolver::FindBaseDataFromPath(Base* context, const std::string& path)
{
    return context->findBaseDataFromPath(path);
}

bool PathResolver::FindDataLinkDest(Base* context, BaseData*& ptr, const std::string& path, const BaseLink* link)
{
    return context->findDataLinkDest(ptr, path, link);
}

void* PathResolver::FindLinkDestClass(Base* context, const BaseClass* destType, const std::string& path, const BaseLink* link)
{
    return context->findLinkDestClass(destType, path, link);
}

}
