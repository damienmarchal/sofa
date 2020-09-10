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

#include <sofa/core/config.h>
#include <string>

namespace sofa::core::objectmodel
{

/**
 * Link between two BaseData.
 */
template<class T>
class SOFA_CORE_API DataLink
{
public:
    DataLink(T& owner) : m_owner{owner} { }
    virtual ~DataLink(){}


    T* getTarget() const
    {
        return m_target;
    }

    void setTarget(T* target)
    {
        m_path = "";
        m_target = target;
    }

    void setPath(const std::string& path)
    {
        m_path = path;
        m_target = nullptr;
    }

    const std::string getPath() const
    {
        if(m_target == nullptr)
            return m_path;
        return "mince";
    }

    T& getOwner() const { return m_owner; }

    void unSet(){ m_target = nullptr; m_path = ""; }
    bool isSet() const { return m_target != nullptr; }
    bool hasPath() const { return !m_path.empty(); }

protected:
    T& m_owner  ;
    T* m_target {nullptr};
    std::string m_path {""};
};

} /// namespace sofa::core::objectmodel

