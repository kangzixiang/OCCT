// Created on: 1997-12-05
// Created by: Philippe MANGIN
// Copyright (c) 1997-1999 Matra Datavision
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

#include <GCPnts_AbscissaPoint.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Geometry.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <GeomConvert.hxx>
#include <GeomFill_UniformSection.hxx>
#include <gp_Pnt.hxx>
#include <Precision.hxx>
#include <Standard_Type.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>

#include <stdio.h>
IMPLEMENT_STANDARD_RTTIEXT(GeomFill_UniformSection, GeomFill_SectionLaw)

#ifdef DRAW
  #include <DrawTrSurf.hxx>
  #include <Geom_Curve.hxx>
  #include <Geom_BSplineCurve.hxx>
static Standard_Integer NumSec = 0;
static Standard_Boolean Affich = 0;
#endif

GeomFill_UniformSection::GeomFill_UniformSection(const Handle(Geom_Curve)& C,
                                                 const Standard_Real       FirstParameter,
                                                 const Standard_Real       LastParameter)
    : First(FirstParameter),
      Last(LastParameter)
{
  mySection = Handle(Geom_Curve)::DownCast(C->Copy());
  myCurve   = Handle(Geom_BSplineCurve)::DownCast(C);
  if (myCurve.IsNull())
  {
    myCurve = GeomConvert::CurveToBSplineCurve(C, Convert_QuasiAngular);
    if (myCurve->IsPeriodic())
    {
      Standard_Integer M = myCurve->Degree() / 2 + 1;
      myCurve->RemoveKnot(1, M, Precision::Confusion());
    }
  }

#ifdef DRAW
  if (Affich)
  {
    char name[256];
    sprintf(name, "UnifSect_%d", ++NumSec);
    DrawTrSurf::Set(name, myCurve);
  }
#endif
}

//=======================================================
// Purpose :D0
//=======================================================
Standard_Boolean GeomFill_UniformSection::D0(const Standard_Real,
                                             TColgp_Array1OfPnt&   Poles,
                                             TColStd_Array1OfReal& Weights)
{
  myCurve->Poles(Poles);
  myCurve->Weights(Weights);

  return Standard_True;
}

//=======================================================
// Purpose :D1
//=======================================================
Standard_Boolean GeomFill_UniformSection::D1(const Standard_Real,
                                             TColgp_Array1OfPnt&   Poles,
                                             TColgp_Array1OfVec&   DPoles,
                                             TColStd_Array1OfReal& Weights,
                                             TColStd_Array1OfReal& DWeights)
{
  myCurve->Poles(Poles);
  myCurve->Weights(Weights);
  gp_Vec V0(0, 0, 0);
  DPoles.Init(V0);
  DWeights.Init(0);

  return Standard_True;
}

//=======================================================
// Purpose :D2
//=======================================================
Standard_Boolean GeomFill_UniformSection::D2(const Standard_Real,
                                             TColgp_Array1OfPnt&   Poles,
                                             TColgp_Array1OfVec&   DPoles,
                                             TColgp_Array1OfVec&   D2Poles,
                                             TColStd_Array1OfReal& Weights,
                                             TColStd_Array1OfReal& DWeights,
                                             TColStd_Array1OfReal& D2Weights)
{
  myCurve->Poles(Poles);
  myCurve->Weights(Weights);
  gp_Vec V0(0, 0, 0);
  DPoles.Init(V0);
  DWeights.Init(0);
  D2Poles.Init(V0);
  D2Weights.Init(0);

  return Standard_True;
}

//=======================================================
// Purpose :BSplineSurface()
//=======================================================
Handle(Geom_BSplineSurface) GeomFill_UniformSection::BSplineSurface() const
{
  Standard_Integer        ii, NbPoles = myCurve->NbPoles();
  TColgp_Array2OfPnt      Poles(1, NbPoles, 1, 2);
  TColStd_Array1OfReal    UKnots(1, myCurve->NbKnots()), VKnots(1, 2);
  TColStd_Array1OfInteger UMults(1, myCurve->NbKnots()), VMults(1, 2);

  for (ii = 1; ii <= NbPoles; ii++)
  {
    Poles(ii, 1) = Poles(ii, 2) = myCurve->Pole(ii);
  }

  myCurve->Knots(UKnots);
  VKnots(1) = First;
  VKnots(2) = Last;

  myCurve->Multiplicities(UMults);
  VMults.Init(2);

  Handle(Geom_BSplineSurface) BS = new (Geom_BSplineSurface)(Poles,
                                                             UKnots,
                                                             VKnots,
                                                             UMults,
                                                             VMults,
                                                             myCurve->Degree(),
                                                             1,
                                                             myCurve->IsPeriodic());

  return BS;
}

//=======================================================
// Purpose :SectionShape
//=======================================================
void GeomFill_UniformSection::SectionShape(Standard_Integer& NbPoles,
                                           Standard_Integer& NbKnots,
                                           Standard_Integer& Degree) const
{
  NbPoles = myCurve->NbPoles();
  NbKnots = myCurve->NbKnots();
  Degree  = myCurve->Degree();
}

void GeomFill_UniformSection::Knots(TColStd_Array1OfReal& TKnots) const
{
  myCurve->Knots(TKnots);
}

//=======================================================
// Purpose :Mults
//=======================================================
void GeomFill_UniformSection::Mults(TColStd_Array1OfInteger& TMults) const
{
  myCurve->Multiplicities(TMults);
}

//=======================================================
// Purpose :IsRational
//=======================================================
Standard_Boolean GeomFill_UniformSection::IsRational() const
{
  return myCurve->IsRational();
}

//=======================================================
// Purpose :IsUPeriodic
//=======================================================
Standard_Boolean GeomFill_UniformSection::IsUPeriodic() const
{
  return myCurve->IsPeriodic();
}

//=======================================================
// Purpose :IsVPeriodic
//=======================================================
Standard_Boolean GeomFill_UniformSection::IsVPeriodic() const
{
  return Standard_True;
}

//=======================================================
// Purpose :NbIntervals
//=======================================================
// Standard_Integer GeomFill_UniformSection::NbIntervals(const GeomAbs_Shape S) const
Standard_Integer GeomFill_UniformSection::NbIntervals(const GeomAbs_Shape) const
{
  return 1;
}

//=======================================================
// Purpose :Intervals
//=======================================================
void GeomFill_UniformSection::Intervals(TColStd_Array1OfReal& T,
                                        //					 const GeomAbs_Shape S) const
                                        const GeomAbs_Shape) const
{
  T(T.Lower()) = First;
  T(T.Upper()) = Last;
}

//=======================================================
// Purpose : SetInterval
//=======================================================
void GeomFill_UniformSection::SetInterval(const Standard_Real, const Standard_Real)
{
  // Ne fait Rien
}

//=======================================================
// Purpose : GetInterval
//=======================================================
void GeomFill_UniformSection::GetInterval(Standard_Real& F, Standard_Real& L) const
{
  F = First;
  L = Last;
}

//=======================================================
// Purpose : GetDomain
//=======================================================
void GeomFill_UniformSection::GetDomain(Standard_Real& F, Standard_Real& L) const
{
  F = First;
  L = Last;
}

//=======================================================
// Purpose : GetTolerance
//=======================================================
void GeomFill_UniformSection::GetTolerance(const Standard_Real BoundTol,
                                           const Standard_Real SurfTol,
                                           //					    const Standard_Real AngleTol,
                                           const Standard_Real,
                                           TColStd_Array1OfReal& Tol3d) const
{
  Tol3d.Init(SurfTol);
  if (BoundTol < SurfTol)
  {
    Tol3d(Tol3d.Lower()) = BoundTol;
    Tol3d(Tol3d.Upper()) = BoundTol;
  }
}

//=======================================================
// Purpose :
//=======================================================
gp_Pnt GeomFill_UniformSection::BarycentreOfSurf() const
{
  Standard_Real U = mySection->FirstParameter(), Delta;
  gp_Pnt        P, Bary;

  Delta = (myCurve->LastParameter() - U) / 20;
  Bary.SetCoord(0., 0., 0.);
  for (Standard_Integer ii = 0; ii <= 20; ii++, U += Delta)
  {
    P = myCurve->Value(U);
    Bary.ChangeCoord() += P.XYZ();
  }
  Bary.ChangeCoord() /= 21.;

  return Bary;
}

Standard_Real GeomFill_UniformSection::MaximalSection() const
{
  GeomAdaptor_Curve AC(mySection);
  return GCPnts_AbscissaPoint::Length(AC);
}

void GeomFill_UniformSection::GetMinimalWeight(TColStd_Array1OfReal& Weights) const
{
  if (myCurve->IsRational())
  {
    myCurve->Weights(Weights);
  }
  else
  {
    Weights.Init(1);
  }
}

Standard_Boolean GeomFill_UniformSection::IsConstant(Standard_Real& Error) const
{
  Error = 0.;
  return Standard_True;
}

Handle(Geom_Curve) GeomFill_UniformSection::ConstantSection() const
{
  Handle(Geom_Curve) C;
  C = Handle(Geom_Curve)::DownCast(mySection->Copy());
  return C;
}
