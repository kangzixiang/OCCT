// Created on: 1993-10-14
// Created by: Christian CAILLET
// Copyright (c) 1993-1999 Matra Datavision
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

#ifndef _IGESDimen_ToolSection_HeaderFile
#define _IGESDimen_ToolSection_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Integer.hxx>
class IGESDimen_Section;
class IGESData_IGESReaderData;
class IGESData_ParamReader;
class IGESData_IGESWriter;
class Interface_EntityIterator;
class IGESData_DirChecker;
class Interface_ShareTool;
class Interface_Check;
class Interface_CopyTool;
class IGESData_IGESDumper;

//! Tool to work on a Section. Called by various Modules
//! (ReadWriteModule, GeneralModule, SpecificModule)
class IGESDimen_ToolSection
{
public:
  DEFINE_STANDARD_ALLOC

  //! Returns a ToolSection, ready to work
  Standard_EXPORT IGESDimen_ToolSection();

  //! Reads own parameters from file. <PR> gives access to them,
  //! <IR> detains parameter types and values
  Standard_EXPORT void ReadOwnParams(const Handle(IGESDimen_Section)&       ent,
                                     const Handle(IGESData_IGESReaderData)& IR,
                                     IGESData_ParamReader&                  PR) const;

  //! Writes own parameters to IGESWriter
  Standard_EXPORT void WriteOwnParams(const Handle(IGESDimen_Section)& ent,
                                      IGESData_IGESWriter&             IW) const;

  //! Lists the Entities shared by a Section <ent>, from
  //! its specific (own) parameters
  Standard_EXPORT void OwnShared(const Handle(IGESDimen_Section)& ent,
                                 Interface_EntityIterator&        iter) const;

  //! Sets automatic unambiguous Correction on a Section
  //! (LineFont forced to Rank = 1, DataType forced to 1)
  Standard_EXPORT Standard_Boolean OwnCorrect(const Handle(IGESDimen_Section)& ent) const;

  //! Returns specific DirChecker
  Standard_EXPORT IGESData_DirChecker DirChecker(const Handle(IGESDimen_Section)& ent) const;

  //! Performs Specific Semantic Check
  Standard_EXPORT void OwnCheck(const Handle(IGESDimen_Section)& ent,
                                const Interface_ShareTool&       shares,
                                Handle(Interface_Check)&         ach) const;

  //! Copies Specific Parameters
  Standard_EXPORT void OwnCopy(const Handle(IGESDimen_Section)& entfrom,
                               const Handle(IGESDimen_Section)& entto,
                               Interface_CopyTool&              TC) const;

  //! Dump of Specific Parameters
  Standard_EXPORT void OwnDump(const Handle(IGESDimen_Section)& ent,
                               const IGESData_IGESDumper&       dumper,
                               Standard_OStream&                S,
                               const Standard_Integer           own) const;

protected:
private:
};

#endif // _IGESDimen_ToolSection_HeaderFile
