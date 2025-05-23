// Created on: 2000-05-11
// Created by: data exchange team
// Copyright (c) 2000-2014 OPEN CASCADE SAS
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

#ifndef _StepRepr_CharacterizedDefinition_HeaderFile
#define _StepRepr_CharacterizedDefinition_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <StepData_SelectType.hxx>
#include <Standard_Integer.hxx>
class Standard_Transient;
class StepBasic_CharacterizedObject;
class StepBasic_ProductDefinition;
class StepBasic_ProductDefinitionRelationship;
class StepRepr_ProductDefinitionShape;
class StepRepr_ShapeAspect;
class StepRepr_ShapeAspectRelationship;
class StepBasic_DocumentFile;

//! Representation of STEP SELECT type CharacterizedDefinition
class StepRepr_CharacterizedDefinition : public StepData_SelectType
{
public:
  DEFINE_STANDARD_ALLOC

  //! Empty constructor
  Standard_EXPORT StepRepr_CharacterizedDefinition();

  //! Recognizes a kind of CharacterizedDefinition select type
  //! 1 -> CharacterizedObject from StepBasic
  //! 2 -> ProductDefinition from StepBasic
  //! 3 -> ProductDefinitionRelationship from StepBasic
  //! 4 -> ProductDefinitionShape from StepRepr
  //! 5 -> ShapeAspect from StepRepr
  //! 6 -> ShapeAspectRelationship from StepRepr
  //! 7 -> DocumentFile from StepBasic
  //! 0 else
  Standard_EXPORT Standard_Integer CaseNum(const Handle(Standard_Transient)& ent) const;

  //! Returns Value as CharacterizedObject (or Null if another type)
  Standard_EXPORT Handle(StepBasic_CharacterizedObject) CharacterizedObject() const;

  //! Returns Value as ProductDefinition (or Null if another type)
  Standard_EXPORT Handle(StepBasic_ProductDefinition) ProductDefinition() const;

  //! Returns Value as ProductDefinitionRelationship (or Null if another type)
  Standard_EXPORT Handle(StepBasic_ProductDefinitionRelationship) ProductDefinitionRelationship()
    const;

  //! Returns Value as ProductDefinitionShape (or Null if another type)
  Standard_EXPORT Handle(StepRepr_ProductDefinitionShape) ProductDefinitionShape() const;

  //! Returns Value as ShapeAspect (or Null if another type)
  Standard_EXPORT Handle(StepRepr_ShapeAspect) ShapeAspect() const;

  //! Returns Value as ShapeAspectRelationship (or Null if another type)
  Standard_EXPORT Handle(StepRepr_ShapeAspectRelationship) ShapeAspectRelationship() const;

  //! Returns Value as DocumentFile (or Null if another type)
  Standard_EXPORT Handle(StepBasic_DocumentFile) DocumentFile() const;

protected:
private:
};

#endif // _StepRepr_CharacterizedDefinition_HeaderFile
