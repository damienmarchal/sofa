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

#include <sofa/core/PathResolver.h>

namespace sofa::core::objectmodel
{

class BaseData;

/// @brief AbstractDataLink is the base class for every link between two data fields
/// The targetted BaseData is called the "target",
/// The base object owning the current "child" object is the "owner"
class AbstractDataLink
{
public:
    /// Get the DataField having thins link as an attribute
    /// there is a one to one owner relationship.
    const BaseData& getOwner() { return __doGetOwner__(); }

    /// Change the targetted DataField
    void setTarget(BaseData* target){ __doSetTarget__(target); }

    /// Get the targetted DataField
    BaseData* getTarget(){ return __doGetTarget__(); }

    const std::string getPath() const
    {
        return m_path;
    }

    void setPath(const std::string& path)
    {
        /// Trying to resolve link
        m_path = path;
        PathResolver::ResolveDataLinkFromPath(*this);
    }

    bool hasPath() const { return !m_path.empty(); }

protected:
    virtual void __doSetTarget__(BaseData* target) = 0;
    virtual BaseData* __doGetTarget__() = 0;
    virtual const BaseData& __doGetOwner__() = 0;

    std::string m_path {""};
};

/**
 * Link between two BaseData.
 */
template<class T>
class SOFA_CORE_API DataLink final : public AbstractDataLink
{
public:

    DataLink(T& owner) : m_owner{owner} { }
    virtual ~DataLink(){}

    T* getTarget()
    {
        if(m_target==nullptr && !m_path.empty())
            PathResolver::ResolveDataLinkFromPath(*this);
        return m_target;
    }

    void unSet(){ m_target=nullptr; m_path = ""; }
    bool isSet() const { return m_target != nullptr; }

    void setTarget(T* target)
    {
        m_path = "";
        m_target = target;
    }

    T& getOwner() const { return m_owner; }

protected:
    void __doSetTarget__(BaseData* target) override
    {
        setTarget(dynamic_cast<T*>(target));
    }

    BaseData* __doGetTarget__() override
    {
        return getTarget();
    }

    const BaseData& __doGetOwner__()
    {
        return getOwner();
    }

    T& m_owner  ;
    T* m_target {nullptr};
};

} /// namespace sofa::core::objectmodel

