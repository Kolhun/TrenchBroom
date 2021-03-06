/*
 Copyright (C) 2010-2017 Kristian Duske

 This file is part of TrenchBroom.

 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#include "FindLayerVisitor.h"

#include "Model/Node.h"

namespace TrenchBroom {
    namespace Model {
        void FindLayerVisitor::doVisit(World* world) {}

        void FindLayerVisitor::doVisit(Layer* layer) {
            setResult(layer);
            cancel();
        }

        void FindLayerVisitor::doVisit(Group* group) {}
        void FindLayerVisitor::doVisit(Entity* entity) {}
        void FindLayerVisitor::doVisit(Brush* brush) {}

        Model::Layer* findLayer(Model::Node* node) {
            FindLayerVisitor visitor;
            node->acceptAndEscalate(visitor);
            return visitor.result();
        }
    }
}
