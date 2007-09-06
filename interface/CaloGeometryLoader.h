#ifndef GEOMETRY_ECALGEOMETRYLOADER_H
#define GEOMETRY_ECALGEOMETRYLOADER_H 1

#include "DetectorDescription/Core/interface/DDSolid.h"
//#include "Geometry/CaloGeometry/interface/CaloVGeometryLoader.h"

#include "DetectorDescription/Core/interface/DDFilter.h"
#include "DetectorDescription/Core/interface/DDFilteredView.h"
#include "CLHEP/Geometry/Transform3D.h"
#include <string>
#include <vector>

/** \class EcalGeometryLoader
 *
 *
 * base class for endcap and barrel loaders so code sharing can occur
*/

class DDCompactView;
class CaloSubdetectorGeometry;

template < class T >
class CaloGeometryLoader
{
   public:

      typedef std::vector< double > ParmVec ;

      typedef std::auto_ptr< CaloSubdetectorGeometry > PtrType ;

      CaloGeometryLoader< T >() ;

      ~CaloGeometryLoader< T >() {}
 
      PtrType load( const DDCompactView* cpv ) ;  

   private:

      void makeGeometry( const DDCompactView* cpv  , 
			 T*                   geom   ) ;

      void fillNamedParams( DDFilteredView fv,
			    T*             geom ) ;

      void fillGeom( T*                           geom ,
		     const ParmVec&               pv ,
		     const HepTransform3D&        tr ,
		     const DetId&                 id     ) ;

      void extraStuff( T* geom ) ;

      unsigned int getDetIdForDDDNode( const DDFilteredView& fv ) ;

      typename T::NumberingScheme m_scheme;
      DDSpecificsFilter  m_filter;
};

#endif