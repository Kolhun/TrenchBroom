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
 along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "SmartDefaultAttributeEditor.h"

#include "Assets/EntityDefinition.h"
#include "Model/AttributableNode.h"

#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/wupdlock.h>

namespace TrenchBroom {
    namespace View {
        SmartDefaultAttributeEditor::SmartDefaultAttributeEditor(View::MapDocumentWPtr document) :
        SmartAttributeEditor(document),
        m_panel(nullptr) {}

        wxWindow* SmartDefaultAttributeEditor::doCreateVisual(wxWindow* parent) {
            m_panel = new wxPanel(parent);
            return m_panel;
        }

        void SmartDefaultAttributeEditor::doDestroyVisual() {
            m_panel->Destroy();
            m_panel = nullptr;
        }

        void SmartDefaultAttributeEditor::doUpdateVisual(const Model::AttributableNodeList& attributables) {
        }
    }
}
