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

#ifndef VertexTool_h
#define VertexTool_h

#include "Renderer/PointGuideRenderer.h"
#include "View/UndoableCommand.h"
#include "View/VertexToolBase.h"
#include "View/VertexHandleManager.h"

namespace TrenchBroom {
    namespace Model {
        class PickResult;
    }

    namespace Renderer {
        class Camera;
        class RenderContext;
        class RenderBatch;
        class RenderService;
    }

    namespace View {
        class Grid;
        class Lasso;
        class Selection;

        class VertexTool : public VertexToolBase<vm::vec3> {
        private:
            typedef enum {
                Mode_Move,
                Mode_Split_Edge,
                Mode_Split_Face
            } Mode;

            Mode m_mode;

            VertexHandleManager m_vertexHandles;
            EdgeHandleManager m_edgeHandles;
            FaceHandleManager m_faceHandles;

            mutable Renderer::PointGuideRenderer m_guideRenderer;
        public:
            VertexTool(MapDocumentWPtr document);
        public:
            Model::BrushSet findIncidentBrushes(const vm::vec3& handle) const;
            Model::BrushSet findIncidentBrushes(const vm::segment3& handle) const;
            Model::BrushSet findIncidentBrushes(const vm::polygon3& handle) const;
        private:
            using VertexToolBase::findIncidentBrushes;
        public:
            void pick(const vm::ray3& pickRay, const Renderer::Camera& camera, Model::PickResult& pickResult) const override;
        public: // Handle selection
            bool deselectAll() override;
        public:
            VertexHandleManager& handleManager() override;
            const VertexHandleManager& handleManager() const override;
        public: // Vertex moving
            bool startMove(const Model::Hit::List& hits) override;
            MoveResult move(const vm::vec3& delta) override;
            void endMove() override;
            void cancelMove() override;

            const vm::vec3& getHandlePosition(const Model::Hit& hit) const override;
            String actionName() const override;

            void removeSelection();
        public: // Rendering
            void renderGuide(Renderer::RenderContext& renderContext, Renderer::RenderBatch& renderBatch, const vm::vec3& position) const override;
        private: // Tool interface
            bool doActivate() override;
            bool doDeactivate() override;
        private:
            void addHandles(const Model::NodeList& nodes) override;
            void removeHandles(const Model::NodeList& nodes) override;

            void addHandles(VertexCommand* command) override;
            void removeHandles(VertexCommand* command) override;
        private: // General helper methods
            void resetModeAfterDeselection();
        };
    }
}

#endif /* VertexTool_h */
