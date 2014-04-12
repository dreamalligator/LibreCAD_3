#ifndef SPLINE_H
#define SPLINE_H

#include "qdebug.h"

#include "cad/const.h"
#include "cad/interface/entityvisitor.h"
#include "cad/interface/entitydispatch.h"

#include "lckernel_global.h"
#include "cad/geometry/geocoordinate.h"
#include "cad/geometry/geospline.h"
#include "cad/base/cadentity.h"
#include "cad/vo/entitycoordinate.h"
#include "cad/interface/snapable.h"

namespace lc {


    class Spline : public enable_shared_from_this<Spline>, public CADEntity, public geo::Spline, public Snapable {
        public:
            Spline(const QList<geo::Coordinate>& control_points, const int degree, const bool closed);
            Spline(const QList<geo::Coordinate>& control_points, const int degree, const bool closed, const QList<shared_ptr<const lc::MetaType> >& metaTypes);

        public:
            virtual QList<lc::EntityCoordinate> snapPoints(const geo::Coordinate& coord, double minDistanceToSnap, int maxNumberOfSnapPoints) const;
            virtual geo::Coordinate nearestPointOnPath(const geo::Coordinate& coord) const;

        public:
            virtual shared_ptr<const lc::CADEntity> move(const geo::Coordinate& offset) const;
            virtual shared_ptr<const lc::CADEntity> copy(const geo::Coordinate& offset) const;
            virtual shared_ptr<const lc::CADEntity> rotate(const geo::Coordinate &rotation_center, const double& rotation_angle, const bool with_same_id) const;
            virtual shared_ptr<const lc::CADEntity> scale(const geo::Coordinate& scale_center, const geo::Coordinate& scale_factor) const;
        public:
            virtual void accept(shared_ptr<const lc::Line> o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(shared_ptr<const lc::Circle> o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(shared_ptr<const lc::Arc> o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(shared_ptr<const lc::Ellipse> o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(shared_ptr<const lc::Text> o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(shared_ptr<const lc::Spline> o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(shared_ptr<const lc::CADEntity> o, EntityVisitor& ei) const {
                o->accept(shared_from_this(), ei);
            }
            virtual void dispatch(EntityDispatch& ed) const {
                ed.visit(shared_from_this());
            }

    };
}

#endif // SPLINE_H
