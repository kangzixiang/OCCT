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

#ifndef _StepRepr_GlobalUnitAssignedContext_HeaderFile
#define _StepRepr_GlobalUnitAssignedContext_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <StepBasic_HArray1OfNamedUnit.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <Standard_Integer.hxx>
class TCollection_HAsciiString;
class StepBasic_NamedUnit;

class StepRepr_GlobalUnitAssignedContext;
DEFINE_STANDARD_HANDLE(StepRepr_GlobalUnitAssignedContext, StepRepr_RepresentationContext)

class StepRepr_GlobalUnitAssignedContext : public StepRepr_RepresentationContext
{

public:
  //! Returns a GlobalUnitAssignedContext
  Standard_EXPORT StepRepr_GlobalUnitAssignedContext();

  Standard_EXPORT void Init(const Handle(TCollection_HAsciiString)&     aContextIdentifier,
                            const Handle(TCollection_HAsciiString)&     aContextType,
                            const Handle(StepBasic_HArray1OfNamedUnit)& aUnits);

  Standard_EXPORT void SetUnits(const Handle(StepBasic_HArray1OfNamedUnit)& aUnits);

  Standard_EXPORT Handle(StepBasic_HArray1OfNamedUnit) Units() const;

  Standard_EXPORT Handle(StepBasic_NamedUnit) UnitsValue(const Standard_Integer num) const;

  Standard_EXPORT Standard_Integer NbUnits() const;

  DEFINE_STANDARD_RTTIEXT(StepRepr_GlobalUnitAssignedContext, StepRepr_RepresentationContext)

protected:
private:
  Handle(StepBasic_HArray1OfNamedUnit) units;
};

#endif // _StepRepr_GlobalUnitAssignedContext_HeaderFile
