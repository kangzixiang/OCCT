// Created on: 1995-12-01
// Created by: EXPRESS->CDL V0.2 Translator
// Copyright (c) 1995-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _StepBasic_ProductCategory_HeaderFile
#define _StepBasic_ProductCategory_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Boolean.hxx>
#include <Standard_Transient.hxx>
class TCollection_HAsciiString;

class StepBasic_ProductCategory;
DEFINE_STANDARD_HANDLE(StepBasic_ProductCategory, Standard_Transient)

class StepBasic_ProductCategory : public Standard_Transient
{

public:
  //! Returns a ProductCategory
  Standard_EXPORT StepBasic_ProductCategory();

  Standard_EXPORT void Init(const Handle(TCollection_HAsciiString)& aName,
                            const Standard_Boolean                  hasAdescription,
                            const Handle(TCollection_HAsciiString)& aDescription);

  Standard_EXPORT void SetName(const Handle(TCollection_HAsciiString)& aName);

  Standard_EXPORT Handle(TCollection_HAsciiString) Name() const;

  Standard_EXPORT void SetDescription(const Handle(TCollection_HAsciiString)& aDescription);

  Standard_EXPORT void UnSetDescription();

  Standard_EXPORT Handle(TCollection_HAsciiString) Description() const;

  Standard_EXPORT Standard_Boolean HasDescription() const;

  DEFINE_STANDARD_RTTIEXT(StepBasic_ProductCategory, Standard_Transient)

protected:
private:
  Handle(TCollection_HAsciiString) name;
  Handle(TCollection_HAsciiString) description;
  Standard_Boolean                 hasDescription;
};

#endif // _StepBasic_ProductCategory_HeaderFile
