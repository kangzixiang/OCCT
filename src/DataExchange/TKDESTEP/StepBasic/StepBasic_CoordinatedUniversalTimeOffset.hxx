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

#ifndef _StepBasic_CoordinatedUniversalTimeOffset_HeaderFile
#define _StepBasic_CoordinatedUniversalTimeOffset_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Integer.hxx>
#include <StepBasic_AheadOrBehind.hxx>
#include <Standard_Transient.hxx>

class StepBasic_CoordinatedUniversalTimeOffset;
DEFINE_STANDARD_HANDLE(StepBasic_CoordinatedUniversalTimeOffset, Standard_Transient)

class StepBasic_CoordinatedUniversalTimeOffset : public Standard_Transient
{

public:
  //! Returns a CoordinatedUniversalTimeOffset
  Standard_EXPORT StepBasic_CoordinatedUniversalTimeOffset();

  Standard_EXPORT void Init(const Standard_Integer        aHourOffset,
                            const Standard_Boolean        hasAminuteOffset,
                            const Standard_Integer        aMinuteOffset,
                            const StepBasic_AheadOrBehind aSense);

  Standard_EXPORT void SetHourOffset(const Standard_Integer aHourOffset);

  Standard_EXPORT Standard_Integer HourOffset() const;

  Standard_EXPORT void SetMinuteOffset(const Standard_Integer aMinuteOffset);

  Standard_EXPORT void UnSetMinuteOffset();

  Standard_EXPORT Standard_Integer MinuteOffset() const;

  Standard_EXPORT Standard_Boolean HasMinuteOffset() const;

  Standard_EXPORT void SetSense(const StepBasic_AheadOrBehind aSense);

  Standard_EXPORT StepBasic_AheadOrBehind Sense() const;

  DEFINE_STANDARD_RTTIEXT(StepBasic_CoordinatedUniversalTimeOffset, Standard_Transient)

protected:
private:
  Standard_Integer        hourOffset;
  Standard_Integer        minuteOffset;
  StepBasic_AheadOrBehind sense;
  Standard_Boolean        hasMinuteOffset;
};

#endif // _StepBasic_CoordinatedUniversalTimeOffset_HeaderFile
