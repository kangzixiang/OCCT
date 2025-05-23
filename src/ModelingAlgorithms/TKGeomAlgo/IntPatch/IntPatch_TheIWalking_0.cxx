// Created on: 1992-05-06
// Created by: Jacques GOUSSARD
// Copyright (c) 1992-1999 Matra Datavision
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

#include <IntPatch_TheIWalking.hxx>

#include <StdFail_NotDone.hxx>
#include <Standard_OutOfRange.hxx>
#include <IntSurf_PathPoint.hxx>
#include <IntSurf_PathPointTool.hxx>
#include <IntSurf_InteriorPoint.hxx>
#include <IntSurf_InteriorPointTool.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Adaptor3d_HSurfaceTool.hxx>
#include <IntPatch_TheSurfFunction.hxx>
#include <IntPatch_TheIWLineOfTheIWalking.hxx>
#include <IntPatch_SequenceOfIWLineOfTheIWalking.hxx>
#include <IntSurf_PntOn2S.hxx>

#define ThePointOfPath IntSurf_PathPoint
#define ThePointOfPath_hxx <IntSurf_PathPoint.hxx>
#define ThePointOfPathTool IntSurf_PathPointTool
#define ThePointOfPathTool_hxx <IntSurf_PathPointTool.hxx>
#define ThePOPIterator IntSurf_SequenceOfPathPoint
#define ThePOPIterator_hxx <IntSurf_SequenceOfPathPoint.hxx>
#define ThePointOfLoop IntSurf_InteriorPoint
#define ThePointOfLoop_hxx <IntSurf_InteriorPoint.hxx>
#define ThePointOfLoopTool IntSurf_InteriorPointTool
#define ThePointOfLoopTool_hxx <IntSurf_InteriorPointTool.hxx>
#define ThePOLIterator IntSurf_SequenceOfInteriorPoint
#define ThePOLIterator_hxx <IntSurf_SequenceOfInteriorPoint.hxx>
#define ThePSurface Handle(Adaptor3d_Surface)
#define ThePSurface_hxx <Adaptor3d_Surface.hxx>
#define ThePSurfaceTool Adaptor3d_HSurfaceTool
#define ThePSurfaceTool_hxx <Adaptor3d_HSurfaceTool.hxx>
#define TheIWFunction IntPatch_TheSurfFunction
#define TheIWFunction_hxx <IntPatch_TheSurfFunction.hxx>
#define IntWalk_TheIWLine IntPatch_TheIWLineOfTheIWalking
#define IntWalk_TheIWLine_hxx <IntPatch_TheIWLineOfTheIWalking.hxx>
#define IntWalk_SequenceOfIWLine IntPatch_SequenceOfIWLineOfTheIWalking
#define IntWalk_SequenceOfIWLine_hxx <IntPatch_SequenceOfIWLineOfTheIWalking.hxx>
#define Handle_IntWalk_TheIWLine Handle(IntPatch_TheIWLineOfTheIWalking)
#define IntWalk_IWalking IntPatch_TheIWalking
#define IntWalk_IWalking_hxx <IntPatch_TheIWalking.hxx>
#include <IntWalk_IWalking.gxx>
